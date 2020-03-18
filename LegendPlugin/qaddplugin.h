#ifndef QADDPLUGIN_H
#define QADDPLUGIN_H

#include <QWidget>
#include<QPushButton>
#include<QGridLayout>
#include<QHBoxLayout>
#include<QLabel>
#include<QLineEdit>
#include<QCheckBox>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMessageBox>
#include <QFileDialog>
#include <QMetaEnum>
#include <QUrl>
#include <QFile>
#include <QDir>
#include<QSettings>
#include"gloabl.h"
#include "qxml.h"
#include "aes.h"
namespace Ui {
class QAddPlugin;
}

class QAddPlugin : public QWidget
{
    Q_OBJECT

public:
    explicit QAddPlugin(QWidget *parent = 0);
    ~QAddPlugin();
private slots:
    void slot_DownLoadProject();
    void slot_SelectBrowseFile();
    void slot_CancelDownProcject();
    void commandFinished(int, bool err);
    void dataTransferProgress(qint64 readBytes, qint64 totalBytes);
private:
    Ui::QAddPlugin *ui;
    QFile file;
    QFtp ftp;
    QNetworkReply *reply;
    QString down_ftp_path;
    QString path;
    QString log;
    QXml xml;
    DesCrypt *des;
	config_plugin cp;
	QString tmpMainFile;
private:
    bool  InitFTP();
    void saveToIni();
    void loadFmIni();
    void InsertLong(bool isOk,QString log);
    void DecryptionFile();
    void SplitWhiteList(QString data,plugin_process &pp);
    void SplitBlackList(QString data,plugin_process &pp);
signals:
  void LogInfo(const QString& text);
};

#endif // QADDPLUGIN_H
