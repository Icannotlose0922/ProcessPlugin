/********************************************************************************
** Form generated from reading UI file 'qeditplugin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QEDITPLUGIN_H
#define UI_QEDITPLUGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QEditPlugin
{
public:
    QGroupBox *groupbox_list;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *lab_name;
    QLineEdit *txt_name;
    QLabel *lab_config_path;
    QLineEdit *txt_config_path;
    QPushButton *btn_browse;
    QLabel *lab_ftp;
    QLineEdit *txt_ftp;
    QLabel *lab_username;
    QLineEdit *txt_username;
    QLabel *lab_password;
    QLineEdit *txt_password;
    QLabel *lab_relative_path;
    QLineEdit *txt_relative_path;
    QLabel *lab_address;
    QLineEdit *txt_address;
    QCheckBox *check_ie_synchronize;
    QCheckBox *checkbox_temp_file;
    QCheckBox *checkBox_3;
    QCheckBox *checkbox_illegal_pages;
    QLabel *lab_waining_link;
    QLineEdit *txt_waining_link;
    QLabel *lab_intercept_count;
    QLineEdit *txt_intercept_count;
    QGroupBox *groupBox_2;
    QTableWidget *m_table;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_save;
    QFrame *line;
    QPushButton *btn_add;
    QFrame *line_2;
    QPushButton *btn_del;

    void setupUi(QWidget *QEditPlugin)
    {
        if (QEditPlugin->objectName().isEmpty())
            QEditPlugin->setObjectName(QString::fromUtf8("QEditPlugin"));
        QEditPlugin->resize(727, 315);
        groupbox_list = new QGroupBox(QEditPlugin);
        groupbox_list->setObjectName(QString::fromUtf8("groupbox_list"));
        groupbox_list->setGeometry(QRect(10, 0, 361, 281));
        widget = new QWidget(groupbox_list);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 30, 282, 277));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lab_name = new QLabel(widget);
        lab_name->setObjectName(QString::fromUtf8("lab_name"));

        gridLayout->addWidget(lab_name, 0, 0, 1, 1);

        txt_name = new QLineEdit(widget);
        txt_name->setObjectName(QString::fromUtf8("txt_name"));

        gridLayout->addWidget(txt_name, 0, 1, 1, 3);

        lab_config_path = new QLabel(widget);
        lab_config_path->setObjectName(QString::fromUtf8("lab_config_path"));

        gridLayout->addWidget(lab_config_path, 1, 0, 1, 1);

        txt_config_path = new QLineEdit(widget);
        txt_config_path->setObjectName(QString::fromUtf8("txt_config_path"));

        gridLayout->addWidget(txt_config_path, 1, 1, 1, 2);

        btn_browse = new QPushButton(widget);
        btn_browse->setObjectName(QString::fromUtf8("btn_browse"));

        gridLayout->addWidget(btn_browse, 1, 3, 1, 1);

        lab_ftp = new QLabel(widget);
        lab_ftp->setObjectName(QString::fromUtf8("lab_ftp"));

        gridLayout->addWidget(lab_ftp, 2, 0, 1, 1);

        txt_ftp = new QLineEdit(widget);
        txt_ftp->setObjectName(QString::fromUtf8("txt_ftp"));

        gridLayout->addWidget(txt_ftp, 2, 1, 1, 3);

        lab_username = new QLabel(widget);
        lab_username->setObjectName(QString::fromUtf8("lab_username"));

        gridLayout->addWidget(lab_username, 3, 0, 1, 1);

        txt_username = new QLineEdit(widget);
        txt_username->setObjectName(QString::fromUtf8("txt_username"));

        gridLayout->addWidget(txt_username, 3, 1, 1, 3);

        lab_password = new QLabel(widget);
        lab_password->setObjectName(QString::fromUtf8("lab_password"));

        gridLayout->addWidget(lab_password, 4, 0, 1, 1);

        txt_password = new QLineEdit(widget);
        txt_password->setObjectName(QString::fromUtf8("txt_password"));

        gridLayout->addWidget(txt_password, 4, 1, 1, 3);

        lab_relative_path = new QLabel(widget);
        lab_relative_path->setObjectName(QString::fromUtf8("lab_relative_path"));

        gridLayout->addWidget(lab_relative_path, 5, 0, 1, 1);

        txt_relative_path = new QLineEdit(widget);
        txt_relative_path->setObjectName(QString::fromUtf8("txt_relative_path"));

        gridLayout->addWidget(txt_relative_path, 5, 1, 1, 3);

        lab_address = new QLabel(widget);
        lab_address->setObjectName(QString::fromUtf8("lab_address"));

        gridLayout->addWidget(lab_address, 6, 0, 1, 1);

        txt_address = new QLineEdit(widget);
        txt_address->setObjectName(QString::fromUtf8("txt_address"));

        gridLayout->addWidget(txt_address, 6, 1, 1, 3);

        check_ie_synchronize = new QCheckBox(widget);
        check_ie_synchronize->setObjectName(QString::fromUtf8("check_ie_synchronize"));

        gridLayout->addWidget(check_ie_synchronize, 7, 0, 1, 2);

        checkbox_temp_file = new QCheckBox(widget);
        checkbox_temp_file->setObjectName(QString::fromUtf8("checkbox_temp_file"));

        gridLayout->addWidget(checkbox_temp_file, 7, 2, 1, 2);

        checkBox_3 = new QCheckBox(widget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout->addWidget(checkBox_3, 8, 0, 1, 2);

        checkbox_illegal_pages = new QCheckBox(widget);
        checkbox_illegal_pages->setObjectName(QString::fromUtf8("checkbox_illegal_pages"));

        gridLayout->addWidget(checkbox_illegal_pages, 8, 2, 1, 2);

        lab_waining_link = new QLabel(widget);
        lab_waining_link->setObjectName(QString::fromUtf8("lab_waining_link"));

        gridLayout->addWidget(lab_waining_link, 9, 0, 1, 1);

        txt_waining_link = new QLineEdit(widget);
        txt_waining_link->setObjectName(QString::fromUtf8("txt_waining_link"));

        gridLayout->addWidget(txt_waining_link, 9, 1, 1, 3);

        lab_intercept_count = new QLabel(widget);
        lab_intercept_count->setObjectName(QString::fromUtf8("lab_intercept_count"));

        gridLayout->addWidget(lab_intercept_count, 10, 0, 1, 1);

        txt_intercept_count = new QLineEdit(widget);
        txt_intercept_count->setObjectName(QString::fromUtf8("txt_intercept_count"));

        gridLayout->addWidget(txt_intercept_count, 10, 1, 1, 3);

        groupBox_2 = new QGroupBox(QEditPlugin);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(370, 0, 361, 281));
        m_table = new QTableWidget(groupBox_2);
        m_table->setObjectName(QString::fromUtf8("m_table"));
        m_table->setGeometry(QRect(0, 10, 361, 271));
        widget1 = new QWidget(QEditPlugin);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(190, 290, 251, 25));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_save = new QPushButton(widget1);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout->addWidget(btn_save);

        line = new QFrame(widget1);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        btn_add = new QPushButton(widget1);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        horizontalLayout->addWidget(btn_add);

        line_2 = new QFrame(widget1);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        btn_del = new QPushButton(widget1);
        btn_del->setObjectName(QString::fromUtf8("btn_del"));

        horizontalLayout->addWidget(btn_del);


        retranslateUi(QEditPlugin);

        QMetaObject::connectSlotsByName(QEditPlugin);
    } // setupUi

    void retranslateUi(QWidget *QEditPlugin)
    {
        QEditPlugin->setWindowTitle(QCoreApplication::translate("QEditPlugin", "Form", nullptr));
        groupbox_list->setTitle(QCoreApplication::translate("QEditPlugin", "\345\217\202\346\225\260", nullptr));
        lab_name->setText(QCoreApplication::translate("QEditPlugin", "\351\241\271\347\233\256\345\220\215\347\247\260\357\274\232", nullptr));
        lab_config_path->setText(QCoreApplication::translate("QEditPlugin", "\351\205\215\347\275\256\350\267\257\345\276\204\357\274\232", nullptr));
        btn_browse->setText(QCoreApplication::translate("QEditPlugin", "\346\265\217\350\247\210", nullptr));
        lab_ftp->setText(QCoreApplication::translate("QEditPlugin", "FTP\345\234\260\345\235\200\357\274\232", nullptr));
        lab_username->setText(QCoreApplication::translate("QEditPlugin", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        lab_password->setText(QCoreApplication::translate("QEditPlugin", "\345\257\206\347\240\201\357\274\232", nullptr));
        lab_relative_path->setText(QCoreApplication::translate("QEditPlugin", "\347\233\270\345\257\271\350\267\257\345\276\204", nullptr));
        lab_address->setText(QCoreApplication::translate("QEditPlugin", "\350\256\277\351\227\256\345\234\260\345\235\200\357\274\232", nullptr));
        check_ie_synchronize->setText(QCoreApplication::translate("QEditPlugin", "\345\274\200\345\220\257\347\275\221\347\253\231\345\220\214\346\255\245", nullptr));
        checkbox_temp_file->setText(QCoreApplication::translate("QEditPlugin", "\347\224\237\346\210\220\344\270\264\346\227\266\346\226\207\344\273\266", nullptr));
        checkBox_3->setText(QCoreApplication::translate("QEditPlugin", "\351\235\236\346\263\225\350\277\233\347\250\213\350\255\246\345\221\212", nullptr));
        checkbox_illegal_pages->setText(QCoreApplication::translate("QEditPlugin", "\345\205\263\351\227\255\351\235\236\346\263\225\347\275\221\351\241\265", nullptr));
        lab_waining_link->setText(QCoreApplication::translate("QEditPlugin", "\350\255\246\345\221\212\351\223\276\346\216\245", nullptr));
        lab_intercept_count->setText(QCoreApplication::translate("QEditPlugin", "\346\213\246\346\210\252\346\254\241\346\225\260", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("QEditPlugin", "\345\210\227\350\241\250", nullptr));
        btn_save->setText(QCoreApplication::translate("QEditPlugin", "\344\277\235\345\255\230", nullptr));
        btn_add->setText(QCoreApplication::translate("QEditPlugin", "\346\267\273\345\212\240", nullptr));
        btn_del->setText(QCoreApplication::translate("QEditPlugin", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QEditPlugin: public Ui_QEditPlugin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QEDITPLUGIN_H
