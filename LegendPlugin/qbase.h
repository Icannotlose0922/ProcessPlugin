#ifndef QBASE_H
#define QBASE_H

#include<QString>
class QBase
{
public:
    QBase();
   static QString  toXOREncryptUncrypt(QString src, const QString key);
};

#endif // QBASE_H
