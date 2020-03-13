#include"qxml.h"
#include"gloabl.h"

void QXml::WriteXml(CONFIG_PLUGIN & cp)
{
    QString filename=QString("%1%2").arg(cp.path).arg(CONFIG_FILENAME);
    QFile file(filename); //相对路径、绝对路径、资源路径都可以
	if (!file.open(QFile::WriteOnly|QFile::Truncate))
	{
		return;
	}
    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true); // 自动格式化
    writer.writeStartDocument();  // 开始文档（XML 声明）

    writer.writeEndDocument();  // 结束文档
	QDomDocument doc;
    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);
    QDomElement root = doc.createElement("root");
	doc.appendChild(root);

	QDomElement project = doc.createElement("project");
	QDomAttr project_name = doc.createAttribute("name");
	project_name.setValue(cp.title);
	project.setAttributeNode(project_name);

	QDomElement ftp = doc.createElement("ftp");
	QDomText ftp_text; //设置括号标签中间的值
	ftp_text = doc.createTextNode(cp.ftp);
	project.appendChild(ftp);
	ftp.appendChild(ftp_text);

	QDomElement username = doc.createElement("usernmae");
	QDomText username_text = doc.createTextNode(cp.username);
	username.appendChild(username_text);
	project.appendChild(username);

	QDomElement password = doc.createElement("password");
	QDomText password_text = doc.createTextNode(cp.password);
	password.appendChild(password_text);
	project.appendChild(password);

	QDomElement mainfile = doc.createElement("mainfile");
	QDomText mainfile_text = doc.createTextNode(cp.mainfile);
	mainfile.appendChild(mainfile_text);
	project.appendChild(mainfile);

    QDomElement plugin = doc.createElement( "plugin" );
    QDomElement ie = doc.createElement( "ie_plugin" );

      QDomElement iefeature = doc.createElement( "featurelist" );
      QDomAttr fname = doc.createAttribute( "name" );
      fname.setValue("111.txt");
      iefeature.setAttributeNode(fname);
      ie.appendChild(iefeature);

      QDomElement iewhite = doc.createElement( "whitelist" );
      QDomAttr wname = doc.createAttribute( "name" );
      wname.setValue("在.txt");
      iewhite.setAttributeNode(wname);
      ie.appendChild(iewhite);

      QDomElement ieblack = doc.createElement( "blacklist" );
      QDomAttr bname = doc.createAttribute( "name" );
      bname.setValue("333.txt");
      ieblack.setAttributeNode(bname);
      ie.appendChild(ieblack);
       plugin.appendChild(ie);
    QDomElement process = doc.createElement( "process_plugin" );

     QDomElement processfeature = doc.createElement( "feature" );
     QDomAttr pname = doc.createAttribute( "name" );
     pname.setValue("444.txt");
     processfeature.setAttributeNode(pname);
     process.appendChild(processfeature);

     QDomElement processblack = doc.createElement( "black" );
     QDomElement blacklist = doc.createElement( "blacklist" );
     QDomAttr bid = doc.createAttribute( "id" );
     bid.setValue("0");
     blacklist.setAttributeNode(bid);


     QDomElement btitle = doc.createElement( "title") ;
      QDomText   titletext = doc.createTextNode("mingdan1.txt");
      btitle.appendChild(titletext);
       blacklist.appendChild(btitle);

     QDomElement bnum = doc.createElement( "num") ;
     QDomText   numtext = doc.createTextNode("5");
     bnum.appendChild(numtext);
      blacklist.appendChild(bnum);

      QDomElement link = doc.createElement( "links") ;
       QDomElement blink1 = doc.createElement( "link") ;
        QDomText   linktext1 = doc.createTextNode("http://www.baidu.com");
        blink1.appendChild(linktext1);
        link.appendChild(blink1);
        QDomElement blink2 = doc.createElement( "link") ;
         QDomText   linktext2 = doc.createTextNode("http://www.sina.com");
         blink2.appendChild(linktext2);
         link.appendChild(blink2);
        blacklist.appendChild(link);
         processblack.appendChild(blacklist);
     QDomElement processwhite = doc.createElement( "white" );



      process.appendChild(processblack);
       process.appendChild(processwhite);
    plugin.appendChild(process);
    project.appendChild(plugin);
	root.appendChild(project);
    //QTextStream out_stream(&file);
    //doc.save(out_stream, 4); //缩进4格
    //QTextStream out(&file);
   // QString xml = doc.toString();
    //out << xml;
   // file.close();
    QTextStream out_stream(&file);
    doc.save(out_stream,4); //缩进4格
    file.close();


}

//读xml
void QXml::ReadXml(CONFIG_PLUGIN& cp)
{
    //QString filename=QString("%1%2").arg(cp.path).arg(CONFIG_FILENAME);
    //QFile file(filename);
    //if(!file.open(QFile::ReadOnly)) //可以用QIODevice，Truncate表示清空原来的内容
    // {
    //    LOG(ERROR)<<" open config or read config'"<<filename.toStdString().c_str()<<"' is failed.err:"<<file.errorString().toStdString().c_str()  ;
    //    return;
    //}


    //QDomDocument doc;
    //if(!doc.setContent(&file))
    //{
    //    file.close();
    //    return;
    //}
    //file.close();

    //QDomElement root=doc.documentElement(); //返回根节点
    //qDebug()<<root.nodeName();
    //QDomNode node=root.firstChild(); //获得第一个子节点
    //while(!node.isNull())  //如果节点不空
    //{
    //    if(node.isElement()) //如果节点是元素
    //    {
    //        QDomElement e=node.toElement(); //转换为元素，注意元素和节点是两个数据结构，其实差不多
    //        qDebug()<<e.tagName()<<" "<<e.attribute("id")<<" "<<e.attribute("time"); //打印键值对，tagName和nodeName是一个东西
    //        QDomNodeList list=e.childNodes();
    //        for(int i=0;i<list.count();i++) //遍历子元素，count和size都可以用,可用于标签数计数
    //        {
    //            QDomNode n=list.at(i);
    //            if(node.isElement())
    //                qDebug()<<n.nodeName()<<":"<<n.toElement().text();
    //        }
    //    }
    //    node=node.nextSibling(); //下一个兄弟节点,nextSiblingElement()是下一个兄弟元素，都差不多
    //}

}

//增加xml内容
void QXml::AddXml(CONFIG_PLUGIN& cp)
{
    //QString filename=QString("%1%2").arg(cp.path).arg(CONFIG_FILENAME);
    //QFile file(filename);
    //if(!file.open(QFile::ReadOnly)) //可以用QIODevice，Truncate表示清空原来的内容
    // {
    //    LOG(ERROR)<<" open config or read config'"<<filename.toStdString().c_str()<<"' is failed.err:"<<file.errorString().toStdString().c_str() ;
    //    return;
    //}

    ////增加一个一级子节点以及元素
    //QDomDocument doc;
    //if(!doc.setContent(&file))
    //{
    //    file.close();
    //    return;
    //}
    //file.close();

    //QDomElement root=doc.documentElement();
    //QDomElement book=doc.createElement("book");
    //book.setAttribute("id",3);
    //book.setAttribute("time","1813/1/27");
    //QDomElement title=doc.createElement("title");
    //QDomText text;
    //text=doc.createTextNode("Pride and Prejudice");
    //title.appendChild(text);
    //book.appendChild(title);
    //QDomElement author=doc.createElement("author");
    //text=doc.createTextNode("Jane Austen");
    //author.appendChild(text);
    //book.appendChild(author);
    //root.appendChild(book);

    //if(!file.open(QFile::WriteOnly|QFile::Truncate)) //先读进来，再重写，如果不用truncate就是在后面追加内容，就无效了
    //    return;
    ////输出到文件
    //QTextStream out_stream(&file);
    //doc.save(out_stream,4); //缩进4格
    //file.close();
}

//删减xml内容
void QXml:: RemoveXml(CONFIG_PLUGIN &cp)
{
    //QString filename=QString("%1%2").arg(cp.path).arg(CONFIG_FILENAME);
    //QFile file(filename);
    //if(!file.open(QFile::ReadOnly)) //可以用QIODevice，Truncate表示清空原来的内容
    // {
    //    LOG(ERROR)<<" open config or read config'"<<filename.toStdString().c_str()<<"' is failed.err:"<<file.errorString().toStdString().c_str()  ;
    //    return;
    //}

    ////删除一个一级子节点及其元素，外层节点删除内层节点于此相同
    //QDomDocument doc;
    //if(!doc.setContent(&file))
    //{
    //    file.close();
    //    return;
    //}
    //file.close();  //一定要记得关掉啊，不然无法完成操作

    //QDomElement root=doc.documentElement();
    //QDomNodeList list=doc.elementsByTagName("book"); //由标签名定位
    //for(int i=0;i<list.count();i++)
    //{
    //    QDomElement e=list.at(i).toElement();
    //    if(e.attribute("time")=="2007/5/25")  //以属性名定位，类似于hash的方式，warning：这里仅仅删除一个节点，其实可以加个break
    //        root.removeChild(list.at(i));
    //}

    //if(!file.open(QFile::WriteOnly|QFile::Truncate))
    //    return;
    ////输出到文件
    //QTextStream out_stream(&file);
    //doc.save(out_stream,4); //缩进4格
    //file.close();
}

//更新xml内容
void QXml::UpdateXml(CONFIG_PLUGIN &cp)
{
    //QString filename=QString("%1%2").arg(cp.path).arg(CONFIG_FILENAME);
    //QFile file(filename);
    //if(!file.open(QFile::ReadOnly)) //可以用QIODevice，Truncate表示清空原来的内容
    // {
    //    LOG(ERROR)<<" open config or read config'"<<filename.toStdString().c_str()<<"' is failed.err:"<<file.errorString().toStdString().c_str()   ;
    //    return;
    //}
    ////更新一个标签项,如果知道xml的结构，直接定位到那个标签上定点更新
    ////或者用遍历的方法去匹配tagname或者attribut，value来更新
    //QDomDocument doc;
    //if(!doc.setContent(&file))
    //{
    //    file.close();
    //    return;
    //}
    //file.close();

    //QDomElement root=doc.documentElement();
    //QDomNodeList list=root.elementsByTagName("book");
    //QDomNode node=list.at(list.size()-1).firstChild(); //定位到第三个一级子节点的子元素
    //QDomNode oldnode=node.firstChild(); //标签之间的内容作为节点的子节点出现,当前是Pride and Projudice
    //node.firstChild().setNodeValue("Emma");
    //QDomNode newnode=node.firstChild();
    //node.replaceChild(newnode,oldnode);

    //if(!file.open(QFile::WriteOnly|QFile::Truncate))
    //    return;
    ////输出到文件
    //QTextStream out_stream(&file);
    //doc.save(out_stream,4); //缩进4格
    //file.close();
}

