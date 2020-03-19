#ifndef QLOG_H
#define QLOG_H

#include <QWidget>

namespace Ui {
class QLog;
}

class QLog : public QWidget
{
    Q_OBJECT
public:

public:
    explicit QLog(QWidget *parent = 0);
    ~QLog();
void importTable();
private:
    Ui::QLog *ui;
 private slots:
   void slot_ImportLog();
};
 #endif // QLOG_H
