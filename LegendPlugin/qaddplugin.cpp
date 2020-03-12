#include "qaddplugin.h"
#include "ui_qaddplugin.h"
#include "easylogging++.h"
#include"gloabl.h"
QAddPlugin::QAddPlugin(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::QAddPlugin)
{
	ui->setupUi(this);
	LOG(INFO) << __FILE__ << __FUNCTION__ << " QAddPlugin form is init";
	ui->progressBar->setValue(0);
	connect(ui->btn_browse, SIGNAL(clicked()), this, SLOT(slot_SelectBrowseFile()));
	connect(ui->btn_cancel, SIGNAL(clicked()), this, SLOT(slot_CancelDownProcject()));
	connect(ui->btn_download, SIGNAL(clicked()), this, SLOT(slot_DownLoadProject()));
	connect(&ftp, SIGNAL(listInfo(QUrlInfo)), SLOT(listInfo(QUrlInfo)));
	connect(&ftp, SIGNAL(commandFinished(int, bool)), SLOT(commandFinished(int, bool)));
	connect(&ftp, SIGNAL(dataTransferProgress(qint64, qint64)), SLOT(dataTransferProgress(qint64, qint64)));
	des = new DesCrypt();
}


QAddPlugin::~QAddPlugin()
{
	delete ui;

	if (des)
	{
		delete des;
		des = NULL;
	}
}

bool QAddPlugin::InitFTP()
{
	if (ui->txt_username->text().isEmpty())
	{
		LOG(ERROR) << "用户名不能为空";
		QMessageBox::critical(NULL, tr("Error"), "用户名不能为空");
		return false;
	}
	else if (ui->txt_password->text().isEmpty())
	{
		LOG(ERROR) << "密码不能为空";
		QMessageBox::critical(NULL, tr("Error"), "密码不能为空");
		return false;
	}
	else if (ui->txt_name->text().isEmpty())
	{
		LOG(ERROR) << "项目名称不能为空";
		QMessageBox::critical(NULL, tr("Error"), "项目名称不能为空");
		return false;
	}
	else if (ui->txt_config_path->text().isEmpty())
	{
		LOG(ERROR) << "配置路径不能为空";
		QMessageBox::critical(NULL, tr("Error"), "配置路径不能为空");
		return false;
	}
	else if (ui->txt_ftp->text().isEmpty())
	{
		LOG(ERROR) << "ftp地址不能为空";
		QMessageBox::critical(NULL, tr("Error"), "ftp地址不能为空");
		return false;
	}
	QUrl url = QUrl(ui->txt_ftp->text());
	if (!url.isValid())
	{
		LOG(ERROR) << "'" << ui->txt_ftp->text().toStdString().c_str() << "'URL地址不合法！";
		QMessageBox::critical(NULL, tr("Error"), "URL地址不合法！");
	}
	LOG(INFO) << " ftp address:" << ui->txt_ftp->text().toStdString().c_str();
	if (ftp.state() != QFtp::LoggedIn)
	{
		ftp.connectToHost(ui->txt_ftp->text().toStdString().c_str());
		ftp.login(ui->txt_username->text().toStdString().c_str(), ui->txt_password->text().toStdString().c_str());
		LOG(INFO) << "usernmae:" << ui->txt_username->text().toStdString().c_str();
		LOG(INFO) << "password:" << ui->txt_password->text().toStdString().c_str();
		LOG(INFO) << "default ftp port:" << FTP_PORT;
	}
	return true;
}


void QAddPlugin::commandFinished(int, bool err)
{
	int cmd = ftp.currentCommand();
	switch (cmd)
	{
	case QFtp::Login:
		if (!err)
		{
			ftp.list();
			log = QString("%1 %2").arg(ui->txt_ftp->text().toStdString().c_str()).arg("服务器连接成功");
			InsertLong(true, log);
		}
		else
		{
			InsertLong(false, ftp.errorString());
		}
		break;
	case QFtp::Close:
		if (!err)
		{
			log = QString("%1 %2").arg(ui->txt_ftp->text().toStdString().c_str()).arg("断开服务器连接");
			InsertLong(true, log);
		}
		else
		{
			InsertLong(false, ftp.errorString());
		}
		break;

	case QFtp::Get:
		if (file.isOpen())
		{
			file.flush();
			file.close();
			log = QString("%1 %2").arg(path.toStdString().c_str()).arg("文件下载成功");

			InsertLong(true, log);
			DecryptionFile();
		}
		else
		{
			InsertLong(false, ftp.errorString());
		}
		break;

	case QFtp::Put:
		if (file.isOpen())
		{
			file.close();
			InsertLong(true, "文件上传成功");
		}
		else
		{
			InsertLong(false, ftp.errorString());
		}
		break;
	}
}


void QAddPlugin::slot_DownLoadProject()
{
	if (InitFTP())
	{
		ui->btn_browse->setEnabled(false);
		ui->btn_download->setEnabled(false);
		tmpMainFile = QString("%1%2%3%4").arg(QDir::tempPath()).arg("/").arg(QBase::RandomString()).arg(DEFUALT_FILE);
		file.setFileName(tmpMainFile.toStdString().c_str());
		if (!file.open(QIODevice::WriteOnly))
		{
			LOG(ERROR) << " file is open error or write error:" << file.errorString().toStdString().c_str();
		}
		int t = ftp.get(DEFUALT_FILE, &file);

		cp.title = ui->txt_name->text().toStdString().c_str();
		cp.path = ui->txt_config_path->text().toStdString().c_str();
		cp.ftp = ui->txt_ftp->text().toStdString().c_str();
		cp.username = ui->txt_username->text().toStdString().c_str();
		//cp.password=ui->txt_password->text().toStdString().c_str();  ftp://hx:123456@219.146.3.7/workplan.ini   ftp://219.146.3.7/workplan.ini
		cp.mainfile = path;
		xml.WriteXml(cp);

	}
}



void QAddPlugin::dataTransferProgress(qint64 readBytes, qint64 totalBytes)
{
	ui->progressBar->setMaximum(totalBytes);
	ui->progressBar->setValue(readBytes);

}


void QAddPlugin::slot_SelectBrowseFile()
{
	down_ftp_path = QFileDialog::getExistingDirectory(this, "选择文件保存路径", "/");

	if (down_ftp_path.isEmpty())
	{
		return;
	}
	else
	{
		LOG(INFO) << "select download ftp file directory is :" << down_ftp_path.toStdString().c_str();
		ui->txt_config_path->setText(down_ftp_path);
		down_ftp_path += "/";
	}
}

void QAddPlugin::InsertLong(bool isOk, QString log)
{
	ui->list_log->insertItem(ui->list_log->count(), log);
	if (isOk)
	{
		LOG(INFO) << log.toStdString().c_str();;
	}
	else
	{
		LOG(ERROR) << log.toStdString().c_str();;
	}
}

void QAddPlugin::slot_CancelDownProcject()
{
	

	if (ftp.state() == QFtp::LoggedIn)
	{
		LOG(INFO) << __FUNCTION__ << " click button is' " << ui->btn_cancel->text().toStdString().c_str() << " ' and close ftp";
		ftp.close();
	}
}

void QAddPlugin::DecryptionFile()
{
	
	path = QString("%1%2").arg(ui->txt_config_path->text().toStdString().c_str()).arg("workplan.ini");
	if (tmpMainFile.isEmpty())
	{
		LOG(ERROR) << " tmp main file is empty string";
		return;
	}
	QFile fileD(tmpMainFile);
	AES aes(Bits256, aeskey);
	QFile tmpFile(path);
	if(!aes.FileInvCipher(&fileD, &tmpFile))
	{
		LOG(ERROR) << path.toStdString().c_str() << " extracting as " << path.toStdString().c_str() << " is failed err:"<<file.errorString().toStdString().c_str();
		return;
	}

	QSettings setting(path, QSettings::IniFormat);
	QStringList grouplist = setting.childGroups();
	foreach (QString group,grouplist )
	{
		setting.beginGroup(group);	
		QString value = setting.value("name").toString();
		LOG(INFO) << " group:" << group.toStdString().c_str() << " key:name value:" << value.toStdString().c_str();
		if (value.isEmpty())
		{
			setting.endGroup();
			continue;
		}
		if (group.compare(CONFIG_IE_FEATURE)== 0)
		{
			cp.pinfo.pi.ie_feature = value;
		}
		else if (group.compare(CONFIG_IE_WHITELIST) == 0)
		{
			cp.pinfo.pi.ie_whitelist = value;
		}
		else if (group.compare(CONFIG_IE_BLACKLIST) == 0) 
		{
			cp.pinfo.pi.ie_blacklist = value;
		}
		else if (group.compare(CONFIG_PROCESS_FEATURE) == 0) 
		{
			cp.pinfo.pp.process_feature = value;		
		}
		else if (group.compare(CONFIG_PROCESS_WHITE) == 0)
		{
			cp.pinfo.pp = SplitWhiteList(value);
		}
		else if (group.compare(CONFIG_PROCESS_BLACK) == 0)
		{
			cp.pinfo.pp = SplitBlackList(value);
		}
		setting.endGroup();
	}
	

}

plugin_process& QAddPlugin::SplitWhiteList(QString data)//解析白名单字符串 
{ //ey: #mingdan1.txt#mingdan2.txt#mingdan3.txt#
	plugin_process pp;
	QStringList main = data.split("#");
	for (QStringList::iterator it = main.begin(); it != main.end(); ++it)
	{
		if (!it->size())
		{
			continue;
		}
		pp.process_whitelist << *it;
		QString tmp = *it;
		LOG(INFO) << tmp.toStdString().c_str();
	}
	return pp;

}

plugin_process & QAddPlugin::SplitBlackList(QString data)//解析黑名单字符串 
{
	//ey: #mingdan1.txt 5 *http://11.com*http://22.com*http://33.com*#mingdan2.txt 10 *http://11.com*http://22.com*http://33.com*#mingdan3.txt  5 *http://11.com*http://22.com*http://33.com*#
#define BLACK_LIST_VALID_FIELD 3
	plugin_process pp;
	QStringList main = data.split("#");
	for (QStringList::iterator it = main.begin(); it != main.end(); ++it)
	{
		if (!it->size())
		{
			continue;
		}
		blacklist bl;
		QStringList tmp = it->split(" ");
		if (tmp.size()< BLACK_LIST_VALID_FIELD)
		{
			continue;
		}
		bl.filename = tmp[0];
		bl.num = tmp[1];
		if (!bl.filename.isEmpty() && !bl.num.isEmpty()&& QBase::IsNumber(bl.num))
		{
			QStringList link = tmp[2].split("*");
			for (QStringList::iterator ie = link.begin(); ie != link.end(); ++ie)
			{
				if (!ie->size())
				{
					continue;
				}
				bl.link << *ie;
			}
			pp.process_blacklist.push_back(bl);
		}
		else 
		{
			LOG(ERROR) << " blacklist filename and num is invalid";
		}

	}
	return pp;
}