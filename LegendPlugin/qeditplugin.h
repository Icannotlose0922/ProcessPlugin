#ifndef QEDITPLUGIN_H
#define QEDITPLUGIN_H

#include <QWidget>
#include<QPushButton>
#include<QGridLayout>
#include<QHBoxLayout>
#include<QLabel>
#include<QLineEdit>
#include<QCheckBox>
#include<QTableWidget>
#include<QComboBox>
#include<QGroupBox>
namespace Ui {
class QEditPlugin;
}

class QEditPlugin : public QWidget
{
    Q_OBJECT

public:
    explicit QEditPlugin(QWidget *parent = 0);
    ~QEditPlugin();
private:
  void  InitPluginList();
private:
    Ui::QEditPlugin *ui;

};

#endif // QEDITPLUGIN_H
