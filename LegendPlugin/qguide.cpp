#include "qguide.h"
#include "ui_qguide.h"
#include"gloabl.h"
QGuide::QGuide(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QGuide)
{
    ui->setupUi(this);
    QGridLayout *mainlayout=new QGridLayout(this);

    m_list=new QTableWidget(this);
    m_btnSave=new QPushButton(tr("同步数据"));
    m_btnAdd=new QPushButton(tr("添加数据"));
    m_btnDel=new QPushButton(tr("删除数据"));
    mainlayout->addWidget(m_list,0,0);
    QHBoxLayout *btnLayout=new QHBoxLayout(this);
    btnLayout->addWidget(m_btnSave);
    btnLayout->addWidget(m_btnDel);
    btnLayout->addWidget(m_btnAdd);
    mainlayout->addLayout(btnLayout,1,0);
    InitFtpList();
    connect(m_btnAdd,SIGNAL(clicked()),this,SLOT(slot_AddPlugin()));
    connect(m_btnSave,SIGNAL(clicked()),this,SLOT(slot_SavePlugin()));
    connect(m_btnDel,SIGNAL(clicked()),this,SLOT(slot_EditPlugin()));
    connect(m_list,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(slot_doubleTableItemRC(QTableWidgetItem*)));

}

void QGuide::InitFtpList()
{
    m_list->setColumnCount(6); //设置列数
    m_list->setColumnWidth(0, 80);
    m_list->setColumnWidth(1, 80);
    m_list->setColumnWidth(2, 80);
    m_list->setColumnWidth(3, 80);
    m_list->setColumnWidth(4, 80);
    m_list->setColumnWidth(5, 80);
    listHead<<"项目名称"<<"进程特征"<<"进程白名单"<<"进程黑名单"<<"域名白名单"<<"域名黑名单";
    m_list->horizontalHeader()->setStretchLastSection(true);//设置充满表宽度

    m_list->setHorizontalHeaderLabels(listHead);
#if defined(SS_UBUNTU) //UBUNTU  //设置列内容自适应宽度
    m_list->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    m_list->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
#else //ARM
    m_list->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    m_list->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
#endif

    QFont font= m_list->horizontalHeader()->font();  //每一列的标题字体设置为粗体
    font.setBold(true);
    m_list->horizontalHeader()->setFont(font);
    m_list->setSelectionBehavior(QAbstractItemView::SelectItems); //设置选择模式，选择单行
    m_list->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);//禁止鼠标拖动缩放行高度
    m_list->verticalHeader()->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // m_list->setSelectionBehavior(QAbstractItemView::SelectColumns); //设置选择模式，选择单列
    // m_list->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);//禁止鼠标拖动缩放行列宽

    int row=m_list->rowCount();
    m_list->insertRow(row);
    m_list->setItem(row,0,new QTableWidgetItem("新建项目"));
    m_list->setItem(row,1,new QTableWidgetItem("ProClass.txt"));
    m_list->setItem(row,2,new QTableWidgetItem("Program.txt"));
    m_list->setItem(row,3,new QTableWidgetItem("IEClass.txt"));
    m_list->setItem(row,4,new QTableWidgetItem("DoMain.txt"));

    QStringList combobox1_list;
    combobox1_list<<"heimingdan1"<<"heimingdan2"<<"heimingdan3"<<"heimingdan4"<<"heimingdan5";
    QComboBox *combobox1=new QComboBox();
    combobox1->addItems(combobox1_list);
    m_list->setCellWidget(row,5, combobox1);

    row++;
    m_list->insertRow(row);
    m_list->setItem(row,0,new QTableWidgetItem("新建项目1"));
    m_list->setItem(row,1,new QTableWidgetItem("ProClass.txt"));
    m_list->setItem(row,2,new QTableWidgetItem("Program.txt"));
    m_list->setItem(row,3,new QTableWidgetItem("IEClass.txt"));
    m_list->setItem(row,4,new QTableWidgetItem("DoMain.txt"));
    QStringList combobox1_list2;
    combobox1_list2<<"bi1.txt"<<"bi2.txt"<<"bi3.txt"<<"bi4.txt"<<"bi5.txt";
    QComboBox *combobox2=new QComboBox();
    combobox2->addItems(combobox1_list2);
    m_list->setCellWidget(row,5, combobox2);
}

void QGuide::slot_AddPlugin()
{
    LOG(INFO)<<__FILE__<<__FUNCTION__<<" click is'"<<m_btnAdd->text().toStdString().c_str()<<"' button";
    QAddPlugin *addPlugin=new QAddPlugin();
    addPlugin->show();
}

void QGuide::slot_doubleTableItemRC(QTableWidgetItem *item)
{
    int row=item->row();
    int column=item->column();
    LOG(INFO)<<__FILE__<<__FUNCTION__<<" this is select row:"<<row<<" columnu:"<<column<<" cells";
    switch(column)
    {
    case 0:
    {
        QEditPlugin *editPlugin=new QEditPlugin();
        editPlugin->show();
    }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        break;
    case 5:
        break;
        break;

    }
}

void QGuide::slot_SavePlugin()
{
    LOG(INFO)<<__FILE__<<__FUNCTION__<<" click is'"<<m_btnSave->text().toStdString().c_str()<<"' button";

}

void QGuide::slot_DelPlugin()
{
    LOG(INFO)<<__FILE__<<__FUNCTION__<<" click is'"<<m_btnDel->text().toStdString().c_str()<<"' button";

}

QGuide::~QGuide()
{
    delete ui;
}
