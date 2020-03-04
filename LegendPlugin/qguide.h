#ifndef QGUIDE_H
#define QGUIDE_H

#include <QWidget>
#include<QTableWidget>
#include<QPushButton>
#include<QGridLayout>
#include<QHBoxLayout>
#include<QStringList>
#include<QHeaderView>
#include<QSpinBox>
#include<QComboBox>
#include<QMessageBox>
#include<QDebug>
#include"qaddplugin.h"
#include "qeditplugin.h"
namespace Ui {
class QGuide;
}

class QGuide : public QWidget
{
    Q_OBJECT

public:
    explicit QGuide(QWidget *parent = 0);
    ~QGuide();
public slots:
    void slot_AddPlugin();
    void slot_doubleTableItemRC(QTableWidgetItem *item);
    void slot_SavePlugin();
    void slot_DelPlugin();
    private:
    Ui::QGuide *ui;
    QTableWidget *m_list;
    QPushButton *m_btnSave;
    QPushButton *m_btnDel;
    QPushButton *m_btnAdd;
    QStringList listHead;

private:
     void  InitFtpList();
};

#endif // QGUIDE_H
