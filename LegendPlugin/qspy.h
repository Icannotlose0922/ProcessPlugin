#ifndef QSPY_H
#define QSPY_H

#include <QWidget>

namespace Ui {
class QSpy;
}

class QSpy : public QWidget
{
    Q_OBJECT

public:
    explicit QSpy(QWidget *parent = 0);
    ~QSpy();

private:
    Ui::QSpy *ui;
};

#endif // QSPY_H
