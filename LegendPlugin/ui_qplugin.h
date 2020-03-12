/********************************************************************************
** Form generated from reading UI file 'qplugin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPLUGIN_H
#define UI_QPLUGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QPlugin
{
public:

    void setupUi(QWidget *QPlugin)
    {
        if (QPlugin->objectName().isEmpty())
            QPlugin->setObjectName(QString::fromUtf8("QPlugin"));
        QPlugin->resize(400, 300);

        retranslateUi(QPlugin);

        QMetaObject::connectSlotsByName(QPlugin);
    } // setupUi

    void retranslateUi(QWidget *QPlugin)
    {
        QPlugin->setWindowTitle(QCoreApplication::translate("QPlugin", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QPlugin: public Ui_QPlugin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPLUGIN_H
