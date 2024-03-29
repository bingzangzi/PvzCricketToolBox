#ifndef RANDPLANTPLACE_H
#define RANDPLANTPLACE_H
#pragma once
#include <QWidget>
#include <QMessageBox>
#include "headfile.h"
#include <QCheckBox>
#include <QGridLayout>
#include <QMutex>
#include <QWaitCondition>
#include "mythread.h"
namespace Ui {
class RandPlantPlace;
}

class RandPlantPlace : public QWidget
{
    Q_OBJECT

public:
    explicit RandPlantPlace(QWidget *parent = nullptr);
    ~RandPlantPlace();
    void sure_plant();
    void InitForbidPlant();
    const char* plant_book[48] = {
        "豌豆射手","向日葵","樱桃炸弹","坚果","土豆雷","寒冰射手","大嘴花","双发射手",
        "小喷菇","阳光菇","大喷菇","墓碑吞噬者","魅惑菇","胆小菇","寒冰菇","毁灭菇",
        "睡莲","窝瓜","三线射手","缠绕海草","火爆辣椒","地刺","火炬","高坚果",
        "海蘑菇","路灯花","仙人掌","三叶草","裂荚射手","杨桃","南瓜头","磁力菇",
        "卷心菜投手","花盆","玉米投手","咖啡豆","大蒜","叶子保护伞","金盏花","西瓜投手",
        "机枪射手","双子向日葵","忧郁蘑菇","香蒲","冰西瓜投手","吸金磁","地磁王","玉米加农炮"
    }; //原版图鉴植物
    vector<int> forbid_plant_list={ 1,2,4,9,11,14,15,17,19,20,21,25,27,31,35,37,38,41,45,47 };
    vector<QCheckBox*> boxes;
    bool is_game_on;
    bool is_board_on;
    bool SaveCheck();

private:
    Ui::RandPlantPlace *ui;
    int maxallowplant=0x300;

protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_rowcol_sure_clicked();
    void on_sure_plant_clicked();
    void on_reset_select_clicked();
    void on_change_mode_clicked();
    void on_clearallplant_clicked();
    void on_exit_button_clicked();

    void on_allselct_clicked();
    void on_resetbutton_clicked();
    void on_forbidsure_clicked();
};

#endif // RANDPLANTPLACE_H
