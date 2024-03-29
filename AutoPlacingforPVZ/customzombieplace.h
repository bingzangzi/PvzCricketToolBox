#ifndef CUSTOMZOMBIEPLACE_H
#define CUSTOMZOMBIEPLACE_H
#pragma once
#include <QWidget>
#include <QMessageBox>
#include <QThread>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "headfile.h"
namespace Ui {
class customzombieplace;
class ZombieMoniter;
}

class ZombieMoniter:public QThread
{
    Q_OBJECT
public:
    struct ZombieStruct{
        int type;
        int body_blood;
        int armor1_type;
        int armor2_type;
        int armor1_blood;
        int armor2_blood;
        int slow_down_time;
        int butter_down_time;
        int froze_down_time;
        int shining_down_time;
        int row;
        int x_corordinate;
        int y_corordinate;
        bool ishypno;
        uint32_t zombie_address;

    };
    vector<ZombieStruct> zombie_info_list;
    unordered_set<size_t> offsetnum;
    bool thread_survive=false;
    bool SaveCheck()
    {
        if(!CheckGameOn())return false;;//检查游戏是否运行
        if(!CheckBoardOn()) return false;//检查关卡是否运行
        return true;
    }

signals:
    void updateValue(uint32_t num,QDateTime currentDateTime);
    void deadzombie(uint32_t num,QDateTime currentDateTime);

private:
    void run() override
    {
        while(thread_survive){
            if(!SaveCheck()) {
                thread_survive=false;
                break;
            }
            uint32_t zombieoffset=ReadMemory<uint32_t>({lawn,board,zombie_offset});
            uint32_t maxzombiecount=ReadMemory<uint32_t>({lawn,board,zombie_count_max});
            uint32_t currentzombiecount=ReadMemory<uint32_t>({lawn,board,zombie_current_count});
            //qDebug()<<offsetnum.size()<<" "<<currentzombiecount<<" "<<zombie_info_list.size()<<"\n";
            for(size_t i=0;i<maxzombiecount;i++)
            {
                bool isdead=ReadMemory<bool>({zombieoffset+i*zombie_struct_size+zombie_dead});
                if(isdead) {
                    QDateTime currentDateTime = QDateTime::currentDateTime();
                    emit deadzombie(i,currentDateTime);
                    offsetnum.erase(i);
                    continue;
                }
                zombie_info_list[i].zombie_address=i*zombie_struct_size+zombieoffset;
                zombie_info_list[i].x_corordinate=ReadMemory<uint32_t>({zombie_info_list[i].zombie_address+zombie_xcorordinate});
                //if(newzomb.x_corordinate>810) continue;
                zombie_info_list[i].y_corordinate=ReadMemory<uint32_t>({zombie_info_list[i].zombie_address+zombie_ycorordinate});
                zombie_info_list[i].row=ReadMemory<uint32_t>({zombie_info_list[i].zombie_address+zombie_row});
                //if(newzomb.row<0||newzomb.row>6) continue;
                zombie_info_list[i].type=ReadMemory<uint32_t>({zombie_info_list[i].zombie_address+zombie_type});
                zombie_info_list[i].body_blood=ReadMemory<uint32_t>({zombie_info_list[i].zombie_address+zombie_body_blood});
                zombie_info_list[i].armor1_type=ReadMemory<uint32_t>({zombie_info_list[i].zombie_address+zombie_armor1_isexist});
                zombie_info_list[i].armor2_type=ReadMemory<uint32_t>({zombie_info_list[i].zombie_address+zombie_armor2_isexist});
                zombie_info_list[i].armor1_blood=ReadMemory<uint32_t>({zombie_info_list[i].zombie_address+zombie_armor1_body});
                zombie_info_list[i].armor2_blood=ReadMemory<uint32_t>({zombie_info_list[i].zombie_address+zombie_armor2_body});
                zombie_info_list[i].slow_down_time=ReadMemory<uint32_t>({zombie_info_list[i].zombie_address+zombie_slow_down_time});
                zombie_info_list[i].butter_down_time=ReadMemory<uint32_t>({zombie_info_list[i].zombie_address+zombie_butter_time});
                zombie_info_list[i].froze_down_time=ReadMemory<uint32_t>({zombie_info_list[i].zombie_address+zombie_freeze_time});
                zombie_info_list[i].shining_down_time=ReadMemory<uint32_t>({zombie_info_list[i].zombie_address+zombie_shining_time});
                if(zombie_info_list[i].shining_down_time<0)zombie_info_list[i].shining_down_time=0;
                zombie_info_list[i].ishypno=ReadMemory<bool>({zombie_info_list[i].zombie_address+zombie_ishypno});
                QDateTime currentDateTime = QDateTime::currentDateTime();
                offsetnum.insert(i);
                emit updateValue(i,currentDateTime);
            }
            std::chrono::milliseconds sleepDuration(10);
            std::this_thread::sleep_for(sleepDuration);
        }
    }
};

class customzombieplace : public QWidget
{
    Q_OBJECT

public:
    explicit customzombieplace(QWidget *parent = nullptr);
    ~customzombieplace();
    const char* zombie_book[33] = {
        "普通僵尸",
        "旗帜",
        "路障（盲盒）",
        "撑杆",
        "铁桶",
        "读报",
        "钢铁门",
        "橄榄",
        "舞王",
        "伴舞",
        "鸭子",
        "潜水",
        "冰车",
        "雪橇",
        "海豚",
        "小丑",
        "气球",
        "矿工",
        "跳跳",
        "雪人",
        "蹦极",
        "扶梯",
        "投篮",
        "白眼",
        "小鬼",
        "僵王",
        "豌豆",
        "坚果",
        "辣椒",
        "机枪",
        "窝瓜",
        "高坚果",
        "红眼"
    };
    int full_blood_book[33]={
        270,1100,370,500,1100,1100,
        1100,1600,720,270,270,270,
        1350,270,500,500,270,200,
        720,1350,450,500,850,3000,
        270,60000,270,1100,500,270,
        270,2200,6000
    };

    const char *armor1_book[10] = {
        "",
        "路障",
        "铁桶",
        "橄榄球",
        "矿工帽",
        "",
        "",
        "雪橇车",
        "坚果",
        "高坚果"
    };
    const char *armor2_book[10] = {
        "",
        "铁门",
        "报纸",
        "扶梯",
    };

    struct ZombieStatistic{
        int type;
        int body_init_blood;
        int row;
        bool isdead;
        bool mower_is_dead;
        uint32_t zombie_address;
        QDateTime first_moniter_time;
        QDateTime dead_time;
    };
    vector<ZombieStatistic> zombie_totall_list;
    ZombieMoniter* zMoniter=nullptr;
    void ShowZombie();
    bool iscounting=false;
    bool iscounted=false;
    QDateTime start_counting_time;
    vector<int> indexnum;
    bool SaveCheck();
    bool is_game_on=false;
    bool is_board_on;

private:
    Ui::customzombieplace *ui;

protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_reset_clicked();
    void on_singleplace_clicked();
    void on_rowplace_clicked();
    void on_colplace_clicked();
    void on_realtime_stateChanged(int arg1);
    void on_zombielist_currentRowChanged(int currentRow);
    void on_pushButton_clicked();
    void on_isdead_stateChanged(int arg1);
    void on_startcount_clicked();
    void on_stopcount_clicked();
    void on_tofile_clicked();
    void on_exitbutton_clicked();
};

#endif // CUSTOMZOMBIEPLACE_H
