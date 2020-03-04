#include "qeditplugin.h"
#include "ui_qeditplugin.h"
#include"gloabl.h"
QEditPlugin::QEditPlugin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QEditPlugin)
{
    ui->setupUi(this);
    LOG(INFO)<<__FILE__<<__FUNCTION__<<" QEditddPlugin form is init";
    InitPluginList();

}

void QEditPlugin::InitPluginList()
{
    LOG(INFO)<<__FILE__<<__FUNCTION__<<" QEditPlugin form is init";
    ui->m_table->setColumnCount(4); //设置列数
    ui-> m_table->setColumnWidth(0, 80);
    ui->m_table->setColumnWidth(1, 80);
    ui-> m_table->setColumnWidth(2, 80);
    ui->m_table->setColumnWidth(3, 80);
    QStringList listHead;
    listHead<<"文件名"<<"类型"<<"链接"<<"次数";
    ui->m_table->horizontalHeader()->setStretchLastSection(true);//设置充满表宽度

    ui-> m_table->setHorizontalHeaderLabels(listHead);
/*#if defined(SS_UBUNTU) //UBUNTU  //设置列内容自适应宽度
    ui->m_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui-> m_table->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
#else //ARM
    ui->m_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui-> m_table->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
#endif*/

    QFont font= ui->m_table->horizontalHeader()->font();  //每一列的标题字体设置为粗体
    font.setBold(true);
    ui->m_table->horizontalHeader()->setFont(font);
    ui-> m_table->setSelectionBehavior(QAbstractItemView::SelectRows); //设置选择模式，选择单行
    ui->m_table->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);//禁止鼠标拖动缩放行高度
    ui->m_table->setSelectionBehavior(QAbstractItemView::SelectColumns); //设置选择模式，选择单列
    ui-> m_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);//禁止鼠标拖动缩放行列宽

    int row=ui->m_table->rowCount();
    ui-> m_table->insertRow(row);
     QTableWidgetItem *check=new QTableWidgetItem("huolun.txt");
     check->setCheckState(Qt::Checked);
    ui-> m_table->setItem(row,0, check);
    ui-> m_table->setItem(row,3,new QTableWidgetItem("10"));
    QStringList combobox1_list;
    combobox1_list<<"白名单"<<"黑名单";
    QComboBox *combobox1=new QComboBox();
    combobox1->addItems(combobox1_list);
    ui->m_table->setCellWidget(row,1, combobox1);

    QStringList combobox1_ip;
    combobox1_ip<<"http://baidu.com"<<"http://360.com";
    QComboBox *comboboxip=new QComboBox();
    comboboxip->addItems(combobox1_ip);
    ui->m_table->setCellWidget(row,2, comboboxip);

}
QEditPlugin::~QEditPlugin()
{
    delete ui;
}
