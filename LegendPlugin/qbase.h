#ifndef QBASE_H
#define QBASE_H

#include<QString>
class QBase
{
public:
    QBase();
   static QString  toXOREncryptUncrypt(QByteArray src, const QString key);
   static  QString  RandomString();
   static bool copyFileToPath(QString sourceDir, QString toDir, bool coverFileIfExist);
   static bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);
   static bool  IsEnglish(QString &qstrSrc);
   static bool  IsNumber(QString &qstrSrc);
};

#endif // QBASE_H
