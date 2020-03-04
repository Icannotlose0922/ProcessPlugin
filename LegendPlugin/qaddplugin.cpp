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
        LOG (ERROR) << "'" << ui->txt_ftp->text().toStdString().c_str() << "'URL地址不合法！";
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
            log=QString("%1 %2").arg(ui->txt_ftp->text().toStdString().c_str()).arg("服务器连接成功");
            InsertLong(true,log);
        }
        else
        {
            InsertLong(false,ftp.errorString());
        }
        break;
    case QFtp::Close:
        if (!err)
        {
            log=QString("%1 %2").arg(ui->txt_ftp->text().toStdString().c_str()).arg("断开服务器连接");
            InsertLong(true,log);
        }
        else
        {
            InsertLong(false,ftp.errorString());
        }
        break;

    case QFtp::Get:
        if (file.isOpen())
        {
            file.flush();
            file.close();
            log=QString("%1 %2").arg(path.toStdString().c_str()).arg("文件下载成功");
            InsertLong(true,log);
        }
        else
        {
            InsertLong(false,ftp.errorString());
        }
        break;

    case QFtp::Put:
        if (file.isOpen())
        {
            file.close();
            InsertLong(true,"文件上传成功");
        }
        else
        {
            InsertLong(false,ftp.errorString());
        }
        break;
    }
}


void QAddPlugin::slot_DownLoadProject()
{
    if (InitFTP());
    {
        ui->btn_browse->setEnabled(false);
        ui->btn_download->setEnabled(false);
        path = QString("%1/%2").arg(down_ftp_path).arg("workplan.ini");
        file.setFileName(path.toStdString().c_str());
        if(!file.open(QIODevice::WriteOnly))
        {
            LOG(ERROR)<<" file is open error or write error:"<<file.errorString().toStdString().c_str();
        }
        ftp.get(DEFUALT_FILE, &file);
        config_plugin cp;
        cp.title=ui->txt_name->text().toStdString().c_str();
        cp.path=ui->txt_config_path->text().toStdString().c_str();
        cp.ftp=ui->txt_ftp->text().toStdString().c_str();
        cp.username=ui->txt_username->text().toStdString().c_str();
        cp.password=ui->txt_password->text().toStdString().c_str();
        cp.mainfile=path;
        xml.WriteXml(cp);
		DecryptionFile();
    }
}



void QAddPlugin::dataTransferProgress(qint64 readBytes, qint64 totalBytes)
{
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(readBytes);

}


void QAddPlugin::slot_SelectBrowseFile()
{
    down_ftp_path =QFileDialog::getExistingDirectory(this, "选择文件保存路径","/");

    if (down_ftp_path.isEmpty())
    {
        return;
    }
    else
    {
        LOG(INFO)<< "select download ftp file directory is :" << down_ftp_path.toStdString().c_str();
        ui->txt_config_path->setText(down_ftp_path);
        down_ftp_path += "/";
    }
}

void QAddPlugin::InsertLong(bool isOk,QString log)
{
    ui->list_log->insertItem(ui->list_log->count(),log);
    if(isOk)
    {
        LOG(INFO)<<log.toStdString().c_str();;
    }
    else
    {
        LOG(ERROR)<<log.toStdString().c_str();;
    }
}

void QAddPlugin::slot_CancelDownProcject()
{

	QFile f1("E:/workplan.ini");
	if (!f1.open(QIODevice::ReadOnly))
	{
		LOG(ERROR) << " open config or read config'" << path.toStdString().c_str() << "' is failed.err:" << file.errorString().toStdString().c_str();
		return;
	}
	QByteArray array = f1.readAll().toBase64();
	QString str = QString(array);
	str = QBase::toXOREncryptUncrypt(str, CONFIG_FILE_PS_KEY); // 加密 --- 注意：（这里的key是可以指定为任意字符的，相应的，解密也要同意字符才行）
	f1.close();
	f1.open(QIODevice::Truncate);
	f1.close();

	f1.open(QIODevice::WriteOnly);
	f1.write(str.toStdString().c_str());
	f1.close();


    if (ftp.state() == QFtp::LoggedIn)
    {
        LOG(INFO) << __FUNCTION__ << " click button is' " << ui->btn_cancel->text().toStdString().c_str() << " ' and close ftp";
        ftp.close();
    }
}

void QAddPlugin::DecryptionFile()
{
    QString Qkey =CONFIG_FILE_PS_KEY;
    char *key = Qkey.toLatin1().data();
    des->setKey(key);

    QFile decryFile(path);
    decryFile.setFileName(path);
   if(!decryFile.open(QIODevice::ReadOnly))
   {
       LOG(ERROR)<<" open config or read config'"<<path.toStdString().c_str()<<"' is failed.err:"<<file.errorString().toStdString().c_str();
       return;
   }

   QByteArray array = decryFile.readAll();
   QString str = array;
   QString data=QBase::toXOREncryptUncrypt(str, CONFIG_FILE_PS_KEY);
   QByteArray text = data.toLocal8Bit();
   QByteArray by = text.fromBase64(text);
   decryFile.close();

   decryFile.open(QIODevice::Truncate);
   decryFile.close();

   str = QString::fromLocal8Bit(by);

   decryFile.open(QIODevice::WriteOnly);
   decryFile.write(str.toStdString().c_str());
   decryFile.close();

   QSettings setting(path,QSettings::IniFormat);
   QStringListIterator keyIterator(setting.allKeys());
    while(keyIterator.hasNext())
    {
        QString key=keyIterator.next();
        QString tmp=setting.value(key).toString();
        if(key.compare(CONFIG_IE_FEATURE)==0&&!tmp.isEmpty())
        {

        }
        if(key.compare(CONFIG_IE_WHITELIST)==0&&!tmp.isEmpty())
        {

        }
        if(key.compare(CONFIG_IE_BLACKLIST)==0&&!tmp.isEmpty())
        {

        }
        if(key.compare(CONFIG_PROCESS_FEATURE)==0&&!tmp.isEmpty())
        {

        }
        if(key.compare(CONFIG_PROCESS_WHITE)==0&&!tmp.isEmpty())
        {

        }
        if(key.compare(CONFIG_PROCESS_Black)==0&&!tmp.isEmpty())
        {

        }
    }

}
