/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *rand_plant_mode_menu;
    QAction *custom_plant_mode_menu;
    QAction *rand_zombie_mode_menu;
    QAction *custom_zombie_mode_menu;
    QAction *browseversion;
    QAction *browshelpinfo;
    QAction *setting;
    QWidget *centralwidget;
    QTabWidget *maintable;
    QWidget *tab;
    QLineEdit *GetNameText;
    QLabel *miantitel;
    QLabel *tips_one;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *main_commitButton;
    QPushButton *main_exitButton;
    QGridLayout *gridLayout;
    QPushButton *main_plantplace;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_4;
    QCheckBox *plantInvincible;
    QCheckBox *nocostsun;
    QCheckBox *freeplant;
    QCheckBox *nocool;
    QCheckBox *nocrater;
    QCheckBox *noawake;
    QCheckBox *nolimitonplant;
    QCheckBox *clearplant;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *zombieInvincible;
    QCheckBox *pausesystemzombie;
    QCheckBox *zombiepause;
    QCheckBox *clearallzombies;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_3;
    QCheckBox *lockspade;
    QCheckBox *hidespade;
    QCheckBox *autocollect;
    QCheckBox *unlockallmode;
    QCheckBox *passthegame;
    QCheckBox *pausegame;
    QCheckBox *hideslot;
    QCheckBox *hidemenu;
    QCheckBox *nosun;
    QCheckBox *unlockglod;
    QCheckBox *allowrunback;
    QLineEdit *more;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *suntext;
    QPushButton *sunchange;
    QSpacerItem *horizontalSpacer;
    QPushButton *quickset;
    QPushButton *resetall;
    QMenuBar *menubar;
    QMenu *main_menu;
    QMenu *plant_menu;
    QMenu *zombie_menu;
    QMenu *help_menu;
    QMenu *version_menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(816, 580);
        QFont font;
        font.setFamilies({QString::fromUtf8("\347\255\211\347\272\277 Light")});
        font.setPointSize(11);
        MainWindow->setFont(font);
        rand_plant_mode_menu = new QAction(MainWindow);
        rand_plant_mode_menu->setObjectName("rand_plant_mode_menu");
        custom_plant_mode_menu = new QAction(MainWindow);
        custom_plant_mode_menu->setObjectName("custom_plant_mode_menu");
        rand_zombie_mode_menu = new QAction(MainWindow);
        rand_zombie_mode_menu->setObjectName("rand_zombie_mode_menu");
        custom_zombie_mode_menu = new QAction(MainWindow);
        custom_zombie_mode_menu->setObjectName("custom_zombie_mode_menu");
        browseversion = new QAction(MainWindow);
        browseversion->setObjectName("browseversion");
        browshelpinfo = new QAction(MainWindow);
        browshelpinfo->setObjectName("browshelpinfo");
        setting = new QAction(MainWindow);
        setting->setObjectName("setting");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        maintable = new QTabWidget(centralwidget);
        maintable->setObjectName("maintable");
        maintable->setGeometry(QRect(0, 0, 811, 541));
        tab = new QWidget();
        tab->setObjectName("tab");
        GetNameText = new QLineEdit(tab);
        GetNameText->setObjectName("GetNameText");
        GetNameText->setGeometry(QRect(70, 260, 651, 41));
        miantitel = new QLabel(tab);
        miantitel->setObjectName("miantitel");
        miantitel->setGeometry(QRect(20, 20, 781, 121));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\347\255\211\347\272\277")});
        font1.setPointSize(20);
        font1.setBold(true);
        miantitel->setFont(font1);
        miantitel->setAlignment(Qt::AlignCenter);
        tips_one = new QLabel(tab);
        tips_one->setObjectName("tips_one");
        tips_one->setGeometry(QRect(100, 140, 571, 101));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\347\255\211\347\272\277 Light")});
        font2.setPointSize(20);
        tips_one->setFont(font2);
        tips_one->setLayoutDirection(Qt::LeftToRight);
        tips_one->setAutoFillBackground(false);
        tips_one->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(160, 331, 461, 151));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        main_commitButton = new QPushButton(layoutWidget);
        main_commitButton->setObjectName("main_commitButton");

        horizontalLayout->addWidget(main_commitButton);

        main_exitButton = new QPushButton(layoutWidget);
        main_exitButton->setObjectName("main_exitButton");

        horizontalLayout->addWidget(main_exitButton);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        main_plantplace = new QPushButton(layoutWidget);
        main_plantplace->setObjectName("main_plantplace");

        gridLayout->addWidget(main_plantplace, 0, 0, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        maintable->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 20, 801, 131));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 38, 781, 81));
        gridLayout_4 = new QGridLayout(layoutWidget1);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        plantInvincible = new QCheckBox(layoutWidget1);
        plantInvincible->setObjectName("plantInvincible");

        gridLayout_4->addWidget(plantInvincible, 0, 0, 1, 1);

        nocostsun = new QCheckBox(layoutWidget1);
        nocostsun->setObjectName("nocostsun");

        gridLayout_4->addWidget(nocostsun, 0, 1, 1, 1);

        freeplant = new QCheckBox(layoutWidget1);
        freeplant->setObjectName("freeplant");

        gridLayout_4->addWidget(freeplant, 0, 2, 1, 1);

        nocool = new QCheckBox(layoutWidget1);
        nocool->setObjectName("nocool");

        gridLayout_4->addWidget(nocool, 0, 3, 1, 1);

        nocrater = new QCheckBox(layoutWidget1);
        nocrater->setObjectName("nocrater");

        gridLayout_4->addWidget(nocrater, 0, 4, 1, 1);

        noawake = new QCheckBox(layoutWidget1);
        noawake->setObjectName("noawake");

        gridLayout_4->addWidget(noawake, 1, 0, 1, 1);

        nolimitonplant = new QCheckBox(layoutWidget1);
        nolimitonplant->setObjectName("nolimitonplant");

        gridLayout_4->addWidget(nolimitonplant, 1, 1, 1, 1);

        clearplant = new QCheckBox(layoutWidget1);
        clearplant->setObjectName("clearplant");

        gridLayout_4->addWidget(clearplant, 1, 2, 1, 1);

        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 170, 801, 81));
        layoutWidget2 = new QWidget(groupBox_2);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 30, 621, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        zombieInvincible = new QCheckBox(layoutWidget2);
        zombieInvincible->setObjectName("zombieInvincible");

        horizontalLayout_2->addWidget(zombieInvincible);

        pausesystemzombie = new QCheckBox(layoutWidget2);
        pausesystemzombie->setObjectName("pausesystemzombie");

        horizontalLayout_2->addWidget(pausesystemzombie);

        zombiepause = new QCheckBox(layoutWidget2);
        zombiepause->setObjectName("zombiepause");

        horizontalLayout_2->addWidget(zombiepause);

        clearallzombies = new QCheckBox(layoutWidget2);
        clearallzombies->setObjectName("clearallzombies");

        horizontalLayout_2->addWidget(clearallzombies);

        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(0, 270, 801, 121));
        layoutWidget3 = new QWidget(groupBox_3);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(10, 22, 781, 93));
        gridLayout_3 = new QGridLayout(layoutWidget3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lockspade = new QCheckBox(layoutWidget3);
        lockspade->setObjectName("lockspade");

        gridLayout_3->addWidget(lockspade, 0, 3, 1, 1);

        hidespade = new QCheckBox(layoutWidget3);
        hidespade->setObjectName("hidespade");

        gridLayout_3->addWidget(hidespade, 0, 4, 1, 1);

        autocollect = new QCheckBox(layoutWidget3);
        autocollect->setObjectName("autocollect");

        gridLayout_3->addWidget(autocollect, 1, 3, 1, 1);

        unlockallmode = new QCheckBox(layoutWidget3);
        unlockallmode->setObjectName("unlockallmode");

        gridLayout_3->addWidget(unlockallmode, 0, 2, 1, 1);

        passthegame = new QCheckBox(layoutWidget3);
        passthegame->setObjectName("passthegame");

        gridLayout_3->addWidget(passthegame, 0, 0, 1, 1);

        pausegame = new QCheckBox(layoutWidget3);
        pausegame->setObjectName("pausegame");

        gridLayout_3->addWidget(pausegame, 1, 4, 1, 1);

        hideslot = new QCheckBox(layoutWidget3);
        hideslot->setObjectName("hideslot");

        gridLayout_3->addWidget(hideslot, 1, 0, 1, 1);

        hidemenu = new QCheckBox(layoutWidget3);
        hidemenu->setObjectName("hidemenu");

        gridLayout_3->addWidget(hidemenu, 1, 1, 1, 1);

        nosun = new QCheckBox(layoutWidget3);
        nosun->setObjectName("nosun");

        gridLayout_3->addWidget(nosun, 1, 2, 1, 1);

        unlockglod = new QCheckBox(layoutWidget3);
        unlockglod->setObjectName("unlockglod");

        gridLayout_3->addWidget(unlockglod, 0, 1, 1, 1);

        allowrunback = new QCheckBox(layoutWidget3);
        allowrunback->setObjectName("allowrunback");

        gridLayout_3->addWidget(allowrunback, 2, 0, 1, 1);

        more = new QLineEdit(tab_2);
        more->setObjectName("more");
        more->setGeometry(QRect(10, 460, 781, 31));
        layoutWidget4 = new QWidget(tab_2);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(10, 410, 781, 41));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        suntext = new QLineEdit(layoutWidget4);
        suntext->setObjectName("suntext");

        horizontalLayout_3->addWidget(suntext);

        sunchange = new QPushButton(layoutWidget4);
        sunchange->setObjectName("sunchange");

        horizontalLayout_3->addWidget(sunchange);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        quickset = new QPushButton(layoutWidget4);
        quickset->setObjectName("quickset");

        horizontalLayout_4->addWidget(quickset);

        resetall = new QPushButton(layoutWidget4);
        resetall->setObjectName("resetall");

        horizontalLayout_4->addWidget(resetall);

        maintable->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 816, 27));
        main_menu = new QMenu(menubar);
        main_menu->setObjectName("main_menu");
        plant_menu = new QMenu(menubar);
        plant_menu->setObjectName("plant_menu");
        zombie_menu = new QMenu(menubar);
        zombie_menu->setObjectName("zombie_menu");
        help_menu = new QMenu(menubar);
        help_menu->setObjectName("help_menu");
        version_menu = new QMenu(menubar);
        version_menu->setObjectName("version_menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(main_menu->menuAction());
        menubar->addAction(plant_menu->menuAction());
        menubar->addAction(zombie_menu->menuAction());
        menubar->addAction(help_menu->menuAction());
        menubar->addAction(version_menu->menuAction());
        main_menu->addAction(setting);
        plant_menu->addAction(rand_plant_mode_menu);
        plant_menu->addSeparator();
        plant_menu->addAction(custom_plant_mode_menu);
        zombie_menu->addAction(rand_zombie_mode_menu);
        zombie_menu->addSeparator();
        zombie_menu->addAction(custom_zombie_mode_menu);
        help_menu->addAction(browshelpinfo);
        version_menu->addAction(browseversion);

        retranslateUi(MainWindow);

        maintable->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        rand_plant_mode_menu->setText(QCoreApplication::translate("MainWindow", "\351\232\217\346\234\272\346\224\276\347\275\256\346\250\241\345\274\217", nullptr));
        custom_plant_mode_menu->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211\346\224\276\347\275\256\346\250\241\345\274\217", nullptr));
        rand_zombie_mode_menu->setText(QCoreApplication::translate("MainWindow", "\351\232\217\346\234\272\346\224\276\347\275\256\346\250\241\345\274\217", nullptr));
        custom_zombie_mode_menu->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211\346\224\276\347\275\256\346\250\241\345\274\217", nullptr));
        browseversion->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\347\211\210\346\234\254\344\277\241\346\201\257", nullptr));
        browshelpinfo->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\345\270\256\345\212\251\344\277\241\346\201\257", nullptr));
        setting->setText(QCoreApplication::translate("MainWindow", "\346\270\270\346\210\217\350\256\276\347\275\256", nullptr));
        GetNameText->setText(QCoreApplication::translate("MainWindow", "PlantsVsZombies.exe", nullptr));
        miantitel->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\344\275\277\347\224\250\346\244\215\347\211\251\345\244\247\346\210\230\345\203\265\345\260\270\357\274\232\346\244\215\347\211\251&\345\203\265\345\260\270\350\207\252\345\212\250\345\270\203\351\230\265\345\231\250", nullptr));
        tips_one->setText(QCoreApplication::translate("MainWindow", "\345\234\250\345\274\200\345\247\213\344\271\213\345\211\215\350\257\267\351\246\226\345\205\210\345\257\273\346\211\276\346\270\270\346\210\217", nullptr));
        main_commitButton->setText(QCoreApplication::translate("MainWindow", "\347\241\256 \350\256\244", nullptr));
        main_exitButton->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
        main_plantplace->setText(QCoreApplication::translate("MainWindow", "\351\232\217\346\234\272\346\224\276\347\275\256\346\244\215\347\211\251", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211\346\224\276\347\275\256\346\244\215\347\211\251", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\351\232\217\346\234\272\346\224\276\347\275\256\345\203\265\345\260\270", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211\346\224\276\347\275\256\345\203\265\345\260\270", nullptr));
        maintable->setTabText(maintable->indexOf(tab), QCoreApplication::translate("MainWindow", "\344\270\273\347\225\214\351\235\242", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\244\215\347\211\251\347\233\270\345\205\263", nullptr));
        plantInvincible->setText(QCoreApplication::translate("MainWindow", "\346\244\215\347\211\251\346\227\240\346\225\214", nullptr));
        nocostsun->setText(QCoreApplication::translate("MainWindow", "\344\270\215\346\266\210\350\200\227\351\230\263\345\205\211", nullptr));
        freeplant->setText(QCoreApplication::translate("MainWindow", "\350\207\252\347\224\261\347\247\215\346\244\215", nullptr));
        nocool->setText(QCoreApplication::translate("MainWindow", "\345\215\241\347\211\207\346\227\240\345\206\267\345\215\264", nullptr));
        nocrater->setText(QCoreApplication::translate("MainWindow", "\344\270\215\347\225\231\345\274\271\345\235\221", nullptr));
        noawake->setText(QCoreApplication::translate("MainWindow", "\350\230\221\350\217\207\345\205\215\345\224\244\351\206\222", nullptr));
        nolimitonplant->setText(QCoreApplication::translate("MainWindow", "\347\264\253\345\215\241\346\227\240\351\231\220\345\210\266", nullptr));
        clearplant->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\345\234\272\344\270\212\346\244\215\347\211\251", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\345\203\265\345\260\270\347\233\270\345\205\263", nullptr));
        zombieInvincible->setText(QCoreApplication::translate("MainWindow", "\345\203\265\345\260\270\346\227\240\346\225\214", nullptr));
        pausesystemzombie->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234\347\263\273\347\273\237\345\207\272\346\200\252", nullptr));
        zombiepause->setText(QCoreApplication::translate("MainWindow", "\345\203\265\345\260\270\344\270\215\345\212\250", nullptr));
        clearallzombies->setText(QCoreApplication::translate("MainWindow", "\347\247\222\346\235\200\346\211\200\346\234\211\345\203\265\345\260\270", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\345\205\266\344\273\226\346\235\202\351\241\271", nullptr));
        lockspade->setText(QCoreApplication::translate("MainWindow", "\351\274\240\346\240\207\351\224\201\345\256\232\351\223\262\345\255\220", nullptr));
        hidespade->setText(QCoreApplication::translate("MainWindow", "\351\232\220\350\227\217\351\223\262\345\255\220", nullptr));
        autocollect->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\224\266\351\233\206", nullptr));
        unlockallmode->setText(QCoreApplication::translate("MainWindow", "\350\247\243\351\224\201\346\211\200\346\234\211\346\250\241\345\274\217", nullptr));
        passthegame->setText(QCoreApplication::translate("MainWindow", "\347\233\264\346\216\245\350\277\207\345\205\263", nullptr));
        pausegame->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234\346\270\270\346\210\217", nullptr));
        hideslot->setText(QCoreApplication::translate("MainWindow", "\351\232\220\350\227\217\345\215\241\346\247\275", nullptr));
        hidemenu->setText(QCoreApplication::translate("MainWindow", "\351\232\220\350\227\217\350\217\234\345\215\225\346\214\211\351\222\256", nullptr));
        nosun->setText(QCoreApplication::translate("MainWindow", "\344\270\215\346\216\211\351\230\263\345\205\211", nullptr));
        unlockglod->setText(QCoreApplication::translate("MainWindow", "\350\247\243\351\224\201\351\207\221\345\220\221\346\227\245\350\221\265", nullptr));
        allowrunback->setText(QCoreApplication::translate("MainWindow", "\345\205\201\350\256\270\345\220\216\345\217\260\350\277\220\350\241\214", nullptr));
        more->setText(QCoreApplication::translate("MainWindow", "\346\233\264\345\244\232\345\212\237\350\203\275\346\225\254\350\257\267\346\234\237\345\276\205\357\274\201", nullptr));
        sunchange->setText(QCoreApplication::translate("MainWindow", "\351\230\263\345\205\211\344\277\256\346\224\271", nullptr));
        quickset->setText(QCoreApplication::translate("MainWindow", "\344\270\200\351\224\256\346\226\227\350\233\220\350\233\220", nullptr));
        resetall->setText(QCoreApplication::translate("MainWindow", "\351\207\215\347\275\256", nullptr));
        maintable->setTabText(maintable->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\346\270\270\346\210\217\350\256\276\347\275\256", nullptr));
        main_menu->setTitle(QCoreApplication::translate("MainWindow", "\344\270\273\347\225\214\351\235\242", nullptr));
        plant_menu->setTitle(QCoreApplication::translate("MainWindow", "\346\224\276\347\275\256\346\244\215\347\211\251", nullptr));
        zombie_menu->setTitle(QCoreApplication::translate("MainWindow", "\346\224\276\347\275\256\345\203\265\345\260\270", nullptr));
        help_menu->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
        version_menu->setTitle(QCoreApplication::translate("MainWindow", "\347\211\210\346\234\254\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
