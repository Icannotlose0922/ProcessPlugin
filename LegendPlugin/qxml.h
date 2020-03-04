#ifndef QXML_H
#define QXML_H
#include <QtXml>
#define CONFIG_FILENAME  "config.xml"
typedef struct process_blacklist
{
   QString filename;
   QString count;//拦截次数
   QVector<QString>link;//链接
}PROCESS_BLACKliST;

typedef struct plugin_info
{
  QString process_feature;//进程特征
  QString ie_feature;//ie特征
  QString process_whitelist;//进程白名单
  QString ie_whitelist;//ie白名单
  PROCESS_BLACKliST pb;//进程黑名单

}PLUGIN_INFO;

typedef struct config_plugin
{
   QString title;//项目名称
   QString path;//配置路径
   QString ftp;
   QString username;//用户名
   QString password;//密码
   QString mainfile;//主配置文件
   bool openSynchronize;//开启网站同步
   bool tempFile;//生成临时文件
   bool processWarning;//进程警告
   bool illegal_pages;//非法网页
   QString warningLink;//警告链接
   PLUGIN_INFO  pi;
}CONFIG_PLUGIN;

class QXml
{
 public:
    void WriteXml(CONFIG_PLUGIN &cp);
    void ReadXml(CONFIG_PLUGIN &cp);
    void AddXml(CONFIG_PLUGIN &cp);
   void RemoveXml(CONFIG_PLUGIN &cp);
    void UpdateXml(CONFIG_PLUGIN &cp);
};

#endif // QXML_H
