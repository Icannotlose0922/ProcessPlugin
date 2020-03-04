#include "qplugin.h"
#include "ui_qplugin.h"

QPlugin::QPlugin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QPlugin)
{
    ui->setupUi(this);
}

QPlugin::~QPlugin()
{
    delete ui;
}
