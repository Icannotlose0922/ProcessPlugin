#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QListWidget>
#include<QStackedWidget>
#include <QVBoxLayout>
#include <QLabel>
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

private:
    Ui::MainWindow *ui;
    Content *content;
    QGridLayout *mainLayout;
    void createAction();
    void createToolBar();
private:
    QToolBar *stackTool;                                //工具栏
    QAction *openStack[3];
private slots:
    void openBaseInfo();                                //点击状态栏的槽函数
    void openContact();
    void openDtail();
};

#endif // MAINWINDOW_H
