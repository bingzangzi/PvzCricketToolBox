#ifndef CUSTOMPLANTPLACE_H
#define CUSTOMPLANTPLACE_H
#pragma once
#include <QWidget>
#include <QListView>
#include <QRunnable>
#include <QThreadPool>
#include <QObject>
#include <QThread>
#include <QComboBox>
#include <QOverload>
#include <QGridLayout>
#include <QCheckBox>
#include <QTimer>
#include <QMessageBox>
#include <QMetaObject>
#include <QLineEdit>
#include <QRegularExpression>
#include <QStringList>
#include <QHBoxLayout>
#include "headfile.h"
namespace Ui {
class customplantplace;
class PlantBloodMoniter;
class PlantMoniter;//写完上面那个bloodmoniter后发现一次运行过多线程对cpu负载很大，干脆写到一个线程里通过循环更新，上面那个就不start了，就相当于一个结构体吧（懒得改了，屎山代码里有屎也很正常）
}


class PlantBloodMoniter
{
public:
    int object_type;
    int object_row;
    int object_col;
    int object_blood;
    int object_attack_interval;
    uint32_t object_address;
};

class PlantMoniter:public QThread
{
    Q_OBJECT
public:
    vector<PlantBloodMoniter*> moniters;
    bool thread_survive=false;
    uint32_t nextplantposiition=-1;
    bool blood_moniter=false;
    vector<int>pointer;
    bool SaveCheck()
    {
        if(!CheckGameOn())return false;;//检查游戏是否运行
        if(!CheckBoardOn()) return false;//检查关卡是否运行
        return true;
    }

signals:
    void updateValues(int changetype,int p0,int p1);
    void threadend();

private:
    void run() override{
        auto origincount=ReadMemory<uint32_t>({lawn,board,plant_curren_count});
        while(thread_survive){
        if(!thread_survive) return;
            if(!SaveCheck()) {
                thread_survive=false;
               // break;
            }
            for(int i=0;i<moniters.size();i++){
                if(ReadMemory<bool>({moniters[i]->object_address+plant_dead})){
                    if(thread_survive)emit updateValues(1,moniters[i]->object_row*10+moniters[i]->object_col,pointer[i]);
                    moniters.erase(moniters.begin()+i);//检查是否死亡
                    pointer.erase(pointer.begin()+i);
                    i--;
                    nextplantposiition=ReadMemory<uint32_t>({lawn,board,plant_next_plant_position});
                    continue;
                }
                auto newblood=ReadMemory<uint32_t>({moniters[i]->object_address+plant_blood});
                if(newblood!=moniters[i]->object_blood){
                    moniters[i]->object_blood=newblood;
                    if(thread_survive)emit updateValues(2,moniters[i]->object_row*10+moniters[i]->object_col,pointer[i]);
                    continue;

                }
                if(moniters[i]->object_blood==0)WriteMemory<bool>(true,{moniters[i]->object_address+plant_dead});
            }
            auto new_nextplantposiition=ReadMemory<uint32_t>({lawn,board,plant_next_plant_position});
            auto nowcount=ReadMemory<uint32_t>({lawn,board,plant_curren_count});
            if(new_nextplantposiition!=nextplantposiition&&nowcount>origincount)
            {
               if(thread_survive) emit updateValues(3,-1,-1);//检查是否产生植物数量是否发生变化,或者说是否有新植物种植
            }
            nextplantposiition = new_nextplantposiition;
            origincount=ReadMemory<uint32_t>({lawn,board,plant_curren_count});
            std::chrono::milliseconds sleepDuration(20);
            std::this_thread::sleep_for(sleepDuration);
        }
        emit threadend();
    }
};


class customplantplace : public QWidget
{
    Q_OBJECT

public:
    explicit customplantplace(QWidget *parent = nullptr);
    ~customplantplace();
    int now_map_row=0;

    struct InfoDisplay{
        QCheckBox *check;
        QHBoxLayout *layout;
        QComboBox *combobox;
        QLineEdit *text;
        int row;
        int col;
        vector<int> planttype;
        vector<PlantBloodMoniter*> plantmoniters;
    };

    struct CustomPlant{
        QHBoxLayout* layout;
        QComboBox* combobox;
        QLineEdit* bloodline;
        QLineEdit* intervalline;
        int row;
        int col;
    };

    vector<InfoDisplay*> plant_info_list;//植物信息
    uint32_t next_plant_position=999999999;//下一个植物种植的偏移位置
    bool is_game_on=false;//游戏是否运行
    bool is_board_on=false;//关卡是否运行
    bool SaveCheck();//安全检查
    void UpdatePlantList();//更新植物列表
    void InitPlantList();
    void ShowGrid();
    void clearLayout(QLayout *layout);
    void StartMoniter();
    void InitCustomPlantList();
    PlantMoniter* pMoniter=nullptr;
    vector<CustomPlant*> custom_info_list;
    QTimer* timer=nullptr;

    const char* plant_book[48] = {
        "豌豆射手","向日葵","樱桃炸弹","坚果","土豆雷","寒冰射手","大嘴花","双发射手",
        "小喷菇","阳光菇","大喷菇","墓碑吞噬者","魅惑菇","胆小菇","寒冰菇","毁灭菇",
        "睡莲","窝瓜","三线射手","缠绕海草","火爆辣椒","地刺","火炬","高坚果",
        "海蘑菇","路灯花","仙人掌","三叶草","裂荚射手","杨桃","南瓜头","磁力菇",
        "卷心菜投手","花盆","玉米投手","咖啡豆","大蒜","叶子保护伞","金盏花","西瓜投手",
        "机枪射手","双子向日葵","忧郁蘑菇","香蒲","冰西瓜投手","吸金磁","地磁王","玉米加农炮"
    }; //原版图鉴植物

private:
    Ui::customplantplace *ui;

protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_exitbutton_clicked();
    void on_updateplant_clicked();
    void showgrid_slot(bool);
    void on_isrealtime_stateChanged(int arg1);
    void on_deleteplant_clicked();
    void on_clear_clicked();
    void on_plantplace_clicked();
};

#endif // CUSTOMPLANTPLACE_H
