#ifndef CONTENT_H
#define CONTENT_H
#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QWidget>
#else
#include <QtGui/QWidget>
#endif
#include <QFrame>
#include <QStackedWidget>
#include <QGridLayout>
#include"qguide.h"
#include"qspy.h"
#include "qplugin.h"
#include "qlog.h"
class Content : public QFrame
{
    Q_OBJECT
public:
    explicit Content(QWidget *parent = nullptr);
    QStackedWidget *stack;
    QGuide *guide;
    QPlugin *plugin;
    QSpy *spy;
    QLog  *log;
signals:
public slots:
private:
    QGridLayout *mainLayout;
};
#endif // CONTENT_H
