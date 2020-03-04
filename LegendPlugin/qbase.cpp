#include "qbase.h"

QBase::QBase()
{

}

QString QBase::toXOREncryptUncrypt(QString src, const QString key)
{
    for(int i = 0; i < src.count(); i++)
    {
        for (int j=0;j<key.count();j++)
        {
                 src[i] = src.at(i).toLatin1() ^ key[j].toLatin1();
        }

    }
    return src;
}
