/********************************************************************************
** Form generated from reading UI file 'randzombieplace.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANDZOMBIEPLACE_H
#define UI_RANDZOMBIEPLACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_randzombieplace
{
public:
    QTableWidget *timeandrate_table;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *deletedata;
    QPushButton *editdatalist;
    QPushButton *pausezombie;
    QPushButton *stopzombie;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QPushButton *returnmain;
    QLabel *label_5;
    QPushButton *resetall;
    QLabel *label_9;
    QLabel *label;
    QSpinBox *zombierow;
    QLabel *label_2;
    QSpinBox *zombiecol;
    QLabel *label_3;
    QComboBox *zombiechoose;
    QSpinBox *mowerrow;
    QLabel *label_8;
    QPushButton *clearmower;
    QPushButton *startmower;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QDoubleSpinBox *initrate;
    QPushButton *initratesure;
    QLabel *inittext;
    QLabel *inittextvalue;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QDoubleSpinBox *timenode;
    QLabel *label_7;
    QDoubleSpinBox *rates;
    QPushButton *addsure;
    QPushButton *addfinish;
    QCheckBox *autospicy;
    QGridLayout *gridLayout_2;
    QPushButton *skipandput;
    QPushButton *resumemower;
    QPushButton *killallzombies;
    QPushButton *beginput;
    QCheckBox *pausewithgame;
    QHBoxLayout *horizontalLayout_4;
    QLabel *totalzombie;
    QLabel *currentrate;

    void setupUi(QWidget *randzombieplace)
    {
        if (randzombieplace->objectName().isEmpty())
            randzombieplace->setObjectName("randzombieplace");
        randzombieplace->resize(810, 349);
        timeandrate_table = new QTableWidget(randzombieplace);
        timeandrate_table->setObjectName("timeandrate_table");
        timeandrate_table->setGeometry(QRect(600, 10, 201, 251));
        layoutWidget = new QWidget(randzombieplace);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(600, 270, 201, 71));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        deletedata = new QPushButton(layoutWidget);
        deletedata->setObjectName("deletedata");

        horizontalLayout->addWidget(deletedata);

        editdatalist = new QPushButton(layoutWidget);
        editdatalist->setObjectName("editdatalist");

        horizontalLayout->addWidget(editdatalist);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        pausezombie = new QPushButton(layoutWidget);
        pausezombie->setObjectName("pausezombie");

        gridLayout->addWidget(pausezombie, 1, 0, 1, 1);

        stopzombie = new QPushButton(layoutWidget);
        stopzombie->setObjectName("stopzombie");

        gridLayout->addWidget(stopzombie, 1, 1, 1, 1);

        layoutWidget1 = new QWidget(randzombieplace);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 11, 581, 331));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light")});
        font.setPointSize(10);
        label_4->setFont(font);

        gridLayout_3->addWidget(label_4, 0, 0, 1, 5);

        returnmain = new QPushButton(layoutWidget1);
        returnmain->setObjectName("returnmain");

        gridLayout_3->addWidget(returnmain, 0, 6, 1, 1);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName("label_5");
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_5, 1, 0, 1, 4);

        resetall = new QPushButton(layoutWidget1);
        resetall->setObjectName("resetall");

        gridLayout_3->addWidget(resetall, 1, 6, 1, 1);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName("label_9");
        QFont font1;
        font1.setPointSize(8);
        label_9->setFont(font1);

        gridLayout_3->addWidget(label_9, 1, 7, 1, 1);

        label = new QLabel(layoutWidget1);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label, 2, 0, 1, 1);

        zombierow = new QSpinBox(layoutWidget1);
        zombierow->setObjectName("zombierow");
        zombierow->setMaximum(10);

        gridLayout_3->addWidget(zombierow, 2, 1, 1, 1);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_2, 2, 2, 1, 1);

        zombiecol = new QSpinBox(layoutWidget1);
        zombiecol->setObjectName("zombiecol");
        zombiecol->setMaximum(15);

        gridLayout_3->addWidget(zombiecol, 2, 3, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_3, 2, 4, 1, 1);

        zombiechoose = new QComboBox(layoutWidget1);
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

        gridLayout_3->addWidget(zombiechoose, 2, 5, 1, 2);

        mowerrow = new QSpinBox(layoutWidget1);
        mowerrow->setObjectName("mowerrow");
        mowerrow->setMaximum(6);

        gridLayout_3->addWidget(mowerrow, 2, 7, 1, 1);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName("label_8");
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_8, 3, 0, 1, 6);

        clearmower = new QPushButton(layoutWidget1);
        clearmower->setObjectName("clearmower");
        QFont font2;
        font2.setPointSize(9);
        clearmower->setFont(font2);

        gridLayout_3->addWidget(clearmower, 3, 6, 1, 1);

        startmower = new QPushButton(layoutWidget1);
        startmower->setObjectName("startmower");
        startmower->setFont(font2);

        gridLayout_3->addWidget(startmower, 3, 7, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName("label_10");
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_10);

        initrate = new QDoubleSpinBox(layoutWidget1);
        initrate->setObjectName("initrate");

        horizontalLayout_2->addWidget(initrate);

        initratesure = new QPushButton(layoutWidget1);
        initratesure->setObjectName("initratesure");

        horizontalLayout_2->addWidget(initratesure);

        inittext = new QLabel(layoutWidget1);
        inittext->setObjectName("inittext");

        horizontalLayout_2->addWidget(inittext);

        inittextvalue = new QLabel(layoutWidget1);
        inittextvalue->setObjectName("inittextvalue");

        horizontalLayout_2->addWidget(inittextvalue);


        gridLayout_3->addLayout(horizontalLayout_2, 4, 0, 1, 8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_6);

        timenode = new QDoubleSpinBox(layoutWidget1);
        timenode->setObjectName("timenode");

        horizontalLayout_3->addWidget(timenode);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_7);

        rates = new QDoubleSpinBox(layoutWidget1);
        rates->setObjectName("rates");

        horizontalLayout_3->addWidget(rates);

        addsure = new QPushButton(layoutWidget1);
        addsure->setObjectName("addsure");

        horizontalLayout_3->addWidget(addsure);

        addfinish = new QPushButton(layoutWidget1);
        addfinish->setObjectName("addfinish");

        horizontalLayout_3->addWidget(addfinish);


        gridLayout_3->addLayout(horizontalLayout_3, 5, 0, 1, 8);

        autospicy = new QCheckBox(layoutWidget1);
        autospicy->setObjectName("autospicy");

        gridLayout_3->addWidget(autospicy, 6, 0, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        skipandput = new QPushButton(layoutWidget1);
        skipandput->setObjectName("skipandput");

        gridLayout_2->addWidget(skipandput, 0, 0, 1, 2);

        resumemower = new QPushButton(layoutWidget1);
        resumemower->setObjectName("resumemower");
        resumemower->setFont(font2);

        gridLayout_2->addWidget(resumemower, 0, 2, 1, 1);

        killallzombies = new QPushButton(layoutWidget1);
        killallzombies->setObjectName("killallzombies");

        gridLayout_2->addWidget(killallzombies, 1, 2, 1, 1);

        beginput = new QPushButton(layoutWidget1);
        beginput->setObjectName("beginput");

        gridLayout_2->addWidget(beginput, 1, 0, 1, 2);


        gridLayout_3->addLayout(gridLayout_2, 6, 6, 2, 2);

        pausewithgame = new QCheckBox(layoutWidget1);
        pausewithgame->setObjectName("pausewithgame");

        gridLayout_3->addWidget(pausewithgame, 7, 0, 1, 4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        totalzombie = new QLabel(layoutWidget1);
        totalzombie->setObjectName("totalzombie");

        horizontalLayout_4->addWidget(totalzombie);

        currentrate = new QLabel(layoutWidget1);
        currentrate->setObjectName("currentrate");

        horizontalLayout_4->addWidget(currentrate);


        gridLayout_3->addLayout(horizontalLayout_4, 8, 0, 1, 8);


        retranslateUi(randzombieplace);

        QMetaObject::connectSlotsByName(randzombieplace);
    } // setupUi

    void retranslateUi(QWidget *randzombieplace)
    {
        randzombieplace->setWindowTitle(QCoreApplication::translate("randzombieplace", "Form", nullptr));
        deletedata->setText(QCoreApplication::translate("randzombieplace", "\345\210\240\351\231\244\351\200\211\344\270\255\347\232\204\346\225\260\346\215\256", nullptr));
        editdatalist->setText(QCoreApplication::translate("randzombieplace", "\347\241\256\350\256\244\344\277\256\346\224\271\346\225\260\346\215\256", nullptr));
        pausezombie->setText(QCoreApplication::translate("randzombieplace", "\346\232\202\345\201\234\345\207\272\346\200\252", nullptr));
        stopzombie->setText(QCoreApplication::translate("randzombieplace", "\347\273\210\346\255\242\345\207\272\346\200\252", nullptr));
        label_4->setText(QCoreApplication::translate("randzombieplace", "\351\200\211\346\213\251\351\234\200\350\246\201\346\224\276\347\275\256\347\232\204\345\203\265\345\260\270\344\273\245\345\217\212\346\211\200\345\234\250\347\232\204\350\241\214\345\210\227", nullptr));
        returnmain->setText(QCoreApplication::translate("randzombieplace", "\351\200\200\345\207\272", nullptr));
        label_5->setText(QCoreApplication::translate("randzombieplace", "0\350\241\214\350\241\250\347\244\272\346\225\264\345\210\227/0\345\210\227\350\241\250\347\244\272\346\225\264\350\241\214\357\274\2101~11\357\274\211", nullptr));
        resetall->setText(QCoreApplication::translate("randzombieplace", "\345\205\250\351\203\250\351\207\215\347\275\256", nullptr));
        label_9->setText(QCoreApplication::translate("randzombieplace", "\347\233\256\346\240\207\345\260\217\346\216\250\350\275\246\347\232\204\350\241\214", nullptr));
        label->setText(QCoreApplication::translate("randzombieplace", "\350\241\214", nullptr));
        label_2->setText(QCoreApplication::translate("randzombieplace", "\345\210\227", nullptr));
        label_3->setText(QCoreApplication::translate("randzombieplace", "\347\261\273\345\236\213", nullptr));
        zombiechoose->setItemText(0, QCoreApplication::translate("randzombieplace", "\343\200\2200\343\200\221\346\231\256\351\200\232\345\203\265\345\260\270", nullptr));
        zombiechoose->setItemText(1, QCoreApplication::translate("randzombieplace", "\343\200\2201\343\200\221\346\227\227\345\270\234", nullptr));
        zombiechoose->setItemText(2, QCoreApplication::translate("randzombieplace", "\343\200\2202\343\200\221\350\267\257\351\232\234\357\274\210\347\233\262\347\233\222\357\274\211", nullptr));
        zombiechoose->setItemText(3, QCoreApplication::translate("randzombieplace", "\343\200\2203\343\200\221\346\222\221\346\235\206", nullptr));
        zombiechoose->setItemText(4, QCoreApplication::translate("randzombieplace", "\343\200\2204\343\200\221\351\223\201\346\241\266", nullptr));
        zombiechoose->setItemText(5, QCoreApplication::translate("randzombieplace", "\343\200\2205\343\200\221\350\257\273\346\212\245", nullptr));
        zombiechoose->setItemText(6, QCoreApplication::translate("randzombieplace", "\343\200\2206\343\200\221\351\222\242\351\223\201\351\227\250", nullptr));
        zombiechoose->setItemText(7, QCoreApplication::translate("randzombieplace", "\343\200\2207\343\200\221\346\251\204\346\246\204", nullptr));
        zombiechoose->setItemText(8, QCoreApplication::translate("randzombieplace", "\343\200\2208\343\200\221\350\210\236\347\216\213", nullptr));
        zombiechoose->setItemText(9, QCoreApplication::translate("randzombieplace", "\343\200\2209\343\200\221\344\274\264\350\210\236", nullptr));
        zombiechoose->setItemText(10, QCoreApplication::translate("randzombieplace", "\343\200\22010\343\200\221\351\270\255\345\255\220", nullptr));
        zombiechoose->setItemText(11, QCoreApplication::translate("randzombieplace", "\343\200\22011\343\200\221\346\275\234\346\260\264", nullptr));
        zombiechoose->setItemText(12, QCoreApplication::translate("randzombieplace", "\343\200\22012\343\200\221\345\206\260\350\275\246", nullptr));
        zombiechoose->setItemText(13, QCoreApplication::translate("randzombieplace", "\343\200\22013\343\200\221\351\233\252\346\251\207", nullptr));
        zombiechoose->setItemText(14, QCoreApplication::translate("randzombieplace", "\343\200\22014\343\200\221\346\265\267\350\261\232", nullptr));
        zombiechoose->setItemText(15, QCoreApplication::translate("randzombieplace", "\343\200\22015\343\200\221\345\260\217\344\270\221", nullptr));
        zombiechoose->setItemText(16, QCoreApplication::translate("randzombieplace", "\343\200\22016\343\200\221\346\260\224\347\220\203", nullptr));
        zombiechoose->setItemText(17, QCoreApplication::translate("randzombieplace", "\343\200\22017\343\200\221\347\237\277\345\267\245", nullptr));
        zombiechoose->setItemText(18, QCoreApplication::translate("randzombieplace", "\343\200\22018\343\200\221\350\267\263\350\267\263", nullptr));
        zombiechoose->setItemText(19, QCoreApplication::translate("randzombieplace", "\343\200\22019\343\200\221\351\233\252\344\272\272", nullptr));
        zombiechoose->setItemText(20, QCoreApplication::translate("randzombieplace", "\343\200\22020\343\200\221\350\271\246\346\236\201", nullptr));
        zombiechoose->setItemText(21, QCoreApplication::translate("randzombieplace", "\343\200\22021\343\200\221\346\211\266\346\242\257", nullptr));
        zombiechoose->setItemText(22, QCoreApplication::translate("randzombieplace", "\343\200\22022\343\200\221\346\212\225\347\257\256", nullptr));
        zombiechoose->setItemText(23, QCoreApplication::translate("randzombieplace", "\343\200\22023\343\200\221\347\231\275\347\234\274", nullptr));
        zombiechoose->setItemText(24, QCoreApplication::translate("randzombieplace", "\343\200\22024\343\200\221\345\260\217\351\254\274", nullptr));
        zombiechoose->setItemText(25, QCoreApplication::translate("randzombieplace", "\343\200\22025\343\200\221\345\203\265\347\216\213", nullptr));
        zombiechoose->setItemText(26, QCoreApplication::translate("randzombieplace", "\343\200\22026\343\200\221\350\261\214\350\261\206", nullptr));
        zombiechoose->setItemText(27, QCoreApplication::translate("randzombieplace", "\343\200\22027\343\200\221\345\235\232\346\236\234", nullptr));
        zombiechoose->setItemText(28, QCoreApplication::translate("randzombieplace", "\343\200\22028\343\200\221\350\276\243\346\244\222", nullptr));
        zombiechoose->setItemText(29, QCoreApplication::translate("randzombieplace", "\343\200\22029\343\200\221\346\234\272\346\236\252", nullptr));
        zombiechoose->setItemText(30, QCoreApplication::translate("randzombieplace", "\343\200\22030\343\200\221\347\252\235\347\223\234", nullptr));
        zombiechoose->setItemText(31, QCoreApplication::translate("randzombieplace", "\343\200\22031\343\200\221\351\253\230\345\235\232\346\236\234", nullptr));
        zombiechoose->setItemText(32, QCoreApplication::translate("randzombieplace", "\343\200\22032\343\200\221\347\272\242\347\234\274", nullptr));

        label_8->setText(QCoreApplication::translate("randzombieplace", "\346\216\245\344\270\213\346\235\245\350\276\223\345\205\245\345\217\230\346\233\264\351\200\237\347\216\207\347\232\204\346\227\266\351\227\264\350\212\202\347\202\271\344\273\245\345\217\212\345\257\271\345\272\224\351\200\237\347\216\207", nullptr));
        clearmower->setText(QCoreApplication::translate("randzombieplace", "\346\270\205\351\231\244\345\260\217\346\216\250\350\275\246", nullptr));
        startmower->setText(QCoreApplication::translate("randzombieplace", "\345\220\257\345\212\250\345\260\217\346\216\250\350\275\246", nullptr));
        label_10->setText(QCoreApplication::translate("randzombieplace", "\345\210\235\345\247\213\351\200\237\347\216\207\357\274\210\345\215\225\344\275\215\357\274\232s\357\274\211", nullptr));
        initratesure->setText(QCoreApplication::translate("randzombieplace", "\347\241\256\350\256\244", nullptr));
        inittext->setText(QCoreApplication::translate("randzombieplace", "\345\210\235\345\247\213\351\200\237\347\216\207", nullptr));
        inittextvalue->setText(QString());
        label_6->setText(QCoreApplication::translate("randzombieplace", "\350\212\202\347\202\271(\345\215\225\344\275\215\357\274\232min)", nullptr));
        label_7->setText(QCoreApplication::translate("randzombieplace", "\351\200\237\347\216\207(\345\215\225\344\275\215\357\274\232s)", nullptr));
        addsure->setText(QCoreApplication::translate("randzombieplace", "\347\241\256\350\256\244", nullptr));
        addfinish->setText(QCoreApplication::translate("randzombieplace", "\347\273\223\346\235\237\346\267\273\345\212\240", nullptr));
        autospicy->setText(QCoreApplication::translate("randzombieplace", "\350\207\252\345\212\250\346\224\276\347\275\256\350\276\243\346\244\222", nullptr));
        skipandput->setText(QCoreApplication::translate("randzombieplace", "\350\267\263\350\277\207\345\271\266\347\233\264\346\216\245\346\224\276\347\275\256\344\270\200\346\254\241", nullptr));
        resumemower->setText(QCoreApplication::translate("randzombieplace", "\346\201\242\345\244\215\345\260\217\346\216\250\350\275\246", nullptr));
        killallzombies->setText(QCoreApplication::translate("randzombieplace", "\346\270\205\347\251\272\345\203\265\345\260\270", nullptr));
        beginput->setText(QCoreApplication::translate("randzombieplace", "\345\274\200\345\247\213\346\224\276\347\275\256", nullptr));
        pausewithgame->setText(QCoreApplication::translate("randzombieplace", "\346\232\202\345\201\234\346\224\276\347\275\256\346\227\266\346\270\270\346\210\217\345\220\214\346\227\266\346\232\202\345\201\234", nullptr));
        totalzombie->setText(QString());
        currentrate->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class randzombieplace: public Ui_randzombieplace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDZOMBIEPLACE_H
