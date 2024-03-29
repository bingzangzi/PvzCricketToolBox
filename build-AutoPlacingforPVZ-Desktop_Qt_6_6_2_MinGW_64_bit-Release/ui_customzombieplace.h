/********************************************************************************
** Form generated from reading UI file 'customzombieplace.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMZOMBIEPLACE_H
#define UI_CUSTOMZOMBIEPLACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customzombieplace
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextEdit *textEdit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *zombiechoose;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *row;
    QLabel *label_3;
    QSpinBox *col;
    QLabel *label_7;
    QPushButton *reset;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *bodyblood;
    QLabel *label_5;
    QLineEdit *armor_1;
    QLabel *label_6;
    QLineEdit *armor_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *batchcheck;
    QSpinBox *batchnum;
    QPushButton *singleplace;
    QPushButton *rowplace;
    QPushButton *colplace;
    QWidget *tab_2;
    QListWidget *zombielist;
    QCheckBox *realtime;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QLabel *label_21;
    QLabel *label_13;
    QLineEdit *zombiearmor2;
    QLineEdit *xcor;
    QSlider *freezetime;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_15;
    QLabel *label_17;
    QLineEdit *rowbelong;
    QLabel *label_16;
    QLineEdit *zombietype;
    QLabel *label_20;
    QLabel *label_14;
    QLineEdit *zombiearmor2blood;
    QLineEdit *zombiebody;
    QLabel *label_18;
    QSlider *shiningtime;
    QLineEdit *zombiename;
    QLineEdit *zombiearmor1blood;
    QLabel *label_8;
    QSlider *slowdown;
    QLineEdit *ycor;
    QLabel *label_10;
    QLineEdit *zombiearmor1;
    QLabel *label_19;
    QLabel *label_12;
    QSlider *buttertime;
    QCheckBox *ischarm;
    QCheckBox *isdead;
    QPushButton *pushButton;
    QWidget *tab_3;
    QTextEdit *totalprint;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *ignoreblindbox;
    QCheckBox *rowdetails;
    QPushButton *startcount;
    QPushButton *stopcount;
    QPushButton *tofile;
    QPushButton *exitbutton;

    void setupUi(QWidget *customzombieplace)
    {
        if (customzombieplace->objectName().isEmpty())
            customzombieplace->setObjectName("customzombieplace");
        customzombieplace->resize(706, 445);
        tabWidget = new QTabWidget(customzombieplace);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 711, 411));
        tab = new QWidget();
        tab->setObjectName("tab");
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(40, 190, 621, 171));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 20, 621, 101));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        zombiechoose = new QComboBox(layoutWidget);
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->addItem(QString());
        zombiechoose->setObjectName("zombiechoose");
        zombiechoose->setEnabled(true);
        zombiechoose->setMinimumSize(QSize(89, 26));
        zombiechoose->setFrame(true);

        horizontalLayout->addWidget(zombiechoose);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        row = new QSpinBox(layoutWidget);
        row->setObjectName("row");
        row->setMinimum(1);
        row->setMaximum(12);

        horizontalLayout_2->addWidget(row);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        col = new QSpinBox(layoutWidget);
        col->setObjectName("col");
        col->setMinimum(1);
        col->setMaximum(12);

        horizontalLayout_2->addWidget(col);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        horizontalLayout_4->addWidget(label_7);

        reset = new QPushButton(layoutWidget);
        reset->setObjectName("reset");

        horizontalLayout_4->addWidget(reset);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_5->addWidget(label_4);

        bodyblood = new QLineEdit(layoutWidget);
        bodyblood->setObjectName("bodyblood");

        horizontalLayout_5->addWidget(bodyblood);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        armor_1 = new QLineEdit(layoutWidget);
        armor_1->setObjectName("armor_1");

        horizontalLayout_5->addWidget(armor_1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        horizontalLayout_5->addWidget(label_6);

        armor_2 = new QLineEdit(layoutWidget);
        armor_2->setObjectName("armor_2");

        horizontalLayout_5->addWidget(armor_2);


        verticalLayout->addLayout(horizontalLayout_5);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(40, 130, 621, 51));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        batchcheck = new QCheckBox(layoutWidget1);
        batchcheck->setObjectName("batchcheck");

        horizontalLayout_3->addWidget(batchcheck);

        batchnum = new QSpinBox(layoutWidget1);
        batchnum->setObjectName("batchnum");
        batchnum->setMinimum(1);
        batchnum->setMaximum(100);

        horizontalLayout_3->addWidget(batchnum);

        singleplace = new QPushButton(layoutWidget1);
        singleplace->setObjectName("singleplace");

        horizontalLayout_3->addWidget(singleplace);

        rowplace = new QPushButton(layoutWidget1);
        rowplace->setObjectName("rowplace");

        horizontalLayout_3->addWidget(rowplace);

        colplace = new QPushButton(layoutWidget1);
        colplace->setObjectName("colplace");

        horizontalLayout_3->addWidget(colplace);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        zombielist = new QListWidget(tab_2);
        zombielist->setObjectName("zombielist");
        zombielist->setGeometry(QRect(20, 30, 221, 321));
        realtime = new QCheckBox(tab_2);
        realtime->setObjectName("realtime");
        realtime->setGeometry(QRect(20, 0, 221, 31));
        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(250, 30, 421, 326));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_21 = new QLabel(layoutWidget2);
        label_21->setObjectName("label_21");

        gridLayout->addWidget(label_21, 1, 3, 1, 1);

        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName("label_13");

        gridLayout->addWidget(label_13, 3, 0, 1, 1);

        zombiearmor2 = new QLineEdit(layoutWidget2);
        zombiearmor2->setObjectName("zombiearmor2");

        gridLayout->addWidget(zombiearmor2, 3, 1, 1, 2);

        xcor = new QLineEdit(layoutWidget2);
        xcor->setObjectName("xcor");

        gridLayout->addWidget(xcor, 4, 1, 1, 2);

        freezetime = new QSlider(layoutWidget2);
        freezetime->setObjectName("freezetime");
        freezetime->setMaximum(2000);
        freezetime->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(freezetime, 7, 2, 1, 1);

        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 0, 3, 1, 1);

        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName("label_11");

        gridLayout->addWidget(label_11, 2, 0, 1, 1);

        label_15 = new QLabel(layoutWidget2);
        label_15->setObjectName("label_15");

        gridLayout->addWidget(label_15, 4, 0, 1, 1);

        label_17 = new QLabel(layoutWidget2);
        label_17->setObjectName("label_17");

        gridLayout->addWidget(label_17, 5, 0, 1, 2);

        rowbelong = new QLineEdit(layoutWidget2);
        rowbelong->setObjectName("rowbelong");

        gridLayout->addWidget(rowbelong, 1, 4, 1, 1);

        label_16 = new QLabel(layoutWidget2);
        label_16->setObjectName("label_16");

        gridLayout->addWidget(label_16, 4, 3, 1, 1);

        zombietype = new QLineEdit(layoutWidget2);
        zombietype->setObjectName("zombietype");

        gridLayout->addWidget(zombietype, 0, 4, 1, 1);

        label_20 = new QLabel(layoutWidget2);
        label_20->setObjectName("label_20");

        gridLayout->addWidget(label_20, 8, 0, 1, 2);

        label_14 = new QLabel(layoutWidget2);
        label_14->setObjectName("label_14");

        gridLayout->addWidget(label_14, 3, 3, 1, 1);

        zombiearmor2blood = new QLineEdit(layoutWidget2);
        zombiearmor2blood->setObjectName("zombiearmor2blood");

        gridLayout->addWidget(zombiearmor2blood, 3, 4, 1, 1);

        zombiebody = new QLineEdit(layoutWidget2);
        zombiebody->setObjectName("zombiebody");

        gridLayout->addWidget(zombiebody, 1, 1, 1, 2);

        label_18 = new QLabel(layoutWidget2);
        label_18->setObjectName("label_18");

        gridLayout->addWidget(label_18, 6, 0, 1, 2);

        shiningtime = new QSlider(layoutWidget2);
        shiningtime->setObjectName("shiningtime");
        shiningtime->setMaximum(2000);
        shiningtime->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(shiningtime, 8, 2, 1, 1);

        zombiename = new QLineEdit(layoutWidget2);
        zombiename->setObjectName("zombiename");

        gridLayout->addWidget(zombiename, 0, 1, 1, 2);

        zombiearmor1blood = new QLineEdit(layoutWidget2);
        zombiearmor1blood->setObjectName("zombiearmor1blood");

        gridLayout->addWidget(zombiearmor1blood, 2, 4, 1, 1);

        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        slowdown = new QSlider(layoutWidget2);
        slowdown->setObjectName("slowdown");
        slowdown->setMaximum(2000);
        slowdown->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(slowdown, 5, 2, 1, 1);

        ycor = new QLineEdit(layoutWidget2);
        ycor->setObjectName("ycor");

        gridLayout->addWidget(ycor, 4, 4, 1, 1);

        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName("label_10");

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        zombiearmor1 = new QLineEdit(layoutWidget2);
        zombiearmor1->setObjectName("zombiearmor1");

        gridLayout->addWidget(zombiearmor1, 2, 1, 1, 2);

        label_19 = new QLabel(layoutWidget2);
        label_19->setObjectName("label_19");

        gridLayout->addWidget(label_19, 7, 0, 1, 2);

        label_12 = new QLabel(layoutWidget2);
        label_12->setObjectName("label_12");

        gridLayout->addWidget(label_12, 2, 3, 1, 1);

        buttertime = new QSlider(layoutWidget2);
        buttertime->setObjectName("buttertime");
        buttertime->setMaximum(2000);
        buttertime->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(buttertime, 6, 2, 1, 1);

        ischarm = new QCheckBox(layoutWidget2);
        ischarm->setObjectName("ischarm");

        gridLayout->addWidget(ischarm, 5, 3, 1, 1);

        isdead = new QCheckBox(layoutWidget2);
        isdead->setObjectName("isdead");

        gridLayout->addWidget(isdead, 6, 3, 1, 1);

        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 5, 4, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        totalprint = new QTextEdit(tab_3);
        totalprint->setObjectName("totalprint");
        totalprint->setGeometry(QRect(20, 40, 661, 311));
        layoutWidget3 = new QWidget(tab_3);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(20, 0, 661, 41));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        ignoreblindbox = new QCheckBox(layoutWidget3);
        ignoreblindbox->setObjectName("ignoreblindbox");

        horizontalLayout_6->addWidget(ignoreblindbox);

        rowdetails = new QCheckBox(layoutWidget3);
        rowdetails->setObjectName("rowdetails");

        horizontalLayout_6->addWidget(rowdetails);

        startcount = new QPushButton(layoutWidget3);
        startcount->setObjectName("startcount");

        horizontalLayout_6->addWidget(startcount);

        stopcount = new QPushButton(layoutWidget3);
        stopcount->setObjectName("stopcount");

        horizontalLayout_6->addWidget(stopcount);

        tofile = new QPushButton(layoutWidget3);
        tofile->setObjectName("tofile");

        horizontalLayout_6->addWidget(tofile);

        tabWidget->addTab(tab_3, QString());
        exitbutton = new QPushButton(customzombieplace);
        exitbutton->setObjectName("exitbutton");
        exitbutton->setGeometry(QRect(590, 410, 100, 30));

        retranslateUi(customzombieplace);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(customzombieplace);
    } // setupUi

    void retranslateUi(QWidget *customzombieplace)
    {
        customzombieplace->setWindowTitle(QCoreApplication::translate("customzombieplace", "Form", nullptr));
        textEdit->setHtml(QCoreApplication::translate("customzombieplace", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\234\252\346\235\245\351\242\204\347\225\231\345\212\237\350\203\275\347\251\272\351\227\264</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("customzombieplace", "\351\200\211\346\213\251\346\224\276\347\275\256\347\261\273\345\236\213\357\274\232", nullptr));
        zombiechoose->setItemText(0, QCoreApplication::translate("customzombieplace", "\343\200\2200\343\200\221\346\231\256\351\200\232\345\203\265\345\260\270", nullptr));
        zombiechoose->setItemText(1, QCoreApplication::translate("customzombieplace", "\343\200\2201\343\200\221\346\227\227\345\270\234", nullptr));
        zombiechoose->setItemText(2, QCoreApplication::translate("customzombieplace", "\343\200\2202\343\200\221\350\267\257\351\232\234\357\274\210\347\233\262\347\233\222\357\274\211", nullptr));
        zombiechoose->setItemText(3, QCoreApplication::translate("customzombieplace", "\343\200\2203\343\200\221\346\222\221\346\235\206", nullptr));
        zombiechoose->setItemText(4, QCoreApplication::translate("customzombieplace", "\343\200\2204\343\200\221\351\223\201\346\241\266", nullptr));
        zombiechoose->setItemText(5, QCoreApplication::translate("customzombieplace", "\343\200\2205\343\200\221\350\257\273\346\212\245", nullptr));
        zombiechoose->setItemText(6, QCoreApplication::translate("customzombieplace", "\343\200\2206\343\200\221\351\222\242\351\223\201\351\227\250", nullptr));
        zombiechoose->setItemText(7, QCoreApplication::translate("customzombieplace", "\343\200\2207\343\200\221\346\251\204\346\246\204", nullptr));
        zombiechoose->setItemText(8, QCoreApplication::translate("customzombieplace", "\343\200\2208\343\200\221\350\210\236\347\216\213", nullptr));
        zombiechoose->setItemText(9, QCoreApplication::translate("customzombieplace", "\343\200\2209\343\200\221\344\274\264\350\210\236", nullptr));
        zombiechoose->setItemText(10, QCoreApplication::translate("customzombieplace", "\343\200\22010\343\200\221\351\270\255\345\255\220", nullptr));
        zombiechoose->setItemText(11, QCoreApplication::translate("customzombieplace", "\343\200\22011\343\200\221\346\275\234\346\260\264", nullptr));
        zombiechoose->setItemText(12, QCoreApplication::translate("customzombieplace", "\343\200\22012\343\200\221\345\206\260\350\275\246", nullptr));
        zombiechoose->setItemText(13, QCoreApplication::translate("customzombieplace", "\343\200\22013\343\200\221\351\233\252\346\251\207", nullptr));
        zombiechoose->setItemText(14, QCoreApplication::translate("customzombieplace", "\343\200\22014\343\200\221\346\265\267\350\261\232", nullptr));
        zombiechoose->setItemText(15, QCoreApplication::translate("customzombieplace", "\343\200\22015\343\200\221\345\260\217\344\270\221", nullptr));
        zombiechoose->setItemText(16, QCoreApplication::translate("customzombieplace", "\343\200\22016\343\200\221\346\260\224\347\220\203", nullptr));
        zombiechoose->setItemText(17, QCoreApplication::translate("customzombieplace", "\343\200\22017\343\200\221\347\237\277\345\267\245", nullptr));
        zombiechoose->setItemText(18, QCoreApplication::translate("customzombieplace", "\343\200\22018\343\200\221\350\267\263\350\267\263", nullptr));
        zombiechoose->setItemText(19, QCoreApplication::translate("customzombieplace", "\343\200\22019\343\200\221\351\233\252\344\272\272", nullptr));
        zombiechoose->setItemText(20, QCoreApplication::translate("customzombieplace", "\343\200\22020\343\200\221\350\271\246\346\236\201", nullptr));
        zombiechoose->setItemText(21, QCoreApplication::translate("customzombieplace", "\343\200\22021\343\200\221\346\211\266\346\242\257", nullptr));
        zombiechoose->setItemText(22, QCoreApplication::translate("customzombieplace", "\343\200\22022\343\200\221\346\212\225\347\257\256", nullptr));
        zombiechoose->setItemText(23, QCoreApplication::translate("customzombieplace", "\343\200\22023\343\200\221\347\231\275\347\234\274", nullptr));
        zombiechoose->setItemText(24, QCoreApplication::translate("customzombieplace", "\343\200\22024\343\200\221\345\260\217\351\254\274", nullptr));
        zombiechoose->setItemText(25, QCoreApplication::translate("customzombieplace", "\343\200\22025\343\200\221\345\203\265\347\216\213", nullptr));
        zombiechoose->setItemText(26, QCoreApplication::translate("customzombieplace", "\343\200\22026\343\200\221\350\261\214\350\261\206", nullptr));
        zombiechoose->setItemText(27, QCoreApplication::translate("customzombieplace", "\343\200\22027\343\200\221\345\235\232\346\236\234", nullptr));
        zombiechoose->setItemText(28, QCoreApplication::translate("customzombieplace", "\343\200\22028\343\200\221\350\276\243\346\244\222", nullptr));
        zombiechoose->setItemText(29, QCoreApplication::translate("customzombieplace", "\343\200\22029\343\200\221\346\234\272\346\236\252", nullptr));
        zombiechoose->setItemText(30, QCoreApplication::translate("customzombieplace", "\343\200\22030\343\200\221\347\252\235\347\223\234", nullptr));
        zombiechoose->setItemText(31, QCoreApplication::translate("customzombieplace", "\343\200\22031\343\200\221\351\253\230\345\235\232\346\236\234", nullptr));
        zombiechoose->setItemText(32, QCoreApplication::translate("customzombieplace", "\343\200\22032\343\200\221\347\272\242\347\234\274", nullptr));

        label_2->setText(QCoreApplication::translate("customzombieplace", "\350\241\214\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("customzombieplace", "\345\210\227", nullptr));
        label_7->setText(QString());
        reset->setText(QCoreApplication::translate("customzombieplace", "\351\207\215\347\275\256", nullptr));
        label_4->setText(QCoreApplication::translate("customzombieplace", "\346\234\254\344\275\223\350\241\200\351\207\217", nullptr));
        label_5->setText(QCoreApplication::translate("customzombieplace", "\351\230\262\345\205\2671\350\241\200\351\207\217", nullptr));
        label_6->setText(QCoreApplication::translate("customzombieplace", "\351\230\262\345\205\2671\350\241\200\351\207\217", nullptr));
        armor_2->setText(QString());
        batchcheck->setText(QCoreApplication::translate("customzombieplace", "\346\211\271\351\207\217\346\224\276\347\275\256", nullptr));
        singleplace->setText(QCoreApplication::translate("customzombieplace", "\345\215\225\344\270\252\346\224\276\347\275\256", nullptr));
        rowplace->setText(QCoreApplication::translate("customzombieplace", "\346\225\264\350\241\214\346\224\276\347\275\256", nullptr));
        colplace->setText(QCoreApplication::translate("customzombieplace", "\346\225\264\345\210\227\346\224\276\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("customzombieplace", "\345\203\265\345\260\270\346\224\276\347\275\256", nullptr));
        realtime->setText(QCoreApplication::translate("customzombieplace", "\345\274\200\345\220\257\345\256\236\346\227\266\346\230\276\347\244\272", nullptr));
        label_21->setText(QCoreApplication::translate("customzombieplace", "\346\211\200\345\234\250\350\241\214\346\225\260", nullptr));
        label_13->setText(QCoreApplication::translate("customzombieplace", "\351\230\262\345\205\2672\347\261\273\345\236\213", nullptr));
        label_9->setText(QCoreApplication::translate("customzombieplace", "\345\203\265\345\260\270\347\261\273\345\236\213", nullptr));
        label_11->setText(QCoreApplication::translate("customzombieplace", "\351\230\262\345\205\2671\347\261\273\345\236\213", nullptr));
        label_15->setText(QCoreApplication::translate("customzombieplace", "X\345\235\220\346\240\207", nullptr));
        label_17->setText(QCoreApplication::translate("customzombieplace", "\345\207\217\351\200\237\345\200\222\350\256\241\346\227\266", nullptr));
        label_16->setText(QCoreApplication::translate("customzombieplace", "Y\345\235\220\346\240\207", nullptr));
        label_20->setText(QCoreApplication::translate("customzombieplace", "\351\227\252\345\205\211\345\200\222\350\256\241\346\227\266", nullptr));
        label_14->setText(QCoreApplication::translate("customzombieplace", "\351\230\262\345\205\2672\350\241\200\351\207\217", nullptr));
        label_18->setText(QCoreApplication::translate("customzombieplace", "\351\273\204\346\262\271\345\200\222\350\256\241\346\227\266", nullptr));
        label_8->setText(QCoreApplication::translate("customzombieplace", "\345\203\265\345\260\270\345\220\215\347\247\260", nullptr));
        label_10->setText(QCoreApplication::translate("customzombieplace", "\346\234\254\344\275\223\350\241\200\351\207\217", nullptr));
        label_19->setText(QCoreApplication::translate("customzombieplace", "\345\206\273\347\273\223\345\200\222\350\256\241\346\227\266", nullptr));
        label_12->setText(QCoreApplication::translate("customzombieplace", "\351\230\262\345\205\2671\350\241\200\351\207\217", nullptr));
        ischarm->setText(QCoreApplication::translate("customzombieplace", "\351\255\205\346\203\221", nullptr));
        isdead->setText(QCoreApplication::translate("customzombieplace", "\346\255\273\344\272\241", nullptr));
        pushButton->setText(QCoreApplication::translate("customzombieplace", "\346\233\264\346\224\271\351\255\205\346\203\221\347\212\266\346\200\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("customzombieplace", "\345\203\265\345\260\270\344\277\241\346\201\257", nullptr));
        ignoreblindbox->setText(QCoreApplication::translate("customzombieplace", "\345\277\275\347\225\245\350\267\257\351\232\234(\347\233\262\347\233\222)\345\203\265\345\260\270", nullptr));
        rowdetails->setText(QCoreApplication::translate("customzombieplace", "\347\224\237\346\210\220\350\241\214\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        startcount->setText(QCoreApplication::translate("customzombieplace", "\345\274\200\345\247\213\347\273\237\350\256\241", nullptr));
        stopcount->setText(QCoreApplication::translate("customzombieplace", "\347\273\223\346\235\237\347\273\237\350\256\241", nullptr));
        tofile->setText(QCoreApplication::translate("customzombieplace", "\347\224\237\346\210\220\347\273\237\350\256\241\346\226\207\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("customzombieplace", "\345\203\265\345\260\270\347\273\237\350\256\241", nullptr));
        exitbutton->setText(QCoreApplication::translate("customzombieplace", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customzombieplace: public Ui_customzombieplace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMZOMBIEPLACE_H
