#include "qlog.h"
#include "ui_qlog.h"
#include"qaddplugin.h"
QLog::QLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QLog)
{
    ui->setupUi(this);
    connect(ui->btn_import, SIGNAL(clicked()), this, SLOT(slot_ImportLog()));
   QRect rect= this->geometry();
    rect.y()=rect.y()-100;
    ui->listWidget->setGeometry(&rect);

}

QLog::~QLog()
{
    delete ui;
}



//将文件数据导入表格
void QLog::slot_ImportLog()
{
    QString fileName = QFileDialog::getOpenFileName(0, tr("导入文件"),
                                                    tr("/root/Projects/product/bin/config"),
                                                    tr("file(*.log *.xls);;Allfile(*.*)"));
     ui->listWidget->clear();
    if(!fileName.isEmpty())
    {
        QFile file;
        file.setFileName(fileName);
        //打开文件
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox msg;
            msg.setText("打开文件失败!");
            msg.exec();
            return;
        }

        if(!file.size())
        {
            QMessageBox::warning(0,tr("警告"),tr("文件大小为空!"),QMessageBox::Ok);
            return ;
        }


        QTextStream in(&file);
        while (!in.atEnd())
        {

            QListWidgetItem*item=new QListWidgetItem;
            item->setText(in.readLine());
            ui->listWidget->addItem(item);
        }
        file.close();       //关闭文件

    }
    else
    {
        QMessageBox::warning(0,tr("警告"),tr("文件名未指定!"),QMessageBox::Ok);
        return ;
    }
}
