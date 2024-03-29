#include "mainwindow.h"
#include "ui_mainwindow.h"
extern bool GameonFlag;
bool RPflag=false;//随机植物窗口是否打开
bool CPflag=false;//自定义植物窗口是否打开
bool RZflag=false;//随机僵尸窗口是否打开
bool CZflag=false;//自定义僵尸窗口是否打开
bool Verflag=false;//版本窗口是否打开
bool Helpflag=false;//查看帮助窗口
bool Animatedflag=false;//是否开启种植动画
wstring PvzName;
wstring QStringToWString(const QString& qstr)
{
    return qstr.toStdWString();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->GetNameText,SIGNAL(returnPressed()),this,SLOT(on_main_commitButton_clicked()));
    connect(ui->browseversion,&QAction::triggered,this,&MainWindow::open_versioninfo);
    connect(ui->rand_plant_mode_menu,&QAction::triggered,this,&MainWindow::open_randplantplace);
    connect(ui->custom_plant_mode_menu,&QAction::triggered,this,&MainWindow::open_customplantplace);
    connect(ui->rand_zombie_mode_menu,&QAction::triggered,this,&MainWindow::open_randzombieplace);
    connect(ui->custom_zombie_mode_menu,&QAction::triggered,this,&MainWindow::open_customzombieplace);
    connect(ui->browshelpinfo,&QAction::triggered,this,&MainWindow::open_browshelpinfo);
    connect(ui->setting,&QAction::triggered,this,[&](){
        ui->maintable->setCurrentIndex(1);
    });
    ui->more->setReadOnly(true);
    on_main_commitButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_main_commitButton_clicked()
{
    QString Getpvzname=ui->GetNameText->text();
    wstring pvzname=QStringToWString(Getpvzname);
    if(GetHandle(pvzname)){
        PvzName=pvzname;
        QMessageBox::information(this,"提示","已找到游戏，你可以继续操作了。");
        GameonFlag=true;
    }
    else{
        GameonFlag=false;
        QMessageBox::information(this,"提示","游戏未找到！\n请确认是否运行或名称是否正确。");
    }
}


void MainWindow::on_main_exitButton_clicked()
{

    QList<QWidget *> topLevelWidgets = qApp->topLevelWidgets();
    for (QWidget *widget : topLevelWidgets)
    {
            widget->close();
    }
    this->close();
}


void MainWindow::on_main_plantplace_clicked()
{
    if(!GameonFlag){
        QMessageBox::information(this,"提示","当前未找到游戏，不能继续");
    }
    else
    {
        open_randplantplace();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if(!GameonFlag){
        QMessageBox::information(this,"提示","当前未找到游戏，不能继续");
    }
    else
    {
        open_randzombieplace();
    }
}

void MainWindow::open_versioninfo()
{
    if(!Verflag){
        Verflag=true;
        versioninfo *Verwind=new versioninfo;
        Verwind->setWindowTitle("版本信息");
        Verwind->show();
    }
    else{
        QMessageBox::information(this,"提示","窗口已打开，请勿重复打开！");
    }
}

void MainWindow::open_browshelpinfo()
{
    if(!Helpflag){
        Helpflag=true;
        help *helpWind=new help;
        helpWind->setWindowTitle("帮助信息");
        helpWind->show();
    }
    else{
        QMessageBox::information(this,"提示","窗口已打开，请勿重复打开！");
    }
}

void MainWindow::open_randplantplace()
{
    if(GameonFlag){
        if(!RPflag){
            RPflag=true;
            RandPlantPlace *randplantwin=new RandPlantPlace();
            randplantwin->setWindowTitle("随机植物种植模式");
            randplantwin->show();
        }
        else{
            QMessageBox::information(this,"提示","窗口已打开，请勿重复打开！");
        }
    }
    else{
        QMessageBox::information(this,"提示","当前未找到游戏，不能继续");
    }
}

void MainWindow::open_customplantplace()
{
    if(!CPflag){
        CPflag=true;
        customplantplace *cusplantwin=new customplantplace();
        cusplantwin->setWindowTitle("自定义植物种植模式");
        cusplantwin->show();
    }
    else{
        QMessageBox::information(this,"提示","窗口已打开，请勿重复打开！");
    }
}

void MainWindow::open_randzombieplace()
{
 if(GameonFlag){
    if(!RZflag){
        RZflag=true;
        randzombieplace *randzombiewin=new randzombieplace();
        randzombiewin->setWindowTitle("随机僵尸放置模式");
        randzombiewin->show();
    }
    else
    {
        QMessageBox::information(this,"提示","窗口已打开，请勿重复打开！");
    }
}
else{
    QMessageBox::information(this,"提示","当前未找到游戏，不能继续");
}
}

void MainWindow::open_customzombieplace()
{
    if(!CZflag){
        CZflag=true;
        customzombieplace *cuszombiewin=new customzombieplace();
        cuszombiewin->setWindowTitle("自定义僵尸放置模式");
        cuszombiewin->show();
    }
    else{
        QMessageBox::information(this,"提示","窗口已打开，请勿重复打开！");
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(!GameonFlag){
        QMessageBox::information(this,"提示","当前未找到游戏，不能继续");
    }
    else
    {
        open_customplantplace();
    }
}


void MainWindow::on_pushButton_3_clicked()
{

    if(!GameonFlag){
        QMessageBox::information(this,"提示","当前未找到游戏，不能继续");
    }
    else
    {
        open_customzombieplace();
    }
}


void MainWindow::on_sunchange_clicked()
{
    if (!CheckGameOn())
        return;
    QString underchangevalue=ui->suntext->text();
    bool ok;
    int value=underchangevalue.toInt(&ok);
    if(!ok){
        QMessageBox::information(this,"提示","请输入一个整数！");
    }
    WriteMemory<uint32_t>(value,{lawn,board,sunshine_value});
}


void MainWindow::on_nocostsun_stateChanged(int arg1)
{
    if(ui->nocostsun->isChecked()){
        IgnoreSun(true);
    }
    else IgnoreSun(false);

}


void MainWindow::on_allowrunback_stateChanged(int arg1)
{
    if(ui->allowrunback->isChecked()){
        AllowBackRunning(true);
    }
    else AllowBackRunning(false);
}


void MainWindow::on_pausegame_stateChanged(int arg1)
{
    if (!CheckGameOn())
        return;
    if(ui->pausegame->isChecked()){
        WriteMemory<bool>(true,{lawn,board,game_pause});
    }
    else WriteMemory<bool>(false,{lawn,board,game_pause});
}


void MainWindow::on_freeplant_stateChanged(int arg1)
{
    if (!CheckGameOn())
        return;
    if(ui->freeplant->isChecked()){
        PlantNoLimit(true);
    }
    else PlantNoLimit(false);
}


void MainWindow::on_lockspade_stateChanged(int arg1)
{
    if (!CheckGameOn())
        return;
    if(ui->lockspade->isChecked()){
        LockShovel(true);
    }
    else LockShovel(false);
}


void MainWindow::on_hideslot_stateChanged(int arg1)
{
    if (!CheckGameOn())
        return;
    auto offset=ReadMemory<uint32_t>({lawn,board,slot_offset});
    if(ui->hideslot->isChecked()){
        WriteMemory<bool>(false,{offset+slot_hide});
    }
    else WriteMemory<bool>(true,{offset+slot_hide});
}


void MainWindow::on_plantInvincible_stateChanged(int arg1)
{
    if (!CheckGameOn())
        return;
    if(ui->plantInvincible->isChecked()){
        PlantInvincible(true);
    }
    else PlantInvincible(false);
}


void MainWindow::on_unlockallmode_stateChanged(int arg1)
{
    if (!CheckGameOn())
        return;
    if(ui->unlockallmode->isChecked()){
        UnlockAllMode(true);
    }
    else UnlockAllMode(false);
}


void MainWindow::on_unlockglod_stateChanged(int arg1)
{
    if (!CheckGameOn())
        return;
    if(ui->unlockallmode->isChecked()){
        UnlockGoldFlower(true);
    }
    else UnlockGoldFlower(false);
}


void MainWindow::on_passthegame_stateChanged(int arg1)
{
    if(ui->passthegame->isChecked())PassGame();
}


void MainWindow::on_hidespade_stateChanged(int arg1)
{
    if(ui->hidespade->isChecked()){
        HideShovel(true);
    }
    else HideShovel(false);
}


void MainWindow::on_hidemenu_stateChanged(int arg1)
{
    if(ui->hidemenu->isChecked()){
        HideMenu(true);
    }
    else HideMenu(false);
}


void MainWindow::on_nosun_stateChanged(int arg1)
{
    if(ui->nosun->isChecked()){
        SetNoSun(true);
    }
    else SetNoSun(false);
}


void MainWindow::on_autocollect_stateChanged(int arg1)
{
    if(ui->autocollect->isChecked()){
        AutoCollect(true);
    }
    else AutoCollect(false);
}


void MainWindow::on_zombieInvincible_stateChanged(int arg1)
{
    if (!CheckGameOn())
        return;
    if(ui->zombieInvincible->isChecked()){
        ZombieInvincible(true);
    }
    else ZombieInvincible(false);
}


void MainWindow::on_noawake_stateChanged(int arg1)
{
    if (!CheckGameOn())
        return;
    if(ui->noawake->isChecked()){
        MushroomNoSleep(true);
    }
    else MushroomNoSleep(false);
}


void MainWindow::on_pausesystemzombie_stateChanged(int arg1)
{
    if(ui->pausesystemzombie->isChecked()){
        StopSystemZombie(true);
    }
    else StopSystemZombie(false);
}


void MainWindow::on_zombiepause_stateChanged(int arg1)
{
    if(ui->zombiepause->isChecked()){
        StopZombieMove(true);
    }
    else StopZombieMove(false);
}


void MainWindow::on_nocrater_stateChanged(int arg1)
{
    if(ui->nocrater->isChecked()){
        NoCrater(true);
    }
    else NoCrater(false);
}


void MainWindow::on_nocool_stateChanged(int arg1)
{
    if(ui->nocool->isChecked()){
        PlaceNoCD(true);
    }
    else PlaceNoCD(false);
}


void MainWindow::on_clearallzombies_stateChanged(int arg1)
{
    if (!CheckGameOn()||!CheckBoardOn())
        return;
    if(ui->clearallzombies->isChecked()){
        KillAllZombies();
    }
    ui->clearallzombies->setCheckState(Qt::Unchecked);
}


void MainWindow::on_clearplant_stateChanged(int arg1)
{
    if (!CheckGameOn()||!CheckBoardOn())
        return;
    if(ui->clearplant->isChecked()){
        ClearAllPlants();
    }
    ui->clearplant->setCheckState(Qt::Unchecked);
}


void MainWindow::on_nolimitonplant_stateChanged(int arg1)
{
    if(ui->nolimitonplant->isChecked()){
        PurpleSeedUnlimited(true);
    }
    else PurpleSeedUnlimited(false);
}


void MainWindow::on_resetall_clicked()
{
    QList<QCheckBox *> checkboxes = ui->tab_2->findChildren<QCheckBox *>();
    for (QCheckBox *checkbox : checkboxes)
    {
       // checkbox->setCheckState(Qt::Checked);
        checkbox->setCheckState(Qt::Unchecked);
    }
    ui->suntext->setText("");
}


void MainWindow::on_quickset_clicked()
{
    ui->nocostsun->setCheckState(Qt::Checked);
    ui->freeplant->setCheckState(Qt::Checked);
    ui->nocool->setCheckState(Qt::Checked);
    ui->nocrater->setCheckState(Qt::Checked);
    ui->noawake->setCheckState(Qt::Checked);
    ui->nolimitonplant->setCheckState(Qt::Checked);
    ui->pausesystemzombie->setCheckState(Qt::Checked);
    ui->unlockallmode->setCheckState(Qt::Checked);
    ui->hidespade->setCheckState(Qt::Checked);
    ui->hideslot->setCheckState(Qt::Checked);
    ui->hidemenu->setCheckState(Qt::Checked);
    ui->autocollect->setCheckState(Qt::Checked);
    ui->allowrunback->setCheckState(Qt::Checked);
}


void MainWindow::on_selectall_clicked()
{
    QList<QCheckBox *> checkboxes = ui->tab_2->findChildren<QCheckBox *>();
    for (QCheckBox *checkbox : checkboxes)
    {
        checkbox->setCheckState(Qt::Checked);
    }
}

