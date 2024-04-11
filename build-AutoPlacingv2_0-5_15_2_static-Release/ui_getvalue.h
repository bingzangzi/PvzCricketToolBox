/********************************************************************************
** Form generated from reading UI file 'getvalue.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETVALUE_H
#define UI_GETVALUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GetValue
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QLineEdit *lineEdit;

    void setupUi(QWidget *GetValue)
    {
        if (GetValue->objectName().isEmpty())
            GetValue->setObjectName(QString::fromUtf8("GetValue"));
        GetValue->resize(400, 300);
        verticalLayoutWidget = new QWidget(GetValue);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 141, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(GetValue);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 20, 100, 30));
        lineEdit = new QLineEdit(GetValue);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(190, 70, 121, 26));
        lineEdit->setReadOnly(true);

        retranslateUi(GetValue);

        QMetaObject::connectSlotsByName(GetValue);
    } // setupUi

    void retranslateUi(QWidget *GetValue)
    {
        GetValue->setWindowTitle(QCoreApplication::translate("GetValue", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("GetValue", "\347\241\256\350\256\244\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GetValue: public Ui_GetValue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETVALUE_H
