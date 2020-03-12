/********************************************************************************
** Form generated from reading UI file 'qspy.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSPY_H
#define UI_QSPY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QSpy
{
public:

    void setupUi(QWidget *QSpy)
    {
        if (QSpy->objectName().isEmpty())
            QSpy->setObjectName(QString::fromUtf8("QSpy"));
        QSpy->resize(400, 300);

        retranslateUi(QSpy);

        QMetaObject::connectSlotsByName(QSpy);
    } // setupUi

    void retranslateUi(QWidget *QSpy)
    {
        QSpy->setWindowTitle(QCoreApplication::translate("QSpy", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QSpy: public Ui_QSpy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSPY_H
