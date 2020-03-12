#include "qbase.h"
#include "gloabl.h"
QBase::QBase()
{

}

QString QBase::toXOREncryptUncrypt(QByteArray src, const QString key)
{
    for(int i = 0; i < src.size(); i++)
    {
        for (int j=0;j<key.count();j++)
        {
                 src[i] = src.at(i) ^ key[j].toLatin1();
        }
    }
    return src;
}


QString QBase::RandomString()//�ַ��������
{
#define LENGTH 15
	qsrand(QDateTime::currentMSecsSinceEpoch());//Ϊ���ֵ�趨һ��seed

	const char chrs[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int chrs_size = sizeof(chrs);

	char* ch = new char[LENGTH + 1];
	memset(ch, 0, LENGTH + 1);
	int randomx = 0;
	for (int i = 0; i < LENGTH; ++i)
	{
		randomx = rand() % (chrs_size - 1);
		ch[i] = chrs[randomx];
	}

	QString ret(ch);
	delete[] ch;
	return ret;
}


//�����ļ���
bool QBase::copyFileToPath(QString sourceDir, QString toDir, bool coverFileIfExist)
{
	toDir.replace("\\", "/");
	if (sourceDir == toDir) 
	{
		return true;
	}
	if (!QFile::exists(sourceDir)) 
	{
		return false;
	}
	QDir *createfile = new QDir;
	bool exist = createfile->exists(toDir);
	if (exist) 
	{
		if (coverFileIfExist)
		{
			createfile->remove(toDir);
		}
	}//end if

	if (!QFile::copy(sourceDir, toDir))
	{
		return false;
	}
	return true;
}

//�����ļ��У�
bool QBase::copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
{
	QDir sourceDir(fromDir);
	QDir targetDir(toDir);
	if (!targetDir.exists()) 
	{    //���Ŀ��Ŀ¼�����ڣ�����д��� 
		if (!targetDir.mkdir(targetDir.absolutePath())) 
		{
			return false;
		}		
	}
	QFileInfoList fileInfoList = sourceDir.entryInfoList();
	foreach(QFileInfo fileInfo, fileInfoList) 
	{
		if (fileInfo.fileName() == "." || fileInfo.fileName() == "..") 
		{
			continue;
		}
	
		if (fileInfo.isDir()) //��ΪĿ¼ʱ���ݹ�Ľ���copy 
		{    
			if (!copyDirectoryFiles(fileInfo.filePath(), targetDir.filePath(fileInfo.fileName()), coverFileIfExist)) 
			{
				return false;
			}			
		}
		else 
		{            
			if (coverFileIfExist && targetDir.exists(fileInfo.fileName()))// �������ǲ���ʱ�������ļ�����ɾ������ 
			{
				targetDir.remove(fileInfo.fileName());
			}
			/// �����ļ�copy
			if (!QFile::copy(fileInfo.filePath(),targetDir.filePath(fileInfo.fileName())))
			{
				return false;
			}
		}
	}
	return true;
}

bool QBase::IsEnglish(QString &qstrSrc)//�Ƿ��Ǵ�Ӣ��
{
	QByteArray ba = qstrSrc.toLatin1();
	const char *s = ba.data();
	bool bret = true;
	while (*s)
	{
		if ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
		{

		}
		else
		{
			bret = false;
			break;
		}
		s++;
	}
	return bret;
}

bool QBase::IsNumber(QString &qstrSrc)//�Ƿ��Ǵ�����
{
	QByteArray ba = qstrSrc.toLatin1();
	const char *s = ba.data();
	bool bret = true;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
		{

		}
		else
		{
			bret = false;
			break;
		}
		s++;
	}
	return bret;
}
 