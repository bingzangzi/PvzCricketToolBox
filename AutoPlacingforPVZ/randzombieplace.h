#ifndef RANDZOMBIEPLACE_H
#define RANDZOMBIEPLACE_H
#pragma once
#include <QWidget>
#include <QMessageBox>
#include <QTableView>
#include <QThread>
#include <QStandardItemModel>
#include "headfile.h"
namespace Ui {
class randzombieplace;
class ZombieThread;//放置僵尸的线程
class SpicyThread;//检测并放置辣椒的线程
class ZombieSafeCheck;//检查游戏是否正常运行以及内存是否有溢出嫌疑的线程
}

class SpiceThread : public QThread {
    Q_OBJECT
public:
    bool paused = false;
    bool stopped = false;
    int type=20;
signals:

protected:
    void run() override {
        int maxrow = GetRowCount();
        while(!stopped)
        {
            if(paused){
                chrono::duration<double> sleepDuration(0.3);
                for(int i=0;i<50;i++){
                    this_thread::sleep_for(sleepDuration);
                    if(!paused||stopped) break;
                }
                continue;
            }
            uint32_t moweroffset=ReadMemory<uint32_t>({lawn,board,lawn_mower});
            auto currenmowers=ReadMemory<uint32_t>({lawn,board,lawn_mower_current_count});

            if(currenmowers==maxrow) {
                chrono::duration<double> sleepDuration(0.3);
                for(int i=0;i<50;i++){
                    this_thread::sleep_for(sleepDuration);
                    if(paused||stopped) break;
                }
                continue;
            }
            for(size_t i=0;i<maxrow;i++){
                auto nowisdead=ReadMemory<bool>({moweroffset+lawn_mower_isfalse+lawn_mower_next*i});

                if(!nowisdead) continue;
               // count++;
                auto nowmowerrow=ReadMemory<uint32_t>({moweroffset+lawn_mower_row+lawn_mower_next*i});

                PlacePlant(nowmowerrow,10,20);
            }
            chrono::duration<double> sleepDuration(0.3);
            for(int i=0;i<50;i++){
                this_thread::sleep_for(sleepDuration);
                if(paused||stopped) break;
            }
        }
    }
};

class ZombieThread : public QThread {
    Q_OBJECT
public:
    bool paused = false;
    bool stopped = false;
    vector<double> ratetable;
    vector<double> timetable;
    int type;
    int col;
signals:
    void updateValues(int zombies, double rate);
    void threadFinished();

protected:
    void run() override {
        int maxrow = GetRowCount();
        timetable.push_back(99999999);
        ratetable.push_back(99999999);
        int countzombies = 0;
        int currentpoint = 0;
        double counttime = 0;
        int fragment=1;
        while (!stopped) {
            if(paused){
                emit updateValues(countzombies, ratetable[currentpoint]);
                //while(paused);
                chrono::duration<double> sleepDuration(0.5);
                this_thread::sleep_for(sleepDuration);
                continue;
            }
            if(fragment!=1&&fragment!=51)goto finishtiming;
            for (int i = 0; i < maxrow; i++) {
                PlaceZombie(i,col, type);
            }
            countzombies++;
            finishtiming:
            emit updateValues(countzombies, ratetable[currentpoint]); // 发送更新信号
            chrono::duration<double> sleepDuration(ratetable[currentpoint]/50);
            if(fragment==51) fragment=1;
            for(;fragment<=50;fragment++){
                this_thread::sleep_for(sleepDuration);
                if(paused||stopped) break;
            }
            counttime += ratetable[currentpoint]*(fragment-1)/50;
            if (counttime > timetable[currentpoint]*60) currentpoint++;
        }
        exit();
    }
};

class ZombieSafeCheck: public QThread {
    Q_OBJECT
public:
    int status=0;
    //0：正常运行
    //1：游戏关闭
    //2：关卡退出
    //3：僵尸上限
    //4：外部结束
signals:
        void threadFinished();

protected:
    void run() override {
        while(true){
            if(!CheckGameOn()){
                status=1;
                break;
            }
            if(!CheckBoardOn()){
                status=2;
                break;
            }
            auto zombiemaxcount=ReadMemory<uint32_t>({lawn,board,zombie_count_max});
            if(zombiemaxcount>900){
                status=3;
                break;
            }
            if(status==4) break;
            status=0;
            chrono::duration<double> sleepDuration(0.1);
            this_thread::sleep_for(sleepDuration);
        }
    }
};

class randzombieplace : public QWidget
{
    Q_OBJECT

public:
    explicit randzombieplace(QWidget *parent = nullptr);
    ~randzombieplace();
    double inititial_rate=0;
    vector<double>time_list;
    vector<double>rate_list;
    bool iffinishinput=false;
    int currenttotalzombies=0;
    double currentrate=0;

public slots:
    void PauseThread();
    void StopThread();
    void StartThread();
    void stopThread();
    void autospicythread();
    void setgamepause_zom();
    void safecheckstop();

private:
    Ui::randzombieplace *ui;
    ZombieThread *thread;
    SpiceThread *spicythread;
    ZombieSafeCheck *safecheck;

protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_returnmain_clicked();
    void on_resetall_clicked();
    void on_skipandput_clicked();
    void on_initratesure_clicked();
    void on_addsure_clicked();
    void on_deletedata_clicked();
    void on_addfinish_clicked();
    void on_beginput_clicked();
    void on_startmower_clicked();
    void on_clearmower_clicked();
    void on_resumemower_clicked();
    void on_killallzombies_clicked();
    void on_editdatalist_clicked();
};


#endif // RANDZOMBIEPLACE_H
