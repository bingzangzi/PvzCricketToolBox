/********************************************************************************
** Form generated from reading UI file 'randplantplace.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANDPLANTPLACE_H
#define UI_RANDPLANTPLACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RandPlantPlace
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *select_noneed;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *animatedplant;
    QPushButton *rowcol_sure;
    QPushButton *change_mode;
    QPushButton *clearallplant;
    QPushButton *exit_button;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *currentmode;
    QLabel *rowlabel;
    QSpinBox *maxrow;
    QLabel *collabel;
    QSpinBox *maxcol;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *reset_select;
    QLabel *finished;
    QPushButton *sure_plant;
    QWidget *tab_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget_2;
    QGridLayout *forbidarea;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *allselct;
    QPushButton *resetbutton;
    QPushButton *forbidsure;

    void setupUi(QWidget *RandPlantPlace)
    {
        if (RandPlantPlace->objectName().isEmpty())
            RandPlantPlace->setObjectName("RandPlantPlace");
        RandPlantPlace->resize(809, 511);
        tabWidget = new QTabWidget(RandPlantPlace);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 811, 511));
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(230, 70, 551, 301));
        select_noneed = new QGridLayout(gridLayoutWidget);
        select_noneed->setObjectName("select_noneed");
        select_noneed->setContentsMargins(0, 0, 0, 0);
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 280, 156, 178));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        animatedplant = new QRadioButton(layoutWidget);
        animatedplant->setObjectName("animatedplant");

        verticalLayout_2->addWidget(animatedplant);

        rowcol_sure = new QPushButton(layoutWidget);
        rowcol_sure->setObjectName("rowcol_sure");

        verticalLayout_2->addWidget(rowcol_sure);

        change_mode = new QPushButton(layoutWidget);
        change_mode->setObjectName("change_mode");

        verticalLayout_2->addWidget(change_mode);

        clearallplant = new QPushButton(layoutWidget);
        clearallplant->setObjectName("clearallplant");

        verticalLayout_2->addWidget(clearallplant);

        exit_button = new QPushButton(layoutWidget);
        exit_button->setObjectName("exit_button");

        verticalLayout_2->addWidget(exit_button);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 80, 171, 181));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        currentmode = new QLabel(layoutWidget1);
        currentmode->setObjectName("currentmode");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setBold(true);
        currentmode->setFont(font);

        verticalLayout->addWidget(currentmode);

        rowlabel = new QLabel(layoutWidget1);
        rowlabel->setObjectName("rowlabel");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\347\255\211\347\272\277 Light")});
        font1.setPointSize(12);
        rowlabel->setFont(font1);

        verticalLayout->addWidget(rowlabel);

        maxrow = new QSpinBox(layoutWidget1);
        maxrow->setObjectName("maxrow");
        maxrow->setMinimum(1);
        maxrow->setMaximum(8);

        verticalLayout->addWidget(maxrow);

        collabel = new QLabel(layoutWidget1);
        collabel->setObjectName("collabel");
        collabel->setFont(font1);

        verticalLayout->addWidget(collabel);

        maxcol = new QSpinBox(layoutWidget1);
        maxcol->setObjectName("maxcol");
        maxcol->setMinimum(1);
        maxcol->setMaximum(8);
        maxcol->setSingleStep(1);

        verticalLayout->addWidget(maxcol);

        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 20, 181, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(18);
        font2.setBold(true);
        label_3->setFont(font2);
        label_3->setTextFormat(Qt::RichText);
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(230, 20, 551, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font3.setPointSize(14);
        font3.setBold(false);
        label_4->setFont(font3);
        label_4->setTextFormat(Qt::RichText);
        layoutWidget2 = new QWidget(tab);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(230, 380, 551, 81));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        reset_select = new QPushButton(layoutWidget2);
        reset_select->setObjectName("reset_select");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light")});
        font4.setPointSize(14);
        reset_select->setFont(font4);

        horizontalLayout->addWidget(reset_select);

        finished = new QLabel(layoutWidget2);
        finished->setObjectName("finished");
        finished->setFont(font1);
        finished->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(finished);

        sure_plant = new QPushButton(layoutWidget2);
        sure_plant->setObjectName("sure_plant");
        sure_plant->setFont(font4);

        horizontalLayout->addWidget(sure_plant);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        scrollArea = new QScrollArea(tab_2);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(70, 20, 671, 401));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 669, 399));
        gridLayoutWidget_2 = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(0, 0, 671, 401));
        forbidarea = new QGridLayout(gridLayoutWidget_2);
        forbidarea->setObjectName("forbidarea");
        forbidarea->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);
        label = new QLabel(tab_2);
        label->setObjectName("label");
        label->setGeometry(QRect(650, 440, 101, 21));
        widget = new QWidget(tab_2);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(180, 430, 451, 41));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        allselct = new QPushButton(widget);
        allselct->setObjectName("allselct");

        horizontalLayout_2->addWidget(allselct);

        resetbutton = new QPushButton(widget);
        resetbutton->setObjectName("resetbutton");

        horizontalLayout_2->addWidget(resetbutton);

        forbidsure = new QPushButton(widget);
        forbidsure->setObjectName("forbidsure");

        horizontalLayout_2->addWidget(forbidsure);

        tabWidget->addTab(tab_2, QString());

        retranslateUi(RandPlantPlace);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RandPlantPlace);
    } // setupUi

    void retranslateUi(QWidget *RandPlantPlace)
    {
        RandPlantPlace->setWindowTitle(QCoreApplication::translate("RandPlantPlace", "Form", nullptr));
        animatedplant->setText(QCoreApplication::translate("RandPlantPlace", "\346\267\273\345\212\240\347\247\215\346\244\215\345\212\250\347\224\273", nullptr));
        rowcol_sure->setText(QCoreApplication::translate("RandPlantPlace", "\347\241\256 \350\256\244", nullptr));
        change_mode->setText(QCoreApplication::translate("RandPlantPlace", "\345\210\207\346\215\242\350\207\263\351\200\211\346\213\251\347\247\215\346\244\215\346\250\241\345\274\217", nullptr));
        clearallplant->setText(QCoreApplication::translate("RandPlantPlace", "\344\270\200\351\224\256\346\270\205\347\251\272\345\205\250\345\234\272\346\244\215\347\211\251", nullptr));
        exit_button->setText(QCoreApplication::translate("RandPlantPlace", "\351\200\200 \345\207\272", nullptr));
        currentmode->setText(QCoreApplication::translate("RandPlantPlace", "\345\275\223\345\211\215\344\270\272\351\200\211\346\213\251\344\270\215\347\247\215\346\244\215\346\250\241\345\274\217", nullptr));
        rowlabel->setText(QCoreApplication::translate("RandPlantPlace", "\346\234\200\345\244\247\345\210\227\357\274\232", nullptr));
        collabel->setText(QCoreApplication::translate("RandPlantPlace", "\346\234\200\345\244\247\350\241\214\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("RandPlantPlace", "\350\257\267\350\276\223\345\205\245\350\241\214\345\210\227\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("RandPlantPlace", "\350\257\267\351\200\211\346\213\251\344\270\215\351\234\200\350\246\201\347\247\215\346\244\215\347\232\204\344\275\215\347\275\256\357\274\210\351\273\230\350\256\244\345\205\250\351\203\250\347\247\215\346\244\215\357\274\211\357\274\232", nullptr));
        reset_select->setText(QCoreApplication::translate("RandPlantPlace", "\351\207\215 \347\275\256", nullptr));
        finished->setText(QCoreApplication::translate("RandPlantPlace", "\347\247\215\346\244\215\345\256\214\346\210\220\357\274\201", nullptr));
        sure_plant->setText(QCoreApplication::translate("RandPlantPlace", "\347\241\256 \350\256\244 \347\247\215 \346\244\215", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("RandPlantPlace", "\351\232\217\346\234\272\346\224\276\347\275\256", nullptr));
        label->setText(QString());
        allselct->setText(QCoreApplication::translate("RandPlantPlace", "\345\205\250\351\200\211", nullptr));
        resetbutton->setText(QCoreApplication::translate("RandPlantPlace", "\351\207\215\347\275\256", nullptr));
        forbidsure->setText(QCoreApplication::translate("RandPlantPlace", "\347\246\201\346\255\242\347\247\215\346\244\215", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("RandPlantPlace", "\347\246\201\347\247\215\346\244\215\347\211\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RandPlantPlace: public Ui_RandPlantPlace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDPLANTPLACE_H
