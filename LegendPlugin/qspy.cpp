#include "qspy.h"
#include "ui_qspy.h"

QSpy::QSpy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QSpy)
{
    ui->setupUi(this);
}

QSpy::~QSpy()
{
    delete ui;
}
