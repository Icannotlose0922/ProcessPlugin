//#ifndef QPLUGIN_H
//#define QPLUGIN_H

#include <QWidget>
#include<QListWidget>
#include<QPushButton>
#include<QGridLayout>
#include<QHBoxLayout>
namespace Ui {
class QPlugin;
}












class QPlugin : public QWidget
{
    Q_OBJECT

public:
    explicit QPlugin(QWidget *parent = 0);
    ~QPlugin();

private:
    Ui::QPlugin *ui;

};

//#endif // QPLUGIN_H
