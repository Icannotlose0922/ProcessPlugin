/********************************************************************************
** Form generated from reading UI file 'qaddplugin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QADDPLUGIN_H
#define UI_QADDPLUGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QAddPlugin
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *btn_browse;
    QLabel *lab_username;
    QPushButton *btn_cancel;
    QLabel *lab_conf_path;
    QLineEdit *txt_config_path;
    QLineEdit *txt_password;
    QLabel *lab_password;
    QLineEdit *txt_ftp;
    QLineEdit *txt_username;
    QLineEdit *txt_name;
    QLabel *lab_name;
    QPushButton *btn_download;
    QCheckBox *checkBox;
    QLabel *lab_ftp;
    QProgressBar *progressBar;
    QListWidget *list_log;

    void setupUi(QWidget *QAddPlugin)
    {
        if (QAddPlugin->objectName().isEmpty())
            QAddPlugin->setObjectName(QString::fromUtf8("QAddPlugin"));
        QAddPlugin->resize(565, 224);
        layoutWidget = new QWidget(QAddPlugin);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 540, 208));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn_browse = new QPushButton(layoutWidget);
        btn_browse->setObjectName(QString::fromUtf8("btn_browse"));

        gridLayout->addWidget(btn_browse, 1, 3, 1, 1);

        lab_username = new QLabel(layoutWidget);
        lab_username->setObjectName(QString::fromUtf8("lab_username"));

        gridLayout->addWidget(lab_username, 3, 0, 1, 1);

        btn_cancel = new QPushButton(layoutWidget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        gridLayout->addWidget(btn_cancel, 7, 0, 1, 2);

        lab_conf_path = new QLabel(layoutWidget);
        lab_conf_path->setObjectName(QString::fromUtf8("lab_conf_path"));

        gridLayout->addWidget(lab_conf_path, 1, 0, 1, 1);

        txt_config_path = new QLineEdit(layoutWidget);
        txt_config_path->setObjectName(QString::fromUtf8("txt_config_path"));

        gridLayout->addWidget(txt_config_path, 1, 1, 1, 2);

        txt_password = new QLineEdit(layoutWidget);
        txt_password->setObjectName(QString::fromUtf8("txt_password"));

        gridLayout->addWidget(txt_password, 4, 1, 1, 3);

        lab_password = new QLabel(layoutWidget);
        lab_password->setObjectName(QString::fromUtf8("lab_password"));

        gridLayout->addWidget(lab_password, 4, 0, 1, 1);

        txt_ftp = new QLineEdit(layoutWidget);
        txt_ftp->setObjectName(QString::fromUtf8("txt_ftp"));

        gridLayout->addWidget(txt_ftp, 2, 1, 1, 3);

        txt_username = new QLineEdit(layoutWidget);
        txt_username->setObjectName(QString::fromUtf8("txt_username"));

        gridLayout->addWidget(txt_username, 3, 1, 1, 3);

        txt_name = new QLineEdit(layoutWidget);
        txt_name->setObjectName(QString::fromUtf8("txt_name"));

        gridLayout->addWidget(txt_name, 0, 1, 1, 3);

        lab_name = new QLabel(layoutWidget);
        lab_name->setObjectName(QString::fromUtf8("lab_name"));

        gridLayout->addWidget(lab_name, 0, 0, 1, 1);

        btn_download = new QPushButton(layoutWidget);
        btn_download->setObjectName(QString::fromUtf8("btn_download"));

        gridLayout->addWidget(btn_download, 7, 2, 1, 2);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout->addWidget(checkBox, 5, 1, 1, 2);

        lab_ftp = new QLabel(layoutWidget);
        lab_ftp->setObjectName(QString::fromUtf8("lab_ftp"));

        gridLayout->addWidget(lab_ftp, 2, 0, 1, 1);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 6, 0, 1, 4);


        horizontalLayout->addLayout(gridLayout);

        list_log = new QListWidget(layoutWidget);
        list_log->setObjectName(QString::fromUtf8("list_log"));

        horizontalLayout->addWidget(list_log);


        retranslateUi(QAddPlugin);

        QMetaObject::connectSlotsByName(QAddPlugin);
    } // setupUi

    void retranslateUi(QWidget *QAddPlugin)
    {
        QAddPlugin->setWindowTitle(QCoreApplication::translate("QAddPlugin", "\346\267\273\345\212\240\351\241\271\347\233\256", nullptr));
        btn_browse->setText(QCoreApplication::translate("QAddPlugin", "\346\265\217\350\247\210", nullptr));
        lab_username->setText(QCoreApplication::translate("QAddPlugin", "\347\224\250\346\210\267\345\220\215:", nullptr));
        btn_cancel->setText(QCoreApplication::translate("QAddPlugin", "\345\217\226\346\266\210", nullptr));
        lab_conf_path->setText(QCoreApplication::translate("QAddPlugin", "\351\205\215\347\275\256\350\267\257\345\276\204:", nullptr));
        txt_config_path->setText(QCoreApplication::translate("QAddPlugin", "E:\\", nullptr));
        txt_password->setText(QCoreApplication::translate("QAddPlugin", "123456", nullptr));
        lab_password->setText(QCoreApplication::translate("QAddPlugin", "\345\257\206\347\240\201:", nullptr));
        txt_ftp->setText(QCoreApplication::translate("QAddPlugin", "219.146.3.7", nullptr));
        txt_username->setText(QCoreApplication::translate("QAddPlugin", "hx", nullptr));
        txt_name->setText(QCoreApplication::translate("QAddPlugin", "\346\202\211\345\260\274\345\260\206", nullptr));
        lab_name->setText(QCoreApplication::translate("QAddPlugin", "\351\241\271\347\233\256\345\220\215\347\247\260:", nullptr));
        btn_download->setText(QCoreApplication::translate("QAddPlugin", "\346\267\273\345\212\240\351\241\271\347\233\256", nullptr));
        checkBox->setText(QCoreApplication::translate("QAddPlugin", "\346\230\257\345\220\246\345\274\200\345\220\257\347\275\221\347\273\234\345\220\214\346\255\245", nullptr));
        lab_ftp->setText(QCoreApplication::translate("QAddPlugin", "ftp\345\234\260\345\235\200:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QAddPlugin: public Ui_QAddPlugin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QADDPLUGIN_H
