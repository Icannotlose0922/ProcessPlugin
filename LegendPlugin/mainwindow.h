#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QListWidget>
#include<QStackedWidget>
#include <QVBoxLayout>
#include <QLabel>
#include<QAction>
#include"content.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    QAction *openStack[4];
private:
    Ui::MainWindow *ui;
    Content *content;
    QGridLayout *mainLayout;
    void createAction();
    void createToolBar();
private:
    QToolBar *stackTool;                                //工具栏
   
private slots:
    void openBaseInfo();                                //点击状态栏的槽函数
    void openContact();
    void openDtail();
    void openLog();
};

#endif // MAINWINDOW_H
