#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once
#include <QMainWindow>
#include <QMessageBox>
#include <qstring.h>

#include "headfile.h"
#include "randplantplace.h"
#include "customplantplace.h"
#include "randzombieplace.h"
#include "customzombieplace.h"
#include "versioninfo.h"
#include "help.h"
#include "mythread.h"
QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_main_commitButton_clicked();

    void on_main_exitButton_clicked();

    void on_main_plantplace_clicked();

    void on_pushButton_2_clicked();

    void open_versioninfo();

    void open_randplantplace();

    void open_customplantplace();

    void open_randzombieplace();

    void open_customzombieplace();

    void open_browshelpinfo();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_sunchange_clicked();

    void on_nocostsun_stateChanged(int arg1);

    void on_allowrunback_stateChanged(int arg1);

    void on_pausegame_stateChanged(int arg1);

    void on_freeplant_stateChanged(int arg1);

    void on_lockspade_stateChanged(int arg1);

    void on_hideslot_stateChanged(int arg1);

    void on_plantInvincible_stateChanged(int arg1);

    void on_unlockallmode_stateChanged(int arg1);

    void on_unlockglod_stateChanged(int arg1);

    void on_passthegame_stateChanged(int arg1);

    void on_hidespade_stateChanged(int arg1);

    void on_hidemenu_stateChanged(int arg1);

    void on_nosun_stateChanged(int arg1);

    void on_autocollect_stateChanged(int arg1);

    void on_zombieInvincible_stateChanged(int arg1);

    void on_noawake_stateChanged(int arg1);

    void on_pausesystemzombie_stateChanged(int arg1);

    void on_zombiepause_stateChanged(int arg1);

    void on_nocrater_stateChanged(int arg1);

    void on_nocool_stateChanged(int arg1);

    void on_clearallzombies_stateChanged(int arg1);

    void on_clearplant_stateChanged(int arg1);

    void on_nolimitonplant_stateChanged(int arg1);


    void on_resetall_clicked();

    void on_quickset_clicked();

    void on_selectall_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
