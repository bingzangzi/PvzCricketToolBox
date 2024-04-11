#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once
#include <QMainWindow>
#include <QDateTime>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDesktopServices>
#include <QFileInfo>
#include <QStringList>
#include <QProcess>
#include <QFileDialog>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>
#include <QStringListModel>
#include <QListView>
#include <QListWidget>
#include <QSpinBox>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QApplication>
#include <QClipboard>
#include <QRadioButton>
#include <QRegularExpression>
#include <QInputDialog>
#include "headfile.h"
#include "game_info.h"
#include "getvalue.h"
#include "versioninfo.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class ZombieInfoUpdateThread;
class ZombieStatusMoniter;
class NewZombieMoniter;
class PlantInfoUpdateThread;
class PlantStatusMoniter;
class NewPlantMoniter;
class SpiceThread;
class MainWindow;
class slotsetplant;
class slotplantmoniter;
class ZombiePutThread;
class BlindBoxSearch;
class BlindBoxMoniter;
class BlindBoxPut;
}
QT_END_NAMESPACE

class ZombieInfoUpdateThread:public QThread
{
    Q_OBJECT
public:
    ZombieInfoStruct zombiepointer;
    bool thread_survive;
    ~ZombieInfoUpdateThread() override
    {
        if (isRunning()) {
            quit();
            wait();
        }
    }

signals:
    void updatefinied(ZombieInfoStruct );
protected:
    void run()override
    {

        while(thread_survive){
            if(!CheckBoardOn()){
                return;
            }
            zombiepointer.type=ReadMemory<uint32_t>({zombiepointer.addr+zombie_type});
            zombiepointer.row=ReadMemory<uint32_t>({zombiepointer.addr+zombie_row});
            zombiepointer.x=ReadMemory<float>({zombiepointer.addr+zombie_xcorordinate});
            zombiepointer.y=ReadMemory<float>({zombiepointer.addr+zombie_ycorordinate});
            zombiepointer.col=zombiepointer.x/80;
            zombiepointer.armortype_1=ReadMemory<uint32_t>({zombiepointer.addr+zombie_armor1_isexist});
            zombiepointer.armortype_2=ReadMemory<uint32_t>({zombiepointer.addr+zombie_armor2_isexist});
            zombiepointer.bodyblood=ReadMemory<uint32_t>({zombiepointer.addr+zombie_body_blood});
            if(zombiepointer.armortype_1!=0)zombiepointer.armorblood1=ReadMemory<uint32_t>({zombiepointer.addr+zombie_armor1_body});
            if(zombiepointer.armortype_2!=0)zombiepointer.armorblood2=ReadMemory<uint32_t>({zombiepointer.addr+zombie_armor2_body});
            zombiepointer.shingingtime=ReadMemory<uint32_t>({zombiepointer.addr+zombie_shining_time});
            zombiepointer.frozentime=ReadMemory<uint32_t>({zombiepointer.addr+zombie_freeze_time});
            zombiepointer.buttertime=ReadMemory<uint32_t>({zombiepointer.addr+zombie_butter_time});
            zombiepointer.slowingtime=ReadMemory<uint32_t>({zombiepointer.addr+zombie_slow_down_time});
            zombiepointer.armorshiningtime=ReadMemory<uint32_t>({zombiepointer.addr+zombie_armor_shaking_time});
            zombiepointer.armorshaketime=ReadMemory<uint32_t>({zombiepointer.addr+zombie_row});
            zombiepointer.ishypnoed=ReadMemory<bool>({zombiepointer.addr+zombie_ishypno});
            zombiepointer.isvisible=ReadMemory<bool>({zombiepointer.addr+zombie_visible});
            zombiepointer.isneardead=ReadMemory<bool>({zombiepointer.addr+zombie_neardead});
            zombiepointer.iseatgarlic=ReadMemory<bool>({zombiepointer.addr+zombie_eat_garlic});
            zombiepointer.isinwater=ReadMemory<bool>({zombiepointer.addr+zombie_in_water});
            zombiepointer.isnohand=ReadMemory<bool>({zombiepointer.addr+zombie_no_hand});
            bool isdead=ReadMemory<bool>({zombiepointer.addr+zombie_dead});
            if(isdead) {
                thread_survive=false;
                continue;
            }
            emit updatefinied(zombiepointer);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }
};

class ZombieStatusMoniter:public QThread
{
    Q_OBJECT
public:
    bool thread_survive;
    vector<ZombieInfoStruct*> zombielist;
    unordered_set<uint32_t> addrlist;
signals:
    void zombiedeadinfo(ZombieInfoStruct,int num,int state);
    void findnewzombie(int type,int body,int armor1,int armor2,int num,int row,bool);
    void abnormaltermi();
protected:
    void run()override
    {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 僵尸状态监测线程开始运行。\n").arg(currentTime);
            out.flush();
        }
        while(thread_survive){
            if(!CheckBoardOn()){
                thread_survive=false;
                emit abnormaltermi();
                continue;
            }
            for(int iter=0;iter<zombielist.size();iter++){
                ZombieInfoStruct* zomb=zombielist[iter];
                bool isdead=ReadMemory<bool>({zomb->addr+zombie_dead});
                if(isdead){
                    zomb->deadtime=QDateTime::currentDateTime();
                    emit zombiedeadinfo(*zomb,iter,0);
                    addrlist.erase(zomb->addr);
                    delete zomb;
                    zombielist.erase(zombielist.begin()+iter);
                    iter--;
                    continue;
                }
                int type=ReadMemory<uint32_t>({zomb->addr+zombie_type});
                if(type!=zomb->type){
                    zomb->deadtime=QDateTime::currentDateTime();
                    emit zombiedeadinfo(*zomb,iter,1);
                    zomb->type=type;
                    zomb->bodyblood=ReadMemory<uint32_t>({zomb->addr+zombie_body_blood});
                    zomb->row=ReadMemory<uint32_t>({zomb->addr+zombie_row});
                    zomb->armorblood1=ReadMemory<uint32_t>({zomb->addr+zombie_armor1_body});
                    zomb->armorblood2=ReadMemory<uint32_t>({zomb->addr+zombie_armor2_body});
                    zomb->ishypnoed=ReadMemory<bool>({zomb->addr+zombie_ishypno});
                    zomb->initbodyblood=zomb->bodyblood;
                    zomb->initarmor_1blood=zomb->armorblood1;
                    zomb->initarmor_2blood=zomb->armorblood2;
                    zomb->findtime=QDateTime::currentDateTime();
                    emit findnewzombie(zomb->type,zomb->bodyblood,zomb->armorblood1,zomb->armorblood2,iter,zomb->row,zomb->ishypnoed);
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(80));
        }
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 僵尸状态监测线程结束运行。\n").arg(currentTime);
            out.flush();
        }
    }
};

class NewZombieMoniter:public QThread
{
    Q_OBJECT
public:
    bool thread_survive;
    uint32_t zombieoff;
    ZombieStatusMoniter* zstamoniter;
signals:
    void abnormaltermi();
    void findnewzombie(int type,int body,int armor1,int armor2,int num,int row,bool);
protected:
    void run()override
    {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 僵尸数量监测线程开始运行。\n").arg(currentTime);
            out.flush();
        }
        while(thread_survive){
            if(!CheckBoardOn()){
                thread_survive=false;
                emit abnormaltermi();
                continue;
            }
            uint32_t zombiemax=ReadMemory<uint32_t>({lawn,board,zombie_count_max});
            for(size_t i=0;i<zombiemax;i++){
                uint32_t currentaddr=zombieoff+zombie_struct_size*i;
                if(zstamoniter->addrlist.find(currentaddr)!=zstamoniter->addrlist.end())continue;
                bool isdead=ReadMemory<bool>({currentaddr+zombie_dead});
                if(isdead) continue;
                ZombieInfoStruct* newzombie=new ZombieInfoStruct;
                newzombie->type=ReadMemory<uint32_t>({currentaddr+zombie_type});
                newzombie->bodyblood=ReadMemory<uint32_t>({currentaddr+zombie_body_blood});
                newzombie->armorblood1=ReadMemory<uint32_t>({currentaddr+zombie_armor1_body});
                newzombie->armorblood2=ReadMemory<uint32_t>({currentaddr+zombie_armor2_body});
                newzombie->row=ReadMemory<uint32_t>({currentaddr+zombie_row});
                newzombie->ishypnoed=ReadMemory<bool>({currentaddr+zombie_ishypno});
                newzombie->initbodyblood=newzombie->bodyblood;
                newzombie->initarmor_1blood=newzombie->armorblood1;
                newzombie->initarmor_2blood=newzombie->armorblood2;
                newzombie->id=i;
                newzombie->addr=currentaddr;
                newzombie->findtime=QDateTime::currentDateTime();
                zstamoniter->zombielist.push_back(newzombie);
                zstamoniter->addrlist.insert(currentaddr);
                emit findnewzombie(newzombie->type,newzombie->bodyblood,newzombie->armorblood1,newzombie->armorblood2,i,newzombie->row,newzombie->ishypnoed);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(80));
        }
        zstamoniter->thread_survive=false;
        zstamoniter->quit();
        zstamoniter->wait();
        delete zstamoniter;
        zstamoniter=nullptr;
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 僵尸数量监测线程结束运行。\n").arg(currentTime);
            out.flush();
        }
    }
};


class PlantInfoUpdateThread:public QThread
{
    Q_OBJECT
public:
    PlantInfoStruct* plantpointer;
    int num;

    ~PlantInfoUpdateThread() override
    {
        if (isRunning()) {
            quit();
            wait();
        }
    }

signals:
    void updatefinied(int row, int col,int num,int status);
protected:
    void run()override
    {
        if(!CheckBoardOn()){
            return;
        }
        if(!plantpointer) return;
        plantpointer->blood=ReadMemory<uint32_t>({plantpointer->addr+plant_blood});
        plantpointer->interval=ReadMemory<uint32_t>({plantpointer->addr+plant_attack_interval});
        plantpointer->isableshine=ReadMemory<bool>({plantpointer->addr+plant_enable_shine});
        if(plantpointer->isableshine)plantpointer->flashingtime=ReadMemory<uint32_t>({plantpointer->addr+plant_flash_time});
        if(plantpointer->isableshine)plantpointer->shiningtime=ReadMemory<uint32_t>({plantpointer->addr+plant_shine_time});
        plantpointer->towards=ReadMemory<int>({plantpointer->addr+plant_towards});
        plantpointer->isinvisible=ReadMemory<bool>({plantpointer->addr+plant_invisible});
        plantpointer->issquished=ReadMemory<bool>({plantpointer->addr+plant_squished});
        plantpointer->issleep=ReadMemory<bool>({plantpointer->addr+plant_asleep});
        plantpointer->shoottime=ReadMemory<uint32_t>({plantpointer->addr+plant_shoot_time});
        emit updatefinied(plantpointer->row,plantpointer->col,num,0);
    }
};

class PlantStatusMoniter:public QThread
{
    Q_OBJECT
public:
    bool thread_survive;
    int current_plant_book_size;
    vector<vector<PlantInfoStruct*>> plantlist;
    unordered_set<uint32_t> addrlist;
signals:
    void plantchange(int row,int col,int num,int status);
    void abnormaltermi();
protected:
    void run()override
    {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 植物状态监测线程开始运行。\n").arg(currentTime);
            out.flush();
        }
        while(thread_survive){
            if(!CheckBoardOn()){
                thread_survive=false;
                emit abnormaltermi();
                continue;
            }
            for(int i=0;i<60;i++){
                if(plantlist[i].size()==0)continue;
                for(auto iter=plantlist[i].begin();iter!=plantlist[i].end();)
                {
                    PlantInfoStruct* cplant = *iter;
                    bool isdead=ReadMemory<bool>({cplant->addr+plant_dead});
                    if(isdead){
                        emit plantchange(cplant->row,cplant->col,distance(plantlist[i].begin(), iter),1 );
                        addrlist.erase(cplant->addr);
                        delete cplant;
                        iter=plantlist[i].erase(iter);
                        continue;
                    }
                    cplant->type=ReadMemory<uint32_t>({cplant->addr+plant_type});
                    if(cplant->type>=current_plant_book_size){
                        emit plantchange(cplant->row,cplant->col,distance(plantlist[i].begin(), iter),1 );
                        addrlist.erase(cplant->addr);
                        delete *iter;
                        iter=plantlist[i].erase(iter);
                        continue;
                    }
                    PlantInfoUpdateThread* pupdate=new PlantInfoUpdateThread;
                    pupdate->plantpointer=cplant;
                    pupdate->num=distance(plantlist[i].begin(), iter);
                    pupdate->start();
                    connect(pupdate,&PlantInfoUpdateThread::updatefinied,this,&PlantStatusMoniter::plantchange);
                    iter++;
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(75));
        }
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 植物状态监测线程结束运行。\n").arg(currentTime);
            out.flush();
        }
    }
};

class NewPlantMoniter:public QThread
{
    Q_OBJECT
public:
    bool thread_survive;
    int current_plant_book_size;
    uint32_t plantoff;
    PlantStatusMoniter* pstamoniter;
signals:
    void abnormaltermi();
protected:
    void run()override
    {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 植物数量监测线程开始运行。\n").arg(currentTime);
            out.flush();
        }
        while(thread_survive){
            if(!CheckBoardOn()){
                thread_survive=false;
                emit abnormaltermi();
                continue;
            }
            uint32_t plant_max=ReadMemory<uint32_t>({lawn,board,plant_count_max});
            for(size_t i=0;i<plant_max;i++){
                uint32_t currentaddr=plantoff+i*plant_single_size;
                if(pstamoniter->addrlist.find(currentaddr)!=pstamoniter->addrlist.end()) {
                    continue;
                }
                bool isdead=ReadMemory<bool>({currentaddr+plant_dead});
                if(isdead) continue;
                PlantInfoStruct* newplant=new PlantInfoStruct;
                newplant->addr=currentaddr;
                newplant->type=ReadMemory<uint32_t>({newplant->addr+plant_type});
                if(newplant->type>=current_plant_book_size) {
                    delete newplant;
                    continue;
                }
                newplant->number=i;
                newplant->col=ReadMemory<uint32_t>({newplant->addr+plant_col});
                newplant->row=ReadMemory<uint32_t>({newplant->addr+plant_row});
                if(newplant->col>=10||newplant->row>=6||newplant->row<0||newplant->col<0){
                    delete newplant;
                    continue;
                }
                newplant->type=ReadMemory<uint32_t>({newplant->addr+plant_type});
                pstamoniter->addrlist.insert(currentaddr);
                pstamoniter->plantlist[newplant->row*10+newplant->col].push_back(newplant);
            }
             std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
        pstamoniter->thread_survive=false;
        pstamoniter->quit();
        pstamoniter->wait();
        delete pstamoniter;
        pstamoniter=nullptr;
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 植物数量监测线程结束运行。\n").arg(currentTime);
            out.flush();
        }
    }
};

class BlindBoxPut:public QThread
{
    Q_OBJECT
public:
    bool isforbid;
    int row;
    float x;
    uint32_t addr;
protected:
    void run()override
    {
       PutRandZombie_randmode(isforbid,row,x,addr);
    }
};

class BlindBoxMoniter:public QThread
{
    Q_OBJECT
public:
    vector<uint32_t> blindboxzombieaddr;
    unordered_set<uint32_t>chechblindboxzombieaddr;
    uint32_t zombieoffsetaddr;
    bool thread_survive=false;
    int boxtype;
    map<uint32_t,bool>is_equipped_one;
    map<uint32_t,bool> is_equipped_two;
    bool is_forbid=false;
    BlindBoxPut* put;
signals:
    void abnormaltermi();
protected:
    void run()override
    {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 盲盒监测线程开始运行。\n").arg(currentTime);
            out.flush();
        }
        while(thread_survive){
            if(!CheckBoardOn()){
                thread_survive=false;
                emit abnormaltermi();
                continue;
            }
            for(int i=0;i<blindboxzombieaddr.size();i++){
                bool isdead=ReadMemory<bool>({blindboxzombieaddr[i]+zombie_dead});
                uint32_t status=ReadMemory<uint32_t>({blindboxzombieaddr[i]+zombie_status});
                if(isdead||status!=0){
                    chechblindboxzombieaddr.erase(blindboxzombieaddr[i]);
                    blindboxzombieaddr.erase(blindboxzombieaddr.begin()+i);
                    i--;
                    continue;
                }
                uint32_t ctype=ReadMemory<uint32_t>({blindboxzombieaddr[i]+zombie_type});
                if(ctype!=boxtype){
                    chechblindboxzombieaddr.erase(blindboxzombieaddr[i]);
                    blindboxzombieaddr.erase(blindboxzombieaddr.begin()+i);
                }
                uint32_t blood1=0;
                uint32_t blood2=0;
                if(is_equipped_one[blindboxzombieaddr[i]]){
                    blood1=ReadMemory<uint32_t>({blindboxzombieaddr[i]+zombie_armor1_body});
                }
                if(is_equipped_two[blindboxzombieaddr[i]]){
                    blood2=ReadMemory<uint32_t>({blindboxzombieaddr[i]+zombie_armor2_body});
                }
                uint32_t blood=ReadMemory<uint32_t>({blindboxzombieaddr[i]+zombie_body_blood});
                bool isneardead=ReadMemory<bool>({blindboxzombieaddr[i]+zombie_neardead});
                if(((is_equipped_one[blindboxzombieaddr[i]]&&is_equipped_two[blindboxzombieaddr[i]]&&blood2<20&&blood1<20))||
                    (is_equipped_one[blindboxzombieaddr[i]]&&!is_equipped_two[blindboxzombieaddr[i]]&&blood1<20)||
                    (!is_equipped_one[blindboxzombieaddr[i]]&&is_equipped_two[blindboxzombieaddr[i]]&&blood2<20)
                    ||blood<20||!isneardead){
                    uint32_t row=ReadMemory<uint32_t>({blindboxzombieaddr[i]+zombie_row});
                    float x=ReadMemory<float>({blindboxzombieaddr[i]+zombie_xcorordinate});
                    put->isforbid=is_forbid;
                    put->row=row;
                    put->x=x;
                    put->start();
                    WriteMemory<bool>(true,{blindboxzombieaddr[i]+zombie_dead});
                    chechblindboxzombieaddr.erase(blindboxzombieaddr[i]);
                    blindboxzombieaddr.erase(blindboxzombieaddr.begin()+i);
                    i--;
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(45));
        }
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 盲盒监测线程结束运行。\n").arg(currentTime);
            out.flush();
        }
    }
};

class BlindBoxSearch:public QThread
{
    Q_OBJECT
public:
    BlindBoxMoniter* bMoniter;
    bool thread_survive=false;
    int boxtype;
    uint32_t zombieoffsetaddr;
signals:
    void abnormaltermi();
protected:
    void run()override
    {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 盲盒搜索线程开始运行。\n").arg(currentTime);
            out.flush();
        }
        while(thread_survive)
        {
            if(!CheckBoardOn()){
                thread_survive=false;
                emit abnormaltermi();
                continue;
            }
            uint32_t zombiecountmax=ReadMemory<uint32_t>({lawn,board,zombie_count_max});
            for(size_t i=0;i<zombiecountmax;i++){
                uint32_t currentaddr=zombieoffsetaddr+zombie_struct_size*i;
                if(bMoniter->chechblindboxzombieaddr.find(currentaddr)!=bMoniter->chechblindboxzombieaddr.end()) continue;
                uint32_t ctype=ReadMemory<uint32_t>({currentaddr+zombie_type});
                if(ctype!=boxtype) continue;
                uint32_t checkone=ReadMemory<uint32_t>({currentaddr+zombie_armor1_isexist});
                if(checkone) bMoniter->is_equipped_one[currentaddr]=true;
                uint32_t checktwo=ReadMemory<uint32_t>({currentaddr+zombie_armor2_isexist});
                if(checktwo) {
                    bMoniter->is_equipped_two[currentaddr]=true;
                }
                bool isdead=ReadMemory<bool>({currentaddr+zombie_dead});
                if(isdead)continue;
                bMoniter->blindboxzombieaddr.push_back(currentaddr);
                bMoniter->chechblindboxzombieaddr.insert(currentaddr);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(45));
            zombiecountmax=ReadMemory<uint32_t>({lawn,board,zombie_count_max});
        }
        bMoniter->thread_survive=false;
        bMoniter->exit();
        bMoniter->wait();
        delete bMoniter;
        bMoniter=nullptr;
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 盲盒搜索线程结束运行。\n").arg(currentTime);
            out.flush();
        }
    }
};


class SpiceThread : public QThread {
    Q_OBJECT
public:
    SpiceThread(QObject* parent = nullptr) : QThread(parent) {}

    void pause() {
        QMutexLocker locker(&mutex);
        paused = true;
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 自动僵尸放置线程暂停。\n").arg(currentTime);
            out.flush();
        }
    }

    void resume() {
        QMutexLocker locker(&mutex);
        paused = false;
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 自动僵尸放置线程恢复。\n").arg(currentTime);
            out.flush();
        }
        condition.wakeAll();
    }

    void stop() {
        QMutexLocker locker(&mutex);
        stopped = true;
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 自动僵尸放置线程终止。\n").arg(currentTime);
            out.flush();
        }
        condition.wakeAll();
        terminate();
    }

signals:
    void abnormaltermi();

protected:
    void run() override {

        while (!stopped) {
            QMutexLocker locker(&mutex);
            while (paused && !stopped) {
                condition.wait(&mutex);
            }
            locker.unlock();
            if(!CheckBoardOn()){
                stopped=true;
                emit abnormaltermi();
                continue;
            }
            uint32_t maxrow =ReadMemory<uint32_t>({lawn, board, 0x104});
            uint32_t moweroffset = ReadMemory<uint32_t>({lawn, board, lawn_mower});
            auto currenmowers = ReadMemory<uint32_t>({lawn, board, lawn_mower_current_count});

            if (currenmowers == maxrow) {
                std::this_thread::sleep_for(std::chrono::milliseconds(12500));
                continue;
            }

            for (size_t i = 0; i < maxrow; i++) {
                auto nowisdead = ReadMemory<bool>({moweroffset + lawn_mower_isfalse + lawn_mower_next * i});

                if (!nowisdead) continue;

                auto nowmowerrow = ReadMemory<uint32_t>({moweroffset + lawn_mower_row + lawn_mower_next * i});

                SinglePlantPlace(20,nowmowerrow, 10);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(12500));
        }
    }

private:
    QMutex mutex;
    QWaitCondition condition;
    bool paused = false;
    bool stopped = false;
};

class ZombiePutThread : public QThread {
    Q_OBJECT
public:

    void pause() {
        QMutexLocker locker(&mutex);
        paused = true;
        if(pausewithgame){
            WriteMemory<bool>(true,{lawn,board,game_pause});
        }
    }

    void resume() {
        QMutexLocker locker(&mutex);
        paused = false;
        if(pausewithgame){
            WriteMemory<bool>(false,{lawn,board,game_pause});
        }
        condition.wakeAll();
    }

    void stop() {
        QMutexLocker locker(&mutex);
        stopped = true;
        if(pausewithgame){
            WriteMemory<bool>(false,{lawn,board,game_pause});
        }
        condition.wakeAll();
        terminate();
    }

    bool pausewithgame=false;
    bool nomowernozombie=false;
    double current_rate;
    int current_ratetomilli;
    int fragment;
    int fragmentnum;
    vector<int> rowlist;
    vector<int> collist;
    int type;
    int listpoiter;
    int zombiecount=0;
    int totaltime=0;
signals:
    void abnormaltermi();
    void updatetime(int);
    void updatezombiecount();
protected:
    void run() override {
        while (!stopped) {
            QMutexLocker locker(&mutex);
            while (paused && !stopped) {
                condition.wait(&mutex);
            }
            locker.unlock();
            if(!CheckBoardOn()){
                stopped=true;
                emit abnormaltermi();
                continue;
            }
            if(nomowernozombie){
                uint32_t maxrow =ReadMemory<uint32_t>({lawn, board, 0x104});
                uint32_t moweroffset = ReadMemory<uint32_t>({lawn, board, lawn_mower});
                for(int i=0;i<rowlist.size();i++){
                    for (size_t j = 0; j < maxrow; j++) {
                        auto nowisdead = ReadMemory<bool>({moweroffset + lawn_mower_isfalse + lawn_mower_next * j});
                        if (!nowisdead) continue;
                        uint32_t nowmowerrow = ReadMemory<uint32_t>({moweroffset + lawn_mower_row + lawn_mower_next * j});
                        if(rowlist[i]-1==nowmowerrow) {
                            rowlist.erase(rowlist.begin()+i);
                            i--;
                        }
                    }
                }
            }
            PutZombie(type,rowlist,collist);
            emit updatezombiecount();
            for(int i=0;i<fragmentnum;i++){
                if (paused) {
                    QMutexLocker locker(&mutex);
                    condition.wait(&mutex);
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(fragment));
                emit updatetime(fragment);
            }
        }
    }

private:
    QMutex mutex;
    QWaitCondition condition;
    bool paused = false;
    bool stopped = false;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    const char* default_plant_book[52] = {
        "豌豆射手","向日葵","樱桃炸弹","坚果","土豆雷","寒冰射手","大嘴花","双发射手",
        "小喷菇","阳光菇","大喷菇","墓碑吞噬者","魅惑菇","胆小菇","寒冰菇","毁灭菇",
        "睡莲","窝瓜","三线射手","缠绕海草","火爆辣椒","地刺","火炬","高坚果",
        "海蘑菇","路灯花","仙人掌","三叶草","裂荚射手","杨桃","南瓜头","磁力菇",
        "卷心菜投手","花盆","玉米投手","咖啡豆","大蒜","叶子保护伞","金盏花","西瓜投手",
        "机枪射手","双子向日葵","忧郁蘑菇","香蒲","冰西瓜投手","吸金磁","地刺王","玉米加农炮","模仿者","爆炸坚果","巨大坚果","幼苗"
    }; //原版图鉴植物
    QStringList current_plant_book;
    QStringList temp_plant_book;
    vector<QCheckBox*> boxes;
    vector<int> defaultforbid={ 1,2,4,9,11,14,15,17,19,20,21,25,27,31,35,37,38,41,45,47,49,50,51 };
    vector<int> defaultgift = { 16,30,33 };
    bool is_global_forbid_exist=false;
    bool is_randplant_createselections=false;
    vector<QCheckBox*> randplantboxes;
    vector<QHBoxLayout*> freeplantlayouts;
    vector<QComboBox*> freeplant_typeboxes;
    vector<QSpinBox*> freeplant_bloodboxes;
    vector<QSpinBox*> freeplant_intervalboxes;
    bool is_freeplant_createselections=false;
    int randcurrentrow;
    int randcurrentcol;
    int freecurrentrow;
    int freecurrentcol;
    const char* default_zombie_book[33] = {
        "普通僵尸","旗帜","路障","撑杆","铁桶","读报","钢铁门","橄榄",
        "舞王","伴舞","鸭子","潜水","冰车","雪橇","海豚","小丑","气球","矿工","跳跳","雪人","蹦极",
        "扶梯","投篮","白眼","小鬼","僵王","豌豆","坚果","辣椒","机枪","窝瓜","高坚果","红眼"
    };
    QStringList current_zombie_book;
    QStringList temp_zombie_book;
    vector<QCheckBox*> zombieforbidboxes;
    int blindzombie=2;
    struct Ascending {
        bool operator()(const double& lhs, const double& rhs) const {
            return lhs < rhs;
        }
    };
    vector<double>time_list;
    vector<double>rate_list;
    vector<vector<ZombieInfoStruct>> freezombieputlist;
    vector<QComboBox*> freezombieputcombo;
    vector<QCheckBox*> freezombieputcheck;
    QCheckBox *PlantcommonCheckBox;
    vector<QRadioButton*> plantmoniter_check;
    vector<QComboBox*> plantmoniter_type;
    vector<QComboBox*> plantmoniter_type_1;
    vector<QComboBox*> plantmoniter_type_2;
    vector<QComboBox*> plantmoniter_type_3;
    vector<QComboBox*> plantmoniter_type_4;
    vector<QLineEdit*> plantmoniter_blood;
    vector<QLineEdit*> plantmoniter_interval;
    vector<QLineEdit*> plantmoniter_shine;
    vector<QLineEdit*> plantmoniter_flash;
    vector<QCheckBox*> plantmoniter_sleep;
    vector<vector<PlantInfoStruct*>> plantlist;
    vector<DeadZombieStruct> deadzombielist;
    QTextStream zombieoutfile;
    QDateTime StartTime;
    QFile zombiefile;
    struct Base_Value{
        QString name;
        uint32_t addr;
        uint32_t default_value;
        uint32_t value;
    };

    vector<Base_Value> Bullet_Value={{"普通豌豆",0x69f1c8,20,0},{"冰豌豆",0x69f1d4,20,0},{"卷心菜",0x69f1e0,40,0},
                                        {"普通西瓜",0x69f1ec,80,0},{"孢子（蘑菇）",0x69f1f8,20,0},{"冰西瓜",0x69f204,80,0},
                                        {"火豌豆",0x69f210,40,0},{"星星",0x69f21c,20,0},{"尖刺",0x69f228,20,0},{"篮球",0x69f234,75,0},
                                       {"玉米粒",0x69f240,20,0},{"黄油",0x69f258,40,0},{"豌豆僵尸",0x69f264,20,0}};
    vector<Base_Value> Disposable_Value={{"灰烬",0x532fdc,1800,0},{"土豆雷",0x41d931,1800,0},{"窝瓜",0x4607a9,1800,0},{"寒冰菇",0x532493,20,0}};
    vector<Base_Value> Goods_Value={{"普通阳光",0x4309f0,25,0},{"小阳光",0x4309fd,10,0},{"大阳光",0x430a0d,50,0},{"银币",0x430A46,10,0},{"金币",0x430a53,30,0},{"钻石",0x430a63,1000,0}};
    vector<Base_Value> Plant_Cost;
    vector<Base_Value> Plant_Cooltime;


    vector<PlantEffectStruct>plant_effect_inlist;//已经选择了效果


    SpiceThread* autospicy=nullptr;
    ZombiePutThread* zombieput=nullptr;
    BlindBoxMoniter* bMoniter=nullptr;
    BlindBoxSearch* bSearch=nullptr;
    NewPlantMoniter* pMoniter=nullptr;
    NewZombieMoniter* zMoniter=nullptr;
    ZombieInfoUpdateThread* singlezMoniter=nullptr;

    versioninfo* verinfo=nullptr;

    void start_slotplantmoniter();
    void end_slotplantmoniter();
    void comboBoxIndexChangedRow(int index);
    void spinBoxValueChangedRow(int value);
    void comboBoxIndexChangedCol(int index);
    void spinBoxValueChangedCol(int value);
    void son_creatselections_freeplant_clicked();
    void _on_sureupdatezombiebook_clicked();
    void _on_updateplantbook_zombie_clicked();
    void _on_isdefaultplantbook_zombie_stateChanged(int arg1);
    void AutoZombieRowColInit();
    vector<int> QStringListToVector(const QStringList& stringList);
    void AutoZombieChangetableInit();
    void rankchangetable(QTableWidgetItem *item);
    void Initfreezombiegridlayout();
    void ShowFreeZombieInfo(int,int);
    void InitPlantMonitPage();
    void MoniterInfoChange(int,int,int,int);
    void UpdatePlantList();
    void ClearPlantList();
    void PlantInfoChange(int,int );
    void ZombieListSizeAdd(int type,int blood,int armor1,int armor2,int,int,bool);
    void InitZombierealMoniterList();
    void ZombieListDelete(ZombieInfoStruct,int num,int state);
    void ZombieInfoShow(ZombieInfoStruct);
    void InitBaseValue();
    void InitCustomPlant();
    QList<int> extractIntegerNumbers(const QString &input);
    QList<double> extractFloatingPointNumbers(const QString &input);
private slots:
    void closeEvent(QCloseEvent *event);

    void on_lookbyprocess_clicked();

    void on_startlog_stateChanged(int arg1);

    void on_startbypath_clicked();

    void on_sunchange_clicked();

    void on_quickset_clicked();

    void on_resetall_clicked();

    void on_plantInvincible_stateChanged(int arg1);

    void on_nocostsun_stateChanged(int arg1);

    void on_freeplant_stateChanged(int arg1);

    void on_nocool_stateChanged(int arg1);

    void on_nocrater_stateChanged(int arg1);

    void on_noawake_stateChanged(int arg1);

    void on_nolimitonplant_stateChanged(int arg1);

    void on_clearplant_stateChanged(int arg1);

    void on_zombieInvincible_stateChanged(int arg1);

    void on_pausesystemzombie_stateChanged(int arg1);

    void on_zombiepause_stateChanged(int arg1);

    void on_clearallzombies_stateChanged(int arg1);

    void on_passthegame_stateChanged(int arg1);

    void on_unlockglod_stateChanged(int arg1);

    void on_unlockallmode_stateChanged(int arg1);

    void on_lockspade_stateChanged(int arg1);

    void on_hidespade_stateChanged(int arg1);

    void on_hideslot_stateChanged(int arg1);

    void on_hidemenu_stateChanged(int arg1);

    void on_nosun_stateChanged(int arg1);

    void on_autocollect_stateChanged(int arg1);

    void on_pausegame_stateChanged(int arg1);

    void on_allowrunback_stateChanged(int arg1);

    void on_plantplace_clicked();

    void on_plantmoniter_clicked();

    void on_zombieplace_clicked();

    void on_zombiemoniter_clicked();

    void on_isdefaultplantbook_stateChanged(int arg1);

    void on_updateplantbook_clicked();

    void on_sureupdateplantbook_clicked();

    void on_startforbidplace_stateChanged(int arg1);

    void on_globalforbid_clicked();

    void on_rowforbid_clicked();

    void on_colforbid_clicked();

    void on_singleforbid_clicked();

    void on_surerowcol_clicked();

    void on_currentreset_clicked();

    void on_globalreset_clicked();

    void on_sureforbid_clicked();

    void on_randslot_stateChanged(int arg1);

    void on_startforbid_stateChanged(int arg1);

    void on_createselections_clicked();

    void on_forbidaffectrandslot_stateChanged(int arg1);

    void on_randplantreset_clicked();

    void on_startrandplaceplant_clicked();

    void on_radioButton_clicked();

    void on_singleplantplace_clicked();

    void on_enableblood_stateChanged(int arg1);

    void on_enableinterval_stateChanged(int arg1);

    void on_rowtogether_stateChanged(int arg1);

    void on_coltogether_stateChanged(int arg1);

    void on_creatselections_freeplant_clicked();

    void on_suretoplant_free_clicked();

    void on_copy_clicked();

    void on_paste_clicked();

    void on_clearformationtext_clicked();

    void on_clearplant_form_clicked();

    void on_readfile_clicked();

    void on_savaasfile_clicked();

    void on_strtoform_clicked();

    void on_formtostr_clicked();

    void on_isdefaultplantbook_zombie_stateChanged(int arg1);

    void on_updateplantbook_zombie_clicked();

    void on_sureupdatezombiebook_clicked();

    void on_suretosetblindbox_clicked();

    void on_startforbidplace_zombie_stateChanged(int arg1);

    void on_globalreset_2_clicked();

    void on_sureforbid_2_clicked();

    void on_startmower_clicked();

    void on_clearmower_clicked();

    void on_resummower_clicked();

    void on_directputonce_clicked();

    void on_pushButton_clicked();

    void on_pausewithgame_stateChanged(int arg1);

    void on_autospicy_stateChanged(int arg1);

    void on_pauseputting_clicked();

    void on_stopputting_clicked();

    void on_addnode_clicked();

    void on_deletelist_clicked();

    void on_startputting_clicked();

    void on_saveile_autozombie_clicked();

    void on_readfile_autozombie_clicked();

    void on_pushButton_2_clicked();

    void on_randblindboxmode_stateChanged(int arg1);

    void on_addfreezombie_clicked();

    void on_rowcolput_clicked();

    void on_coordinateput_clicked();

    void on_putfreezombie_clicked();

    void on_freezombiedelete_clicked();

    void on_freezombiereset_clicked();

    void on_freezombieput_clicked();

    void on_startplantmoniter_stateChanged(int arg1);

    void on_disappear_stateChanged(int arg1);

    void on_squish_clicked();

    void on_asleep_clicked();

    void on_enableshine_stateChanged(int arg1);

    void on_invisible_clicked();

    void on_left_clicked();

    void on_right_clicked();

    void on_enableshine_clicked();

    void on_moniter_plantshoot_sliderPressed();

    void on_moniter_plantshoot_sliderReleased();

    void on_moniter_plantflash_sliderPressed();

    void on_moniter_plantflash_sliderReleased();

    void on_moniter_plantshine_sliderPressed();

    void on_moniter_plantshine_sliderReleased();

    void on_moniter_plantblood_selectionChanged();

    void on_moniter_plantinterval_selectionChanged();

    void on_moniter_plantblood_editingFinished();

    void on_moniter_plantinterval_editingFinished();

    void on_updateplantlist_clicked();

    void on_clearplantlist_clicked();

    void on_updateplantlist_2_clicked();

    void on_clearplantlist_2_clicked();

    void on_updateplantlist_3_clicked();

    void on_clearplantlist_3_clicked();

    void on_updateplantlist_4_clicked();

    void on_clearplantlist_4_clicked();

    void on_updateplantlist_5_clicked();

    void on_clearplantlist_5_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_starttotal_stateChanged(int arg1);

    void on_realtimefile_stateChanged(int arg1);

    void on_zombiedisapear_stateChanged(int arg1);

    void on_moniter_zombiex_selectionChanged();

    void on_moniter_zombiex_editingFinished();

    void on_moniter_zombiey_selectionChanged();

    void on_moniter_zombiey_editingFinished();

    void on_moniter_zombiebodyblood_selectionChanged();

    void on_moniter_zombiebodyblood_editingFinished();

    void on_moniter_zombiearmorblood1_selectionChanged();

    void on_moniter_zombiearmorblood1_editingFinished();

    void on_moniter_zombiearmorblood2_selectionChanged();

    void on_moniter_zombiearmorblood2_editingFinished();

    void on_moniter_zombieslowtime_sliderPressed();

    void on_moniter_zombieslowtime_sliderReleased();

    void on_moniter_zombiebuttertime_sliderPressed();

    void on_moniter_zombiebuttertime_sliderReleased();

    void on_moniter_zombiefrozetime_sliderPressed();

    void on_moniter_zombiefrozetime_sliderReleased();

    void on_moniter_zombiebodyshinetime_sliderPressed();

    void on_moniter_zombiebodyshinetime_sliderReleased();

    void on_moniter_zombiearmorshinetime_sliderPressed();

    void on_moniter_zombiearmorshinetime_sliderReleased();

    void on_moniter_zombiearmorshaketime_sliderPressed();

    void on_moniter_zombiearmorshaketime_sliderReleased();

    void on_ishypnoed_clicked();

    void on_isvisible_clicked();

    void on_zombie_blowaway_clicked();

    void on_zombie_near_dead_clicked();

    void on_zombie_inwater_clicked();

    void on_zombie_eatgarlic_clicked();

    void on_zombieoutfile_clicked();

    void on_main_exitButton_clicked();

    void on_checkBox_2_stateChanged(int arg1);

    void on_nomowernozombie_stateChanged(int arg1);

    void on_bulletchange_clicked();

    void on_bulletdefault_clicked();

    void on_bulletvalue_currentIndexChanged(int index);

    void on_disposablevalue_currentIndexChanged(int index);

    void on_diposablechange_clicked();

    void on_disposabledefault_clicked();

    void on_goodsvalue_currentIndexChanged(int index);

    void on_goodschange_clicked();

    void on_goodsdefault_clicked();

    void on_plantlistbase_currentIndexChanged(int index);

    void on_plantlistbase_2_currentIndexChanged(int index);

    void on_costchange_clicked();

    void on_coolchange_clicked();

    void on_costdefault_clicked();

    void on_cooldefault_clicked();

    void on_pushButton_13_clicked();

    void on_unlockmemorymaxmiun_stateChanged(int arg1);


    void on_unlockshopitems_stateChanged(int arg1);

    void on_addeffectplant_clicked();

    void on_deleteselectplanteffect_clicked();

    void on_plantaffectongame_clicked();

    void on_cancelaffenctongame_clicked();

    void on_clearallbullet_stateChanged(int arg1);


    void on_savesettings_clicked();

    void on_readsettings_clicked();

    void xorFileData(const QString &filePath);

private:
    Ui::MainWindow *ui;
    bool pausewithgame=false;
    bool is_pauseputting=false;
    bool is_tableediting=false;
    bool is_tabledeleting=false;
    bool is_tableadding=false;
    bool is_timeerroring=false;

    bool plantbloodenable=true;
    bool plantintervalenable=true;
    bool plantleftenable=true;
    bool plantrightenable=true;
    bool plantsleepenable=true;
    bool plantsquishenable=true;
    bool plantshineenableenable=true;
    bool plantinvisibleenable=true;
    bool plantshineenable=true;
    bool plantflashenable=true;
    bool plantshootenable=true;
    vector<bool> plantmoniter_bloodenable;
    vector<bool> plantmoniter_intervalenable;
    vector<bool> plantmoniter_shineenable;
    vector<bool> plantmoniter_flashenable;
    vector<bool> plantmoniter_sleepenable;
    bool zombiexenable=true;
    bool zombieyenable=true;
    bool zombiebodyenable=true;
    bool zombiearmor1_enable=true;
    bool zombiearmor2_enable=true;
    bool zombiehypnoenable=true;
    bool zombievisibleenable=true;
    bool zombieneardeadenable=true;
    bool zombieinwaterenable=true;
    bool zombieeatgarlicenable=true;
    bool zombieslowenable=true;
    bool zombiebutterenable=true;
    bool zombiefreezeenable=true;
    bool zombiebodyshinenable=true;
    bool zombiearmorshineenable=true;
    bool zombiearmorshakeenable=true;

    void savedate();
};

class slotsetplant:public QThread
{
    Q_OBJECT
public:
    int plantbooksize;
    uint32_t mouseslotaddr;
    bool thread_survive=false;
    bool is_forbid=false;
private:
    void run()override
    {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 子线程：子线程：随机卡槽调用\n").arg(currentTime);
            out.flush();
        }
        while(thread_survive){
            if(!CheckBoardOn()){
                if(out.device()){
                    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
                    out<<QString("[%1] slotsetplant监测到关卡退出\n").arg(currentTime);
                    out.flush();
                }
                thread_survive=false;
                break;
            }
            uint32_t isgrabplant=ReadMemory<uint32_t>({mouseslotaddr+mouse_grab_type});
            if(isgrabplant!=1){
                thread_survive=false;
                continue;
            }
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dis(0, plantbooksize-1);
            int temp=dis(gen);
            temp=dis(gen);
            if(is_forbid) while(JudgeifForbid(temp,-1,-1)) temp=dis(gen);
            WriteMemory<uint32_t>(temp,{mouseslotaddr+cursor_plant_type});
            std::chrono::milliseconds sleepDuration(21);
            std::this_thread::sleep_for(sleepDuration);
        }
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 子线程：子线程：随机卡槽结束调用\n").arg(currentTime);
            out.flush();
        }
    }
};

class slotplantmoniter:public QThread
{
    Q_OBJECT
public:
    int plantbooksize;
    uint32_t mouseslotaddr;
    bool thread_survive=false;
    bool isgrabplant=false;
    slotsetplant* setthread=nullptr;
    bool is_forbid=false;
    int imitater;
signals:
         void threadend();
private:
    void run()override
    {
        while(thread_survive){
            if(!CheckBoardOn()){
                if(out.device()){
                    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
                    out<<QString("[%1] slotplantmoniter监测到关卡退出\n").arg(currentTime);
                    out.flush();
                }
                thread_survive=false;
                break;
            }
            uint32_t isgrabplant=ReadMemory<uint32_t>({mouseslotaddr+mouse_grab_type});
            if(isgrabplant!=1) isgrabplant=false;
            else isgrabplant=true;
            if(isgrabplant&&setthread==nullptr){
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> dis(0, plantbooksize-1);
                imitater=dis(gen);
                while(imitater==48) imitater=dis(gen);
                if(is_forbid) while(JudgeifForbid(imitater,-1,-1)||imitater==48) imitater=dis(gen);
                WriteMemory<uint32_t>(imitater,{mouseslotaddr+imitater_type});
                setthread=new slotsetplant;
                setthread->mouseslotaddr=mouseslotaddr;
                setthread->plantbooksize=plantbooksize;
                setthread->thread_survive=true;
                setthread->is_forbid=is_forbid;
                setthread->start();
            }
            else if(!isgrabplant){
                if(setthread){
                    setthread->thread_survive=false;
                    setthread->exit();
                    setthread->wait();
                    delete setthread;
                    setthread=nullptr;
                }
            }
            std::chrono::milliseconds sleepDuration(60);
            std::this_thread::sleep_for(sleepDuration);
        }
        emit threadend();
    }
};



void customMessageHandler();
#endif // MAINWINDOW_H
