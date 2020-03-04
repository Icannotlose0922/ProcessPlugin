#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"gloabl.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("主界面"));
    setMinimumSize(600, 480);
    createAction();
    createToolBar();
    content = new Content(this);
    setCentralWidget(content);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createAction()
{
    //转到第一个界面
    openStack[0] = new QAction(tr("基本信息"), this);
    openStack[0]->setShortcut(tr("Ctrl+Q"));
    openStack[0]->setStatusTip(tr("界面1"));
    connect(openStack[0], SIGNAL(triggered(bool)), this, SLOT(openBaseInfo()));
    //转到第二个界面
    openStack[1] = new QAction(tr("联系方式"), this);
    openStack[1]->setShortcut(tr("Ctrl+W"));
    openStack[1]->setStatusTip(tr("界面2"));
    connect(openStack[1], SIGNAL(triggered(bool)), this, SLOT(openContact()));
    //转到第三个界面
    openStack[2] = new QAction(tr("详细资料"), this);
    openStack[2]->setShortcut(tr("Ctrl+E"));
    openStack[2]->setStatusTip(tr("界面3"));
    connect(openStack[2], SIGNAL(triggered(bool)), this, SLOT(openDtail()));
}
//创建工具栏
void MainWindow::createToolBar()
{
    stackTool = addToolBar("工具栏");
    stackTool->addAction(openStack[0]);
    stackTool->addAction(openStack[1]);
    stackTool->addAction(openStack[2]);
}
//转到界面1槽函数
void MainWindow::openBaseInfo()
{
    this->content->stack->setCurrentIndex(0);
}
//转到界面2槽函数
void MainWindow::openContact()
{
    this->content->stack->setCurrentIndex(1);
}
//转到界面3槽函数
void MainWindow::openDtail()
{
    this->content->stack->setCurrentIndex(2);
}
