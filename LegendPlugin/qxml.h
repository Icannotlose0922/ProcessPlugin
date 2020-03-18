#ifndef QXML_H
#define QXML_H
#include <QtXml>

#include<QFile>
#define CONFIG_FILENAME  "config.xml"


typedef struct plugin_ie
{
	QString ie_feature;//ie特征
	QString ie_whitelist;//ie白名单

	QString ie_blacklist;
}PLUGIN_IE;

typedef struct blacklist 
{
	QString filename;
	QString num;
	QStringList link;
}BLACKLIST;
typedef struct plugin_process
{
	QString process_feature;//特征
	QStringList  process_whitelist;//白名单

	QVector<blacklist> process_blacklist;
}PLUGIN_PROCESS;


typedef struct plugin_info
{
	plugin_process pp;
	plugin_ie  pi;

}PLUGIN_INFO;

typedef struct config_plugin
{
   QString title;//项目名称
   QString path;//配置路径
   QString ftp;
   QString password;
   QString username;//用户名

   QString mainfile;//主配置文件
   bool openSynchronize;//开启网站同步
   bool tempFile;//生成临时文件
   bool processWarning;//进程警告
   bool illegal_pages;//非法网页
   QString warningLink;//警告链接
   PLUGIN_INFO  pinfo;
}CONFIG_PLUGIN;

class QXml
{
 public:
    static void WriteXml(CONFIG_PLUGIN &cp);
    void ReadXml(CONFIG_PLUGIN &cp);
    void AddXml(CONFIG_PLUGIN &cp);
   void RemoveXml(CONFIG_PLUGIN &cp);
    void UpdateXml(CONFIG_PLUGIN &cp);
};

#endif // QXML_H
