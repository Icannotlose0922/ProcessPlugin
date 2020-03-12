/********************************************************************************
** Form generated from reading UI file 'qguide.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGUIDE_H
#define UI_QGUIDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGuide
{
public:

    void setupUi(QWidget *QGuide)
    {
        if (QGuide->objectName().isEmpty())
            QGuide->setObjectName(QString::fromUtf8("QGuide"));
        QGuide->resize(400, 300);

        retranslateUi(QGuide);

        QMetaObject::connectSlotsByName(QGuide);
    } // setupUi

    void retranslateUi(QWidget *QGuide)
    {
        QGuide->setWindowTitle(QCoreApplication::translate("QGuide", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QGuide: public Ui_QGuide {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGUIDE_H
