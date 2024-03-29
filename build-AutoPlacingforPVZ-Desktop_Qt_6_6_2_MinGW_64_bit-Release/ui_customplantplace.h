/********************************************************************************
** Form generated from reading UI file 'customplantplace.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMPLANTPLACE_H
#define UI_CUSTOMPLANTPLACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customplantplace
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTextEdit *textedit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *infodisplayhere;
    QPushButton *updateplant;
    QPushButton *deleteplant;
    QPushButton *plantplace;
    QPushButton *clear;
    QPushButton *exitbutton;
    QLineEdit *forminfo;
    QCheckBox *realmoniter;
    QCheckBox *includeblood;
    QRadioButton *formtostr;
    QRadioButton *planttype;
    QRadioButton *customplace;
    QLineEdit *lineEdit;
    QRadioButton *strtoform;
    QRadioButton *blood;
    QRadioButton *setshine;
    QCheckBox *includeinterval;
    QCheckBox *isrealtime;
    QRadioButton *attackinterval;

    void setupUi(QWidget *customplantplace)
    {
        if (customplantplace->objectName().isEmpty())
            customplantplace->setObjectName("customplantplace");
        customplantplace->resize(1134, 462);
        scrollArea = new QScrollArea(customplantplace);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(240, 30, 821, 351));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 819, 349));
        gridLayoutWidget = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 1191, 351));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textedit = new QTextEdit(gridLayoutWidget);
        textedit->setObjectName("textedit");

        gridLayout->addWidget(textedit, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        layoutWidget = new QWidget(customplantplace);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(250, 400, 801, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        infodisplayhere = new QLabel(layoutWidget);
        infodisplayhere->setObjectName("infodisplayhere");

        horizontalLayout->addWidget(infodisplayhere);

        updateplant = new QPushButton(layoutWidget);
        updateplant->setObjectName("updateplant");

        horizontalLayout->addWidget(updateplant);

        deleteplant = new QPushButton(layoutWidget);
        deleteplant->setObjectName("deleteplant");

        horizontalLayout->addWidget(deleteplant);

        plantplace = new QPushButton(layoutWidget);
        plantplace->setObjectName("plantplace");

        horizontalLayout->addWidget(plantplace);

        clear = new QPushButton(layoutWidget);
        clear->setObjectName("clear");

        horizontalLayout->addWidget(clear);

        exitbutton = new QPushButton(layoutWidget);
        exitbutton->setObjectName("exitbutton");

        horizontalLayout->addWidget(exitbutton);

        forminfo = new QLineEdit(customplantplace);
        forminfo->setObjectName("forminfo");
        forminfo->setGeometry(QRect(240, 0, 821, 31));
        realmoniter = new QCheckBox(customplantplace);
        realmoniter->setObjectName("realmoniter");
        realmoniter->setGeometry(QRect(22, 17, 92, 24));
        includeblood = new QCheckBox(customplantplace);
        includeblood->setObjectName("includeblood");
        includeblood->setGeometry(QRect(22, 389, 124, 24));
        formtostr = new QRadioButton(customplantplace);
        formtostr->setObjectName("formtostr");
        formtostr->setGeometry(QRect(22, 204, 124, 24));
        planttype = new QRadioButton(customplantplace);
        planttype->setObjectName("planttype");
        planttype->setGeometry(QRect(22, 93, 92, 24));
        customplace = new QRadioButton(customplantplace);
        customplace->setObjectName("customplace");
        customplace->setGeometry(QRect(22, 278, 108, 24));
        lineEdit = new QLineEdit(customplantplace);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(22, 54, 139, 26));
        strtoform = new QRadioButton(customplantplace);
        strtoform->setObjectName("strtoform");
        strtoform->setGeometry(QRect(22, 241, 124, 24));
        blood = new QRadioButton(customplantplace);
        blood->setObjectName("blood");
        blood->setGeometry(QRect(22, 130, 92, 24));
        setshine = new QRadioButton(customplantplace);
        setshine->setObjectName("setshine");
        setshine->setGeometry(QRect(22, 315, 92, 24));
        includeinterval = new QCheckBox(customplantplace);
        includeinterval->setObjectName("includeinterval");
        includeinterval->setGeometry(QRect(22, 426, 124, 24));
        isrealtime = new QCheckBox(customplantplace);
        isrealtime->setObjectName("isrealtime");
        isrealtime->setGeometry(QRect(22, 352, 124, 24));
        attackinterval = new QRadioButton(customplantplace);
        attackinterval->setObjectName("attackinterval");
        attackinterval->setGeometry(QRect(22, 167, 124, 24));

        retranslateUi(customplantplace);

        QMetaObject::connectSlotsByName(customplantplace);
    } // setupUi

    void retranslateUi(QWidget *customplantplace)
    {
        customplantplace->setWindowTitle(QCoreApplication::translate("customplantplace", "Form", nullptr));
        infodisplayhere->setText(QString());
        updateplant->setText(QCoreApplication::translate("customplantplace", "\346\233\264\346\226\260\346\244\215\347\211\251\345\210\227\350\241\250", nullptr));
        deleteplant->setText(QCoreApplication::translate("customplantplace", "\345\210\240\351\231\244\351\200\211\344\270\255\347\232\204\346\244\215\347\211\251", nullptr));
        plantplace->setText(QCoreApplication::translate("customplantplace", "\347\241\256\350\256\244", nullptr));
        clear->setText(QCoreApplication::translate("customplantplace", "\346\270\205\347\251\272", nullptr));
        exitbutton->setText(QCoreApplication::translate("customplantplace", "\351\200\200\345\207\272", nullptr));
        forminfo->setText(QCoreApplication::translate("customplantplace", "\346\226\207\346\234\254\346\240\274\345\274\217\357\274\232\346\244\215\347\211\251\347\261\273\345\236\213\347\274\226\345\217\267 \350\241\214 \345\210\227 \350\241\200\351\207\217 \346\224\273\351\200\237\357\274\233\346\225\260\345\255\227\344\271\213\351\227\264\345\217\257\347\224\250\344\273\273\346\204\217\351\235\236\346\225\260\345\255\227\345\255\227\347\254\246\351\232\224\345\274\200\357\274\214\345\205\210\345\220\216\351\241\272\345\272\217\344\270\215\350\203\275\351\224\231\357\274\214\345\220\246\345\210\231\344\274\232\345\207\272\351\224\231\343\200\202", nullptr));
        realmoniter->setText(QCoreApplication::translate("customplantplace", "\345\256\236\346\227\266\347\233\221\346\216\247", nullptr));
        includeblood->setText(QCoreApplication::translate("customplantplace", "\345\214\205\345\220\253\350\241\200\351\207\217\344\277\241\346\201\257", nullptr));
        formtostr->setText(QCoreApplication::translate("customplantplace", "\351\230\265\345\236\213\350\275\254\345\255\227\347\254\246\344\270\262", nullptr));
        planttype->setText(QCoreApplication::translate("customplantplace", "\346\244\215\347\211\251\347\261\273\345\236\213", nullptr));
        customplace->setText(QCoreApplication::translate("customplantplace", "\350\207\252\345\256\232\344\271\211\347\247\215\346\244\215", nullptr));
        lineEdit->setText(QCoreApplication::translate("customplantplace", "\345\212\237\350\203\275\350\217\234\345\215\225", nullptr));
        strtoform->setText(QCoreApplication::translate("customplantplace", "\345\255\227\347\254\246\344\270\262\350\275\254\351\230\265\345\236\213", nullptr));
        blood->setText(QCoreApplication::translate("customplantplace", "\346\244\215\347\211\251\350\241\200\351\207\217", nullptr));
        setshine->setText(QCoreApplication::translate("customplantplace", "\350\256\276\347\275\256\345\217\221\345\205\211", nullptr));
        includeinterval->setText(QCoreApplication::translate("customplantplace", "\345\214\205\345\220\253\346\224\273\351\200\237\344\277\241\346\201\257", nullptr));
        isrealtime->setText(QCoreApplication::translate("customplantplace", "\345\256\236\346\227\266\350\241\200\351\207\217\346\233\264\346\226\260", nullptr));
        attackinterval->setText(QCoreApplication::translate("customplantplace", "\346\244\215\347\211\251\346\224\273\345\207\273\351\227\264\351\232\224", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customplantplace: public Ui_customplantplace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMPLANTPLACE_H
