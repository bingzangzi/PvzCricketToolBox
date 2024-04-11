#include "mainwindow.h"
#include "ui_mainwindow.h"
HANDLE pvzHand;
wstring PVZNAME;
QFile logfile;
QTextStream out;
extern bool* global_forbid_plant;
extern vector<bool*> row_forbid_plant;
extern vector<bool*> col_forbid_plant;
extern vector<unordered_set<int>> single_forbid_plant;
extern vector<bool> global_gift_plant;
slotplantmoniter* slot_plant_moniter=nullptr;
extern vector<bool> global_forbid_zombie;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qRegisterMetaType<ZombieInfoStruct>("ZombieInfoStruct");
    ui->setupUi(this);
    on_lookbyprocess_clicked();
    ui->startlog->setVisible(false);
    connect(ui->logrecord,&QAction::triggered,this,[&](){
        ui->startlog->setVisible(true);
    });
    connect(ui->killzombie,&QAction::triggered,this,[&](){
        if(!CheckBoardOn()) return;
        KillAllZombies();
    });
    connect(ui->clearplant_2,&QAction::triggered,this,[&](){
        if(!CheckBoardOn()) return;
        ClearAllPlants();
    });
    connect(ui->startrandslot,&QAction::triggered,this,[&](){
        ui->randslot->setCheckState(Qt::Checked);
    });
    connect(ui->startrandbox,&QAction::triggered,this,[&](){
        ui->randblindboxmode->setCheckState(Qt::Checked);
    });
    connect(ui->pausegame_2,&QAction::triggered,this,[&](){
        if(ui->pausegame->isChecked())
            ui->pausegame->setCheckState(Qt::Unchecked);
        else ui->pausegame->setCheckState(Qt::Checked);
    });
    connect(ui->clearbullet,&QAction::triggered,this,[&](){
        if(!CheckBoardOn()) return;
        ClearAllBullet();
    });
    connect(ui->versioninfo,&QAction::triggered,this,[&](){
        delete verinfo;
        verinfo=new versioninfo;
        verinfo->setWindowTitle("版本信息");
        verinfo->show();
    });
    connect(ui->helpinfo, &QAction::triggered, this, [=]() {
        QDesktopServices::openUrl(QUrl("https://space.bilibili.com/349199875?spm_id_from=333.1007.0.0"));
    });
    ui->isdefaultplantbook->setCheckState(Qt::Checked);
    ui->more->setReadOnly(true);
    ui->plantbookinfo->setReadOnly(true);
    ui->globalforbid->setVisible(false);
    ui->rowforbid->setVisible(false);
    ui->colforbid->setVisible(false);
    ui->singleforbid->setVisible(false);
    ui->randplantinfo->setReadOnly(true);
    ui->singleplantplaceinfo->setReadOnly(true);
    connect(ui->startforbidplace,&QCheckBox::stateChanged,this,&MainWindow::on_startforbidplace_stateChanged);
    global_gift_plant.resize(52);
    row_forbid_plant.resize(6);
    col_forbid_plant.resize(10);
    for(int i=0;i<6;i++){
        row_forbid_plant[i]=new bool[52];
    }
    for(int i=0;i<10;i++){
        col_forbid_plant[i]=new bool[52];
    }
    for(int i=0;i<defaultgift.size();i++)global_gift_plant[defaultgift[i]]=true;
    ui->chooseplanttype->clear();
    for(int i=0;i<52;i++)ui->chooseplanttype->addItem(QString("[%1]%2").arg(i).arg(default_plant_book[i]));
    ui->formationtips->setReadOnly(true);
    ui->formationinfo->setReadOnly(true);
    ui->isdefaultplantbook_zombie->setCheckState(Qt::Checked);
    ui->zombiepreparetips->setReadOnly(true);
    ui->zombiebookinfo->setReadOnly(true);
    AutoZombieRowColInit();
    AutoZombieChangetableInit();
    Initfreezombiegridlayout();
    InitPlantMonitPage();
    InitZombierealMoniterList();
    InitBaseValue();
    InitCustomPlant();
    on_readsettings_clicked();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(ui->savedatawhenexit->isChecked()){
        savedate();
    }
    QMainWindow::closeEvent(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
    switch (type) {
    case QtDebugMsg:
        out << QString("[%1] Debug: %2 (%3:%4, %5)\n").arg(currentTime).arg(msg).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtInfoMsg:
        out << QString("[%1] Info: %2 (%3:%4, %5)\n").arg(currentTime).arg(msg).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtWarningMsg:
        out << QString("[%1] Warning: %2 (%3:%4, %5)\n").arg(currentTime).arg(msg).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtCriticalMsg:
        out << QString("[%1] Critical: %2 (%3:%4, %5)\n").arg(currentTime).arg(msg).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtFatalMsg:
        out << QString("[%1] Fatal: %2 (%3:%4, %5)\n").arg(currentTime).arg(msg).arg(context.file).arg(context.line).arg(context.function);
        abort();
    }
    out.flush();
}

void MainWindow::on_lookbyprocess_clicked()
{
    wstring pvzName=ui->GetNameText->text().toStdWString();
    PVZNAME=pvzName;
    pvzHand=GetHandle(pvzName);
    if(!pvzHand) {
        ui->infooutput->setText("未找到游戏，请确认游戏名是否正确或游戏是否已运行");
        if(ui->startlog->isChecked()){

            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString currentTime = currentDateTime.toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1]Error: 获取句柄失败。Get handle failed. 错误码：%2\n").arg(currentTime).arg(GetLastError());
            out.flush();
        }
        return;
    }
    if(CompareVerinfo())
        ui->infooutput->setText("已找到游戏，现在可以继续其他操作");
    else{
        ui->infooutput->setText("游戏版本不匹配或游戏不支持");
        pvzHand=nullptr;
        if(ui->startlog->isChecked()){

            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString currentTime = currentDateTime.toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1]Error: 游戏版本不匹配或游戏不支持。Unsupported Game.\n").arg(currentTime);
            out.flush();
        }
    }
    LPVOID lpAddress = (LPVOID)0x400000;

    // 设置新的保护属性
    DWORD flNewProtect = PAGE_EXECUTE_READWRITE;

    // 获取原始的保护属性
    DWORD flOldProtect;
    if (!VirtualProtectEx(pvzHand, lpAddress, 0x1000, flNewProtect, &flOldProtect))
    {
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1]Failed to change protection\n").arg(currentTime);
            out.flush();
        }
        return;
    }
}


void MainWindow::on_startlog_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        QString currentPath = QDir::currentPath();
        QString logDir =currentPath + QDir::separator() + "log";
        QDir().mkpath(logDir);
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString currentTime = currentDateTime.toString("yyyy-MM-dd-hh-mm-ss");
        QString filePath = logDir+ QDir::separator()+currentTime+".log";
        logfile.setFileName(filePath);
        if (!logfile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            if(!pvzHand) ui->infooutput->setText("日志打开失败！");
            ui->startlog->setCheckState(Qt::Unchecked);
            return ;
        }
        out.setDevice(&logfile);
        currentDateTime = QDateTime::currentDateTime();
        currentTime = currentDateTime.toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1]开始记录日志。Start Recording log.\n").arg(currentTime);
        out.flush();
        qInstallMessageHandler(customMessageHandler);
        return;
    }
    else if(arg1==Qt::Unchecked){
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString currentTime = currentDateTime.toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1]结束日志记录。Finish Recording log.\n").arg(currentTime);
        logfile.close();
        logfile.setFileName("");
        out.setDevice(nullptr);
        qInstallMessageHandler(nullptr);
        return;
    }
}


void MainWindow::on_startbypath_clicked()
{
    QString filePath=ui->GetNameText->text();

    QFileInfo fileInfo(filePath);

    if (!fileInfo.exists() || !fileInfo.isFile()) {
        ui->infooutput->setText("找不到该文件");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] %2 File does not exist or is not a file.\n").arg(currentTime).arg(filePath);
            out.flush();
        }
        return;
    }

    if (fileInfo.isExecutable()) {
       // ui->infooutput->setText("不是一个可执行文件");
    } else {
        ui->infooutput->setText("不是一个可执行文件");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] %2不是一个可执行文件\n").arg(currentTime).arg(filePath);
            out.flush();
        }
        return;
    }
    QString productName = GetExeProductName(filePath);
    if(productName!="Plants vs. Zombies"){
        ui->infooutput->setText("不是植物大战僵尸");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] %2不是一个植物大战僵尸游戏，其产品名称为：%3\n").arg(currentTime).arg(filePath).arg(productName);
            out.flush();
        }
        return;
    }

    QString verinfo=GetExeFileVersion(filePath);
    if(verinfo=="1.0.0.1051"){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        if(out.device()!=nullptr){

            out << QString("[%1] Success: 当前版本支持：%2\n").arg(currentTime).arg(verinfo);
            out.flush();
        }
    }
    else{
        ui->infooutput->setText("当前版本不支持");
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        if(out.device()!=nullptr)
        {

            out << QString("[%1] Failed: 当前不版本支持：%2\n").arg(currentTime).arg(verinfo);
            out.flush();
        }
        return;
    }
    QProcess* process=new QProcess;
    QString originalWorkingDir = QDir::currentPath();
    QDir::setCurrent(fileInfo.path()+"/");
    process->startDetached(filePath);
    wstring fileName = fileInfo.fileName().toStdWString();
    // 检查是否成功启动
   /* if (pvzhwnd != nullptr)
    {
        ShowWindow(pvzhwnd, SW_RESTORE); // 这里使用 SW_RESTORE 以确保窗口被还原显示
        SetForegroundWindow(pvzhwnd); // 将窗口置于前台
    }*/
    QDir::setCurrent(originalWorkingDir);
    PVZNAME=fileName;
    pvzHand=GetHandle(fileName);
    if (pvzHand) {

        ui->infooutput->setText("成功启动游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] %2:%3 启动成功\n").arg(currentTime).arg(filePath).arg(productName);
            out.flush();
        }
    }
    else if(!pvzHand){
        ui->infooutput->setText("启动游戏失败");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] %2: 启动失败。 错误码：%3\n").arg(currentTime).arg(filePath).arg(GetLastError());
            out.flush();
        }
    }

}


void MainWindow::on_sunchange_clicked()
{
    if (!CheckBoardOn()){
        ui->more->setText("未检测到关卡");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，修改阳光失败。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    QString underchangevalue=ui->suntext->text();
    bool ok;
    int value=underchangevalue.toInt(&ok);
    if(!ok){
       ui->more->setText("请输入一个整数");
    }
    WriteMemory<uint32_t>(value,{lawn,board,sunshine_value});
    ui->more->setText("修改成功");
}


void MainWindow::on_quickset_clicked()
{
    if (!CheckGameOn()||!CheckBoardOn()){
        ui->more->setText("请进入关卡后再使用本功能");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏或关卡，一键斗蛐蛐设置失败。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    HACK<uint8_t, 1> block_main_loop={0x00552014, {0xfe}, {0xdb}};
    WriteMemory(block_main_loop.hack_value,{block_main_loop.mem_addr});
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
    ui->nosun->setCheckState(Qt::Checked);
    ui->checkBox_2->setCheckState(Qt::Checked);
    WriteMemory(block_main_loop.reset_value,{block_main_loop.mem_addr});
    ui->more->setText("设置成功");
}


void MainWindow::on_resetall_clicked()
{
    QList<QCheckBox *> checkboxes = ui->gamesettings->findChildren<QCheckBox *>();
    ui->more->setText("重置成功");
    for (QCheckBox *checkbox : checkboxes)
    {
        // checkbox->setCheckState(Qt::Checked);
        checkbox->setCheckState(Qt::Unchecked);
    }
    ui->suntext->setText("");
}


void MainWindow::on_plantInvincible_stateChanged(int arg1)
{
    if (!CheckGameOn()){
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->plantInvincible->isChecked()){
        PlantInvincible(true);
    }
    else PlantInvincible(false);
}


void MainWindow::on_nocostsun_stateChanged(int arg1)
{
    if (!CheckGameOn()){
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->nocostsun->isChecked()){
        IgnoreSun(true);
    }
    else IgnoreSun(false);
}


void MainWindow::on_freeplant_stateChanged(int arg1)
{
    if (!CheckGameOn()){
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->freeplant->isChecked()){
        PlantNoLimit(true);
    }
    else PlantNoLimit(false);
}


void MainWindow::on_nocool_stateChanged(int arg1)
{
    if (!CheckGameOn()){
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->nocool->isChecked()){
        PlaceNoCD(true);
    }
    else PlaceNoCD(false);
}


void MainWindow::on_nocrater_stateChanged(int arg1)
{
    if (!CheckGameOn()){
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->nocrater->isChecked()){
        NoCrater(true);
    }
    else NoCrater(false);
}


void MainWindow::on_noawake_stateChanged(int arg1)
{
    if (!CheckGameOn()){
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->noawake->isChecked()){
        MushroomNoSleep(true);
    }
    else MushroomNoSleep(false);
}


void MainWindow::on_nolimitonplant_stateChanged(int arg1)
{
    if (!CheckGameOn()){
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->nolimitonplant->isChecked()){
        PurpleSeedUnlimited(true);
    }
    else PurpleSeedUnlimited(false);
}


void MainWindow::on_clearplant_stateChanged(int arg1)
{
    if (!CheckBoardOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->clearplant->isChecked()){
        ClearAllPlants();
    }
    ui->clearplant->setCheckState(Qt::Unchecked);
}


void MainWindow::on_zombieInvincible_stateChanged(int arg1)
{
    if (!CheckGameOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->zombieInvincible->isChecked()){
        ZombieInvincible(true);
    }
    else ZombieInvincible(false);
}


void MainWindow::on_pausesystemzombie_stateChanged(int arg1)
{
    if (!CheckGameOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->pausesystemzombie->isChecked()){
        StopSystemZombie(true);
    }
    else StopSystemZombie(false);
}


void MainWindow::on_zombiepause_stateChanged(int arg1)
{
    if (!CheckGameOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->zombiepause->isChecked()){
        StopZombieMove(true);
    }
    else StopZombieMove(false);
}


void MainWindow::on_clearallzombies_stateChanged(int arg1)
{
    if (!CheckBoardOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->clearallzombies->isChecked()){
        KillAllZombies();
    }
    ui->clearallzombies->setCheckState(Qt::Unchecked);
}


void MainWindow::on_passthegame_stateChanged(int arg1)
{
    if (!CheckBoardOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->passthegame->isChecked())PassGame();
}


void MainWindow::on_unlockglod_stateChanged(int arg1)
{
    if (!CheckGameOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->unlockallmode->isChecked()){
        UnlockGoldFlower(true);
    }
    else UnlockGoldFlower(false);
}


void MainWindow::on_unlockallmode_stateChanged(int arg1)
{
    if (!CheckGameOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->unlockallmode->isChecked()){
        UnlockAllMode(true);
    }
    else UnlockAllMode(false);
}


void MainWindow::on_lockspade_stateChanged(int arg1)
{
    if (!CheckBoardOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->lockspade->isChecked()){
        LockShovel(true);
    }
    else LockShovel(false);
}


void MainWindow::on_hidespade_stateChanged(int arg1)
{
    if (!CheckBoardOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->hidespade->isChecked()){
        HideShovel(true);
    }
    else HideShovel(false);
}


void MainWindow::on_hideslot_stateChanged(int arg1)
{
    if (!CheckBoardOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(out.device()){

        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始设置隐藏卡槽\n").arg(currentTime);
        out.flush();
    }
    auto offset=ReadMemory<uint32_t>({lawn,board,slot_offset});
    if(ui->hideslot->isChecked()){
        WriteMemory<bool>(false,{offset+slot_hide});
    }
    else WriteMemory<bool>(true,{offset+slot_hide});
    if(out.device()){

        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束设置隐藏卡槽\n").arg(currentTime);
        out.flush();
    }
}


void MainWindow::on_hidemenu_stateChanged(int arg1)
{
    if (!CheckBoardOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->hidemenu->isChecked()){
        HideMenu(true);
    }
    else HideMenu(false);
}


void MainWindow::on_nosun_stateChanged(int arg1)
{
    if (!CheckBoardOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->nosun->isChecked()){
        SetNoSun(true);
    }
    else SetNoSun(false);
}


void MainWindow::on_autocollect_stateChanged(int arg1)
{
    if (!CheckBoardOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->autocollect->isChecked()){
        AutoCollect(true);
    }
    else AutoCollect(false);
}


void MainWindow::on_pausegame_stateChanged(int arg1)
{
    if (!CheckBoardOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(out.device()){

        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始设置游戏暂停/恢复。\n").arg(currentTime);
        out.flush();
    }
    if(ui->pausegame->isChecked()){
        WriteMemory<bool>(true,{lawn,board,game_pause});
    }
    else WriteMemory<bool>(false,{lawn,board,game_pause});
    if(out.device()){

        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束设置游戏暂停/恢复。\n").arg(currentTime);
        out.flush();
    }
}


void MainWindow::on_allowrunback_stateChanged(int arg1)
{
    if (!CheckGameOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->allowrunback->isChecked()){
        AllowBackRunning(true);
    }
    else AllowBackRunning(false);
}


void MainWindow::on_plantplace_clicked()
{
    ui->maintable->setCurrentIndex(2);
}


void MainWindow::on_plantmoniter_clicked()
{
    ui->maintable->setCurrentIndex(4);
}


void MainWindow::on_zombieplace_clicked()
{
    ui->maintable->setCurrentIndex(3);
}


void MainWindow::on_zombiemoniter_clicked()
{
    ui->maintable->setCurrentIndex(5);
}

void MainWindow::on_isdefaultplantbook_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        current_plant_book.clear();
        for(int i=0;i<52;i++){
            current_plant_book<<this->default_plant_book[i];
        }
        ui->currentplantbookshow->clear();
        for(int i=0;i<52;i++){
            ui->currentplantbookshow->addItem(QString("[%1]").arg(i)+current_plant_book.at(i));
        }
        global_gift_plant.clear();
        global_gift_plant.resize(52);
        for(int i=0;i<defaultgift.size();i++)global_gift_plant[defaultgift[i]]=true;
        boxes.clear();
        while (QLayoutItem* item = ui->forbidgridlayout->takeAt(0)) {
            QWidget* widget = item->widget();
            if (widget) {
                ui->forbidgridlayout->removeWidget(widget); // 从布局中移除部件
                delete widget; // 删除部件
            }
            delete item; // 删除布局项
        }
        ui->chooseplanttype->clear();
        for(int i=0;i<current_plant_book.size();i++)
            ui->chooseplanttype->addItem(QString("[%1]%2").arg(i).arg(current_plant_book[i]));
        return;
    }
    if(ui->startforbidplace->isChecked())ui->startforbidplace->setCheckState(Qt::Unchecked);
    row_forbid_plant.clear();
    col_forbid_plant.clear();
    single_forbid_plant.clear();
    global_gift_plant.clear();
}


void MainWindow::on_updateplantbook_clicked()
{
    if(out.device()){

        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 尝试更新植物图鉴\n").arg(currentTime);
        out.flush();
    }
    temp_plant_book.clear();
    QMessageBox::information(this,"提示","请选择一个文本文件类型的文件，文件内的格式请务必按照实际顺序写下\n植物的名称，每个植物以换行或空格隔开。");
    QString filePath = QFileDialog::getOpenFileName(this, "Select File", "", "Text Files (*.txt)");
    if (filePath.isEmpty()) {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 用户未选择文件\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        // 逐行读取文件内容，并按空格或换行符分割为QStringList
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 打开文件:%2 成功\n").arg(currentTime).arg(filePath);
            out.flush();
        }
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList words = line.split(QRegularExpression("[\\s]+")); // 使用正则表达式匹配空格或换行符
            temp_plant_book<<words;
        }
        ui->plantbookinfo->setText("读取文件成功");
    }
    else {
        ui->plantbookinfo->setText("读取文件失败");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 打开文件:%2 失败，错误码\n").arg(currentTime).arg(filePath).arg(GetLastError());
            out.flush();
        }
        return;
    }
    //current_plant_book=GetPlantBook();
    if(temp_plant_book.isEmpty()){
        ui->plantbookinfo->setText("获取植物图鉴失败");
        return;
    }
    ui->currentplantbookshow->clear();
    for(int i=0;i<temp_plant_book.size();i++){
        ui->currentplantbookshow->addItem(QString("[%1]").arg(i)+temp_plant_book.at(i));
    }
    file.close();
}


void MainWindow::on_sureupdateplantbook_clicked()
{
    if(temp_plant_book.size()==0) return;
    current_plant_book.clear();
    current_plant_book=temp_plant_book;
    temp_plant_book.clear();
    ui->plantbookinfo->setText("更新植物图鉴成功");
    ui->isdefaultplantbook->setCheckState(Qt::Unchecked);
    if(ui->startforbidplace->isChecked())ui->startforbidplace->setCheckState(Qt::Unchecked);
    row_forbid_plant.clear();
    col_forbid_plant.clear();
    single_forbid_plant.clear();
    global_gift_plant.clear();
    global_gift_plant.resize(current_plant_book.size());
    boxes.clear();
    while (QLayoutItem* item = ui->forbidgridlayout->takeAt(0)) {
        QWidget* widget = item->widget();
        if (widget) {
            ui->forbidgridlayout->removeWidget(widget); // 从布局中移除部件
            delete widget; // 删除部件
        }
        delete item; // 删除布局项
    }
    ui->chooseplanttype->clear();
    for(int i=0;i<current_plant_book.size();i++)ui->chooseplanttype->addItem(QString("[%1]%2").arg(i).arg(current_plant_book[i]));
    InitBaseValue();
}


void MainWindow::on_startforbidplace_stateChanged(int arg1)
{
    if(ui->startforbidplace->isChecked()){
        ui->globalforbid->setChecked(true);
        ui->globalforbid->setVisible(true);
        ui->rowforbid->setVisible(true);
        ui->colforbid->setVisible(true);
        ui->singleforbid->setVisible(true);
        if(boxes.size()!=0) goto target;
        boxes.clear();
        boxes.resize(current_plant_book.size());
        for(int i=0;i<current_plant_book.size();i++){
            boxes[i]=new QCheckBox;
            boxes[i]->setText(QString("[%1]").arg(i)+current_plant_book[i]);
            ui->forbidgridlayout->addWidget(boxes[i],i/6,i%6);
        }
        ui->scrollAreaWidgetContents->setLayout(ui->forbidgridlayout);
        ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
        ui->scrollArea->setWidgetResizable(true);
target:
        if(is_global_forbid_exist){
            on_globalforbid_clicked();
            return;
        }
        global_forbid_plant=new bool[current_plant_book.size()];
        memset(global_forbid_plant,false,sizeof(bool)*current_plant_book.size());
        if(ui->isdefaultplantbook->isChecked()){
            for(int i=0;i<defaultforbid.size();i++){
                global_forbid_plant[defaultforbid[i]]=true;
            }
        }
        on_globalforbid_clicked();
    }
    else if(!ui->startforbidplace->isChecked()){
        ui->globalforbid->setVisible(false);
        ui->rowforbid->setVisible(false);
        ui->colforbid->setVisible(false);
        ui->singleforbid->setVisible(false);
        //int itemCount = ui->forbidgridlayout->count();
        //delete[] global_forbid_plant;
    }
}


void MainWindow::on_globalforbid_clicked()
{
    for(int i=0;i<current_plant_book.size();i++){
        if(global_forbid_plant[i]) boxes[i]->setCheckState(Qt::Checked);
        else boxes[i]->setCheckState(Qt::Unchecked);
    }
    is_global_forbid_exist=true;
}


void MainWindow::on_rowforbid_clicked()
{
    if(row_forbid_plant.size()==0){
        row_forbid_plant.resize(6);
        for(int i=0;i<6;i++){
            bool *forbidlist=new bool[current_plant_book.size()];
            memset(forbidlist,false,sizeof(bool)*current_plant_book.size());
            row_forbid_plant[i]=forbidlist;
        }
    }
    if(ui->rownum->value()==0) ui->rownum->setValue(1);
    int currentrow=ui->rownum->value();
    for(int i=0;i<current_plant_book.size();i++){
        if(row_forbid_plant[currentrow-1][i]){
            boxes[i]->setCheckState(Qt::Checked);
        }
        else boxes[i]->setCheckState(Qt::Unchecked);
    }
}


void MainWindow::on_colforbid_clicked()
{
    if(col_forbid_plant.size()==0){
        col_forbid_plant.resize(10);
        for(int i=0;i<10;i++){
            bool *forbidlist=new bool[current_plant_book.size()];
            memset(forbidlist,false,sizeof(bool)*current_plant_book.size());
            col_forbid_plant[i]=forbidlist;
        }
    }
    if(ui->colnum->value()==0) ui->colnum->setValue(1);
    int currentcol=ui->colnum->value();
    for(int i=0;i<current_plant_book.size();i++){
        if(col_forbid_plant[currentcol-1][i])
            boxes[i]->setCheckState(Qt::Checked);
        else boxes[i]->setCheckState(Qt::Unchecked);
    }
}


void MainWindow::on_singleforbid_clicked()
{
    if(single_forbid_plant.size()==0){
        single_forbid_plant.resize(60);
    }
    if(ui->colnum->value()==0) ui->colnum->setValue(1);
    if(ui->rownum->value()==0) ui->rownum->setValue(1);
    for(int i=0;i<current_plant_book.size();i++){
        boxes[i]->setCheckState(Qt::Unchecked);
    }
    for(const auto& element:single_forbid_plant[(ui->rownum->value()-1)*10+(ui->colnum->value()-1)]){
        boxes[element]->setCheckState(Qt::Checked);
    }
}


void MainWindow::on_surerowcol_clicked()
{
    if(ui->rowforbid->isChecked()){
        int currentrow=ui->rownum->value();
        if(currentrow==0) {
            ui->plantbookinfo->setText("行号需要从1开始");
            return;
        }
        for(int i=0;i<current_plant_book.size();i++){
            boxes[i]->setCheckState(Qt::Unchecked);
        }
        for(int i=0;i<current_plant_book.size();i++){
            if(row_forbid_plant[currentrow-1][i])
                boxes[i]->setCheckState(Qt::Checked);
            else boxes[i]->setCheckState(Qt::Unchecked);
        }
        //on_rowforbid_clicked();
    }
    if(ui->colforbid->isChecked()){
        int currentcol=ui->colnum->value();
        if(currentcol==0){
            ui->plantbookinfo->setText("列号需要从1开始");
            return;
        }
        for(int i=0;i<current_plant_book.size();i++){
            boxes[i]->setCheckState(Qt::Unchecked);
        }
        for(int i=0;i<current_plant_book.size();i++){
            if(col_forbid_plant[currentcol-1][i])
                boxes[i]->setCheckState(Qt::Checked);
            else boxes[i]->setCheckState(Qt::Unchecked);
        }
        //on_colforbid_clicked();
    }
    if(ui->singleforbid->isChecked()){
        int currentrow=ui->rownum->value()-1;
        int currentcol=ui->colnum->value()-1;
        if(currentcol==-1||currentrow==-1){
            ui->plantbookinfo->setText("列/行号需要从1开始");
            return;
        }
        for(int i=0;i<current_plant_book.size();i++){
            boxes[i]->setCheckState(Qt::Unchecked);
        }
        for(const auto& element:single_forbid_plant[currentrow*10+currentcol]){
            boxes[element]->setCheckState(Qt::Checked);
        }
        //on_singleforbid_clicked();
    }
}


void MainWindow::on_currentreset_clicked()
{
    if(ui->rowforbid->isChecked()){
        int currentrow=ui->rownum->value()-1;
        if(currentrow==-1) {
            ui->plantbookinfo->setText("行号需要从1开始");
            return;
        }
        for(int i=0;i<current_plant_book.size();i++){
            boxes[i]->setCheckState(Qt::Unchecked);
        }
        memset(row_forbid_plant[currentrow],false,sizeof(bool)*current_plant_book.size());
    }
    else if(ui->colforbid->isChecked()){
        int currentcol=ui->colnum->value()-1;
        if(currentcol==-1){
            ui->plantbookinfo->setText("列号需要从1开始");
            return;
        }
        for(int i=0;i<current_plant_book.size();i++){
            boxes[i]->setCheckState(Qt::Unchecked);
        }
        memset(col_forbid_plant[currentcol],false,sizeof(bool)*current_plant_book.size());
    }
    else if(ui->singleforbid->isChecked()){
        int currentrow=ui->rownum->value()-1;
        int currentcol=ui->colnum->value()-1;
        if(currentcol==-1||currentrow==-1){
            ui->plantbookinfo->setText("列/行号需要从1开始");
            return;
        }
        for(int i=0;i<current_plant_book.size();i++){
            boxes[i]->setCheckState(Qt::Unchecked);
        }
        single_forbid_plant[currentrow*10+currentcol].clear();
    }
    else if(ui->globalforbid->isChecked()){
        for(int i=0;i<current_plant_book.size();i++){
            boxes[i]->setCheckState(Qt::Unchecked);
        }
        memset(global_forbid_plant,false,sizeof(bool)*current_plant_book.size());
    }
    else if(ui->radioButton->isChecked()){
        for(int i=0;i<current_plant_book.size();i++){
            boxes[i]->setCheckState(Qt::Unchecked);
            global_gift_plant[i]=false;
        }
    }
    ui->plantbookinfo->setText("当前重置成功");
}


void MainWindow::on_globalreset_clicked()
{
    for(int i=0;i<6;i++)memset(row_forbid_plant[i],false,sizeof(bool)*current_plant_book.size());
    for(int i=0;i<10;i++)memset(col_forbid_plant[i],false,sizeof(bool)*current_plant_book.size());
    for(int i=0;i<60;i++)single_forbid_plant[i].clear();
    for(int i=0;i<current_plant_book.size();i++){
        if(boxes.size()!=0)boxes[i]->setCheckState(Qt::Unchecked);
        global_gift_plant[i]=false;
    }
    memset(global_forbid_plant,false,sizeof(bool)*current_plant_book.size());
    ui->plantbookinfo->setText("全局重置成功");
}


void MainWindow::on_sureforbid_clicked()
{
    if(ui->rowforbid->isChecked()){
        int currentrow=ui->rownum->value()-1;
        if(currentrow==-1) {
            ui->plantbookinfo->setText("行号需要从1开始");
            return;
        }
        for(int i=0;i<current_plant_book.size();i++){
            row_forbid_plant[currentrow][i]=boxes[i]->isChecked();
        }
        //on_rowforbid_clicked();
    }
    else if(ui->colforbid->isChecked()){
        int currentcol=ui->colnum->value()-1;
        if(currentcol==-1){
            ui->plantbookinfo->setText("列号需要从1开始");
            return;
        }
        for(int i=0;i<current_plant_book.size();i++){
            col_forbid_plant[currentcol][i]=boxes[i]->isChecked();
        }
        //on_colforbid_clicked();
    }
    else if(ui->singleforbid->isChecked()){
        int currentrow=ui->rownum->value()-1;
        int currentcol=ui->colnum->value()-1;
        if(currentcol==-1||currentrow==-1){
            ui->plantbookinfo->setText("列/行号需要从1开始");
            return;
        }
        for(int i=0;i<current_plant_book.size();i++){
            if(boxes[i]->isChecked()){
                single_forbid_plant[currentrow*10+currentcol].insert(i);
            }
        }
        //on_singleforbid_clicked();
    }
    else if(ui->radioButton->isChecked()){
        for(int i=0;i<current_plant_book.size();i++){
            global_gift_plant[i]=boxes[i]->isChecked();
        }
    }
    else if(ui->globalforbid->isChecked()){
        for(int i=0;i<current_plant_book.size();i++){
            global_forbid_plant[i]=boxes[i]->isChecked();
        }
    }
    ui->plantbookinfo->setText("设置成功");
}


void MainWindow::on_randslot_stateChanged(int arg1)
{
    if (!CheckBoardOn())
    {
        ui->randplantinfo->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    if(arg1==Qt::Checked)
    {
        start_slotplantmoniter();
        ui->randplantinfo->setText("已开启随机卡槽(不使用时记得关闭)");
    }
    else if(arg1==Qt::Unchecked)
    {
        end_slotplantmoniter();
        ui->randplantinfo->setText("已关闭随机卡槽");
    }
}

void MainWindow::start_slotplantmoniter()
{
    if(slot_plant_moniter)
        return;
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 子线程：随机卡槽开始运行\n").arg(currentTime);
        out.flush();
    }
    slot_plant_moniter=new slotplantmoniter;
    slot_plant_moniter->thread_survive=true;
    slot_plant_moniter->is_forbid=ui->forbidaffectrandslot->isChecked();
    slot_plant_moniter->plantbooksize= this->current_plant_book.size();
    slot_plant_moniter->mouseslotaddr= ReadMemory<uint32_t>({lawn,board,cursor_off});
    connect(slot_plant_moniter,&slotplantmoniter::threadend,this,&MainWindow::end_slotplantmoniter);
    slot_plant_moniter->start();
}

void MainWindow::end_slotplantmoniter()
{

    if(!slot_plant_moniter) return;
    if(slot_plant_moniter->setthread){
        slot_plant_moniter->setthread->thread_survive=false;
        slot_plant_moniter->setthread->exit();
        slot_plant_moniter->setthread->wait();
        delete slot_plant_moniter->setthread;
        slot_plant_moniter->setthread=nullptr;
    }
    slot_plant_moniter->thread_survive=false;
    slot_plant_moniter->exit();
    slot_plant_moniter->wait();
    delete slot_plant_moniter;
    slot_plant_moniter=nullptr;
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 子线程：随机卡槽结束运行\n").arg(currentTime);
        out.flush();
    }
    ui->randslot->setCheckState(Qt::Unchecked);
}

void MainWindow::on_startforbid_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        if(!ui->startforbidplace->isChecked()){
            ui->randplantinfo->setText("种植准备中未开启禁种");
            ui->startforbid->setCheckState(Qt::Unchecked);
            return;
        }
        ui->randplantinfo->setText("已启用禁种");
    }
    else if(arg1==Qt::Unchecked&&ui->startforbidplace->isChecked()){
        ui->randplantinfo->setText("关闭禁种");
    }
}


void MainWindow::on_createselections_clicked()
{
    randcurrentrow=ui->randrownum->value()-1;
    ui->selectnoplant->setChecked(true);
    if(CheckBoardOn())
    {
        int nowmaprow=GetRowCount();
        if(randcurrentrow+1>nowmaprow){
            randcurrentrow=nowmaprow-1;
            ui->randplantinfo->setText("设置的行数超过了当前地图行数，已自动调整");
            ui->randrownum->setValue(nowmaprow);
        }
    }
    randcurrentcol=ui->randcolnum->value()-1;
    if(randplantboxes.size()!=0){
        for(int i=0;i<randplantboxes.size();i++){
            delete randplantboxes[i];
        }
        randplantboxes.clear();
        while (QLayoutItem* item = ui->randplantgridlayout->takeAt(0)) {
            QWidget* widget = item->widget();
            if (widget) {
                ui->randplantgridlayout->removeWidget(widget); // 从布局中移除部件
                delete widget; // 删除部件
            }
            delete item; // 删除布局项
        }
    }
    randplantboxes.resize((randcurrentrow+1)*(randcurrentcol+1));
    for(int i=0;i<randplantboxes.size();i++){
        QCheckBox* newbox=new QCheckBox;
        newbox->setText(QString("%1行%2列").arg(i/(randcurrentcol+1)+1).arg(i%(randcurrentcol+1)+1));
        randplantboxes[i]=newbox;
        ui->randplantgridlayout->addWidget(newbox,i/(randcurrentcol+1),i%(randcurrentcol+1));
    }
    ui->scrollAreaWidgetContents_2->setLayout(ui->randplantgridlayout);
    ui->scrollArea_2->setWidget(ui->scrollAreaWidgetContents_2);
    ui->scrollArea_2->setWidgetResizable(true);
    is_randplant_createselections=true;
}


void MainWindow::on_forbidaffectrandslot_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        if(!ui->startforbid->isChecked()){
            ui->randplantinfo->setText("请先启用禁种");
            ui->forbidaffectrandslot->setCheckState(Qt::Unchecked);
            return;
        }
        else{
            if(slot_plant_moniter){
               slot_plant_moniter->is_forbid=true;
            }
        }
        return;
    }
    else if(arg1==Qt::Unchecked){
        if(slot_plant_moniter){
            slot_plant_moniter->is_forbid=false;
        }
    }
}


void MainWindow::on_randplantreset_clicked()
{
    for(size_t i=0;i<randplantboxes.size();i++)
    {
        randplantboxes[i]->setCheckState(Qt::Unchecked);
    }
    ui->randplantinfo->setText("重置完成");
}


void MainWindow::on_startrandplaceplant_clicked()
{
    if(!is_randplant_createselections){
        ui->randplantinfo->setText("请先生成选择项");
        return;
    }
    if (!CheckBoardOn())
    {
        ui->randplantinfo->setText("未检测到游戏，种植终止");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏，随机种植终止\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    vector<bool> plantposition((randcurrentcol+1)*(randcurrentrow+1));
    for(size_t i=0;i<randplantboxes.size();i++){
        if(ui->selectnoplant->isChecked())plantposition[i]=!randplantboxes[i]->isChecked();
        else if(ui->selectplant->isChecked())plantposition[i]=randplantboxes[i]->isChecked();
    }
    if(RandPlantplace(plantposition,ui->startforbid->isChecked(),current_plant_book.size(),randcurrentcol+1)){
        ui->randplantinfo->setText("种植完成");
    }
    else{
        ui->randplantinfo->setText("随机种植终止，因为没有植物种植");
    }
}


void MainWindow::on_radioButton_clicked()
{
    if(boxes.size()==0){
        boxes.clear();
        boxes.resize(current_plant_book.size());
        for(int i=0;i<current_plant_book.size();i++){
            boxes[i]=new QCheckBox;
            boxes[i]->setText(QString("[%1]").arg(i)+current_plant_book[i]);
            ui->forbidgridlayout->addWidget(boxes[i],i/6,i%6);
        }
        ui->scrollAreaWidgetContents->setLayout(ui->forbidgridlayout);
        ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
        ui->scrollArea->setWidgetResizable(true);
    }
    for(int i=0;i<current_plant_book.size();i++){
        if(global_gift_plant[i]) boxes[i]->setCheckState(Qt::Checked);
        else boxes[i]->setCheckState(Qt::Unchecked);
    }
}


void MainWindow::on_singleplantplace_clicked()
{
    if (!CheckBoardOn())
    {
        ui->singleplantplaceinfo->setText("未检测到游戏");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏，随机种植终止\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    uint32_t nextpositon=ReadMemory<uint32_t>({lawn,board,plant_next_plant_position});
    SinglePlantPlace(ui->chooseplanttype->currentIndex(),ui->freerownum->value()-1,ui->freecolnum->value()-1);
    uint32_t currentaddr=ReadMemory<uint32_t>({lawn,board,plant_offset})+nextpositon*plant_single_size;
    if(ui->plantblood->value()!=0){
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 开始设置血量\n").arg(currentTime);
            out.flush();
        }
        WriteMemory<uint32_t>(ui->plantblood->value(),{currentaddr+plant_blood});
    }
    if(ui->plantattackinterval->value()!=0){
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 开始设置攻击间隔\n").arg(currentTime);
            out.flush();
        }
        WriteMemory<uint32_t>(ui->plantattackinterval->value(),{currentaddr+plant_attack_interval});
    }
    if(ui->shingingtime->value()!=0){
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 开始设置发光时间\n").arg(currentTime);
            out.flush();
        }
        WriteMemory<uint32_t>(ui->shingingtime->value(),{currentaddr+plant_shine_time});
    }
    if(ui->flashingtime->value()!=0){
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 开始设置闪光时间\n").arg(currentTime);
            out.flush();
        }
        WriteMemory<uint32_t>(ui->flashingtime->value(),{currentaddr+plant_flash_time});
    }
    ui->singleplantplaceinfo->setText("种植完成");
}


void MainWindow::son_creatselections_freeplant_clicked()
{
    freecurrentrow=ui->multifreerownum->value();
    if(CheckBoardOn())
    {
        int nowmaprow=GetRowCount();
        if(freecurrentrow>nowmaprow){
            freecurrentrow=nowmaprow;
            ui->singleplantplaceinfo->setText("不要超过地图行数");
            ui->multifreerownum->setValue(nowmaprow);
        }
    }
    freecurrentcol=ui->multifreecolnum->value();
    if(freeplantlayouts.size()==0){
        freeplantlayouts.resize(freecurrentrow*freecurrentcol);
        for(int i=0;i<freeplantlayouts.size();i++){
            freeplantlayouts[i]=new QHBoxLayout;
            QLabel *newlabel=new QLabel;
            newlabel->setText(QString("%1行%2列").arg(i/freecurrentcol+1).arg(i%freecurrentcol+1));
            freeplantlayouts[i]->addWidget(newlabel);
            QComboBox *newcomb=new QComboBox;
            newcomb->setFixedWidth(100);
            newcomb->addItem("");
            for(int i=0;i<current_plant_book.size();i++){
                newcomb->addItem(QString("[%1]%2").arg(i).arg(current_plant_book[i]));
            }
            freeplant_typeboxes.push_back(newcomb);
            freeplantlayouts[i]->addWidget(newcomb);
            QLabel *newlabel_blood=new QLabel;
            newlabel_blood->setText("血量");
            freeplantlayouts[i]->addWidget(newlabel_blood);
            QSpinBox* newspin=new QSpinBox;
            newspin->setFixedWidth(60);
            newspin->setMaximum(999999999);
            newspin->setMinimum(0);
            freeplantlayouts[i]->addWidget(newspin);
            freeplant_bloodboxes.push_back(newspin);
            QLabel *newlabel_interval=new QLabel;
            newlabel_interval->setText("攻击间隔");
            freeplantlayouts[i]->addWidget(newlabel_interval);
            QSpinBox* newspin2=new QSpinBox;
            newspin2->setFixedWidth(60);
            newspin2->setMaximum(999999999);
            newspin2->setMinimum(0);
            freeplant_intervalboxes.push_back(newspin2);
            freeplantlayouts[i]->addWidget(newspin2);
            ui->freeplantgridlayout->addLayout(freeplantlayouts[i],i/freecurrentcol,i%freecurrentcol);
        }
        if(!ui->enableinterval->isChecked()){
            for(int i=0;i<freeplantlayouts.size();i++){
                QLayoutItem *item=freeplantlayouts[i]->itemAt(5);
                item->widget()->setVisible(false);
                item=freeplantlayouts[i]->itemAt(4);
                item->widget()->setVisible(false);
            }
        }
        if(!ui->enableblood->isChecked()){
            for(int i=0;i<freeplantlayouts.size();i++){
                QLayoutItem *item=freeplantlayouts[i]->itemAt(3);
                item->widget()->setVisible(false);
                item=freeplantlayouts[i]->itemAt(2);
                item->widget()->setVisible(false);
            }
        }
        ui->scrollAreaWidgetContents_3->setLayout(ui->freeplantgridlayout);
        ui->scrollArea_3->setWidget(ui->scrollAreaWidgetContents_3);
        ui->scrollArea_3->setWidgetResizable(true);
        return;
    }
    else{
        ui->rowtogether->setCheckState(Qt::Unchecked);
        ui->coltogether->setCheckState(Qt::Unchecked);
        freeplant_bloodboxes.clear();
        freeplant_intervalboxes.clear();
        freeplant_typeboxes.clear();
        while(QLayoutItem *item=ui->freeplantgridlayout->takeAt(0)){
            if (item && item->layout()) {
            QHBoxLayout *hboxLayout = qobject_cast<QHBoxLayout*>(item->layout());
            if (hboxLayout) {
                while (QLayoutItem *widgetItem = hboxLayout->takeAt(0)) {
                    if (QWidget *widget = widgetItem->widget()) {
                        hboxLayout->removeWidget(widget);
                        delete widget;
                    }
                    delete widgetItem;
                }
                ui->freeplantgridlayout->removeItem(item);
                delete item;
                hboxLayout=nullptr;
                //delete hboxLayout;
            }
        }
        }
        freeplantlayouts.clear();
        on_creatselections_freeplant_clicked();
    }
}


void MainWindow::on_enableblood_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        if(freeplantlayouts.size()==0) return;
        else{
            for(int i=0;i<freeplantlayouts.size();i++){
                QLayoutItem *item=freeplantlayouts[i]->itemAt(3);
                item->widget()->setVisible(true);
                item=freeplantlayouts[i]->itemAt(2);
                item->widget()->setVisible(true);
            }
        }
    }
    else if(arg1==Qt::Unchecked){
        if(freeplantlayouts.size()==0) return;
        else{
            for(int i=0;i<freeplantlayouts.size();i++){
                QLayoutItem *item=freeplantlayouts[i]->itemAt(3);
                item->widget()->setVisible(false);
                item=freeplantlayouts[i]->itemAt(2);
                item->widget()->setVisible(false);
            }
        }
    }
}


void MainWindow::on_enableinterval_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        if(freeplantlayouts.size()==0) return;
        else{
            for(int i=0;i<freeplantlayouts.size();i++){
                QLayoutItem *item=freeplantlayouts[i]->itemAt(5);
                item->widget()->setVisible(true);
                item=freeplantlayouts[i]->itemAt(4);
                item->widget()->setVisible(true);
            }
        }
    }
    else if(arg1==Qt::Unchecked){
        if(freeplantlayouts.size()==0) return;
        else{
            for(int i=0;i<freeplantlayouts.size();i++){
                QLayoutItem *item=freeplantlayouts[i]->itemAt(5);
                item->widget()->setVisible(false);
                item=freeplantlayouts[i]->itemAt(4);
                item->widget()->setVisible(false);
            }
        }
    }
}


void MainWindow::on_rowtogether_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        if(freeplantlayouts.size()==0) return;
        for (int i = 0; i < freecurrentcol; ++i) {
            for (int j = 0; j < freecurrentrow; ++j) {
                QComboBox* comboBox = freeplant_typeboxes[j*freecurrentcol+i];
                QSpinBox* spinBox1 = freeplant_bloodboxes[j*freecurrentcol+i];
                QSpinBox* spinBox2 = freeplant_intervalboxes[j*freecurrentcol+i];

                connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
                        this, &MainWindow::comboBoxIndexChangedRow);
                connect(spinBox1, QOverload<int>::of(&QSpinBox::valueChanged),
                        this, &MainWindow::spinBoxValueChangedRow);
                connect(spinBox2, QOverload<int>::of(&QSpinBox::valueChanged),
                        this, &MainWindow::spinBoxValueChangedRow);

            }
        }
    }
    else if(arg1==Qt::Unchecked){
        if(freeplantlayouts.size()==0) return;
        for (int i = 0; i < freecurrentcol; ++i) {
            for (int j = 0; j < freecurrentrow; ++j) {
                QComboBox* comboBox = freeplant_typeboxes[j*freecurrentcol+i];
                QSpinBox* spinBox1 = freeplant_bloodboxes[j*freecurrentcol+i];
                QSpinBox* spinBox2 = freeplant_intervalboxes[j*freecurrentcol+i];

                disconnect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
                        this, &MainWindow::comboBoxIndexChangedRow);
                disconnect(spinBox1, QOverload<int>::of(&QSpinBox::valueChanged),
                        this, &MainWindow::spinBoxValueChangedRow);
                disconnect(spinBox2, QOverload<int>::of(&QSpinBox::valueChanged),
                        this, &MainWindow::spinBoxValueChangedRow);

            }
        }
    }
}

void MainWindow::comboBoxIndexChangedRow(int index) {
    QObject* senderObj = sender();
    // 查找是哪个 comboBox 发出了信号
    int row = -1, column = -1;
    for (int i = 0; i < freecurrentrow; ++i) {
        for (int j = 0; j < freecurrentcol; ++j) {
            if ( freeplant_typeboxes[i*freecurrentcol+j] == static_cast<QComboBox*>(senderObj)) {
                row = i;
                column = j;
                break;
            }
        }
    }

    if (row != -1 && column != -1) {
        // 更新同一行
        for (int j = 0; j < freecurrentcol; ++j) {
            freeplant_typeboxes[row*freecurrentcol+j]->setCurrentIndex(index);
            freeplant_bloodboxes[row*freecurrentcol+j]->setValue(freeplant_bloodboxes[row*freecurrentcol+column]->value());
            freeplant_intervalboxes[row*freecurrentcol+j]->setValue(freeplant_intervalboxes[row*freecurrentcol+column]->value());
        }
    }
}

// spinBox 的值发生变化时的槽函数
void MainWindow::spinBoxValueChangedRow(int value) {
    QObject* senderObj = sender();
    // 查找是哪个 spinBox 发出了信号
    int row = -1, column = -1;
    for (int i = 0; i < freecurrentrow; ++i) {
        for (int j = 0; j < freecurrentcol; ++j) {
            if ( freeplant_intervalboxes[i*freecurrentcol+j] == static_cast<QSpinBox*>(senderObj)||
                freeplant_bloodboxes[i*freecurrentcol+j] == static_cast<QSpinBox*>(senderObj)) {
                row = i;
                column = j;
                break;
            }
        }
    }

    if (row != -1 && column != -1) {
        // 更新同一行
        for (int j = 0; j < freecurrentcol; ++j) {
            freeplant_typeboxes[row*freecurrentcol+j]->setCurrentIndex(freeplant_typeboxes[row*freecurrentcol+column]->currentIndex());
            freeplant_bloodboxes[row*freecurrentcol+j]->setValue(freeplant_bloodboxes[row*freecurrentcol+column]->value());
            freeplant_intervalboxes[row*freecurrentcol+j]->setValue(freeplant_intervalboxes[row*freecurrentcol+column]->value());
        }
    }
}

void MainWindow::comboBoxIndexChangedCol(int index) {
    QObject* senderObj = sender();
    // 查找是哪个 comboBox 发出了信号
    int row = -1, column = -1;
    for (int i = 0; i < freecurrentrow; ++i) {
        for (int j = 0; j < freecurrentcol; ++j) {
            if ( freeplant_typeboxes[i*freecurrentcol+j] == static_cast<QComboBox*>(senderObj)) {
                row = i;
                column = j;
                break;
            }
        }
    }

    if (row != -1 && column != -1) {
        // 更新同一列
        for (int j = 0; j < freecurrentrow; ++j) {
            freeplant_typeboxes[j*freecurrentcol+column]->setCurrentIndex(freeplant_typeboxes[row*freecurrentcol+column]->currentIndex());
            freeplant_bloodboxes[j*freecurrentcol+column]->setValue(freeplant_bloodboxes[row*freecurrentcol+column]->value());
            freeplant_intervalboxes[j*freecurrentcol+column]->setValue(freeplant_intervalboxes[row*freecurrentcol+column]->value());
        }
    }
}

// spinBox 的值发生变化时的槽函数
void MainWindow::spinBoxValueChangedCol(int value) {
    QObject* senderObj = sender();
    // 查找是哪个 spinBox 发出了信号
    int row = -1, column = -1;
    for (int i = 0; i < freecurrentrow; ++i) {
        for (int j = 0; j < freecurrentcol; ++j) {
            if ( freeplant_intervalboxes[i*freecurrentcol+j] == static_cast<QSpinBox*>(senderObj)||
                freeplant_bloodboxes[i*freecurrentcol+j] == static_cast<QSpinBox*>(senderObj)) {
                row = i;
                column = j;
                break;
            }
        }
    }

    if (row != -1 && column != -1) {
        // 更新同一列
        for (int j = 0; j < freecurrentrow; ++j) {
            freeplant_typeboxes[j*freecurrentcol+column]->setCurrentIndex(freeplant_typeboxes[row*freecurrentcol+column]->currentIndex());
            freeplant_bloodboxes[j*freecurrentcol+column]->setValue(freeplant_bloodboxes[row*freecurrentcol+column]->value());
            freeplant_intervalboxes[j*freecurrentcol+column]->setValue(freeplant_intervalboxes[row*freecurrentcol+column]->value());
        }
    }
}

void MainWindow::on_coltogether_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        if(freeplantlayouts.size()==0) return;
        for (int i = 0; i < freecurrentcol; ++i) {
            for (int j = 0; j < freecurrentrow; ++j) {
                QComboBox* comboBox = freeplant_typeboxes[j*freecurrentcol+i];
                QSpinBox* spinBox1 = freeplant_bloodboxes[j*freecurrentcol+i];
                QSpinBox* spinBox2 = freeplant_intervalboxes[j*freecurrentcol+i];

                connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
                        this, &MainWindow::comboBoxIndexChangedCol);
                connect(spinBox1, QOverload<int>::of(&QSpinBox::valueChanged),
                        this, &MainWindow::spinBoxValueChangedCol);
                connect(spinBox2, QOverload<int>::of(&QSpinBox::valueChanged),
                        this, &MainWindow::spinBoxValueChangedCol);

            }
        }
    }
    else if(arg1==Qt::Unchecked){
        if(freeplantlayouts.size()==0) return;
        for (int i = 0; i < freecurrentcol; ++i) {
            for (int j = 0; j < freecurrentrow; ++j) {
                QComboBox* comboBox = freeplant_typeboxes[j*freecurrentcol+i];
                QSpinBox* spinBox1 = freeplant_bloodboxes[j*freecurrentcol+i];
                QSpinBox* spinBox2 = freeplant_intervalboxes[j*freecurrentcol+i];

                disconnect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
                           this, &MainWindow::comboBoxIndexChangedCol);
                disconnect(spinBox1, QOverload<int>::of(&QSpinBox::valueChanged),
                            this, &MainWindow::spinBoxValueChangedCol);
                disconnect(spinBox2, QOverload<int>::of(&QSpinBox::valueChanged),
                            this, &MainWindow::spinBoxValueChangedCol);

            }
        }
    }
}


void MainWindow::on_creatselections_freeplant_clicked()
{
    son_creatselections_freeplant_clicked();
    is_freeplant_createselections=true;
}


void MainWindow::on_suretoplant_free_clicked()
{
    if(!is_freeplant_createselections) {
        ui->singleplantplaceinfo->setText("请先生成选择项");
        return;
    }
    if(CheckBoardOn())
    {
        int nowmaprow=GetRowCount();
        if(freecurrentrow>nowmaprow){
            freecurrentrow=nowmaprow;
            ui->singleplantplaceinfo->setText("不要超过地图行数");
            ui->multifreerownum->setValue(nowmaprow);
            return;
        }
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始批量种植\n").arg(currentTime);
        out.flush();
    }
    for(int i=0;i<freeplantlayouts.size();i++){
        if(freeplant_typeboxes[i]->currentIndex()==0) continue;
    if (!CheckBoardOn())
    {
        ui->singleplantplaceinfo->setText("未检测到游戏");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏，批量种植终止\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    uint32_t nextpositon=ReadMemory<uint32_t>({lawn,board,plant_next_plant_position});
    SinglePlantPlace(freeplant_typeboxes[i]->currentIndex()-1,i/freecurrentcol,i%freecurrentcol);
    uint32_t currentaddr=ReadMemory<uint32_t>({lawn,board,plant_offset})+nextpositon*plant_single_size;
    if(freeplant_bloodboxes[i]->value()!=0){
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 开始设置血量\n").arg(currentTime);
            out.flush();
        }
        WriteMemory<uint32_t>(freeplant_bloodboxes[i]->value(),{currentaddr+plant_blood});
    }
    if(freeplant_intervalboxes[i]->value()!=0){
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 开始设置攻击间隔\n").arg(currentTime);
            out.flush();
        }
        WriteMemory<uint32_t>(freeplant_intervalboxes[i]->value(),{currentaddr+plant_attack_interval});
    }
    }
    ui->singleplantplaceinfo->setText("种植完成");
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束批量种植\n").arg(currentTime);
        out.flush();
    }
}


void MainWindow::on_copy_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->formtext->toPlainText());
    ui->formationinfo->setText("已复制");
}


void MainWindow::on_paste_clicked()
{
    ui->formtext->paste();
    ui->formationinfo->setText("已粘贴");
}


void MainWindow::on_clearformationtext_clicked()
{
    ui->formtext->clear();
    ui->formationinfo->setText("已清空");
}


void MainWindow::on_clearplant_form_clicked()
{
    if (!CheckBoardOn())
    {
        ui->formationinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，清空植物终止\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ClearAllPlants();
    ui->formationinfo->setText("已清空");
}


void MainWindow::on_readfile_clicked()
{
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 尝试读取阵型文件\n").arg(currentTime);
        out.flush();
    }
    QMessageBox::information(this,"提示","请选择一个文本文件类型的文件，文件内的格式请务必按照本页面提示写\n分隔符随意。");
    QString filePath = QFileDialog::getOpenFileName(this, "Select File", "", "Text Files (*.txt)");
    if (filePath.isEmpty()) {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 用户未选择文件\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 打开文件:%2 成功\n").arg(currentTime).arg(filePath);
            out.flush();
        }
        QString temptext=in.readAll();
        ui->formtext->setText(temptext);
        ui->formationinfo->setText("读取文件成功");
    }
    else {
        ui->formationinfo->setText("读取文件失败");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 打开文件:%2 失败，错误码\n").arg(currentTime).arg(filePath).arg(GetLastError());
            out.flush();
        }
        return;
    }
    file.close();
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束读取阵型文件\n").arg(currentTime);
        out.flush();
    }
}


void MainWindow::on_savaasfile_clicked()
{
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始保存文件\n").arg(currentTime);
        out.flush();
    }
    QString textContent = ui->formtext->toPlainText();
    QString defaultFileName = "Formation.txt";
    QString filePath = QFileDialog::getSaveFileName(nullptr, "保存文件", QDir::homePath() + "/" + defaultFileName, "Text Files (*.txt)");
    if (filePath.isEmpty()) {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 用户未选择保存地址\n").arg(currentTime);
            out.flush();
        }
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        //qDebug() << "Failed to open file for writing:" << file.errorString();
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] Failed to open file for writing:%2\n").arg(currentTime).arg(file.errorString());
            out.flush();
        }
        return;
    }

    QTextStream fileOut(&file);
    fileOut << textContent;
    file.close();

    ui->formationinfo->setText(QString("文件保存成功：%1").arg(filePath));
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束保存文件\n").arg(currentTime);
        out.flush();
    }
}


void MainWindow::on_strtoform_clicked()
{
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始字符串转阵型\n").arg(currentTime);
        out.flush();
    }
    if (!CheckBoardOn())
    {
        ui->formationinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，字符串转阵型终止\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    QString formtext=ui->formtext->toPlainText();
    vector<vector<int>> plantinfo=StringCheck(formtext,ui->saveblood->isChecked(),ui->saveinterval->isChecked(),current_plant_book.size(),GetRowCount());
    if(plantinfo.size()==0) {
        ui->formationinfo->setText("字符串识别到错误数据");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 识别到错误数据，字符串转阵型终止\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    for(int i=0;i<plantinfo.size();i++){
        if (!CheckBoardOn())
        {
            ui->formationinfo->setText("未检测到游戏");
            if(out.device()){
                QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
                out<<QString("[%1] 未检测到关卡，字符串转阵型终止\n").arg(currentTime);
                out.flush();
            }
            return;
        }
        uint32_t nextpositon=ReadMemory<uint32_t>({lawn,board,plant_next_plant_position});
        SinglePlantPlace(plantinfo[i][0],plantinfo[i][1]-1,plantinfo[i][2]-1);
        uint32_t currentaddr=ReadMemory<uint32_t>({lawn,board,plant_offset})+nextpositon*plant_single_size;
        if(ui->saveblood->isChecked())
            {
            if(out.device()){
                QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
                out<<QString("[%1] 开始设置血量\n").arg(currentTime);
                out.flush();
            }
            if(plantinfo[i][3]!=0) WriteMemory<uint32_t>(plantinfo[i][3],{currentaddr+plant_blood});
        }
        if(ui->saveinterval->isChecked()){
            if(out.device()){
                QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
                out<<QString("[%1] 开始设置攻击间隔\n").arg(currentTime);
                out.flush();
            }
            if(!ui->saveblood->isChecked()){
                if(plantinfo[i][4]!=0)
                    WriteMemory<uint32_t>(plantinfo[i][3],{currentaddr+plant_attack_interval});
            }
            else {
                if(plantinfo[i][3]!=0)
                    WriteMemory<uint32_t>(plantinfo[i][4],{currentaddr+plant_attack_interval});
            }
        }
    }
    ui->formationinfo->setText("种植完成");
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束开始字符串转阵型\n").arg(currentTime);
        out.flush();
    }
}


void MainWindow::on_formtostr_clicked()
{
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始阵型转字符串\n").arg(currentTime);
        out.flush();
    }
    if (!CheckBoardOn())
    {
        ui->formationinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，阵型转字符串\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    QString fortext=FormToString(ui->saveblood->isChecked(),ui->saveinterval->isChecked());
    if(fortext.isEmpty()){
        ui->formationinfo->setText("发生错误或无植物");
        return;
    }
    ui->formtext->setText(fortext);
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束阵型转字符串\n").arg(currentTime);
        out.flush();
    }
}


void MainWindow::_on_isdefaultplantbook_zombie_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        current_zombie_book.clear();
        for(int i=0;i<33;i++){
            current_zombie_book<<this->default_zombie_book[i];
        }
        ui->currentzombiebookshow->clear();
        for(int i=0;i<33;i++){
            ui->currentzombiebookshow->addItem(QString("[%1]").arg(i)+current_zombie_book.at(i));
        }
        zombieforbidboxes.clear();
        while (QLayoutItem* item = ui->zombieforbidgridout->takeAt(0)) {
            QWidget* widget = item->widget();
            if (widget) {
                ui->zombieforbidgridout->removeWidget(widget);
                delete widget;
            }
            delete item;
        }
        ui->settingblindbox->clear();
        for(int i=0;i<33;i++){
            ui->settingblindbox->addItem(QString("[%1]").arg(i)+current_zombie_book.at(i));
        }
        ui->settingblindbox->setCurrentIndex(2);
        global_forbid_zombie.clear();
        global_forbid_zombie.resize(current_zombie_book.size());
        global_forbid_zombie[25]=true;
        ui->autozombietype->clear();
        for(int i=0;i<33;i++){
            ui->autozombietype->addItem(QString("[%1]").arg(i)+current_zombie_book.at(i));
        }
        ui->freezombietype->clear();
        for(int i=0;i<current_zombie_book.size();i++){
            ui->freezombietype->addItem(QString("[%1]").arg(i)+current_zombie_book.at(i));
        }
        return;
    }
    if(ui->startforbidplace_zombie->isChecked())ui->startforbidplace_zombie->setCheckState(Qt::Unchecked);
    ui->settingblindbox->clear();
    for(int i=0;i<current_zombie_book.size();i++){
        ui->settingblindbox->addItem(QString("[%1]").arg(i)+current_zombie_book.at(i));
    }
    ui->autozombietype->clear();
    for(int i=0;i<current_zombie_book.size();i++){
        ui->autozombietype->addItem(QString("[%1]").arg(i)+current_zombie_book.at(i));
    }
    ui->freezombietype->clear();
    for(int i=0;i<current_zombie_book.size();i++){
        ui->freezombietype->addItem(QString("[%1]").arg(i)+current_zombie_book.at(i));
    }
}


void MainWindow::_on_updateplantbook_zombie_clicked()
{

    if(out.device()){

        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 尝试更新僵尸图鉴\n").arg(currentTime);
        out.flush();
    }
    temp_zombie_book.clear();
    QMessageBox::information(this,"提示","请选择一个文本文件类型的文件，文件内的格式请务必按照实际顺序写下\n僵尸的名称，每个僵尸以换行或空格隔开。");
    QString filePath = QFileDialog::getOpenFileName(this, "Select File", "", "Text Files (*.txt)");
    if (filePath.isEmpty()) {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 用户未选择文件\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 打开文件:%2 成功\n").arg(currentTime).arg(filePath);
            out.flush();
        }
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList words = line.split(QRegularExpression("[\\s]+"));
            temp_zombie_book<<words;
        }
        ui->zombiebookinfo->setText("读取文件成功");
    }
    else {
        ui->zombiebookinfo->setText("读取文件失败");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 打开文件:%2 失败，错误码\n").arg(currentTime).arg(filePath).arg(GetLastError());
            out.flush();
        }
        return;
    }
    if(temp_zombie_book.isEmpty()){
        ui->zombiebookinfo->setText("获取僵尸图鉴失败");
        return;
    }
    ui->currentzombiebookshow->clear();
    for(int i=0;i<temp_zombie_book.size();i++){
        ui->currentzombiebookshow->addItem(QString("[%1]").arg(i)+temp_zombie_book.at(i));
    }
    file.close();
}


void MainWindow::_on_sureupdatezombiebook_clicked()
{
    current_zombie_book.clear();
    current_zombie_book=temp_zombie_book;
    temp_zombie_book.clear();
    ui->zombiebookinfo->setText("更新僵尸图鉴成功");
    ui->isdefaultplantbook_zombie->setCheckState(Qt::Unchecked);
    if(ui->startforbidplace_zombie->isChecked())ui->startforbidplace_zombie->setCheckState(Qt::Unchecked);
    zombieforbidboxes.clear();
    while (QLayoutItem* item = ui->zombieforbidgridout->takeAt(0)) {
        QWidget* widget = item->widget();
        if (widget) {
            ui->zombieforbidgridout->removeWidget(widget);
            delete widget;
        }
        delete item;
    }
    global_forbid_zombie.clear();
    global_forbid_zombie.resize(current_zombie_book.size());
}


void MainWindow::on_sureupdatezombiebook_clicked()
{
    if(temp_zombie_book.size()==0) return;
    _on_sureupdatezombiebook_clicked();
}


void MainWindow::on_updateplantbook_zombie_clicked()
{
    _on_updateplantbook_zombie_clicked();
}


void MainWindow::on_isdefaultplantbook_zombie_stateChanged(int arg1)
{
    _on_isdefaultplantbook_zombie_stateChanged(arg1);
}


void MainWindow::on_suretosetblindbox_clicked()
{
    if(!ui->randblindboxmode->isChecked()){
        ui->zombiebookinfo->setText(QString("请先打开本软件的随机盲盒模式"));
        ui->settingblindbox->setCurrentIndex(2);
        return;
    }
    blindzombie=ui->settingblindbox->currentIndex();
    ui->zombiebookinfo->setText(QString("设置%1为盲盒僵尸").arg(current_zombie_book[blindzombie]));
    if(bSearch){
        bSearch->boxtype=blindzombie;
        if(bSearch->bMoniter)bSearch->bMoniter->boxtype=blindzombie;
    }
}


void MainWindow::on_startforbidplace_zombie_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        zombieforbidboxes.clear();
        zombieforbidboxes.resize(current_zombie_book.size());
        for(int i=0;i<current_zombie_book.size();i++){
            zombieforbidboxes[i]=new QCheckBox;
            zombieforbidboxes[i]->setText(QString("[%1]").arg(i)+current_zombie_book[i]);
            ui->zombieforbidgridout->addWidget(zombieforbidboxes[i],i/6,i%6);
            if(global_forbid_zombie[i])zombieforbidboxes[i]->setCheckState(Qt::Checked);
        }
        ui->scrollAreaWidgetContents_4->setLayout(ui->zombieforbidgridout);
        ui->scrollArea_4->setWidget(ui->scrollAreaWidgetContents_4);
        ui->scrollArea_4->setWidgetResizable(true);
    }
    else if(arg1==Qt::Unchecked)
    {
        while (QLayoutItem* item = ui->zombieforbidgridout->takeAt(0)) {
            QWidget* widget = item->widget();
            if (widget) {
                ui->zombieforbidgridout->removeWidget(widget);
                delete widget;
            }
            delete item;
        }
    }
}


void MainWindow::on_globalreset_2_clicked()
{
    if(!ui->startforbidplace_zombie->isChecked()) return;
    for(int i=0;i<current_zombie_book.size();i++){
        zombieforbidboxes[i]->setCheckState(Qt::Unchecked);
        global_forbid_zombie[i]=false;
    }
    ui->zombiebookinfo->setText("重置成功");
}


void MainWindow::on_sureforbid_2_clicked()
{
    if(!ui->startforbidplace_zombie->isChecked()) return;
    for(int i=0;i<current_zombie_book.size();i++){
        global_forbid_zombie[i]=zombieforbidboxes[i]->isChecked();;
    }
    ui->zombiebookinfo->setText("设置禁止放置成功");
}


void MainWindow::on_startmower_clicked()
{
    if (!CheckBoardOn())
    {
        ui->puttingstatus->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    if(ui->mowerrow->value()>GetRowCount()) {
        ui->puttingstatus->setText("超出地图行数");
        return;
    }
    Startmower(ui->mowerrow->value());
}


void MainWindow::on_clearmower_clicked()
{
    if (!CheckBoardOn())
    {
        ui->puttingstatus->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    if(ui->mowerrow->value()>GetRowCount()) {
        ui->puttingstatus->setText("超出地图行数");
        return;
    }
    Clearmower(ui->mowerrow->value());
}


void MainWindow::on_resummower_clicked()
{
    if (!CheckBoardOn())
    {
        ui->puttingstatus->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    Resumemower();
}


void MainWindow::AutoZombieRowColInit()
{
    ui->autozombierow->SetSearchBarHidden(true);
    //ui->autozombiecol->SetSearchBarHidden(true);
    ui->autozombierow->setFixedWidth(100);
    ui->autozombiecol->setFixedWidth(100);
    for(int i=0;i<7;i++){
        ui->autozombierow->addItem(QString("%1").arg(i));
    }
    for(int i=0;i<14;i++){
        ui->autozombiecol->addItem(QString("%1").arg(i));
    }
    ui->autozombiecol->setCheckAllitem(0);
    ui->autozombierow->setCheckAllitem(0);
}

vector<int> MainWindow::QStringListToVector(const QStringList& stringList) {
    vector<int> intVector;
    for(const QString& str : stringList) {
        QStringList parts = str.split(";");
        for (const QString& part : parts) {
            bool ok;
            int num = part.toInt(&ok);
            if (ok) {
                intVector.push_back(num);
            } else {
                return vector<int>();
            }
        }
    }

    return intVector;
}

void MainWindow::on_directputonce_clicked()
{
    if (!CheckBoardOn())
    {
        ui->puttingstatus->setText("未检测到游戏");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始放置僵尸\n").arg(currentTime);
        out.flush();
    }
    QStringList rowlist=ui->autozombierow->currentText();
    QStringList collist=ui->autozombiecol->currentText();
    vector<int> Row=QStringListToVector(rowlist);
    vector<int> Col=QStringListToVector(collist);
    if(Row.size()==0||Col.size()==0){
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未选择行列，结束放置\n").arg(currentTime);
            out.flush();
        }
        ui->puttingstatus->setText("未选择行列");
        return;
    }
    if(Row.back()>GetRowCount())Row.pop_back();
    PutZombie(ui->autozombietype->currentIndex(),Row,Col);
    ui->puttingstatus->setText("放置完成");
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束放置僵尸\n").arg(currentTime);
        out.flush();
    }
}


void MainWindow::on_pushButton_clicked()
{
    if (!CheckBoardOn())
    {
        ui->puttingstatus->setText("未检测到游戏");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    KillAllZombies();
}


void MainWindow::on_pausewithgame_stateChanged(int arg1)
{
    pausewithgame=ui->pausewithgame->isChecked();
    if(zombieput)zombieput->pausewithgame=pausewithgame;
}


void MainWindow::on_autospicy_stateChanged(int arg1)
{
    if (!CheckBoardOn())
    {
        ui->puttingstatus->setText("未检测到游戏");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        ui->autospicy->setCheckState(Qt::Unchecked);
        return;
    }
    if(!autospicy&&ui->autospicy->isChecked()){
        autospicy=new SpiceThread;
        connect(autospicy,&SpiceThread::abnormaltermi,this,[&](){
            ui->puttingstatus->setText("未检测到关卡");
            if(out.device()){
                QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
                out<<QString("[%1] 自动辣椒线程监测到关卡退出，自动结束辣椒放置。\n").arg(currentTime);
                out.flush();
            }
            ui->autospicy->setCheckState(Qt::Unchecked);
        });
        autospicy->start();
    }
    else if(!ui->autospicy->isChecked()){
        autospicy->stop();
        autospicy->wait();
        delete autospicy;
        autospicy=nullptr;
    }
}


void MainWindow::on_pauseputting_clicked()
{
    if(is_pauseputting){
        ui->pauseputting->setText("暂停放置");
        if(autospicy) autospicy->resume();
        if(zombieput) {
            ui->puttingstatus->setText("放置中……");
            zombieput->resume();
        }
        is_pauseputting=false;
        return;
    }
    else if(zombieput){
        ui->pauseputting->setText("继续放置");
        if(autospicy) autospicy->pause();
        if(zombieput){
            ui->puttingstatus->setText("暂停放置");
            zombieput->pause();
        }
        is_pauseputting=true;
        return;
    }

}


void MainWindow::on_stopputting_clicked()
{
    if(zombieput){
        ui->puttingstatus->setText("已终止放置");
        zombieput->stop();
        zombieput->wait();
        delete zombieput;
        zombieput=nullptr;
    }
    is_pauseputting=false;
    on_pauseputting_clicked();
}

void MainWindow::AutoZombieChangetableInit()
{
    ui->changetable->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
    ui->changetable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->changetable->resizeRowsToContents();
    ui->changetable->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->changetable->setRowCount(0);
    ui->changetable->setColumnCount(2);
    QHeaderView* view = new QHeaderView(Qt::Horizontal);
    QStandardItemModel* model = new QStandardItemModel;
    QStringList labels;
    labels << QStringLiteral("时间节点min") << QStringLiteral("节点内速率s");
    model->setHorizontalHeaderLabels(labels);
    view->setModel(model);
    ui->changetable->setHorizontalHeader(view);
    ui->changetable->verticalHeader()->setDefaultSectionSize(20);
    connect(ui->changetable,&QTableWidget::itemChanged,this,&MainWindow::rankchangetable);
}


void MainWindow::on_addnode_clicked()
{
    int newRow =  ui->changetable->rowCount();
    is_tableadding=true;
    ui->changetable->insertRow(newRow);
    ui->changetable->setItem(newRow, 0, new QTableWidgetItem(""));
    ui->changetable->setItem(newRow, 1, new QTableWidgetItem(""));
    is_tableadding=false;
}

void MainWindow::rankchangetable(QTableWidgetItem *item)
{
    if(is_tableediting||is_tableadding||is_timeerroring) return;
    item->setTextAlignment(Qt::AlignCenter);
    int row = item->row();
    int column = item->column();
    bool ok;
    double value=ui->changetable->item(row,column)->text().toDouble(&ok);
    if(is_tabledeleting) {
        if(row>=time_list.size()){
            is_tabledeleting=false;
            return;
        }
        goto showtabel;
    }
    if(!ok||!value){
        ui->puttingstatus->setText("请输入正确的数字");
        if(row>=time_list.size()){
            ui->changetable->item(row,column)->setText("");
            return;
        }
        if(column==0) ui->changetable->item(row,column)->setText(QString::number(time_list[row], 'f', 2));
        else ui->changetable->item(row,column)->setText(QString::number(rate_list[row], 'f', 2));
        return;
    }
    if(column==0){
        int num=value*100;
        value=(double)num/100.00;
        for(int i=0;i<time_list.size();i++){
            if(fabs(time_list[i]-value)<0.0099){
                is_timeerroring=true;
                ui->puttingstatus->setText("该时间节点已存在");
                if(row>=time_list.size()){
                    ui->changetable->item(row,column)->setText("");
                    is_timeerroring=false;
                    return;
                }
                ui->changetable->item(row,column)->setText(QString::number(time_list[row], 'f', 2));
                is_timeerroring=false;
                return;
            }
        }
    }
    if(ui->changetable->item(row,column^1)->text().isEmpty()) return;
    if(row>=time_list.size()) {
        value=ui->changetable->item(row,0)->text().toDouble(&ok);
        int num=value*100;
        value=(double)num/100.00;
        time_list.push_back(value);
        value=ui->changetable->item(row,1)->text().toDouble(&ok);
        num=value*100;
        value=(double)num/100.00;
        rate_list.push_back(value);
    }
    else{
        value=ui->changetable->item(row,0)->text().toDouble(&ok);
        int num=value*100;
        value=(double)num/100.00;
        time_list[row]=value;
        value=ui->changetable->item(row,1)->text().toDouble(&ok);
        num=value*100;
        value=(double)num/100.00;
        rate_list[row]=value;
    }
showtabel:
    vector<pair<double,double>> pairlist;
    for (size_t i = 0; i < time_list.size(); i++) {
        pairlist.push_back(std::make_pair(time_list[i], rate_list[i]));
    }
    sort(pairlist.begin(), pairlist.end());
    for(size_t i=0;i< pairlist.size();i++){
        time_list[i]=pairlist[i].first;
        rate_list[i]=pairlist[i].second;
    }
    for (int i = 0; i < time_list.size(); i++) {
        is_tableediting=true;
        ui->changetable->item(i,0)->setText(QString::number(time_list[i], 'f', 2));
        ui->changetable->item(i,1)->setText(QString::number(rate_list[i], 'f', 2));
        is_tableediting=false;
    }
    is_tabledeleting=false;
    ui->puttingstatus->setText("修改完成");
}

void MainWindow::on_deletelist_clicked()
{
    int currentRow=ui->changetable->currentRow();
    if(currentRow<time_list.size()){
        time_list.erase(time_list.begin()+currentRow);
        rate_list.erase(rate_list.begin()+currentRow);
    }
    is_tabledeleting=true;
    ui->changetable->removeRow(currentRow);
    ui->puttingstatus->setText("已删除");
}


void MainWindow::on_startputting_clicked()
{
    ui->nextnode->setValue(0);
    ui->nextzombie->setValue(0);
    if(time_list.size()==0) {
        ui->puttingstatus->setText("请先设置出怪时间表");
        return;
    }
    if (!CheckBoardOn())
    {
        ui->puttingstatus->setText("未检测到游戏");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    if(zombieput){
        ui->puttingstatus->setText("请勿重复开始");
        return;
    }
    for(int i=0;i<ui->changetable->rowCount();i++)
    {
        QTableWidgetItem *item0 = ui->changetable->item(i, 0);
        if (item0) {
            item0->setBackground(Qt::white);
        }
        QTableWidgetItem *item1 = ui->changetable->item(zombieput->listpoiter, 1);
        if (item1) {
            item1->setBackground(Qt::white);
        }
    }
    WriteMemory<uint32_t>(0,{ 0x6a9ec0, 0x82c, 0x28});
    QStringList rowlist=ui->autozombierow->currentText();
    QStringList collist=ui->autozombiecol->currentText();
    vector<int> Row=QStringListToVector(rowlist);
    vector<int> Col=QStringListToVector(collist);
    if(Row.back()>GetRowCount()) Row.pop_back();
    if(Row.size()==0||Col.size()==0){
        ui->puttingstatus->setText("请先选择行列");
        return;
    }
    zombieput=new ZombiePutThread;
    zombieput->type=ui->autozombietype->currentIndex();
    zombieput->rowlist=Row;
    zombieput->collist=Col;
    zombieput->pausewithgame=ui->pausewithgame->isChecked();
    zombieput->current_rate=rate_list[0];
    zombieput->current_ratetomilli=(int)rate_list[0]*1000;
    zombieput->nomowernozombie=ui->nomowernozombie->isChecked();
    if(zombieput->current_ratetomilli<50) {
        zombieput->fragment=zombieput->current_ratetomilli;
        zombieput->fragmentnum=1;
    }
    else if(zombieput->current_ratetomilli>5000) {
        zombieput->fragment=100;
        zombieput->fragmentnum=zombieput->current_ratetomilli/100;
    }
    else {
        zombieput->fragment=zombieput->current_ratetomilli/100;
        zombieput->fragmentnum=100;
    }
    zombieput->listpoiter=0;
    ui->nextnode->setMaximum((int)(time_list[0]*60*1000));
    ui->nextzombie->setMaximum(zombieput->current_ratetomilli);
    connect(zombieput,&ZombiePutThread::abnormaltermi,this,[&](){
        ui->puttingstatus->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 自动僵尸放置线程监测到关卡退出，自动结束僵尸放置。\n").arg(currentTime);
            out.flush();
        }
        on_stopputting_clicked();
    });
    connect(zombieput,&ZombiePutThread::updatezombiecount,this,[&](){
        ui->puttingstatus->setText("放置中……");
        zombieput->zombiecount++;
        ui->nextzombie->setValue(0);
        ui->totalrowzombie->setText(QString("当前已放置僵尸：%1个   当前出怪速率：%2s").arg(zombieput->zombiecount).arg(QString::number(zombieput->current_rate, 'f', 2)));
    });
    connect(zombieput,&ZombiePutThread::updatetime,this,[=](int changetime){
        ui->puttingstatus->setText("放置中……");
        if(zombieput->listpoiter<time_list.size()){
            QTableWidgetItem *item0 = ui->changetable->item(zombieput->listpoiter, 0);
            if (item0) {
                item0->setBackground(Qt::red);
            }
            QTableWidgetItem *item1 = ui->changetable->item(zombieput->listpoiter, 1);
            if (item1) {
                item1->setBackground(Qt::red);
            }
            if(zombieput->listpoiter-1>=0){
                QTableWidgetItem *item2 = ui->changetable->item(zombieput->listpoiter-1, 0);
                if (item2) {
                    item2->setBackground(Qt::white);
                }
                QTableWidgetItem *item3 = ui->changetable->item(zombieput->listpoiter-1, 1);
                if (item3) {
                    item3->setBackground(Qt::white);
                }
            }
        }
        if(zombieput->listpoiter==time_list.size()){
            QTableWidgetItem *item0 = ui->changetable->item(zombieput->listpoiter-1, 0);
            if (item0) {
                item0->setBackground(Qt::white);
            }
            QTableWidgetItem *item1 = ui->changetable->item(zombieput->listpoiter-1, 1);
            if (item1) {
                item1->setBackground(Qt::red);
            }
        }
        int currentvalue=ui->nextzombie->value();
        int newValue = qMin(currentvalue + changetime,ui->nextzombie->maximum());
        ui->nextzombie->setValue(newValue);
        zombieput->totaltime+=changetime;
        int totalSeconds = zombieput->totaltime / 1000;
        int minutes = totalSeconds / 60;
        int seconds = totalSeconds % 60;
        ui->timeshow->setText(QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
        if(zombieput->listpoiter<rate_list.size())
        if(zombieput->current_rate!=rate_list[zombieput->listpoiter]){
            zombieput->current_rate=rate_list[zombieput->listpoiter];
            ui->totalrowzombie->setText(QString("当前已放置僵尸：%1个   当前出怪速率：%2s").arg(zombieput->zombiecount).arg(QString::number(zombieput->current_rate, 'f', 2)));
            zombieput->current_ratetomilli=(int) zombieput->current_rate*1000;
            ui->nextzombie->setMaximum(zombieput->current_ratetomilli);
            if(zombieput->current_ratetomilli<100) {
                zombieput->fragment=zombieput->current_ratetomilli;
                zombieput->fragmentnum=1;
            }
            else if(zombieput->current_ratetomilli>5000) {
                zombieput->fragment=100;
                zombieput->fragmentnum=zombieput->current_ratetomilli/100;
            }
            else {
                zombieput->fragment=zombieput->current_ratetomilli/50;
                zombieput->fragmentnum=50;
            }
        }
        if(zombieput->listpoiter>time_list.size())zombieput->listpoiter=time_list.size()-1;
        if(zombieput->listpoiter<time_list.size()){
            ui->nextnode->setMaximum((int)((time_list[zombieput->listpoiter]-time_list[zombieput->listpoiter-1])*60*1000));
            if(zombieput->listpoiter!=0&&zombieput->listpoiter<time_list.size()){
                ui->nextnode->setValue(zombieput->totaltime-(int)(time_list[zombieput->listpoiter-1]*60*1000));
            }
            else if(zombieput->listpoiter==0){
                ui->nextnode->setValue(zombieput->totaltime);
            }
            if(zombieput->totaltime>=(int)(time_list[zombieput->listpoiter]*60*1000)){
                if(zombieput->listpoiter<time_list.size()){
                    zombieput->listpoiter++;
                    if(zombieput->listpoiter<time_list.size()){
                    QTableWidgetItem *item0 = ui->changetable->item(zombieput->listpoiter, 0);
                    if (item0) {
                      item0->setBackground(Qt::red);
                    }
                    QTableWidgetItem *item1 = ui->changetable->item(zombieput->listpoiter, 1);
                    if (item1) {
                        item1->setBackground(Qt::red);
                    }
                    }
                    if(zombieput->listpoiter-1>=0){
                    QTableWidgetItem *item2 = ui->changetable->item(zombieput->listpoiter-1, 0);
                    if (item2) {
                        item2->setBackground(Qt::white);
                    }
                    QTableWidgetItem *item3 = ui->changetable->item(zombieput->listpoiter-1, 1);
                    if (item3) {
                        item3->setBackground(Qt::white);
                    }
                    }
                    if(zombieput->listpoiter<time_list.size()){
                        ui->nextnode->setMaximum((int)((time_list[zombieput->listpoiter]-time_list[zombieput->listpoiter-1])*60*1000));
                        ui->nextnode->setValue(zombieput->totaltime-(int)(time_list[zombieput->listpoiter-1]*60*1000));
                    }
                }
                if(zombieput->listpoiter<rate_list.size()){
                    zombieput->current_rate=rate_list[zombieput->listpoiter];
                    ui->totalrowzombie->setText(QString("当前已放置僵尸：%1个   当前出怪速率：%2s").arg(zombieput->zombiecount).arg(QString::number(zombieput->current_rate, 'f', 2)));
                    zombieput->current_ratetomilli=(int) zombieput->current_rate*1000;
                    ui->nextzombie->setMaximum(zombieput->current_ratetomilli);
                    if(zombieput->current_ratetomilli<100) {
                        zombieput->fragment=zombieput->current_ratetomilli;
                        zombieput->fragmentnum=1;
                    }
                    else if(zombieput->current_ratetomilli>5000) {
                        zombieput->fragment=100;
                        zombieput->fragmentnum=zombieput->current_ratetomilli/100;
                    }
                    else {
                        zombieput->fragment=zombieput->current_ratetomilli/50;
                        zombieput->fragmentnum=50;
                    }
                }
                if(zombieput->listpoiter==rate_list.size()){
                    zombieput->current_rate=rate_list[zombieput->listpoiter-1];
                    ui->totalrowzombie->setText(QString("当前已放置僵尸：%1个   当前出怪速率：%2s").arg(zombieput->zombiecount).arg(QString::number(zombieput->current_rate, 'f', 2)));
                    zombieput->current_ratetomilli=(int) zombieput->current_rate*1000;
                    ui->nextzombie->setMaximum(zombieput->current_ratetomilli);
                    if(zombieput->current_ratetomilli<100) {
                        zombieput->fragment=zombieput->current_ratetomilli;
                        zombieput->fragmentnum=1;
                    }
                    else if(zombieput->current_ratetomilli>5000) {
                        zombieput->fragment=100;
                        zombieput->fragmentnum=zombieput->current_ratetomilli/100;
                    }
                    else {
                        zombieput->fragment=zombieput->current_ratetomilli/50;
                        zombieput->fragmentnum=50;
                    }
                }
            }
        }

    });
    QTableWidgetItem *item0 = ui->changetable->item(zombieput->listpoiter, 0);
    if (item0) {
        item0->setBackground(Qt::red);
    }
    QTableWidgetItem *item1 = ui->changetable->item(zombieput->listpoiter, 1);
    if (item1) {
        item1->setBackground(Qt::red);
    }
    ui->timeshow->setText(QString("%1:%2").arg(0, 2, 10, QChar('0')).arg(0, 2, 10, QChar('0')));
    zombieput->start();
    ui->puttingstatus->setText("未检测到游戏");
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 自动僵尸放置线程开始运行。\n").arg(currentTime);
        out.flush();
    }
}


void MainWindow::on_saveile_autozombie_clicked()
{
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 开始保存文件\n").arg(currentTime);
        out.flush();
    }
    QString textContent = ui->formtext->toPlainText();
    QString defaultFileName = "出怪速率表.txt";
    QString filePath = QFileDialog::getSaveFileName(nullptr, "保存文件", QDir::homePath() + "/" + defaultFileName, "Text Files (*.txt)");
    if (filePath.isEmpty()) {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 用户未选择保存地址\n").arg(currentTime);
            out.flush();
        }
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        //qDebug() << "Failed to open file for writing:" << file.errorString();
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] Failed to open file for writing:%2\n").arg(currentTime).arg(file.errorString());
            out.flush();
        }
        return;
    }

    QTextStream fileOut(&file);
    for(int i=0;i<time_list.size();i++){
        fileOut << time_list[i]<<" "<<rate_list[i]<<"\n";
    }
    file.close();

    ui->puttingstatus->setText(QString("文件保存成功：%1").arg(filePath));
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束保存文件\n").arg(currentTime);
        out.flush();
    }
}


void MainWindow::on_readfile_autozombie_clicked()
{
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 尝试读取阵型文件\n").arg(currentTime);
        out.flush();
    }
    QMessageBox::information(this,"提示","读取文件将覆盖当前出怪时间速率表！\n文件请按照每行“时间节点 出怪速率”的格式，否则可能读取错误。");
    QString filePath = QFileDialog::getOpenFileName(this, "Select File", "", "Text Files (*.txt)");
    if (filePath.isEmpty()) {
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 用户未选择文件\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    vector<double>templist;
    unordered_set<double>timetemplistcheck;
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 打开文件:%2 成功\n").arg(currentTime).arg(filePath);
            out.flush();
        }
        while (!in.atEnd()) {
            QString line = in.readLine();
            // 使用 QString 的 split 方法将一行拆分为多个浮点数
            QStringList tokens = line.split(" ", Qt::SkipEmptyParts);
            foreach (const QString& token, tokens) {
                // 将字符串转换为浮点数
                bool ok;
                double floatValue = token.toDouble(&ok);
                if (ok) {
                    int num=floatValue*100;
                    floatValue=(double)num/100.00;
                    templist.push_back(floatValue);
                } else {
                    ui->puttingstatus->setText("文件内数据错误，请检查");
                    file.close();
                    return;
                }
            }
        }

        ui->puttingstatus->setText("读取文件成功");
    }
    else {
        ui->puttingstatus->setText("读取文件失败");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 打开文件:%2 失败，错误码\n").arg(currentTime).arg(filePath).arg(GetLastError());
            out.flush();
        }
        return;
    }
    file.close();
    while(ui->changetable->rowCount()!=0){
        ui->changetable->setCurrentItem(ui->changetable->item(ui->changetable->rowCount()-1, 0));
        on_deletelist_clicked();
    }
    if(templist.size()%2==1) templist.pop_back();
    for(int i=0;i<templist.size();i++){
        if(timetemplistcheck.find(templist[i])!=timetemplistcheck.end()){
            i++;
            continue;
        }
        timetemplistcheck.insert(templist[i]);
        time_list.push_back(templist[i++]);
        rate_list.push_back(templist[i]);
        is_tableadding=true;
        ui->changetable->insertRow(time_list.size()-1);
        ui->changetable->setItem(time_list.size()-1, 0, new QTableWidgetItem(""));
        ui->changetable->setItem(rate_list.size()-1, 1, new QTableWidgetItem(""));
        is_tableadding=false;
        ui->changetable->item(time_list.size()-1,0)->setText(QString::number(time_list.back(), 'f', 2));
        ui->changetable->item(rate_list.size()-1,1)->setText(QString::number(rate_list.back(), 'f', 2));
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 结束读取阵型文件\n").arg(currentTime);
        out.flush();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->autozombiecol->clear();
    ui->autozombierow->clear();
    ui->autozombietype->setCurrentIndex(0);
    ui->mowerrow->setValue(0);
    ui->totalrowzombie->setText("");
    ui->autospicy->setCheckState(Qt::Unchecked);
    ui->pausewithgame->setCheckState(Qt::Unchecked);
    ui->randblindboxmode->setCheckState(Qt::Unchecked);
    on_stopputting_clicked();
    while(ui->changetable->rowCount()!=0){
        ui->changetable->setCurrentItem(ui->changetable->item(ui->changetable->rowCount()-1, 0));
        on_deletelist_clicked();
    }
    ui->timeshow->setText("00:00");
    ui->puttingstatus->setText("重置完成");
}


void MainWindow::on_randblindboxmode_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        if (!CheckBoardOn())
        {
            ui->puttingstatus->setText("未检测到游戏");
            if(out.device()){
                QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
                out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
                out.flush();
            }
            ui->randblindboxmode->setCheckState(Qt::Unchecked);
            return;
        }
        bMoniter=new BlindBoxMoniter;
        bSearch=new BlindBoxSearch;
        uint32_t zombieoff=ReadMemory<uint32_t>({lawn,board,zombie_offset});
        bMoniter->zombieoffsetaddr=zombieoff;
        bSearch->zombieoffsetaddr=zombieoff;
        bMoniter->is_forbid=ui->startforbidplace_zombie->isChecked();
        bSearch->boxtype=blindzombie;
        bMoniter->boxtype=blindzombie;
        bSearch->bMoniter=bMoniter;
        bSearch->thread_survive=true;
        bMoniter->thread_survive=true;
        bMoniter->put=new BlindBoxPut;
        bMoniter->put->addr=zombieoff;
        connect(bSearch,&BlindBoxSearch::abnormaltermi,this,[&](){
            ui->puttingstatus->setText("未检测到关卡");
            if(out.device()){
                QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
                out<<QString("[%1] 盲盒搜索线程监测到关卡退出，自动结束盲盒搜索。\n").arg(currentTime);
                out.flush();
            }
            ui->randblindboxmode->setCheckState(Qt::Unchecked);
        });
        connect(bMoniter,&BlindBoxMoniter::abnormaltermi,this,[&](){
            ui->puttingstatus->setText("未检测到关卡");
            if(out.device()){
                QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
                out<<QString("[%1] 盲盒监测线程监测到关卡退出，自动结束盲盒监测。\n").arg(currentTime);
                out.flush();
            }
            ui->randblindboxmode->setCheckState(Qt::Unchecked);
        });
        bMoniter->start();
        bSearch->start();
    }
    else if(arg1==Qt::Unchecked){
        if(bSearch){
            bSearch->thread_survive=false;
            bSearch->exit();
            bSearch->wait();
            delete bSearch;
            bSearch=nullptr;
        }
    }
}

void MainWindow::Initfreezombiegridlayout()
{
    freezombieputlist.resize(72);
    freezombieputcombo.resize(72);
    freezombieputcheck.resize(72);
    for(int i=0;i<6;i++){
        for(int j=0;j<12;j++){
            QHBoxLayout* newlayout=new QHBoxLayout;
            QCheckBox* newcheck=new QCheckBox;
            newcheck->setText(QString("%1行%2列").arg(i+1).arg(j+1));
            connect(newcheck,&QCheckBox::stateChanged,this,[=](int arg){
                if(arg==Qt::Checked){
                    ui->freezombieputxcor->setEnabled(false);
                    ui->freezombieputycor->setEnabled(false);
                    ui->freezombierow->setEnabled(false);
                    ui->freezombiecol->setEnabled(false);
                }
            });
            freezombieputcheck[i*12+j]=newcheck;
            newlayout->addWidget(newcheck);
            QComboBox* newcomb=new QComboBox;
            newcomb->setFixedWidth(100);
            freezombieputcombo[i*12+j]=newcomb;
            connect(newcomb, QOverload<int>::of(&QComboBox::currentIndexChanged),
                    [=](int index) {
                        ShowFreeZombieInfo(i*12+j, index);
                    });
            newlayout->addWidget(newcomb);
            ui->freezombiegridlayout->addLayout(newlayout,i,j);
        }
    }
    ui->scrollAreaWidgetContents_5->setLayout(ui->freezombiegridlayout);
    ui->scrollArea_5->setWidget(ui->scrollAreaWidgetContents_5);
    ui->scrollArea_5->setWidgetResizable(true);
    ui->rowcolput->setChecked(true);
    ui->freezombieputxcor->setValue(10);
    ui->freezombieputycor->setValue(50);
    on_rowcolput_clicked();
}

void MainWindow::ShowFreeZombieInfo(int i,int newIndex)
{
    if(freezombieputcombo[i]->count()==0) return;
    ui->freezombietype->setCurrentIndex(freezombieputlist[i][newIndex].type);
    ui->freezombierow->setValue(freezombieputlist[i][newIndex].row);
    ui->freezombiecol->setValue(freezombieputlist[i][newIndex].col);
    ui->freezombieputxcor->setValue(freezombieputlist[i][newIndex].x);
    ui->freezombieputycor->setValue(freezombieputlist[i][newIndex].y);
    ui->freezombiebody->setValue(freezombieputlist[i][newIndex].bodyblood);
    ui->freezombiearmor1->setValue(freezombieputlist[i][newIndex].armorblood1);
    ui->freezombiearmor2->setValue(freezombieputlist[i][newIndex].armorblood2);
    ui->freezombieshinetime->setValue(freezombieputlist[i][newIndex].shingingtime);
}
void MainWindow::on_addfreezombie_clicked()
{
    if(!ui->freezombiecol->isEnabled()&&!ui->freezombieputxcor->isEnabled()){
        ZombieInfoStruct newzombie;
        newzombie.type=ui->freezombietype->currentIndex();
        newzombie.bodyblood=ui->freezombiebody->value();
        newzombie.armorblood1=ui->freezombiearmor1->value();
        newzombie.armorblood2=ui->freezombiearmor2->value();
        newzombie.shingingtime=ui->freezombieshinetime->value();
        newzombie.frozentime=0;
        newzombie.buttertime=0;
        newzombie.slowingtime=0;
        for(int j=0;j<72;j++){
            if(freezombieputcheck[j]->isChecked()){
                newzombie.row=j/12+1;
                newzombie.col=j%12+1;
                newzombie.x=10+(newzombie.col-1)*80;
                newzombie.y=50+(newzombie.row-1)*100;
                for(int i=0;i<ui->batcount->value();i++){
                    freezombieputlist[j].push_back(newzombie);
                    freezombieputcombo[j]->addItem(QString("no.%1 [%2]").arg( freezombieputcombo[j]->count()+1).arg(current_zombie_book[newzombie.type]));
                }
            }
        }
        return;
    }
        ZombieInfoStruct newzombie;
        newzombie.type=ui->freezombietype->currentIndex();
        newzombie.row=ui->freezombierow->value();
        newzombie.col=ui->freezombiecol->value();
        newzombie.x=ui->freezombieputxcor->value();
        newzombie.y=ui->freezombieputycor->value();
        newzombie.bodyblood=ui->freezombiebody->value();
        newzombie.armorblood1=ui->freezombiearmor1->value();
        newzombie.armorblood2=ui->freezombiearmor2->value();
        newzombie.shingingtime=ui->freezombieshinetime->value();
        newzombie.frozentime=0;
        newzombie.buttertime=0;
        newzombie.slowingtime=0;
        for(int i=0;i<ui->batcount->value();i++){
            freezombieputlist[(newzombie.row-1)*12+(newzombie.col-1)].push_back(newzombie);
            freezombieputcombo[(newzombie.row-1)*12+(newzombie.col-1)]->addItem(QString("no.%1 [%2]").arg( freezombieputcombo[(newzombie.row-1)*12+(newzombie.col-1)]->count()+1).arg(current_zombie_book[newzombie.type]));
        }
}


void MainWindow::on_rowcolput_clicked()
{
    for(int j=0;j<72;j++){
        freezombieputcheck[j]->setCheckState(Qt::Unchecked);
    }
    ui->freezombieputxcor->setEnabled(false);
    ui->freezombieputycor->setEnabled(false);
    ui->freezombierow->setEnabled(true);
    ui->freezombiecol->setEnabled(true);
    disconnect(ui->freezombieputxcor, QOverload<double>::of(&QDoubleSpinBox::valueChanged), nullptr, nullptr);
    disconnect(ui->freezombieputycor, QOverload<double>::of(&QDoubleSpinBox::valueChanged), nullptr, nullptr);
    connect(ui->freezombiecol, QOverload<int>::of(&QSpinBox::valueChanged),
            this, [=](int value){
        ui->freezombieputxcor->setValue(10 + (value - 1) * 80);
    });

    connect(ui->freezombierow, QOverload<int>::of(&QSpinBox::valueChanged),
            this, [=](int value){
        ui->freezombieputycor->setValue(50 + (value - 1) * 100);
    });
}


void MainWindow::on_coordinateput_clicked()
{
    for(int j=0;j<72;j++){
        freezombieputcheck[j]->setCheckState(Qt::Unchecked);
    }
    ui->freezombieputxcor->setEnabled(true);
    ui->freezombieputycor->setEnabled(true);
    ui->freezombierow->setEnabled(false);
    ui->freezombiecol->setEnabled(false);
    disconnect(ui->freezombierow, QOverload<int>::of(&QSpinBox::valueChanged), nullptr, nullptr);
    disconnect(ui->freezombiecol, QOverload<int>::of(&QSpinBox::valueChanged), nullptr, nullptr);
    connect(ui->freezombieputycor, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
            this, [=](double value){
        ui->freezombierow->setValue((int)(value / 80) + 1);
    });
    connect(ui->freezombieputxcor, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
            this, [=](double value){
        ui->freezombiecol->setValue((int)(value / 80) + 1);
    });
}


void MainWindow::on_putfreezombie_clicked()
{
    int j=(ui->freezombierow->value()-1)*12+(ui->freezombiecol->value()-1);
    int currentindex;
    if(freezombieputcombo[j]->count()!=0)currentindex=freezombieputcombo[j]->currentIndex();
    else return;
    freezombieputlist[j][currentindex].type=ui->freezombietype->currentIndex();
    freezombieputlist[j][currentindex].row=ui->freezombierow->value();
    freezombieputlist[j][currentindex].col=ui->freezombiecol->value();
    freezombieputlist[j][currentindex].x=ui->freezombieputxcor->value();
    freezombieputlist[j][currentindex].y=ui->freezombieputycor->value();
    freezombieputlist[j][currentindex].bodyblood=ui->freezombiebody->value();
    freezombieputlist[j][currentindex].armorblood1=ui->freezombiearmor1->value();
    freezombieputlist[j][currentindex].armorblood2=ui->freezombiearmor2->value();
    freezombieputlist[j][currentindex].shingingtime=ui->freezombieshinetime->value();
    freezombieputcombo[j]->setItemText(currentindex,QString("no.%1 [%2]").arg(currentindex+1).arg(current_zombie_book[freezombieputlist[j][currentindex].type]));
}


void MainWindow::on_freezombiedelete_clicked()
{
    bool flag=false;
    for(int j=0;j<72;j++){
        if(freezombieputcheck[j]->isChecked()){
            flag=true;
            int currentindex;
            if(freezombieputcombo[j]->count()!=0)currentindex=freezombieputcombo[j]->currentIndex();
            else continue;
            freezombieputlist[j].erase(freezombieputlist[j].begin()+currentindex);
            freezombieputcombo[j]->removeItem(currentindex);
            for(int i=0;i<freezombieputcombo[j]->count();i++)
                freezombieputcombo[j]->setItemText(i,QString("no.%1 [%2]").arg( i+1).arg(current_zombie_book[freezombieputlist[j][i].type]));
        }
    }
    if(!flag){
        ui->freezombieinfo->setText("未选择需要删除的位置");
    }
}


void MainWindow::on_freezombiereset_clicked()
{
    for(int j=0;j<72;j++){
        freezombieputcheck[j]->setCheckState(Qt::Unchecked);
        freezombieputcombo[j]->clear();
        freezombieputlist[j].clear();
    }
    ui->freezombietype->setCurrentIndex(0);
    ui->freezombierow->setValue(1);
    ui->freezombiecol->setValue(1);
    ui->freezombieputxcor->setValue(10);
    ui->freezombieputycor->setValue(50);
    ui->freezombiebody->setValue(0);
    ui->freezombiearmor1->setValue(0);
    ui->freezombiearmor2->setValue(0);
    ui->freezombieshinetime->setValue(0);
}


void MainWindow::on_freezombieput_clicked()
{
    if (!CheckBoardOn())
    {
        ui->freezombieinfo->setText("未检测到游戏");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏，僵尸自由放置终止\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    uint32_t zombieoff=ReadMemory<uint32_t>({lawn,board,zombie_offset});
    for(int j=0;j<72;j++){
        if(freezombieputlist[j].size()==0) continue;
        for(int i=0;i<freezombieputlist[j].size();i++){
            SingleZombiePut(freezombieputlist[j][i],zombieoff);
        }
    }
    ui->freezombieinfo->setText("放置完成");
}

void MainWindow::InitPlantMonitPage()
{
    PlantcommonCheckBox=new QCheckBox;
    connect(ui->startplantmoniter, &QCheckBox::stateChanged, [=](int state) {
        if (CheckBoardOn())PlantcommonCheckBox->setChecked(state);
        else ui->startplantmoniter->setCheckState(Qt::Unchecked);
    });
    connect(ui->startplantmoniter_2, &QCheckBox::stateChanged, [=](int state) {
        if (CheckBoardOn())PlantcommonCheckBox->setChecked(state);
        else ui->startplantmoniter_2->setCheckState(Qt::Unchecked);
    });
    connect(ui->startplantmoniter_3, &QCheckBox::stateChanged, [=](int state) {
        if (CheckBoardOn())PlantcommonCheckBox->setChecked(state);
        else ui->startplantmoniter_3->setCheckState(Qt::Unchecked);
    });
    connect(ui->startplantmoniter_4, &QCheckBox::stateChanged, [=](int state) {
        if (CheckBoardOn())PlantcommonCheckBox->setChecked(state);
        else ui->startplantmoniter_4->setCheckState(Qt::Unchecked);
    });
    connect(ui->startplantmoniter_5, &QCheckBox::stateChanged, [=](int state) {
        if (CheckBoardOn())PlantcommonCheckBox->setChecked(state);
        else ui->startplantmoniter_5->setCheckState(Qt::Unchecked);
    });
    connect(PlantcommonCheckBox, &QCheckBox::stateChanged, [=](int state) {
        ui->startplantmoniter->setChecked(state);
        ui->startplantmoniter_2->setChecked(state);
        ui->startplantmoniter_3->setChecked(state);
        ui->startplantmoniter_4->setChecked(state);
        ui->startplantmoniter_5->setChecked(state);
    });
    plantmoniter_check.resize(60);
    plantmoniter_type.resize(60);
    plantmoniter_blood.resize(60);
    plantmoniter_interval.resize(60);
    plantmoniter_shine.resize(60);
    plantmoniter_sleep.resize(60);
    plantmoniter_flash.resize(60);
    plantmoniter_type_1.resize(60);
    plantmoniter_type_2.resize(60);
    plantmoniter_type_3.resize(60);
    plantmoniter_type_4.resize(60);
    plantmoniter_bloodenable.resize(60,true);
    plantmoniter_intervalenable.resize(60,true);
    plantmoniter_shineenable.resize(60,true);
    plantmoniter_flashenable.resize(60,true);
    plantmoniter_sleepenable.resize(60,true);
    for(int i=0;i<6;i++){
        for(int j=0;j<10;j++){
            int _i=i;
            int _j=j;
            QHBoxLayout* newtypelayout=new QHBoxLayout;
            plantmoniter_check[_i*10+_j]=new QRadioButton(QString("%1行%2列:").arg(i+1).arg(j+1));
            newtypelayout->addWidget(plantmoniter_check[_i*10+_j]);
            plantmoniter_type[_i*10+_j]=new QComboBox;
            newtypelayout->addWidget(plantmoniter_type[_i*10+_j]);
            connect(plantmoniter_type[_i*10+_j],QOverload<int>::of(&QComboBox::currentIndexChanged),this,[=](int currentindex){
                if(currentindex<0)return;
                if(plantmoniter_check[_i*10+_j]->isChecked()){
                    ui->moniter_plantname->setText(QString("%1").arg(current_plant_book[plantlist[_i*10+_j][currentindex]->type]));
                    ui->moniter_planttype->setText(QString("%1").arg(plantlist[_i*10+_j][currentindex]->type));
                    ui->moniter_plantrow->setText(QString("%1").arg(plantlist[_i*10+_j][currentindex]->row+1));
                    ui->moniter_plantcol->setText(QString("%1").arg(plantlist[_i*10+_j][currentindex]->col+1));
                    if(plantbloodenable)ui->moniter_plantblood->setText(QString("%1").arg(plantlist[_i*10+_j][currentindex]->blood));
                    if(plantintervalenable)ui->moniter_plantinterval->setText(QString("%1").arg(plantlist[_i*10+_j][currentindex]->interval));
                    if(plantshootenable)ui->moniter_plantshoot->setValue(plantlist[_i*10+_j][currentindex]->shoottime);
                    if(plantflashenable)ui->moniter_plantflash->setValue(plantlist[_i*10+_j][currentindex]->flashingtime);
                    if(plantshineenable)ui->moniter_plantshine->setValue(plantlist[_i*10+_j][currentindex]->shiningtime);
                    if(plantleftenable&&plantrightenable){
                        if(plantlist[_i*10+_j][currentindex]->towards==-1) ui->right->setChecked(true);
                        else ui->left->setChecked(true);
                    }
                    if(plantsquishenable){
                        if(plantlist[_i*10+_j][currentindex]->issquished)ui->squish->setCheckState(Qt::Checked);
                        else ui->squish->setCheckState(Qt::Unchecked);
                    }
                    if(plantsleepenable){
                        if(plantlist[_i*10+_j][currentindex]->issleep)ui->asleep->setCheckState(Qt::Checked);
                        else ui->asleep->setCheckState(Qt::Unchecked);
                    }
                    if(plantshineenableenable){
                        if(plantlist[_i*10+_j][currentindex]->isableshine)ui->enableshine->setCheckState(Qt::Checked);
                        else ui->enableshine->setCheckState(Qt::Unchecked);
                    }
                    if(plantinvisibleenable){
                        if(!plantlist[_i*10+_j][currentindex]->isinvisible)ui->invisible->setCheckState(Qt::Checked);
                        else ui->invisible->setCheckState(Qt::Unchecked);
                    }
                }
            });
            connect( plantmoniter_check[_i*10+_j],&QRadioButton::clicked,this,[=](){
                if(plantmoniter_type[_i*10+_j]->count()==0)return;
                int currentindex=0;
                if(plantmoniter_type[_i*10+_j]->currentIndex()!=-1)currentindex=plantmoniter_type[_i*10+_j]->currentIndex();
                ui->moniter_plantname->setText(QString("%1").arg(current_plant_book[plantlist[_i*10+_j][currentindex]->type]));
                ui->moniter_planttype->setText(QString("%1").arg(plantlist[_i*10+_j][currentindex]->type));
                ui->moniter_plantrow->setText(QString("%1").arg(plantlist[_i*10+_j][currentindex]->row+1));
                ui->moniter_plantcol->setText(QString("%1").arg(plantlist[_i*10+_j][currentindex]->col+1));
                if(plantbloodenable)ui->moniter_plantblood->setText(QString("%1").arg(plantlist[_i*10+_j][currentindex]->blood));
                if(plantintervalenable)ui->moniter_plantinterval->setText(QString("%1").arg(plantlist[_i*10+_j][currentindex]->interval));
                if(plantshootenable)ui->moniter_plantshoot->setValue(plantlist[_i*10+_j][currentindex]->shoottime);
                if(plantflashenable)ui->moniter_plantflash->setValue(plantlist[_i*10+_j][currentindex]->flashingtime);
                if(plantshineenable)ui->moniter_plantshine->setValue(plantlist[_i*10+_j][currentindex]->shiningtime);
                if(plantleftenable&&plantrightenable){
                    if(plantlist[_i*10+_j][currentindex]->towards==-1) ui->right->setChecked(true);
                    else ui->left->setChecked(true);
                }
                if(plantsquishenable){
                    if(plantlist[_i*10+_j][currentindex]->issquished)ui->squish->setCheckState(Qt::Checked);
                    else ui->squish->setCheckState(Qt::Unchecked);
                }
                if(plantsleepenable){
                    if(plantlist[_i*10+_j][currentindex]->issleep)ui->asleep->setCheckState(Qt::Checked);
                    else ui->asleep->setCheckState(Qt::Unchecked);
                }
                if(plantshineenableenable){
                    if(plantlist[_i*10+_j][currentindex]->isableshine)ui->enableshine->setCheckState(Qt::Checked);
                    else ui->enableshine->setCheckState(Qt::Unchecked);
                }
                if(plantinvisibleenable){
                    if(!plantlist[_i*10+_j][currentindex]->isinvisible)ui->invisible->setCheckState(Qt::Checked);
                    else ui->invisible->setCheckState(Qt::Unchecked);
                }
            });
            QHBoxLayout* newbloodlayout=new QHBoxLayout;
            QLabel* newlabel=new QLabel(QString("%1行%2列:").arg(i+1).arg(j+1));
            newbloodlayout->addWidget(newlabel);
            plantmoniter_type_1[_i*10+_j]=new QComboBox;
            newbloodlayout->addWidget(plantmoniter_type_1[_i*10+_j]);
            plantmoniter_blood[_i*10+_j]=new QLineEdit;
            newbloodlayout->addWidget(plantmoniter_blood[_i*10+_j]);
            connect(plantmoniter_type_1[_i*10+_j],QOverload<int>::of(&QComboBox::currentIndexChanged),this,[=](int currentindex){
                if(currentindex<0)return;
                plantmoniter_blood[_i*10+_j]->setText(QString("%1").arg(plantlist[_i*10+_j][currentindex]->blood));
            });

            connect(plantmoniter_blood[_i*10+_j],&QLineEdit::selectionChanged,this,[=](){
                if(plantmoniter_type_1[_i*10+_j]->count()==0) return;
                plantmoniter_bloodenable[_i*10+_j]=false;
            });
            connect(plantmoniter_blood[_i*10+_j],&QLineEdit::editingFinished,this,[=](){
                if(plantmoniter_type_1[_i*10+_j]->count()==0) return;
                if(!CheckBoardOn()){
                    ui->plantmoniterbloodinfo->setText("监测到关卡退出，修改失败");
                    plantmoniter_bloodenable[_i*10+_j]=true;
                    return;
                }
                WriteMemory<uint32_t>(plantmoniter_blood[_i*10+_j]->text().toInt(),{plantlist[_i*10+_j][plantmoniter_type[_i*10+_j]->currentIndex()]->addr+plant_blood});
                ui->plantmoniterbloodinfo->setText("本次血量修改完成");
                plantmoniter_bloodenable[_i*10+_j]=true;
            });

            QHBoxLayout* newintervallayout=new QHBoxLayout;
            QLabel* newlabel1=new QLabel(QString("%1行%2列:").arg(i+1).arg(j+1));
            newintervallayout->addWidget(newlabel1);
            plantmoniter_type_2[_i*10+_j]=new QComboBox;
            newintervallayout->addWidget(plantmoniter_type_2[_i*10+_j]);
            plantmoniter_interval[_i*10+_j]=new QLineEdit;
            newintervallayout->addWidget(plantmoniter_interval[_i*10+_j]);
            connect(plantmoniter_type_2[_i*10+_j],QOverload<int>::of(&QComboBox::currentIndexChanged),this,[=](int currentindex){
                if(currentindex<0)return;
                plantmoniter_interval[_i*10+_j]->setText(QString("%1").arg(plantlist[_i*10+_j][currentindex]->interval));
            });

            connect(plantmoniter_interval[_i*10+_j],&QLineEdit::selectionChanged,this,[=](){
                if(plantmoniter_type_2[_i*10+_j]->count()==0) return;
                plantmoniter_intervalenable[_i*10+_j]=false;
            });
            connect(plantmoniter_interval[_i*10+_j],&QLineEdit::editingFinished,this,[=](){
                if(plantmoniter_type_2[_i*10+_j]->count()==0) return;
                if(!CheckBoardOn()){
                    ui->plantmoniterintervalinfo->setText("监测到关卡退出，修改失败");
                    plantmoniter_intervalenable[_i*10+_j]=true;
                    return;
                }
                WriteMemory<uint32_t>(plantmoniter_interval[_i*10+_j]->text().toInt(),{plantlist[_i*10+_j][plantmoniter_type[_i*10+_j]->currentIndex()]->addr+plant_attack_interval});
                ui->plantmoniterintervalinfo->setText("本次攻速修改完成");
                plantmoniter_intervalenable[_i*10+_j]=true;
            });

            QHBoxLayout* newshinelayout=new QHBoxLayout;
            QLabel* newlabel2=new QLabel(QString("%1行%2列:").arg(i+1).arg(j+1));
            newshinelayout->addWidget(newlabel2);
            plantmoniter_type_3[_i*10+_j]=new QComboBox;
            newshinelayout->addWidget(plantmoniter_type_3[_i*10+_j]);
            QVBoxLayout* shineflash=new QVBoxLayout;
            plantmoniter_flash[_i*10+_j]=new QLineEdit;
            plantmoniter_shine[_i*10+_j]=new QLineEdit;
            shineflash->addWidget(plantmoniter_shine[_i*10+_j]);
            shineflash->addWidget(plantmoniter_flash[_i*10+_j]);
            newshinelayout->addLayout(shineflash);
            connect(plantmoniter_type_3[_i*10+_j],QOverload<int>::of(&QComboBox::currentIndexChanged),this,[=](int currentindex){
                if(currentindex<0)return;
                plantmoniter_flash[_i*10+_j]->setText(QString("%1").arg(plantlist[_i*10+_j][currentindex]->flashingtime));
                plantmoniter_shine[_i*10+_j]->setText(QString("%1").arg(plantlist[_i*10+_j][currentindex]->shiningtime));
            });

            connect(plantmoniter_flash[_i*10+_j],&QLineEdit::selectionChanged,this,[=](void){
                if(plantmoniter_type_3[_i*10+_j]->count()==0) return;
                plantmoniter_flashenable[_i*10+_j]=false;
            });
            connect(plantmoniter_flash[_i*10+_j],&QLineEdit::editingFinished,this,[=](void){
                if(plantmoniter_type_3[_i*10+_j]->count()==0) return;
                if(!CheckBoardOn()){
                    ui->plantmonitershineinfo->setText("监测到关卡退出，修改失败");
                    plantmoniter_flashenable[_i*10+_j]=true;
                    return;
                }
                WriteMemory<uint32_t>(plantmoniter_flash[_i*10+_j]->text().toInt(),{plantlist[_i*10+_j][plantmoniter_type[_i*10+_j]->currentIndex()]->addr+plant_flash_time});
                ui->plantmonitershineinfo->setText("本次闪光修改完成");
                plantmoniter_flashenable[_i*10+_j]=true;
            });

            connect(plantmoniter_shine[_i*10+_j],&QLineEdit::selectionChanged,this,[=](){
                if(plantmoniter_type_3[_i*10+_j]->count()==0) return;
                plantmoniter_shineenable[_i*10+_j]=false;
            });
            connect(plantmoniter_shine[_i*10+_j],&QLineEdit::editingFinished,this,[=](){
                if(plantmoniter_type_3[_i*10+_j]->count()==0) return;
                if(!CheckBoardOn()){
                    ui->plantmonitershineinfo->setText("监测到关卡退出，修改失败");
                    plantmoniter_shineenable[_i*10+_j]=true;
                    return;
                }
                WriteMemory<uint32_t>(plantmoniter_shine[_i*10+_j]->text().toInt(),{plantlist[_i*10+_j][plantmoniter_type[_i*10+_j]->currentIndex()]->addr+plant_shine_time});
                ui->plantmonitershineinfo->setText("本次发光修改完成");
                plantmoniter_shineenable[_i*10+_j]=true;
            });

            QHBoxLayout* newsleeplayout=new QHBoxLayout;
            QLabel* newlabel3=new QLabel(QString("%1行%2列:").arg(i+1).arg(j+1));
            newsleeplayout->addWidget(newlabel3);
            plantmoniter_type_4[_i*10+_j]=new QComboBox;
            newsleeplayout->addWidget(plantmoniter_type_4[_i*10+_j]);
            plantmoniter_sleep[_i*10+_j]=new QCheckBox("睡着");
            newsleeplayout->addWidget(plantmoniter_sleep[_i*10+_j]);
            connect(plantmoniter_type_4[_i*10+_j],QOverload<int>::of(&QComboBox::currentIndexChanged),this,[=](int currentindex){
                if(currentindex<0)return;
                if(plantlist[_i*10+_j][currentindex]->issleep)
                    plantmoniter_sleep[_i*10+_j]->setCheckState(Qt::Checked);
                else plantmoniter_sleep[_i*10+_j]->setCheckState(Qt::Unchecked);
            });
            connect(plantmoniter_sleep[_i*10+_j],&QCheckBox::clicked,this,[=](){
                if(plantmoniter_type_4[_i*10+_j]->count()==0) return;
                if(!CheckBoardOn()){
                    ui->plantmonitersleepinfo->setText("监测到关卡退出，修改失败");
                    return;
                }
                plantmoniter_sleepenable[_i*10+_j]=false;
                uint8_t temp=ReadMemory<uint8_t>({0x0045de8e});
                if(ui->asleep->isChecked()){
                    WriteMemory<uint8_t>(0x74,{ 0x0045de8e});
                    WriteMemory<bool>(ui->asleep->isChecked(),{plantlist[_i*10+_j][plantmoniter_type[_i*10+_j]->currentIndex()]->addr+plant_asleep});
                }
                else {
                    WriteMemory<uint8_t>(0xeb,{0x0045de8e});
                    CodeStruct* newcode=Init();
                    MovReg(newcode,Reg::EAX, plantlist[_i*10+_j][plantmoniter_type[_i*10+_j]->currentIndex()]->addr);
                    PushByte(newcode,0);
                    Call(newcode,0x0045e860);
                    Ret(newcode);
                    CodeInject(pvzHand,newcode);
                    WriteMemory<bool>(ui->asleep->isChecked(),{plantlist[_i*10+_j][plantmoniter_type[_i*10+_j]->currentIndex()]->addr+plant_asleep});
                }
                WriteMemory<uint8_t>(temp,{0x0045de8e});
                ui->plantmonitersleepinfo->setText("本次睡眠状态修改完成");
                plantmoniter_sleepenable[_i*10+_j]=true;
            });

            ui->plantmonitergridlayout_whole->addLayout(newtypelayout,i,j);
            ui->plantmonitergridlayout_blood->addLayout(newbloodlayout,i,j);
            ui->plantmonitergridlayout_interval->addLayout(newintervallayout,i,j);
            ui->plantmonitergridlayout_shine->addLayout(newshinelayout,i,j);
            ui->plantmonitergridlayout_sleep->addLayout(newsleeplayout,i,j);
        }
    }
    ui->scrollAreaWidgetContents_6->setLayout(ui->plantmonitergridlayout_whole);
    ui->scrollArea_6->setWidget(ui->scrollAreaWidgetContents_6);
    ui->scrollArea_6->setWidgetResizable(true);

    ui->scrollAreaWidgetContents_7->setLayout(ui->plantmonitergridlayout_blood);
    ui->scrollArea_7->setWidget(ui->scrollAreaWidgetContents_7);
    ui->scrollArea_7->setWidgetResizable(true);

    ui->scrollAreaWidgetContents_9->setLayout(ui->plantmonitergridlayout_interval);
    ui->scrollArea_8->setWidget(ui->scrollAreaWidgetContents_9);
    ui->scrollArea_8->setWidgetResizable(true);

    ui->scrollAreaWidgetContents_10->setLayout(ui->plantmonitergridlayout_shine);
    ui->scrollArea_9->setWidget(ui->scrollAreaWidgetContents_10);
    ui->scrollArea_9->setWidgetResizable(true);

    ui->scrollAreaWidgetContents_11->setLayout(ui->plantmonitergridlayout_sleep);
    ui->scrollArea_10->setWidget(ui->scrollAreaWidgetContents_11);
    ui->scrollArea_10->setWidgetResizable(true);

    plantlist.resize(60);
}

void MainWindow::on_startplantmoniter_stateChanged(int arg1)
{
    if (!CheckBoardOn())
    {
        ui->plantmonitertypeinfo->setText("未检测到关卡");
        ui->plantmoniterbloodinfo->setText("未检测到关卡");
        ui->plantmoniterintervalinfo->setText("未检测到关卡");
        ui->plantmonitershineinfo->setText("未检测到关卡");
        ui->plantmonitersleepinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，植物实时监控终止\n").arg(currentTime);
            out.flush();
        }
        ui->startplantmoniter->setCheckState(Qt::Unchecked);
        return;
    }
    if(arg1==Qt::Checked){
        if(!pMoniter){
            ClearPlantList();
            pMoniter=new NewPlantMoniter;
            pMoniter->pstamoniter=new PlantStatusMoniter;
            pMoniter->thread_survive=true;
            pMoniter->pstamoniter->thread_survive=true;
            pMoniter->pstamoniter->plantlist.resize(60);
            uint32_t plantoff=ReadMemory<uint32_t>({lawn,board,plant_offset});
            pMoniter->plantoff=plantoff;
            connect(pMoniter,&NewPlantMoniter::abnormaltermi,this,[&](){
                ui->plantmonitertypeinfo->setText("未检测到关卡");
                ui->plantmoniterbloodinfo->setText("未检测到关卡");
                ui->plantmoniterintervalinfo->setText("未检测到关卡");
                ui->plantmonitershineinfo->setText("未检测到关卡");
                ui->plantmonitersleepinfo->setText("未检测到关卡");
                if(out.device()){
                    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
                    out<<QString("[%1] 植物数量监测线程监测到关卡退出，自动结束盲盒搜索。\n").arg(currentTime);
                    out.flush();
                }
                ui->startplantmoniter->setCheckState(Qt::Unchecked);
            });
            connect(pMoniter->pstamoniter,&PlantStatusMoniter::abnormaltermi,this,[&](){
                ui->plantmonitertypeinfo->setText("未检测到关卡");
                ui->plantmoniterbloodinfo->setText("未检测到关卡");
                ui->plantmoniterintervalinfo->setText("未检测到关卡");
                ui->plantmonitershineinfo->setText("未检测到关卡");
                ui->plantmonitersleepinfo->setText("未检测到关卡");
                if(out.device()){
                    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
                    out<<QString("[%1] 植物状态监测线程监测到关卡退出，自动结束盲盒搜索。\n").arg(currentTime);
                    out.flush();
                }
                ui->startplantmoniter->setCheckState(Qt::Unchecked);
            });
            connect(pMoniter->pstamoniter,&PlantStatusMoniter::plantchange,this,&MainWindow::MoniterInfoChange);
            ui->plantmonitertypeinfo->setText("开始监控");
            ui->plantmoniterbloodinfo->setText("开始监控");
            ui->plantmoniterintervalinfo->setText("开始监控");
            ui->plantmonitershineinfo->setText("开始监控");
            ui->plantmonitersleepinfo->setText("开始监控");
            pMoniter->current_plant_book_size=current_plant_book.size();
            pMoniter->pstamoniter->current_plant_book_size=current_plant_book.size();
            pMoniter->pstamoniter->start();
            pMoniter->start();
        }
    }
    else if(arg1==Qt::Unchecked){
        if(pMoniter){
            pMoniter->thread_survive=false;
            pMoniter->pstamoniter->thread_survive=false;
            pMoniter->wait();
            delete pMoniter;
            pMoniter=nullptr;
        }
        pMoniter=nullptr;
    }
}

void MainWindow::MoniterInfoChange(int row,int col,int num,int status)
{
    if(!pMoniter) return;
    int i=row*10+col;
    plantlist=pMoniter->pstamoniter->plantlist;
    if(plantlist[i].size()==0&&status==0)return;
    if(status==0){
        if(plantlist[i].size()>plantmoniter_type[i]->count()){
            for(int j=plantmoniter_type[i]->count();j<plantlist[i].size();j++){
                plantmoniter_type[i]->addItem(QString("%1").arg(current_plant_book[plantlist[i][j]->type]));
                plantmoniter_type_1[i]->addItem(QString("%1").arg(current_plant_book[plantlist[i][j]->type]));
                plantmoniter_type_2[i]->addItem(QString("%1").arg(current_plant_book[plantlist[i][j]->type]));
                plantmoniter_type_3[i]->addItem(QString("%1").arg(current_plant_book[plantlist[i][j]->type]));
                plantmoniter_type_4[i]->addItem(QString("%1").arg(current_plant_book[plantlist[i][j]->type]));
            }
        }
        int currentindex=0;
        /*if(plantmoniter_type[i]->currentIndex()!=-1)*/ currentindex=plantmoniter_type[i]->currentIndex();
        int currentindex1=0;
        /*if(plantmoniter_type_1[i]->currentIndex()!=-1)*/ currentindex1=plantmoniter_type_1[i]->currentIndex();
        int currentindex2=0;
       /* if(plantmoniter_type_2[i]->currentIndex()!=-1)*/ currentindex2=plantmoniter_type_2[i]->currentIndex();
        int currentindex3=0;
       /* if(plantmoniter_type_3[i]->currentIndex()!=-1) */currentindex3=plantmoniter_type_3[i]->currentIndex();
        int currentindex4=0;
        /*if(plantmoniter_type_4[i]->currentIndex()!=-1)*/ currentindex4=plantmoniter_type_4[i]->currentIndex();
        if(plantmoniter_check[i]->isChecked()){
            ui->moniter_plantname->setText(QString("%1").arg(current_plant_book[plantlist[i][currentindex]->type]));
            ui->moniter_planttype->setText(QString("%1").arg(plantlist[i][currentindex]->type));
            ui->moniter_plantrow->setText(QString("%1").arg(plantlist[i][currentindex]->row+1));
            ui->moniter_plantcol->setText(QString("%1").arg(plantlist[i][currentindex]->col+1));
            if(plantbloodenable)ui->moniter_plantblood->setText(QString("%1").arg(plantlist[i][currentindex]->blood));
            if(plantintervalenable)ui->moniter_plantinterval->setText(QString("%1").arg(plantlist[i][currentindex]->interval));
            if(plantshootenable)ui->moniter_plantshoot->setValue(plantlist[i][currentindex]->shoottime);
            if(plantflashenable)ui->moniter_plantflash->setValue(plantlist[i][currentindex]->flashingtime);
            if(plantshineenable)ui->moniter_plantshine->setValue(plantlist[i][currentindex]->shiningtime);
            if(plantleftenable&&plantrightenable){
                if(plantlist[i][currentindex]->towards==-1) ui->right->setChecked(true);
                else ui->left->setChecked(true);
            }
            if(plantsquishenable){
                if(plantlist[i][currentindex]->issquished)ui->squish->setCheckState(Qt::Checked);
                else ui->squish->setCheckState(Qt::Unchecked);
            }
            if(plantsleepenable){
                if(plantlist[i][currentindex]->issleep)ui->asleep->setCheckState(Qt::Checked);
                else ui->asleep->setCheckState(Qt::Unchecked);
            }
            if(plantshineenableenable){
                if(plantlist[i][currentindex]->isableshine)ui->enableshine->setCheckState(Qt::Checked);
                else ui->enableshine->setCheckState(Qt::Unchecked);
            }
            if(plantinvisibleenable){
                if(!plantlist[i][currentindex]->isinvisible)ui->invisible->setCheckState(Qt::Checked);
                else ui->invisible->setCheckState(Qt::Unchecked);
            }
        }
        if(plantmoniter_bloodenable[i])plantmoniter_blood[i]->setText(QString("%1").arg(plantlist[i][currentindex1]->blood));
        if(plantmoniter_intervalenable[i])plantmoniter_interval[i]->setText(QString("%1").arg(plantlist[i][currentindex2]->interval));
        if(plantmoniter_shineenable[i])plantmoniter_shine[i]->setText(QString("%1").arg(plantlist[i][currentindex3]->shiningtime));
        if(plantmoniter_flashenable[i])plantmoniter_flash[i]->setText(QString("%1").arg(plantlist[i][currentindex3]->flashingtime));
        if(plantmoniter_sleepenable[i]){
            if(plantlist[i][currentindex4]->issleep)
                plantmoniter_sleep[i]->setCheckState(Qt::Checked);
            else plantmoniter_sleep[i]->setCheckState(Qt::Unchecked);
        }
    }
    if(status==1){
        plantmoniter_type[i]->removeItem(num);
        plantmoniter_type_1[i]->removeItem(num);
        plantmoniter_type_2[i]->removeItem(num);
        plantmoniter_type_3[i]->removeItem(num);
        plantmoniter_type_4[i]->removeItem(num);
        if(plantmoniter_type[i]==0){
            plantbloodenable=false;
            plantintervalenable=false;
            plantshootenable=false;
            plantflashenable=false;
            plantshineenable=false;
            plantleftenable=false;
            plantrightenable=false;
            plantsquishenable=false;
            plantsleepenable=false;
            plantshineenableenable=false;
            plantinvisibleenable=false;
            plantmoniter_bloodenable[i]=false;
            plantmoniter_intervalenable[i]=false;
            plantmoniter_shineenable[i]=false;
            plantmoniter_flashenable[i]=false;
            plantmoniter_sleepenable[i]=false;
            ui->moniter_plantname->setText("");
            ui->moniter_planttype->setText("");
            ui->moniter_plantrow->setText("");
            ui->moniter_plantcol->setText("");
            ui->moniter_plantblood->setText("");
            ui->moniter_plantinterval->setText("");
            ui->moniter_plantshoot->setValue(0);
            ui->moniter_plantflash->setValue(0);
            ui->moniter_plantshine->setValue(0);
            ui->right->setChecked(true);
            ui->squish->setCheckState(Qt::Unchecked);
            ui->asleep->setCheckState(Qt::Unchecked);
            ui->enableshine->setCheckState(Qt::Unchecked);
            ui->invisible->setCheckState(Qt::Unchecked);
            plantmoniter_blood[i]->setText("");
            plantmoniter_interval[i]->setText("");
            plantmoniter_shine[i]->setText("");
            plantmoniter_flash[i]->setText("");
            plantmoniter_sleep[i]->setCheckState(Qt::Unchecked);
            plantbloodenable=true;
            plantintervalenable=true;
            plantshootenable=true;
            plantflashenable=true;
            plantshineenable=true;
            plantleftenable=true;
            plantrightenable=true;
            plantsquishenable=true;
            plantsleepenable=true;
            plantshineenableenable=true;
            plantinvisibleenable=true;
            plantmoniter_bloodenable[i]=true;
            plantmoniter_intervalenable[i]=true;
            plantmoniter_shineenable[i]=true;
            plantmoniter_flashenable[i]=true;
            plantmoniter_sleepenable[i]=true;
        }
    }
}

void MainWindow::on_disappear_stateChanged(int arg1)
{
    if(arg1==Qt::Unchecked) return;
    if (!CheckBoardOn())
    {
        ui->plantmonitertypeinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，植物操作：消失终止\n").arg(currentTime);
            out.flush();
        }
        ui->disappear->setCheckState(Qt::Unchecked);
        return;
    }
    int position=(ui->moniter_plantrow->text().toInt()-1)*10+(ui->moniter_plantcol->text().toInt()-1);
    if(position<0||position>=60) return;
    if(!plantmoniter_check[position]->isChecked()||plantmoniter_type[position]->count()==0) {
        ui->plantmonitertypeinfo->setText("未选中有效植物");
        return;
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：消失开始\n").arg(currentTime);
        out.flush();
    }
    WriteMemory<bool>(true,{plantlist[position][plantmoniter_type[position]->currentIndex()]->addr+plant_dead});
    ui->plantmonitertypeinfo->setText("植物已消失");
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：消失结束\n").arg(currentTime);
        out.flush();
    }
    ui->disappear->setCheckState(Qt::Unchecked);
}


void MainWindow::on_squish_clicked()
{
    plantsquishenable=false;
    if (!CheckBoardOn())
    {
        ui->plantmonitertypeinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，植物操作：压扁终止\n").arg(currentTime);
            out.flush();
        }
        plantsquishenable=true;
        ui->disappear->setCheckState(Qt::Unchecked);
        return;
    }
    int position=(ui->moniter_plantrow->text().toInt()-1)*10+(ui->moniter_plantcol->text().toInt()-1);
    if(position<0||position>=60) return;
    if(!plantmoniter_check[position]->isChecked()||plantmoniter_type[position]->count()==0) {
        ui->plantmonitertypeinfo->setText("未选中有效植物");
        return;
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：压扁开始\n").arg(currentTime);
        out.flush();
    }
    WriteMemory<bool>(true,{plantlist[position][plantmoniter_type[position]->currentIndex()]->addr+plant_squished});
    ui->plantmonitertypeinfo->setText("植物已压扁");
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：压扁结束\n").arg(currentTime);
        out.flush();
    }
    plantsquishenable=true;
}


void MainWindow::on_asleep_clicked()
{
    plantsleepenable=false;
    if (!CheckBoardOn())
    {
        ui->plantmonitertypeinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，植物操作：睡着终止\n").arg(currentTime);
            out.flush();
        }
        plantsleepenable=true;
        return;
    }
    int position=(ui->moniter_plantrow->text().toInt()-1)*10+(ui->moniter_plantcol->text().toInt()-1);
    if(position<0||position>=60) return;
    if(!plantmoniter_check[position]->isChecked()||plantmoniter_type[position]->count()==0) {
        ui->plantmonitertypeinfo->setText("未选中有效植物");
        return;
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：睡着开始\n").arg(currentTime);
        out.flush();
    }
    uint8_t temp=ReadMemory<uint8_t>({0x0045de8e});
    if(ui->asleep->isChecked()){
        WriteMemory<uint8_t>(0x74,{ 0x0045de8e});
        WriteMemory<bool>(ui->asleep->isChecked(),{plantlist[position][plantmoniter_type[position]->currentIndex()]->addr+plant_asleep});
    }
    else {
        WriteMemory<uint8_t>(0xeb,{0x0045de8e});
        CodeStruct* newcode=Init();
        MovReg(newcode,Reg::EAX, plantlist[position][plantmoniter_type[position]->currentIndex()]->addr);
        PushByte(newcode,0);
        Call(newcode,0x0045e860);
        Ret(newcode);
        CodeInject(pvzHand,newcode);
        WriteMemory<bool>(ui->asleep->isChecked(),{plantlist[position][plantmoniter_type[position]->currentIndex()]->addr+plant_asleep});
    }
    WriteMemory<uint8_t>(temp,{0x0045de8e});
    ui->plantmonitertypeinfo->setText("睡着状态改变");
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：睡着结束\n").arg(currentTime);
        out.flush();
    }
    plantsleepenable=true;
}


void MainWindow::on_enableshine_stateChanged(int arg1)
{
    return;
}


void MainWindow::on_invisible_clicked()
{
    plantinvisibleenable=false;
    if (!CheckBoardOn())
    {
        ui->plantmonitertypeinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，植物操作：隐身终止\n").arg(currentTime);
            out.flush();
        }
        plantinvisibleenable=true;
        return;
    }
    int position=(ui->moniter_plantrow->text().toInt()-1)*10+(ui->moniter_plantcol->text().toInt()-1);
    if(position<0||position>=60) return;
    if(!plantmoniter_check[position]->isChecked()||plantmoniter_type[position]->count()==0) {
        ui->plantmonitertypeinfo->setText("未选中有效植物");
        return;
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：隐身开始\n").arg(currentTime);
        out.flush();
    }
    WriteMemory<bool>(!ui->invisible->isChecked(),{plantlist[position][plantmoniter_type[position]->currentIndex()]->addr+plant_invisible});
    ui->plantmonitertypeinfo->setText("隐身状态改变");
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：隐身结束\n").arg(currentTime);
        out.flush();
    }
    plantinvisibleenable=true;
}


void MainWindow::on_left_clicked()
{
    plantleftenable=false;
    plantrightenable=false;
    if (!CheckBoardOn())
    {
        ui->plantmonitertypeinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，植物操作：反向终止\n").arg(currentTime);
            out.flush();
        }
        plantleftenable=true;
        plantrightenable=true;
        return;
    }
    int position=(ui->moniter_plantrow->text().toInt()-1)*10+(ui->moniter_plantcol->text().toInt()-1);
    if(position<0||position>=60) return;
    if(!plantmoniter_check[position]->isChecked()||plantmoniter_type[position]->count()==0) {
        ui->plantmonitertypeinfo->setText("未选中有效植物");
        return;
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：反向开始\n").arg(currentTime);
        out.flush();
    }
    WriteMemory<int>(1,{plantlist[position][plantmoniter_type[position]->currentIndex()]->addr+plant_towards});
    ui->plantmonitertypeinfo->setText("植物方向改变");
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植植物操作：反向结束\n").arg(currentTime);
        out.flush();
    }
    plantleftenable=true;
    plantrightenable=true;
}


void MainWindow::on_right_clicked()
{
    plantleftenable=false;
    plantrightenable=false;
    if (!CheckBoardOn())
    {
        ui->plantmonitertypeinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，植物操作：反向终止\n").arg(currentTime);
            out.flush();
        }
        plantleftenable=true;
        plantrightenable=true;
        return;
    }
    int position=(ui->moniter_plantrow->text().toInt()-1)*10+(ui->moniter_plantcol->text().toInt()-1);
    if(position<0||position>=60) return;
    if(!plantmoniter_check[position]->isChecked()||plantmoniter_type[position]->count()==0) {
        ui->plantmonitertypeinfo->setText("未选中有效植物");
        return;
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：反向开始\n").arg(currentTime);
        out.flush();
    }
    WriteMemory<int>(-1,{plantlist[position][plantmoniter_type[position]->currentIndex()]->addr+plant_towards});
    ui->plantmonitertypeinfo->setText("植物方向改变");
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植植物操作：反向结束\n").arg(currentTime);
        out.flush();
    }
    plantleftenable=true;
    plantrightenable=true;
}


void MainWindow::on_enableshine_clicked()
{
    plantshineenableenable=false;
    if (!CheckBoardOn())
    {
        ui->plantmonitertypeinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，植物操作：可以发亮终止\n").arg(currentTime);
            out.flush();
        }
        plantshineenableenable=true;
        return;
    }
    int position=(ui->moniter_plantrow->text().toInt()-1)*10+(ui->moniter_plantcol->text().toInt()-1);
    if(position<0||position>=60) return;
    if(!plantmoniter_check[position]->isChecked()||plantmoniter_type[position]->count()==0) {
        ui->plantmonitertypeinfo->setText("未选中有效植物");
        return;
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：可以发亮开始\n").arg(currentTime);
        out.flush();
    }
    WriteMemory<bool>(ui->enableshine->isChecked(),{plantlist[position][plantmoniter_type[position]->currentIndex()]->addr+plant_enable_shine});
    ui->plantmonitertypeinfo->setText("可发亮状态改变");
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：可以发亮结束\n").arg(currentTime);
        out.flush();
    }
    plantshineenableenable=true;
}


void MainWindow::on_moniter_plantshoot_sliderPressed()
{
    plantshootenable=false;
}


void MainWindow::on_moniter_plantshoot_sliderReleased()
{
    if (!CheckBoardOn())
    {
        ui->plantmonitertypeinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，修改本次生产/发射间隔终止\n").arg(currentTime);
            out.flush();
        }
        plantshootenable=true;
        return;
    }
    int position=(ui->moniter_plantrow->text().toInt()-1)*10+(ui->moniter_plantcol->text().toInt()-1);
    if(position<0||position>=60) return;
    if(!plantmoniter_check[position]->isChecked()||plantmoniter_type[position]->count()==0) {
        ui->plantmonitertypeinfo->setText("未选中有效植物");
        return;
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：修改本次生产/发射间隔开始\n").arg(currentTime);
        out.flush();
    }
    WriteMemory<uint32_t>(ui->moniter_plantshoot->value(),{plantlist[position][plantmoniter_type[position]->currentIndex()]->addr+plant_shoot_time});
    ui->plantmonitertypeinfo->setText("本次间隔修改完成");
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：修改本次生产/发射间隔结束\n").arg(currentTime);
        out.flush();
    }
    plantshootenable=true;
}


void MainWindow::on_moniter_plantflash_sliderPressed()
{
    plantflashenable=false;
}


void MainWindow::on_moniter_plantflash_sliderReleased()
{
    if (!CheckBoardOn())
    {
        ui->plantmonitertypeinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，设置闪光时间终止\n").arg(currentTime);
            out.flush();
        }
        plantflashenable=true;
        return;
    }
    int position=(ui->moniter_plantrow->text().toInt()-1)*10+(ui->moniter_plantcol->text().toInt()-1);
    if(position<0||position>=60) return;
    if(!plantmoniter_check[position]->isChecked()||plantmoniter_type[position]->count()==0) {
        ui->plantmonitertypeinfo->setText("未选中有效植物");
        return;
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：设置闪光时间开始\n").arg(currentTime);
        out.flush();
    }
    WriteMemory<uint32_t>(ui->moniter_plantflash->value(),{plantlist[position][plantmoniter_type[position]->currentIndex()]->addr+plant_flash_time});
    ui->plantmonitertypeinfo->setText("本次闪光时间修改完成");
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：设置闪光时间结束\n").arg(currentTime);
        out.flush();
    }
    plantflashenable=true;
}


void MainWindow::on_moniter_plantshine_sliderPressed()
{
    plantshineenable=false;
}


void MainWindow::on_moniter_plantshine_sliderReleased()
{
    if (!CheckBoardOn())
    {
        ui->plantmonitertypeinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，设置发光时间终止\n").arg(currentTime);
            out.flush();
        }
        plantshineenable=true;
        return;
    }
    int position=(ui->moniter_plantrow->text().toInt()-1)*10+(ui->moniter_plantcol->text().toInt()-1);
    if(position<0||position>=60) return;
    if(!plantmoniter_check[position]->isChecked()||plantmoniter_type[position]->count()==0) {
        ui->plantmonitertypeinfo->setText("未选中有效植物");
        return;
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：设置闪光时间开始\n").arg(currentTime);
        out.flush();
    }
    WriteMemory<uint32_t>(ui->moniter_plantshine->value(),{plantlist[position][plantmoniter_type[position]->currentIndex()]->addr+plant_shine_time});
    ui->plantmonitertypeinfo->setText("本次发光时间修改完成");
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：设置发光时间结束\n").arg(currentTime);
        out.flush();
    }
    plantshineenable=true;
}


void MainWindow::on_moniter_plantblood_selectionChanged()
{
    plantbloodenable=false;

}


void MainWindow::on_moniter_plantinterval_selectionChanged()
{
    plantintervalenable=false;
}


void MainWindow::on_moniter_plantblood_editingFinished()
{
    if (!CheckBoardOn())
    {
        ui->plantmonitertypeinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，设置血量终止\n").arg(currentTime);
            out.flush();
        }
        plantbloodenable=true;
        return;
    }

    int position=(ui->moniter_plantrow->text().toInt()-1)*10+(ui->moniter_plantcol->text().toInt()-1);
    if(position<0||position>=60) return;
    if(!plantmoniter_check[position]->isChecked()||plantmoniter_type[position]->count()==0) {
        ui->plantmonitertypeinfo->setText("未选中有效植物");
        return;
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：设置血量开始\n").arg(currentTime);
        out.flush();
    }
    WriteMemory<uint32_t>(ui->moniter_plantblood->text().toInt(),{plantlist[position][plantmoniter_type[position]->currentIndex()]->addr+plant_blood});
    ui->plantmonitertypeinfo->setText("本次血量修改完成");
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：设置血量结束\n").arg(currentTime);
        out.flush();
    }
    plantbloodenable=true;
}


void MainWindow::on_moniter_plantinterval_editingFinished()
{
    if (!CheckBoardOn())
    {
        ui->plantmonitertypeinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，设置攻速终止\n").arg(currentTime);
            out.flush();
        }
        plantintervalenable=true;
        return;
    }
    int position=(ui->moniter_plantrow->text().toInt()-1)*10+(ui->moniter_plantcol->text().toInt()-1);
    if(position<0||position>=60) return;
    if(!plantmoniter_check[position]->isChecked()||plantmoniter_type[position]->count()==0) {
        ui->plantmonitertypeinfo->setText("未选中有效植物");
        return;
    }
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：设置攻速开始\n").arg(currentTime);
        out.flush();
    }
    WriteMemory<uint32_t>(ui->moniter_plantinterval->text().toInt(),{plantlist[position][plantmoniter_type[position]->currentIndex()]->addr+plant_attack_interval});
    ui->plantmonitertypeinfo->setText("本次攻速修改完成");
    if(out.device()){
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        out<<QString("[%1] 植物操作：设置攻速结束\n").arg(currentTime);
        out.flush();
    }
    plantintervalenable=true;
}

void MainWindow::ClearPlantList()
{
    if(ui->startplantmoniter->isChecked()){
        ui->plantmonitertypeinfo->setText("请先暂停实时监控");
        return;
    }
    for(int i=0;i<60;i++){
        if(plantlist[i].size()==0)continue;
        plantmoniter_type[i]->clear();
        plantmoniter_type_1[i]->clear();
        plantmoniter_type_2[i]->clear();
        plantmoniter_type_3[i]->clear();
        plantmoniter_type_4[i]->clear();
        ui->moniter_plantname->setText("");
        ui->moniter_planttype->setText("");
        ui->moniter_plantblood->setText("");
        ui->moniter_plantcol->setText("");
        ui->moniter_plantrow->setText("");
        ui->moniter_plantflash->setValue(0);
        ui->moniter_plantinterval->setText("");
        ui->moniter_plantshine->setValue(0);
        ui->asleep->setCheckState(Qt::Unchecked);
        ui->disappear->setCheckState(Qt::Unchecked);
        ui->squish->setCheckState(Qt::Unchecked);
        ui->invisible->setCheckState(Qt::Unchecked);
        ui->enableshine->setCheckState(Qt::Unchecked);
        plantmoniter_blood[i]->setText("");
        plantmoniter_flash[i]->setText("");
        plantmoniter_shine[i]->setText("");
        plantmoniter_interval[i]->setText("");
        plantmoniter_sleep[i]->setCheckState(Qt::Unchecked);
        for(int j=0;j<plantlist[j].size();j++) delete plantlist[i][j];
        plantlist[i].clear();
    }
}

void MainWindow::PlantInfoChange(int row,int col)
{
    int i=row*10+col;
        if(plantlist[i].size()>plantmoniter_type[i]->count()){
            for(int j=plantmoniter_type[i]->count();j<plantlist[i].size();j++){
                plantmoniter_type[i]->addItem(QString("%1").arg(current_plant_book[plantlist[i][j]->type]));
                plantmoniter_type_1[i]->addItem(QString("%1").arg(current_plant_book[plantlist[i][j]->type]));
                plantmoniter_type_2[i]->addItem(QString("%1").arg(current_plant_book[plantlist[i][j]->type]));
                plantmoniter_type_3[i]->addItem(QString("%1").arg(current_plant_book[plantlist[i][j]->type]));
                plantmoniter_type_4[i]->addItem(QString("%1").arg(current_plant_book[plantlist[i][j]->type]));
            }
        }
        int currentindex=0;
        /*if(plantmoniter_type[i]->currentIndex()!=-1)*/ currentindex=plantmoniter_type[i]->currentIndex();
        int currentindex1=0;
        /*if(plantmoniter_type_1[i]->currentIndex()!=-1)*/ currentindex1=plantmoniter_type_1[i]->currentIndex();
        int currentindex2=0;
        /* if(plantmoniter_type_2[i]->currentIndex()!=-1)*/ currentindex2=plantmoniter_type_2[i]->currentIndex();
        int currentindex3=0;
        /* if(plantmoniter_type_3[i]->currentIndex()!=-1) */currentindex3=plantmoniter_type_3[i]->currentIndex();
        int currentindex4=0;
        /*if(plantmoniter_type_4[i]->currentIndex()!=-1)*/ currentindex4=plantmoniter_type_4[i]->currentIndex();
        if(plantmoniter_check[i]->isChecked()){
            ui->moniter_plantname->setText(QString("%1").arg(current_plant_book[plantlist[i][currentindex]->type]));
            ui->moniter_planttype->setText(QString("%1").arg(plantlist[i][currentindex]->type));
            ui->moniter_plantrow->setText(QString("%1").arg(plantlist[i][currentindex]->row+1));
            ui->moniter_plantcol->setText(QString("%1").arg(plantlist[i][currentindex]->col+1));
            if(plantbloodenable)ui->moniter_plantblood->setText(QString("%1").arg(plantlist[i][currentindex]->blood));
            if(plantintervalenable)ui->moniter_plantinterval->setText(QString("%1").arg(plantlist[i][currentindex]->interval));
            if(plantshootenable)ui->moniter_plantshoot->setValue(plantlist[i][currentindex]->shoottime);
            if(plantflashenable)ui->moniter_plantflash->setValue(plantlist[i][currentindex]->flashingtime);
            if(plantshineenable)ui->moniter_plantshine->setValue(plantlist[i][currentindex]->shiningtime);
            if(plantleftenable&&plantrightenable){
                if(plantlist[i][currentindex]->towards==-1) ui->right->setChecked(true);
                else ui->left->setChecked(true);
            }
            if(plantsquishenable){
                if(plantlist[i][currentindex]->issquished)ui->squish->setCheckState(Qt::Checked);
                else ui->squish->setCheckState(Qt::Unchecked);
            }
            if(plantsleepenable){
                if(plantlist[i][currentindex]->issleep)ui->asleep->setCheckState(Qt::Checked);
                else ui->asleep->setCheckState(Qt::Unchecked);
            }
            if(plantshineenableenable){
                if(plantlist[i][currentindex]->isableshine)ui->enableshine->setCheckState(Qt::Checked);
                else ui->enableshine->setCheckState(Qt::Unchecked);
            }
            if(plantinvisibleenable){
                if(!plantlist[i][currentindex]->isinvisible)ui->invisible->setCheckState(Qt::Checked);
                else ui->invisible->setCheckState(Qt::Unchecked);
            }
        }
        if(plantmoniter_bloodenable[i])plantmoniter_blood[i]->setText(QString("%1").arg(plantlist[i][currentindex1]->blood));
        if(plantmoniter_intervalenable[i])plantmoniter_interval[i]->setText(QString("%1").arg(plantlist[i][currentindex2]->interval));
        if(plantmoniter_shineenable[i])plantmoniter_shine[i]->setText(QString("%1").arg(plantlist[i][currentindex3]->shiningtime));
        if(plantmoniter_flashenable[i])plantmoniter_flash[i]->setText(QString("%1").arg(plantlist[i][currentindex3]->flashingtime));
        if(plantmoniter_sleepenable[i]){
            if(plantlist[i][currentindex4]->issleep)
                plantmoniter_sleep[i]->setCheckState(Qt::Checked);
            else plantmoniter_sleep[i]->setCheckState(Qt::Unchecked);
        }

}

void MainWindow::UpdatePlantList()
{
    ClearPlantList();
    uint32_t plantoff=ReadMemory<uint32_t>({lawn,board,plant_offset});
    uint32_t plant_max=ReadMemory<uint32_t>({lawn,board,plant_count_max});
    for(size_t i=0;i<plant_max;i++){
        uint32_t currentaddr=plantoff+i*plant_single_size;
        bool isdead=ReadMemory<bool>({currentaddr+plant_dead});
        if(isdead) continue;
        PlantInfoStruct* newplant=new PlantInfoStruct;
        newplant->addr=currentaddr;
        newplant->number=i;
        newplant->col=ReadMemory<uint32_t>({newplant->addr+plant_col});
        newplant->row=ReadMemory<uint32_t>({newplant->addr+plant_row});
        newplant->type=ReadMemory<uint32_t>({newplant->addr+plant_type});
        newplant->blood=ReadMemory<uint32_t>({newplant->addr+plant_blood});
        newplant->interval=ReadMemory<uint32_t>({newplant->addr+plant_attack_interval});
        newplant->isableshine=ReadMemory<bool>({newplant->addr+plant_enable_shine});
        if(newplant->isableshine)newplant->flashingtime=ReadMemory<uint32_t>({newplant->addr+plant_flash_time});
        if(newplant->isableshine)newplant->shiningtime=ReadMemory<uint32_t>({newplant->addr+plant_shine_time});
        newplant->towards=ReadMemory<int>({newplant->addr+plant_towards});
        newplant->isinvisible=ReadMemory<bool>({newplant->addr+plant_invisible});
        newplant->issquished=ReadMemory<bool>({newplant->addr+plant_squished});
        newplant->issleep=ReadMemory<bool>({newplant->addr+plant_asleep});
        newplant->shoottime=ReadMemory<uint32_t>({newplant->addr+plant_shoot_time});
        plantlist[newplant->row*10+newplant->col].push_back(newplant);
        PlantInfoChange(newplant->row,newplant->col);
    }

}

void MainWindow::on_updateplantlist_clicked()
{
    if(ui->startplantmoniter->isChecked()){
        ui->plantmonitertypeinfo->setText("请先暂停实时监控");
        return;
    }
    if (!CheckBoardOn())
    {
        ui->plantmonitertypeinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，更新植物列表终止\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    UpdatePlantList();
}


void MainWindow::on_clearplantlist_clicked()
{
    if(ui->startplantmoniter->isChecked()){
        ui->plantmonitertypeinfo->setText("请先暂停实时监控");
        return;
    }
    ClearPlantList();
}


void MainWindow::on_updateplantlist_2_clicked()
{
    on_updateplantlist_clicked();
}


void MainWindow::on_clearplantlist_2_clicked()
{
    on_clearplantlist_clicked();
}


void MainWindow::on_updateplantlist_3_clicked()
{
    on_updateplantlist_clicked();
}


void MainWindow::on_clearplantlist_3_clicked()
{
    on_clearplantlist_clicked();
}


void MainWindow::on_updateplantlist_4_clicked()
{
    on_updateplantlist_clicked();
}


void MainWindow::on_clearplantlist_4_clicked()
{
    on_clearplantlist_clicked();
}


void MainWindow::on_updateplantlist_5_clicked()
{
    on_updateplantlist_clicked();
}


void MainWindow::on_clearplantlist_5_clicked()
{
    on_clearplantlist_clicked();
}

void MainWindow::InitZombierealMoniterList()
{
    ui->realtimezombielist->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->realtimezombielist->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->realtimezombielist->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->realtimezombielist->resizeRowsToContents();
    ui->realtimezombielist->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->realtimezombielist->setRowCount(0);
    ui->realtimezombielist->setColumnCount(1);
    QStringList headerLabels;
    headerLabels << QStringLiteral("[编号] 【僵尸名称】");
    ui->realtimezombielist->setHorizontalHeaderLabels(headerLabels);
    int tableWidth = ui->realtimezombielist->viewport()->width();
    QHeaderView *view = new QHeaderView(Qt::Horizontal);
    view->resizeSections(QHeaderView::ResizeToContents);
    ui->realtimezombielist->setHorizontalHeader(view);
    ui->realtimezombielist->horizontalHeader()->resizeSection(0, tableWidth);
    ui->realtimezombielist->horizontalHeader()->setHidden(true);
    ui->realtimezombielist->horizontalHeader()->setStretchLastSection(true);
    ui->realtimezombielist->verticalHeader()->setDefaultSectionSize(20);
    connect(ui->realtimezombielist, &QTableWidget::itemClicked, this,[=](){
        if(singlezMoniter){
            singlezMoniter->thread_survive=false;
            singlezMoniter->quit();
            singlezMoniter->wait();
            delete singlezMoniter;
            singlezMoniter=nullptr;
        }
        if(!CheckBoardOn())return;
        if(!zMoniter)return;
        if(!zMoniter->zstamoniter)return;
        singlezMoniter=new ZombieInfoUpdateThread;
        int row=ui->realtimezombielist->currentRow();
        if(zMoniter->zstamoniter)if(row>=zMoniter->zstamoniter->zombielist.size())return;
        if(row>=ui->realtimezombielist->rowCount()||row<0) return;
        singlezMoniter->zombiepointer=*zMoniter->zstamoniter->zombielist[row];
        if(!ui->checkBox->isChecked()){
            ui->zombierealtimeinfo->setText("请先开启实时监控");
            return;
        }

        ui->zombierealtimeinfo->setText("");
        singlezMoniter->thread_survive=true;
        connect(singlezMoniter,&ZombieInfoUpdateThread::updatefinied,this,&MainWindow::ZombieInfoShow);
        singlezMoniter->start();
    });
}

void MainWindow::ZombieInfoShow(ZombieInfoStruct zomb){
    if(!CheckBoardOn())return;
    QString zombiename;
    if(zomb.type>=current_zombie_book.size())zombiename="未知僵尸";
    else zombiename=current_zombie_book[zomb.type];
    int zrow=-1;
    if(zMoniter&&zMoniter->zstamoniter)
    for(int i=0;i<zMoniter->zstamoniter->zombielist.size();i++)
        if(zomb.id==zMoniter->zstamoniter->zombielist[i]->id)zrow=i;
    if(zrow!=-1)ui->realtimezombielist->setItem(zrow,0,new QTableWidgetItem(QString("[%1] 【%2】").arg(zomb.id).arg(zombiename)));
    else {
        if(singlezMoniter){
            singlezMoniter->thread_survive=false;
            singlezMoniter->quit();
            singlezMoniter->wait();
            delete singlezMoniter;
            singlezMoniter=nullptr;
        }
    }
    ui->moniter_zombiename->setText(zombiename);
    ui->moniter_zombietype->setText(QString("%1").arg(zomb.type));
    ui->moniter_zombierow->setText(QString("%1").arg(zomb.row+1));
    ui->moniter_zombiecol->setText(QString("%1").arg(zomb.col+1));
    if(zombiearmor1_enable)ui->moniter_zombiearmorblood1->setText(QString("%1").arg(zomb.armorblood1));
    if(zombiearmor2_enable)ui->moniter_zombiearmorblood2->setText(QString("%1").arg(zomb.armorblood2));
    ui->moniter_zombiearmortype1->setText(QString("%1").arg(zomb.armortype_1));
    ui->moniter_zombiearmortype2->setText(QString("%1").arg(zomb.armortype_2));
    if(zombiebodyenable)ui->moniter_zombiebodyblood->setText(QString("%1").arg(zomb.bodyblood));
    if(zombiexenable)ui->moniter_zombiex->setText(QString("%1").arg(QString::number(zomb.x, 'f', 2)));
    if(zombieyenable)ui->moniter_zombiey->setText(QString("%1").arg(QString::number(zomb.y, 'f', 2)));
    if(zombieslowenable)ui->moniter_zombieslowtime->setValue(zomb.slowingtime);
    if(zombiebodyshinenable)ui->moniter_zombiebodyshinetime->setValue(zomb.shingingtime);
    if(zombiebutterenable)ui->moniter_zombiebuttertime->setValue(zomb.buttertime);
    if(zombiearmorshineenable)ui->moniter_zombiearmorshinetime->setValue(zomb.armorshiningtime);
    if(zombiefreezeenable)ui->moniter_zombiefrozetime->setValue(zomb.frozentime);
    if(zombiearmorshakeenable)ui->moniter_zombiearmorshaketime->setValue(zomb.armorshaketime);
    if(zombiehypnoenable){
        if(zomb.ishypnoed)ui->ishypnoed->setCheckState(Qt::Checked);
        else ui->ishypnoed->setCheckState(Qt::Unchecked);
    }
    if(zombievisibleenable){
        if(!zomb.isvisible)ui->isvisible->setCheckState(Qt::Checked);
        else ui->isvisible->setCheckState(Qt::Unchecked);
    }
    if(zombieneardeadenable){
        if(!zomb.isneardead)ui->zombie_near_dead->setCheckState(Qt::Checked);
        else ui->zombie_near_dead->setCheckState(Qt::Unchecked);
    }
    if(zombieinwaterenable){
        if(zomb.isinwater)ui->zombie_inwater->setCheckState(Qt::Checked);
        else ui->zombie_inwater->setCheckState(Qt::Unchecked);
    }
    if(zombieeatgarlicenable){
        if(zomb.iseatgarlic)ui->zombie_eatgarlic->setCheckState(Qt::Checked);
        else ui->zombie_eatgarlic->setCheckState(Qt::Unchecked);
    }
    if(!zomb.isnohand)ui->zombie_nohand->setCheckState(Qt::Checked);
    else ui->zombie_nohand->setCheckState(Qt::Unchecked);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (!CheckBoardOn())
    {
        ui->zombierealtimeinfo->setText("未检测到关卡");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到关卡，僵尸实时监控终止\n").arg(currentTime);
            out.flush();
        }
        ui->checkBox->setCheckState(Qt::Unchecked);
        return;
    }
    if(arg1==Qt::Checked){
        while(ui->realtimezombielist->rowCount()!=0){
            ui->realtimezombielist->removeRow(0);
        }
        if(zMoniter){
            zMoniter->quit();
            zMoniter->wait();
            delete zMoniter;
            zMoniter=nullptr;
        }
        zMoniter=new NewZombieMoniter;
        zMoniter->zstamoniter=new ZombieStatusMoniter;
        zMoniter->thread_survive=true;
        zMoniter->zstamoniter->thread_survive=true;
        zMoniter->zombieoff=ReadMemory<uint32_t>({lawn,board,zombie_offset});
        connect(zMoniter,&NewZombieMoniter::findnewzombie,this,&MainWindow::ZombieListSizeAdd);
        connect(zMoniter->zstamoniter,&ZombieStatusMoniter::findnewzombie,this,&MainWindow::ZombieListSizeAdd);
        connect(zMoniter->zstamoniter,&ZombieStatusMoniter::zombiedeadinfo,this,&MainWindow::ZombieListDelete);
        connect(zMoniter,&NewZombieMoniter::abnormaltermi,this,[&](){
            ui->zombierealtimeinfo->setText("未检测到关卡");
            if(out.device()){
                QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
                out<<QString("[%1] 僵尸实时监测线程监测到关卡退出，自动结束盲盒搜索。\n").arg(currentTime);
                out.flush();
            }
            ui->checkBox->setCheckState(Qt::Unchecked);
        });
        connect(zMoniter->zstamoniter,&ZombieStatusMoniter::abnormaltermi,this,[&](){
            ui->zombierealtimeinfo->setText("未检测到关卡");
            if(out.device()){
                QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
                out<<QString("[%1] 僵尸实时监控线程监测到关卡退出，自动结束盲盒搜索。\n").arg(currentTime);
                out.flush();
            }
            ui->checkBox->setCheckState(Qt::Unchecked);
        });
        zMoniter->zstamoniter->start();
        zMoniter->start();
    }
    else if(arg1==Qt::Unchecked){
        if(zMoniter){
            zMoniter->thread_survive=false;
            zMoniter->quit();
            zMoniter->wait();
            delete zMoniter;
            zMoniter=nullptr;
        }
    }
}



void MainWindow::ZombieListSizeAdd(int type,int blood,int armor1,int armor2,int num,int row,bool ishypnoed)
{
    QString zombiename;
    if(type>=current_zombie_book.size())zombiename="未知僵尸";
    else zombiename=current_zombie_book[type];
    int lastRow = ui->realtimezombielist->rowCount();
    ui->realtimezombielist->insertRow(lastRow);
    QTableWidgetItem *item = new QTableWidgetItem(QString("[%1] 【%2】").arg(num).arg(zombiename));
    ui->realtimezombielist->setItem(lastRow, 0, item);
    if(ui->starttotal->isChecked()){
        if(ui->ignoreblindbox->isChecked()&&type==blindzombie)return;
        if(ui->ignoreishypno->isChecked()&&ishypnoed) return;
        QDateTime endtime=QDateTime::currentDateTime();
        int msecsDiff = StartTime.msecsTo(endtime);
        int minutes = msecsDiff / (60 * 1000);
        int seconds = (msecsDiff % (60 * 1000)) / 1000;
        int milliseconds = msecsDiff % 1000;

        if(row==0){
            ui->row0->append(QString("[%1:%2:%3] \n%4产生\n本体血量:%5\n饰品1血量:%6\n饰品2血量:%7").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(blood).arg(armor1).arg(armor2));
        }
        if(row==1){
            ui->row1->append(QString("[%1:%2:%3] \n%4产生\n本体血量:%5\n饰品1血量:%6\n饰品2血量:%7").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(blood).arg(armor1).arg(armor2));
            //if(zombieoutfile.device()) zombieoutfile<<QString("[%1:%2:%3]%5行 %4产生").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(2);
        }
        if(row==2){
            ui->row2->append(QString("[%1:%2:%3] \n%4产生\n本体血量:%5\n饰品1血量:%6\n饰品2血量:%7").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(blood).arg(armor1).arg(armor2));
           // if(zombieoutfile.device()) zombieoutfile<<QString("[%1:%2:%3]%5行 %4产生").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(3);
        }
        if(row==3){
            ui->row3->append(QString("[%1:%2:%3] \n%4产生\n本体血量:%5\n饰品1血量:%6\n饰品2血量:%7").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(blood).arg(armor1).arg(armor2));
           // if(zombieoutfile.device()) zombieoutfile<<QString("[%1:%2:%3]%5行 %4产生").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(4);
        }
        if(row==4){
            ui->row4->append(QString("[%1:%2:%3] \n%4产生\n本体血量:%5\n饰品1血量:%6\n饰品2血量:%7").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(blood).arg(armor1).arg(armor2));
          //  if(zombieoutfile.device()) zombieoutfile<<QString("[%1:%2:%3]%5行 %4产生").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(5);
        }
        if(row==5){
            ui->row5->append(QString("[%1:%2:%3] \n%4产生\n本体血量:%5\n饰品1血量:%6\n饰品2血量:%7").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(blood).arg(armor1).arg(armor2));
           // if(zombieoutfile.device()) zombieoutfile<<QString("[%1:%2:%3]%5行 %4产生").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(6);
        }
        if(zombieoutfile.device()){
            zombieoutfile<<QString("[%1:%2:%3]%8行 \n%4产生\n本体血量:%5\n饰品1血量:%6\n饰品2血量:%7\n").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(blood).arg(armor1).arg(armor2).arg(row+1);
            zombieoutfile.flush();
        }

    }
}

void MainWindow::ZombieListDelete(ZombieInfoStruct zomb,int num,int state)
{
    QString zombiename;
    if(zomb.type>=current_zombie_book.size())zombiename="未知僵尸";
    else zombiename=current_zombie_book[zomb.type];
    if(state==0){
        ui->realtimezombielist->removeRow(num);
        QString name;
        if(zMoniter&&zMoniter->zstamoniter)
            for(int i=0;i<zMoniter->zstamoniter->zombielist.size();i++){
                if(zMoniter->zstamoniter->zombielist[i]->type>=current_zombie_book.size())name="未知僵尸";
                else name=current_zombie_book[zMoniter->zstamoniter->zombielist[i]->type];
                ui->realtimezombielist->setItem(i,0,new QTableWidgetItem(QString("[%1] 【%2】").arg(zMoniter->zstamoniter->zombielist[i]->id).arg(name)));
            }
    }
    else{
        QString name;
         if(zMoniter&&zMoniter->zstamoniter)
        for(int i=0;i<zMoniter->zstamoniter->zombielist.size();i++){
            if(zMoniter->zstamoniter->zombielist[i]->type>=current_zombie_book.size())name="未知僵尸";
            else name=current_zombie_book[zMoniter->zstamoniter->zombielist[i]->type];
            ui->realtimezombielist->setItem(i,0,new QTableWidgetItem(QString("[%1] 【%2】").arg(zMoniter->zstamoniter->zombielist[i]->id).arg(name)));
        }
    }
    if(ui->starttotal->isChecked()){
        if(ui->ignoreblindbox->isChecked()&&zomb.type==blindzombie)return;
        if(ui->ignoreishypno->isChecked()&&zomb.ishypnoed) return;
        QDateTime endtime=QDateTime::currentDateTime();
        int msecsDiff = StartTime.msecsTo(endtime);
        int minutes = msecsDiff / (60 * 1000);
        int seconds = (msecsDiff % (60 * 1000)) / 1000;
        int milliseconds = msecsDiff % 1000;

        if(zomb.row==0){
            ui->row0->append(QString("[%1:%2:%3] \n%4死亡").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename));
            if(zombieoutfile.device()) {
                zombieoutfile<<QString("[%1:%2:%3]%5行 %4死亡\n").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(1);
            }
        }
        if(zomb.row==1){
            ui->row1->append(QString("[%1:%2:%3] \n%4死亡").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename));
            if(zombieoutfile.device())
                zombieoutfile<<QString("[%1:%2:%3]%5行 %4死亡\n").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(2);
        }
        if(zomb.row==2){
            ui->row2->append(QString("[%1:%2:%3] \n%4死亡").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename));
            if(zombieoutfile.device()) zombieoutfile<<QString("[%1:%2:%3]%5行 %4死亡\n").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(3);
        }
        if(zomb.row==3){
            ui->row3->append(QString("[%1:%2:%3] \n%4死亡").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename));
            if(zombieoutfile.device()) zombieoutfile<<QString("[%1:%2:%3]%5行 %4死亡\n").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(4);
        }
        if(zomb.row==4){
            ui->row4->append(QString("[%1:%2:%3] \n%4死亡").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename));
            if(zombieoutfile.device()) zombieoutfile<<QString("[%1:%2:%3]%5行 %4死亡\n").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(5);
        }
        if(zomb.row==5){
            ui->row5->append(QString("[%1:%2:%3] \n%4死亡").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename));
            if(zombieoutfile.device()) zombieoutfile<<QString("[%1:%2:%3]%5行 %4死亡\n").arg(minutes).arg(seconds).arg(milliseconds).arg(zombiename).arg(6);
        }
        if(zombieoutfile.device())zombieoutfile.flush();
    }
    DeadZombieStruct newdead;
    newdead.row=zomb.row;
    newdead.type=zomb.type;
    newdead.findtime=zomb.findtime;
    newdead.deadtime=zomb.deadtime;
    newdead.ishypno=zomb.ishypnoed;
    deadzombielist.push_back(newdead);
}

void MainWindow::on_starttotal_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        StartTime=QDateTime::currentDateTime();
        ui->row0->clear();
        ui->row0->append(QString("[%1]\n第1行开始统计").arg(StartTime.toString("yyyy-MM-dd hh:mm:ss.zzz")));
        ui->row1->clear();
        ui->row1->append(QString("[%1]\n第2行开始统计").arg(StartTime.toString("yyyy-MM-dd hh:mm:ss.zzz")));
        ui->row2->clear();
        ui->row2->append(QString("[%1]\n第3行开始统计").arg(StartTime.toString("yyyy-MM-dd hh:mm:ss.zzz")));
        ui->row3->clear();
        ui->row3->append(QString("[%1]\n第4行开始统计").arg(StartTime.toString("yyyy-MM-dd hh:mm:ss.zzz")));
        ui->row4->clear();
        ui->row4->append(QString("[%1]\n第5行开始统计").arg(StartTime.toString("yyyy-MM-dd hh:mm:ss.zzz")));
        ui->row5->clear();
        ui->row5->append(QString("[%1]\n第6行开始统计").arg(StartTime.toString("yyyy-MM-dd hh:mm:ss.zzz")));
    }
    else if(arg1==Qt::Unchecked){
        ui->row0->append(QString("[%1]结束统计").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")));
        ui->row1->append(QString("[%1]结束统计").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")));
        ui->row2->append(QString("[%1]结束统计").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")));
        ui->row3->append(QString("[%1]结束统计").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")));
        ui->row4->append(QString("[%1]结束统计").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")));
        ui->row5->append(QString("[%1]结束统计").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")));
        if(ui->finalgetrowdetails->isChecked()){
            ui->row0->append(QString("\n以下为行统计信息\n"));
            ui->row1->append(QString("\n以下为行统计信息\n"));
            ui->row2->append(QString("\n以下为行统计信息\n"));
            ui->row3->append(QString("\n以下为行统计信息\n"));
            ui->row4->append(QString("\n以下为行统计信息\n"));
            ui->row5->append(QString("\n以下为行统计信息\n"));
            if(zombieoutfile.device()){
                zombieoutfile<<QString("\n以下为行统计信息\n\n");
                zombieoutfile.flush();
            }
            int count[6]={0};
            vector<DeadZombieStruct>zomb=deadzombielist;
            for(int i=0;i<zomb.size();i++){
                QString zombiename;
                if(zomb[i].type>=current_zombie_book.size())zombiename="未知僵尸";
                else zombiename=current_zombie_book[zomb[i].type];
                int msecsDiff = zomb[i].findtime.msecsTo(zomb[i].deadtime);
                double seconds = ((double)(msecsDiff % (60 * 1000))) / 1000;
                if(zomb[i].ishypno){
                    if(zomb[i].row==0){
                        ui->row0->append(QString("[%1] %2\n存在时间：%3s").arg("魅惑").arg(zombiename).arg(QString::number(seconds, 'f', 2)));
                    }
                    if(zomb[i].row==1){
                        ui->row1->append(QString("[%1] %2\n存在时间：%3s").arg("魅惑").arg(zombiename).arg(QString::number(seconds, 'f', 2)));
                    }
                    if(zomb[i].row==2){
                        ui->row2->append(QString("[%1] %2\n存在时间：%3s").arg("魅惑").arg(zombiename).arg(QString::number(seconds, 'f', 2)));
                    }
                    if(zomb[i].row==3){
                        ui->row3->append(QString("[%1] %2\n存在时间：%3s").arg("魅惑").arg(zombiename).arg(QString::number(seconds, 'f', 2)));
                    }
                    if(zomb[i].row==4){
                        ui->row4->append(QString("[%1] %2\n存在时间：%3s").arg("魅惑").arg(zombiename).arg(QString::number(seconds, 'f', 2)));
                    }
                    if(zomb[i].row==5){
                        ui->row5->append(QString("[%1] %2\n存在时间：%3s").arg("魅惑").arg(zombiename).arg(QString::number(seconds, 'f', 2)));
                    }
                    if(zombieoutfile.device()){
                        zombieoutfile<<QString("第%4行[%1] %2\n存在时间：%3s\n").arg("魅惑").arg(zombiename).arg(QString::number(seconds, 'f', 2)).arg(zomb[i].row+1);
                        zombieoutfile.flush();
                    }
                    continue;
                }
                count[zomb[i].row]++;
                if(zomb[i].row==0){
                    ui->row0->append(QString("[%1] %2\n存活时间：%3s").arg(count[zomb[i].row]).arg(zombiename).arg(QString::number(seconds, 'f', 2)));
                }
                if(zomb[i].row==1){
                    ui->row1->append(QString("[%1] %2\n存活时间：%3s").arg(count[zomb[i].row]).arg(zombiename).arg(QString::number(seconds, 'f', 2)));
                }
                if(zomb[i].row==2){
                    ui->row2->append(QString("[%1] %2\n存活时间：%3s").arg(count[zomb[i].row]).arg(zombiename).arg(QString::number(seconds, 'f', 2)));
                }
                if(zomb[i].row==3){
                    ui->row3->append(QString("[%1] %2\n存活时间：%3s").arg(count[zomb[i].row]).arg(zombiename).arg(QString::number(seconds, 'f', 2)));
                }
                if(zomb[i].row==4){
                    ui->row4->append(QString("[%1] %2\n存活时间：%3s").arg(count[zomb[i].row]).arg(zombiename).arg(QString::number(seconds, 'f', 2)));
                }
                if(zomb[i].row==5){
                    ui->row5->append(QString("[%1] %2\n存活时间：%3s").arg(count[zomb[i].row]).arg(zombiename).arg(QString::number(seconds, 'f', 2)));
                }
                if(zombieoutfile.device()){
                    zombieoutfile<<QString("第%4行[%1] %2\n存活时间：%3s\n").arg(count[zomb[i].row]).arg(zombiename).arg(QString::number(seconds, 'f', 2)).arg(zomb[i].row+1);
                    zombieoutfile.flush();
                }
            }
            ui->row0->append(QString("\n第1行共计击杀%1个僵尸").arg(count[0]));
            ui->row1->append(QString("\n第2行共计击杀%1个僵尸").arg(count[1]));
            ui->row2->append(QString("\n第3行共计击杀%1个僵尸").arg(count[2]));
            ui->row3->append(QString("\n第4行共计击杀%1个僵尸").arg(count[3]));
            ui->row4->append(QString("\n第5行共计击杀%1个僵尸").arg(count[4]));
            ui->row5->append(QString("\n第6行共计击杀%1个僵尸").arg(count[5]));
            if(zombieoutfile.device()){
                for(int i=0;i<6;i++){
                    zombieoutfile<<QString("\n第%2行共计击杀%1个僵尸\n").arg(count[i]).arg(i+1);
                    zombieoutfile.flush();
                }
            }
        }
        if(zombieoutfile.device()){
            zombieoutfile<<QString("[%1]结束统计。\n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz"));
            zombieoutfile.flush();
            zombiefile.close();
        }
    }
}


void MainWindow::on_realtimefile_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        QString currentPath = QDir::currentPath();
        QString logDir =currentPath + QDir::separator() + "ZombieStatistics";
        QDir().mkpath(logDir);
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString currentTime = currentDateTime.toString("yyyy-MM-dd-hh-mm-ss");
        QString filePath = logDir+ QDir::separator()+currentTime+".log";
        zombiefile.setFileName(filePath);
        if (!zombiefile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            ui->realtimefile->setCheckState(Qt::Unchecked);
            return ;
        }
        zombieoutfile.setDevice(&zombiefile);
        currentDateTime = QDateTime::currentDateTime();
        currentTime = currentDateTime.toString("yyyy-MM-dd hh:mm:ss.zzz");
        zombieoutfile<<QString("[%1]开始统计。\n").arg(currentTime);
        zombieoutfile.flush();
    }
}


void MainWindow::on_zombiedisapear_stateChanged(int arg1)
{
    if(!CheckBoardOn())return;
    if(arg1==Qt::Checked){
        if(singlezMoniter){
            WriteMemory<bool>(true,{singlezMoniter->zombiepointer.addr+zombie_dead});
        }
        ui->zombiedisapear->setCheckState(Qt::Unchecked);
    }
}


void MainWindow::on_moniter_zombiex_selectionChanged()
{
    if(!CheckBoardOn())return;
    zombiexenable=false;
}


void MainWindow::on_moniter_zombiex_editingFinished()
{
    if(!CheckBoardOn())return;
    if(singlezMoniter){
        bool ok;
        float value=ui->moniter_zombiex->text().toFloat(&ok);
        if(ok)WriteMemory<float>(value,{singlezMoniter->zombiepointer.addr+zombie_xcorordinate});
    }
    zombiexenable=true;
}


void MainWindow::on_moniter_zombiey_selectionChanged()
{
    if(!CheckBoardOn())return;
    zombieyenable=false;
}


void MainWindow::on_moniter_zombiey_editingFinished()
{
    if(!CheckBoardOn())return;
    if(singlezMoniter){
        bool ok;
        float value=ui->moniter_zombiey->text().toFloat(&ok);
        WriteMemory<float>(value,{singlezMoniter->zombiepointer.addr+zombie_ycorordinate});
    }
    zombieyenable=true;
}


void MainWindow::on_moniter_zombiebodyblood_selectionChanged()
{
    if(!CheckBoardOn())return;
    zombiebodyenable=false;
}


void MainWindow::on_moniter_zombiebodyblood_editingFinished()
{
    if(!CheckBoardOn())return;
    if(singlezMoniter){
        bool ok;
        int value=ui->moniter_zombiebodyblood->text().toInt(&ok);
        WriteMemory<uint32_t>(value,{singlezMoniter->zombiepointer.addr+zombie_body_blood});
    }
    zombiebodyenable=true;
}


void MainWindow::on_moniter_zombiearmorblood1_selectionChanged()
{
    if(!CheckBoardOn())return;
    zombiearmor1_enable=false;
}


void MainWindow::on_moniter_zombiearmorblood1_editingFinished()
{
    if(!CheckBoardOn())return;
    if(singlezMoniter){
        bool ok;
        int value=ui->moniter_zombiearmorblood1->text().toInt(&ok);
        WriteMemory<uint32_t>(value,{singlezMoniter->zombiepointer.addr+zombie_armor1_body});
    }
    zombiearmor1_enable=true;
}


void MainWindow::on_moniter_zombiearmorblood2_selectionChanged()
{
    if(!CheckBoardOn())return;
    zombiearmor2_enable=false;
}


void MainWindow::on_moniter_zombiearmorblood2_editingFinished()
{
    if(!CheckBoardOn())return;
    if(singlezMoniter){
        bool ok;
        int value=ui->moniter_zombiearmorblood2->text().toInt(&ok);
        WriteMemory<uint32_t>(value,{singlezMoniter->zombiepointer.addr+zombie_armor2_body});
    }
    zombiearmor2_enable=true;
}


void MainWindow::on_moniter_zombieslowtime_sliderPressed()
{
    if(!CheckBoardOn())return;
    zombieslowenable=false;
}


void MainWindow::on_moniter_zombieslowtime_sliderReleased()
{
    if(!CheckBoardOn())return;
    if(singlezMoniter){
        WriteMemory<uint32_t>(ui->moniter_zombieslowtime->value(),{singlezMoniter->zombiepointer.addr+zombie_slow_down_time});
    }
    zombieslowenable=true;
}


void MainWindow::on_moniter_zombiebuttertime_sliderPressed()
{
    if(!CheckBoardOn())return;
    zombiebutterenable=false;
}


void MainWindow::on_moniter_zombiebuttertime_sliderReleased()
{
    if(!CheckBoardOn())return;
    if(singlezMoniter){
        WriteMemory<uint32_t>(ui->moniter_zombiebuttertime->value(),{singlezMoniter->zombiepointer.addr+zombie_butter_time});
    }
    zombiebutterenable=true;
}


void MainWindow::on_moniter_zombiefrozetime_sliderPressed()
{
    if(!CheckBoardOn())return;
    zombiefreezeenable=false;
}


void MainWindow::on_moniter_zombiefrozetime_sliderReleased()
{
    if(!CheckBoardOn())return;
    if(singlezMoniter){
        WriteMemory<uint32_t>(ui->moniter_zombiefrozetime->value(),{singlezMoniter->zombiepointer.addr+zombie_freeze_time});
    }
    zombiefreezeenable=true;
}


void MainWindow::on_moniter_zombiebodyshinetime_sliderPressed()
{
    if(!CheckBoardOn())return;
    zombiebodyshinenable=false;
}


void MainWindow::on_moniter_zombiebodyshinetime_sliderReleased()
{
    if(!CheckBoardOn())return;
    if(singlezMoniter){
        WriteMemory<uint32_t>(ui->moniter_zombiebodyshinetime->value(),{singlezMoniter->zombiepointer.addr+zombie_shining_time});
    }
    zombiebodyshinenable=true;
}


void MainWindow::on_moniter_zombiearmorshinetime_sliderPressed()
{
    if(!CheckBoardOn())return;
    zombiearmorshineenable=false;
}


void MainWindow::on_moniter_zombiearmorshinetime_sliderReleased()
{
    if(!CheckBoardOn())return;
    if(singlezMoniter){
        WriteMemory<uint32_t>(ui->moniter_zombiearmorshinetime->value(),{singlezMoniter->zombiepointer.addr+zombie_armor_shining_time});
    }
    zombiearmorshineenable=true;
}


void MainWindow::on_moniter_zombiearmorshaketime_sliderPressed()
{
    if(!CheckBoardOn())return;
    zombiearmorshakeenable=false;
}


void MainWindow::on_moniter_zombiearmorshaketime_sliderReleased()
{
    if(!CheckBoardOn())return;
    if(singlezMoniter){
        WriteMemory<uint32_t>(ui->moniter_zombiearmorshaketime->value(),{singlezMoniter->zombiepointer.addr+zombie_armor_shaking_time});
    }
    zombiearmorshakeenable=true;
}


void MainWindow::on_ishypnoed_clicked()
{
    if(!CheckBoardOn())return;
    zombiehypnoenable=false;
    if(singlezMoniter){
        WriteMemory<bool>(ui->ishypnoed->isChecked(),{singlezMoniter->zombiepointer.addr+zombie_ishypno});
    }
    zombiehypnoenable=true;
}


void MainWindow::on_isvisible_clicked()
{
    if(!CheckBoardOn())return;
    zombievisibleenable=false;
    if(singlezMoniter){
        WriteMemory<bool>(!ui->isvisible->isChecked(),{singlezMoniter->zombiepointer.addr+zombie_visible});
    }
    zombievisibleenable=true;
}


void MainWindow::on_zombie_blowaway_clicked()
{
    if(!CheckBoardOn())return;
    if(singlezMoniter){
        WriteMemory<bool>(true,{singlezMoniter->zombiepointer.addr+zombie_blow_away});
    }
    ui->zombie_blowaway->setCheckState(Qt::Unchecked);
}


void MainWindow::on_zombie_near_dead_clicked()
{
    if(!CheckBoardOn())return;
    zombieneardeadenable=false;
    if(singlezMoniter){
        WriteMemory<bool>(!ui->zombie_near_dead->isChecked(),{singlezMoniter->zombiepointer.addr+zombie_neardead});
    }
    zombieneardeadenable=true;
}


void MainWindow::on_zombie_inwater_clicked()
{
    if(!CheckBoardOn())return;
    zombieinwaterenable=false;
    if(singlezMoniter){
        WriteMemory<bool>(ui->zombie_inwater->isChecked(),{singlezMoniter->zombiepointer.addr+zombie_in_water});
    }
    zombieinwaterenable=true;
}


void MainWindow::on_zombie_eatgarlic_clicked()
{
    if(!CheckBoardOn())return;
    zombieeatgarlicenable=false;
    if(singlezMoniter){
        WriteMemory<bool>(ui->zombie_eatgarlic->isChecked(),{singlezMoniter->zombiepointer.addr+zombie_eat_garlic});
    }
    zombieeatgarlicenable=true;
}


void MainWindow::on_zombieoutfile_clicked()
{
    QString currentPath = QDir::currentPath();
    QString logDir =currentPath + QDir::separator() + "ZombieStatistics";
    QDir().mkpath(logDir);
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentTime = currentDateTime.toString("yyyy-MM-dd-hh-mm-ss");
    QString filePath = logDir+ QDir::separator()+currentTime+".txt";
    QFile newfile;
    newfile.setFileName(filePath);
    if (!newfile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return ;
    }
    QTextStream newout;
    newout.setDevice(&zombiefile);
    newout<<ui->row0->toPlainText();
    newout<<ui->row1->toPlainText();
    newout<<ui->row2->toPlainText();
    newout<<ui->row3->toPlainText();
    newout<<ui->row4->toPlainText();
    newout<<ui->row5->toPlainText();
    newfile.close();
    QMessageBox::information(this,"提示",QString("文件已输出到%1").arg(filePath));
}


void MainWindow::on_main_exitButton_clicked()
{
    if(autospicy){
        autospicy->stop();
        autospicy->wait();
        delete autospicy;
    }
    if(zombieput){
        zombieput->stop();
        zombieput->wait();
        delete zombieput;
    }
    if(bMoniter){
        bMoniter->thread_survive=false;
        bMoniter->quit();
        bMoniter->wait();
        delete bMoniter;
    }
    if(bSearch){
        bSearch->thread_survive=false;
        bSearch->quit();
        bSearch->wait();
        delete bSearch;
    }
    if(pMoniter){
        pMoniter->thread_survive=false;
        pMoniter->quit();
        pMoniter->wait();
        delete pMoniter;
    }
    if(zMoniter){
        if(zMoniter->zstamoniter){
            zMoniter->zstamoniter->thread_survive=false;
            zMoniter->zstamoniter->quit();
            zMoniter->zstamoniter->wait();
            delete zMoniter;
        }
        zMoniter->thread_survive=false;
        zMoniter->quit();
        zMoniter->wait();
        delete zMoniter;
    }
    if(singlezMoniter){
        singlezMoniter->thread_survive=false;
        singlezMoniter->quit();
        singlezMoniter->wait();
        delete singlezMoniter;
    }
    if(slot_plant_moniter){
        if(slot_plant_moniter->setthread){
            slot_plant_moniter->setthread->thread_survive=false;
            slot_plant_moniter->setthread->quit();
            slot_plant_moniter->setthread->wait();
            delete slot_plant_moniter->setthread;
        }
        slot_plant_moniter->thread_survive=false;
        slot_plant_moniter->quit();
        slot_plant_moniter->wait();
        delete slot_plant_moniter;
    }
    this->close();
}


void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    if (!CheckGameOn()){
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->checkBox_2->isChecked()){
         OverlapPlant(true);
    }
    else OverlapPlant(false);
}


void MainWindow::on_nomowernozombie_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        if(zombieput){
            zombieput->nomowernozombie=true;
        }
    }
    else if(arg1==Qt::Unchecked){
        if(zombieput){
            zombieput->nomowernozombie=false;
        }
    }
}

void MainWindow::InitBaseValue()
{
    for(int i=0;i<Bullet_Value.size();i++){
        ui->bulletvalue->addItem(Bullet_Value[i].name);
        Bullet_Value[i].value=ReadMemory<uint32_t>({Bullet_Value[i].addr});
    }
    for(int i=0;i<Disposable_Value.size();i++){
        ui->disposablevalue->addItem(Disposable_Value[i].name);
        if(i==3)Disposable_Value[i].value=ReadMemory<uint8_t>({Disposable_Value[i].addr});
        else Disposable_Value[i].value=ReadMemory<uint32_t>({Disposable_Value[i].addr});
    }
    for(int i=0;i<Goods_Value.size();i++){
        ui->goodsvalue->addItem(Goods_Value[i].name);
        if(i==0||i==2)Goods_Value[i].value=ReadMemory<uint32_t>({Goods_Value[i].addr});
        else if(i==1) Goods_Value[i].value=ReadMemory<uint8_t>({Goods_Value[i].addr});
        else if(i==3) Goods_Value[i].value=ReadMemory<uint32_t>({Goods_Value[i].addr})*10;
        else if(i==4||i==5) Goods_Value[i].value=ReadMemory<uint8_t>({Goods_Value[i].addr})*10;
    }
    Plant_Cost.clear();
    ui->plantlistbase->clear();
    Plant_Cost.resize(current_plant_book.size());
    for(int i=0;i<current_plant_book.size();i++){
        Plant_Cost[i].name=current_plant_book[i];
        Plant_Cost[i].addr=0x69f2c0+0x24*i;
        Plant_Cost[i].default_value=ReadMemory<uint32_t>({Plant_Cost[i].addr});
        Plant_Cost[i].value=Plant_Cost[i].default_value;
        ui->plantlistbase->addItem(QString("[%1]%2").arg(i).arg(current_plant_book[i]));
    }
    Plant_Cooltime.clear();
    ui->plantlistbase_2->clear();
    Plant_Cooltime.resize(current_plant_book.size());
    for(int i=0;i<current_plant_book.size();i++){
        Plant_Cooltime[i].name=current_plant_book[i];
        Plant_Cooltime[i].addr=0x69f2c4+0x24*i;
        Plant_Cooltime[i].default_value=ReadMemory<uint32_t>({Plant_Cooltime[i].addr});
        Plant_Cooltime[i].value=Plant_Cooltime[i].default_value;
        ui->plantlistbase_2->addItem(QString("[%1]%2").arg(i).arg(current_plant_book[i]));
    }
}
void MainWindow::on_bulletchange_clicked()
{
    if (!CheckGameOn()){
        ui->basevalueinfo->setText("未检测到游戏");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    int index=ui->bulletvalue->currentIndex();
    ChangeBaseValue(Bullet_Value[index].addr,ui->getbulletvalue->value(),false);
    ui->basevalueinfo->setText("修改完成");
}


void MainWindow::on_bulletdefault_clicked()
{
    if (!CheckGameOn()){
        ui->basevalueinfo->setText("未检测到游戏");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    int index=ui->bulletvalue->currentIndex();
    ChangeBaseValue(Bullet_Value[index].addr,Bullet_Value[index].default_value,false);
    ui->getbulletvalue->setValue(Bullet_Value[ui->bulletvalue->currentIndex()].default_value);
    ui->basevalueinfo->setText("修改完成");
}


void MainWindow::on_bulletvalue_currentIndexChanged(int index)
{
    if (!CheckGameOn()){
        ui->basevalueinfo->setText("未检测到游戏");
        ui->getbulletvalue->setValue(0);
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    Bullet_Value[index].value=ReadMemory<uint32_t>({Bullet_Value[index].addr});
    ui->getbulletvalue->setValue(Bullet_Value[index].value);
}


void MainWindow::on_disposablevalue_currentIndexChanged(int index)
{
    if (!CheckGameOn()){
        ui->basevalueinfo->setText("未检测到游戏");
        ui->getdisposablevalue->setValue(0);
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    if(index==3){
        Disposable_Value[index].value=ReadMemory<uint8_t>({Disposable_Value[index].addr});
        ui->getdisposablevalue->setValue(Disposable_Value[index].value);
        ui->getdisposablevalue->setMaximum(255);
        return;
    }
    ui->getdisposablevalue->setMaximum(999999999);
    Disposable_Value[index].value=ReadMemory<uint32_t>({Disposable_Value[index].addr});
    ui->getdisposablevalue->setValue(Disposable_Value[index].value);
}


void MainWindow::on_diposablechange_clicked()
{
    if (!CheckGameOn()){
        ui->basevalueinfo->setText("未检测到游戏");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    int index=ui->disposablevalue->currentIndex();
    if(index==3){
        ChangeBaseValue(Disposable_Value[index].addr,ui->getdisposablevalue->value(),true);
    }
    ChangeBaseValue(Disposable_Value[index].addr,ui->getdisposablevalue->value(),false);
    ui->basevalueinfo->setText("修改完成");
}


void MainWindow::on_disposabledefault_clicked()
{
    if (!CheckGameOn()){
        ui->basevalueinfo->setText("未检测到游戏");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    int index=ui->disposablevalue->currentIndex();
    if(index==3){
        ChangeBaseValue(Disposable_Value[index].addr,Disposable_Value[index].default_value,true);
    }
    ChangeBaseValue(Disposable_Value[index].addr,Disposable_Value[index].default_value,false);
    ui->getdisposablevalue->setValue(Disposable_Value[ui->disposablevalue->currentIndex()].default_value);
    ui->basevalueinfo->setText("修改完成");
}


void MainWindow::on_goodsvalue_currentIndexChanged(int index)
{
    if (!CheckGameOn()){
        ui->basevalueinfo->setText("未检测到游戏");
        ui->getgoodsvalue->setValue(0);
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    if(index==3){
        ui->getgoodsvalue->setMaximum(999999999);
        Goods_Value[index].value=ReadMemory<uint32_t>({Goods_Value[index].addr})*10;
        ui->getgoodsvalue->setValue(Disposable_Value[index].value);
        return;
    }
    if(index==0||index==2){
        ui->getgoodsvalue->setMaximum(999999999);
        Goods_Value[index].value=ReadMemory<uint32_t>({Goods_Value[index].addr});
        ui->getgoodsvalue->setValue(Disposable_Value[index].value);
        return;
    }
    if(index==4||index==5){
        Goods_Value[index].value=ReadMemory<uint8_t>({Goods_Value[index].addr})*10;
        ui->getgoodsvalue->setValue(Disposable_Value[index].value);
        ui->getgoodsvalue->setMaximum(2550);
        return;
    }
    if(index==1){
        Goods_Value[index].value=ReadMemory<uint8_t>({Goods_Value[index].addr});
        ui->getgoodsvalue->setValue(Goods_Value[index].value);
        ui->getgoodsvalue->setMaximum(255);
        return;
    }
}


void MainWindow::on_goodschange_clicked()
{
    if (!CheckGameOn()){
        ui->basevalueinfo->setText("未检测到游戏");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    int index=ui->goodsvalue->currentIndex();
    if(index==3){
        ChangeBaseValue(Goods_Value[index].addr,ui->getgoodsvalue->value()/10,false);
        return;
    }
    if(index==0||index==2){
        ChangeBaseValue(Goods_Value[index].addr,ui->getgoodsvalue->value(),false);
        return;
    }
    if(index==4||index==5){
        ChangeBaseValue(Goods_Value[index].addr,ui->getgoodsvalue->value()/10,true);
        return;
    }
    if(index==1){
        ChangeBaseValue(Goods_Value[index].addr,ui->getgoodsvalue->value(),true);
        return;
    }
    ui->basevalueinfo->setText("修改完成");
}


void MainWindow::on_goodsdefault_clicked()
{
    if (!CheckGameOn()){
        ui->basevalueinfo->setText("未检测到游戏");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    int index=ui->goodsvalue->currentIndex();
    if(index==3){
        ChangeBaseValue(Goods_Value[index].addr,Goods_Value[index].default_value/10,false);
        return;
    }
    if(index==0||index==2){
        ChangeBaseValue(Goods_Value[index].addr,Goods_Value[index].default_value,false);
        return;
    }
    if(index==4||index==5){
        ChangeBaseValue(Goods_Value[index].addr,Goods_Value[index].default_value/10,true);
        return;
    }
    if(index==1){
        ChangeBaseValue(Goods_Value[index].addr,Goods_Value[index].default_value,true);
        return;
    }
    ui->getgoodsvalue->setValue(Goods_Value[ui->goodsvalue->currentIndex()].default_value);
    ui->basevalueinfo->setText("修改完成");
}


void MainWindow::on_plantlistbase_currentIndexChanged(int index)
{
    if (!CheckGameOn()){
        ui->basevalueinfo->setText("未检测到游戏");
        ui->getcostvalue->setValue(0);
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    Plant_Cost[index].value=ReadMemory<uint32_t>({Plant_Cost[index].addr});
    ui->getcostvalue->setValue(Plant_Cost[index].value);
}


void MainWindow::on_plantlistbase_2_currentIndexChanged(int index)
{
    if (!CheckGameOn()){
        ui->basevalueinfo->setText("未检测到游戏");
        ui->getcoolvalue->setValue(0);
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    Plant_Cooltime[index].value=ReadMemory<uint32_t>({Plant_Cooltime[index].addr});
    ui->getcoolvalue->setValue(Plant_Cooltime[index].value);
}


void MainWindow::on_costchange_clicked()
{
    if (!CheckGameOn()){
        ui->basevalueinfo->setText("未检测到游戏");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    int index=ui->plantlistbase->currentIndex();
    ChangeBaseValue(Plant_Cost[index].addr,ui->getcostvalue->value(),false);
    ui->basevalueinfo->setText("修改完成");
}


void MainWindow::on_coolchange_clicked()
{
    if (!CheckGameOn()){
        ui->basevalueinfo->setText("未检测到游戏");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    int index=ui->plantlistbase_2->currentIndex();
    ChangeBaseValue(Plant_Cooltime[index].addr,ui->getcoolvalue->value(),false);
    ui->basevalueinfo->setText("修改完成");
}


void MainWindow::on_costdefault_clicked()
{
    if (!CheckGameOn()){
        ui->basevalueinfo->setText("未检测到游戏");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    int index=ui->plantlistbase->currentIndex();
    ChangeBaseValue(Plant_Cost[index].addr,Plant_Cost[index].default_value,false);
    ui->getcostvalue->setValue(Plant_Cost[ui->plantlistbase->currentIndex()].default_value);
    ui->basevalueinfo->setText("修改完成");
}


void MainWindow::on_cooldefault_clicked()
{
    if (!CheckGameOn()){
        ui->basevalueinfo->setText("未检测到游戏");
        if(out.device()){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    int index=ui->plantlistbase_2->currentIndex();
    ChangeBaseValue(Plant_Cooltime[index].addr,Plant_Cooltime[index].default_value,false);
    ui->getcoolvalue->setValue(Plant_Cooltime[ui->plantlistbase_2->currentIndex()].default_value);
    ui->basevalueinfo->setText("修改完成");
}


void MainWindow::on_pushButton_13_clicked()
{
    for(int i=0;i<Bullet_Value.size();i++){
        ChangeBaseValue(Bullet_Value[i].addr,Bullet_Value[i].default_value,false);
    }
    ui->getbulletvalue->setValue(Bullet_Value[ui->bulletvalue->currentIndex()].default_value);
    for(int i=0;i<Disposable_Value.size();i++){
        if(i==3)ChangeBaseValue(Disposable_Value[i].addr,Disposable_Value[i].default_value,true);
        ChangeBaseValue(Disposable_Value[i].addr,Disposable_Value[i].default_value,false);
    }
    ui->getdisposablevalue->setValue(Disposable_Value[ui->disposablevalue->currentIndex()].default_value);
    for(int i=0;i<Goods_Value.size();i++){
        ChangeBaseValue(Goods_Value[i].addr,Goods_Value[i].default_value,false);
        if(i==0||i==2)ChangeBaseValue(Goods_Value[i].addr,Goods_Value[i].default_value,false);
        else if(i==1) ChangeBaseValue(Goods_Value[i].addr,Goods_Value[i].default_value,true);
        else if(i==3) ChangeBaseValue(Goods_Value[i].addr,Goods_Value[i].default_value/10,false);
        else if(i==4||i==5) ChangeBaseValue(Goods_Value[i].addr,Goods_Value[i].default_value/10,true);
    }
    ui->getgoodsvalue->setValue(Goods_Value[ui->goodsvalue->currentIndex()].default_value);
    for(int i=0;i<current_plant_book.size();i++){
        ChangeBaseValue(Plant_Cost[i].addr,Plant_Cost[i].default_value,false);
    }
    ui->getcostvalue->setValue(Plant_Cost[ui->plantlistbase->currentIndex()].default_value);
    for(int i=0;i<current_plant_book.size();i++){
        ChangeBaseValue(Plant_Cooltime[i].addr,Plant_Cooltime[i].default_value,false);
    }
    ui->getcoolvalue->setValue(Plant_Cooltime[ui->plantlistbase_2->currentIndex()].default_value);
}




void MainWindow::on_unlockmemorymaxmiun_stateChanged(int arg1)
{
    if(!CheckGameOn()){
        ui->unlockmemorymaxmiun->setCheckState(Qt::Unchecked);
        return;
    }
    if(arg1==Qt::Checked){
       UnlockMaxMemory();
    }
    else if(arg1==Qt::Unchecked){
        ResumeMaxMemory();
    }
}


void MainWindow::on_unlockshopitems_stateChanged(int arg1)
{
    if (!CheckGameOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->unlockshopitems->isChecked()){
        UnlockShopItems(true);
    }
    else UnlockShopItems(false);
}

void MainWindow::InitCustomPlant(){
    for(int i=0;i<current_plant_book.size();i++)
        ui->customtypeselectplant->addItem(QString("[%1]%2").arg(i).arg(current_plant_book[i]));
    //plant_effect_inlist.resize(current_plant_book.size());

    ui->planteffectlist->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->planteffectlist->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->planteffectlist->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->planteffectlist->resizeRowsToContents();
    ui->planteffectlist->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->planteffectlist->setRowCount(0);
    ui->planteffectlist->setColumnCount(2);
    QHeaderView* view = new QHeaderView(Qt::Horizontal);
    QStandardItemModel* model = new QStandardItemModel;
    QStringList labels;
    labels << QStringLiteral("选择") << QStringLiteral("效果");
    model->setHorizontalHeaderLabels(labels);
    view->setModel(model);
    ui->planteffectlist->setHorizontalHeader(view);
    //ui->planteffectlist->verticalHeader()->setDefaultSectionSize(25);
    ui->planteffectlist->setColumnWidth(0,71);
    ui->planteffectlist->setColumnWidth(1,400);
   // ui->selectvalueplant->setVisible(false);
    ui->customtbulletselect_multiselect->setEnabled(false);
    ui->customtbulletselect_multiselect->SetSearchBarHidden(true);
    connect(ui->effectselectplant,QOverload<int>::of(&QComboBox::currentIndexChanged),this,[=](int index){
       if(index==0){
           ui->customtbulletselect->setEnabled(true);
           ui->customtbulletselect_multiselect->setEnabled(false);
           ui->customtypeselectplant->setEnabled(true);
       }
       else if(index ==1){
           ui->customtbulletselect->setEnabled(false);
           ui->customtbulletselect_multiselect->setEnabled(true);
           ui->customtypeselectplant->setEnabled(true);
       }
       else if(index==2){
           ui->customtbulletselect->setEnabled(true);
           ui->customtbulletselect_multiselect->setEnabled(false);
           ui->customtypeselectplant->setEnabled(false);
       }
    });
}
void MainWindow::on_addeffectplant_clicked()
{
    vector<bool> plant_current_enable(52,false);
    vector<int> enablelist={0,5,7,8,13,18,24,26,28,32,34,39,40,43,44,47};
    for(int i=0;i<enablelist.size();i++){
        plant_current_enable[enablelist[i]]=true;
    }
    int select_plant=ui->customtypeselectplant->currentIndex();
    if(!plant_current_enable[select_plant]){
        ui->customplantinfo->setText("当前植物暂不支持");
        return;
    }
    bool flag=false;
    int iter;
    for(int i=0;i<plant_effect_inlist.size();i++){
        if(plant_effect_inlist[i].modifytype==2){
            if(plant_effect_inlist[i].value_first[0]==ui->customtbulletselect->currentIndex()){
            flag=true;
            iter=i;
            break;
            }
            continue;
        }
        if(plant_effect_inlist[i].planttype==select_plant&&ui->effectselectplant->currentIndex()!=2){
            flag=true;
            iter=i;
            break;
        }

    }
    if(flag){
        if(plant_effect_inlist[iter].modifytype==0||plant_effect_inlist[iter].modifytype==1){
            plant_effect_inlist[iter].modifytype=ui->effectselectplant->currentIndex();
        }
        if(ui->effectselectplant->currentIndex()==0){
            ui->planteffectlist->setItem(iter, 1, new QTableWidgetItem(QString("%1更改子弹类型为%2").arg(ui->customtypeselectplant->currentText()).arg(ui->customtbulletselect->currentText())));
            plant_effect_inlist[iter].value_first.clear();
            plant_effect_inlist[iter].value_first.push_back(ui->customtbulletselect->currentIndex());
        }

        else if(ui->effectselectplant->currentIndex()==1){
            QStringList list=ui->customtbulletselect_multiselect->currentText();
            vector<int> selections=QStringListToVector(list);
            if(selections.back()==14) selections.pop_back();
            plant_effect_inlist[iter].value_first.resize(selections.size());
            plant_effect_inlist[iter].value_first=selections;
            GetValue* getvaluewin=new GetValue(selections.size());
            getvaluewin->setWindowTitle("概率设置");
            getvaluewin->show();
            connect(getvaluewin,&GetValue::updatevalue,this,[=](vector<int>values){
                plant_effect_inlist[iter].value_second.resize(values.size());
                plant_effect_inlist[iter].value_second=values;
                QString text=ui->customtypeselectplant->currentText()+"概率发射子弹\n";
                for(int i=0;i<values.size();i++){
                    text+=QString("%1发射概率%2%\n").arg(ui->customtbulletselect->itemText(selections[i])).arg(values[i]);
                }
                ui->planteffectlist->setItem(iter, 1, new QTableWidgetItem(text));
                ui->planteffectlist->resizeRowsToContents();
            });
        }
        else if(ui->effectselectplant->currentIndex()==2){
            bool ok;
            int number = QInputDialog::getInt(nullptr, "输入数字", "请输入魅惑概率（1-100%）:", 50, 1, 100, 1, &ok);
            if(!ok){
                return;
            }
            plant_effect_inlist[iter].value_second.clear();
            plant_effect_inlist[iter].value_second.push_back(number);
            ui->planteffectlist->setItem(iter, 1, new QTableWidgetItem(QString("%1概率魅惑:%2%").arg(ui->customtbulletselect->itemText(plant_effect_inlist[iter].value_first[0])).arg(number)));
        }
        return;
    }
    else{
        int row=ui->planteffectlist->rowCount();
        ui->planteffectlist->insertRow(ui->planteffectlist->rowCount());
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled); // 启用复选框
        item->setCheckState(Qt::Unchecked); // 设置初始状态为未选中
        PlantEffectStruct neweffect;
        neweffect.planttype=select_plant;
        ui->planteffectlist->setItem(row, 0, item);
        if(ui->effectselectplant->currentIndex()==0){
            neweffect.modifytype=0;
            ui->planteffectlist->setItem(row, 1, new QTableWidgetItem(QString("%1更改子弹类型为%2").arg(ui->customtypeselectplant->currentText()).arg(ui->customtbulletselect->currentText())));
            neweffect.value_first.push_back(ui->customtbulletselect->currentIndex());
            plant_effect_inlist.push_back(neweffect);
        }
        else if(ui->effectselectplant->currentIndex()==1){
            neweffect.modifytype=1;
            QStringList list=ui->customtbulletselect_multiselect->currentText();
            vector<int> selections=QStringListToVector(list);
            if(selections.back()==14) selections.pop_back();
            neweffect.value_first.resize(selections.size());
            neweffect.value_first=selections;
            plant_effect_inlist.push_back(neweffect);
            GetValue* getvaluewin=new GetValue(selections.size());
            getvaluewin->setWindowTitle("概率设置");
            getvaluewin->show();
            connect(getvaluewin,&GetValue::updatevalue,this,[=](vector<int>values){
                plant_effect_inlist[row].value_second.resize(values.size());
                plant_effect_inlist[row].value_second=values;
                QString text=ui->customtypeselectplant->currentText()+"概率发射子弹\n";
                for(int i=0;i<values.size();i++){
                    text+=QString("%1发射概率%2%\n").arg(ui->customtbulletselect->itemText(selections[i])).arg(values[i]);
                }
                ui->planteffectlist->setItem(row, 1, new QTableWidgetItem(text));
                ui->planteffectlist->resizeRowsToContents();
            });
        }
        else if(ui->effectselectplant->currentIndex()==2){
            neweffect.modifytype=2;
            bool ok;
            int number = QInputDialog::getInt(nullptr, "输入数字", "请输入魅惑概率（1-100%）:", 50, 1, 100, 1, &ok);
            if(!ok){
                return;
            }
            neweffect.value_first.push_back(ui->customtbulletselect->currentIndex());
            neweffect.value_second.push_back(number);
            ui->planteffectlist->setItem(row, 1, new QTableWidgetItem(QString("%1概率魅惑:%2%").arg(ui->customtbulletselect->currentText()).arg(number)));
            plant_effect_inlist.push_back(neweffect);
        }
        return;
    }
}


void MainWindow::on_deleteselectplanteffect_clicked()
{
    bool flag=false;
    for(int i=0;i<ui->planteffectlist->rowCount();i++){
        QTableWidgetItem *item =ui->planteffectlist->item(i,0);
        if(item->checkState()==Qt::Checked)
        {
            ui->planteffectlist->removeRow(i);
            plant_effect_inlist.erase(plant_effect_inlist.begin()+i);
            i--;
            flag=true;
        }
    }
    if(!flag){
        ui->customplantinfo->setText("未选中效果");
    }
}


void MainWindow::on_plantaffectongame_clicked()
{
    if(!CheckGameOn()){
        return;
    }
    CustomPlantAffectOnGame(plant_effect_inlist);
    ui->customplantinfo->setText("生效成功");
}


void MainWindow::on_cancelaffenctongame_clicked()
{
    if(!CheckGameOn()){
        return;
    }
    CustomPlantCancelAffectOnGame();
    ui->customplantinfo->setText("恢复成功");
}


void MainWindow::on_clearallbullet_stateChanged(int arg1)
{
    if (!CheckBoardOn())
    {
        ui->more->setText("未检测到游戏");
        if(out.device()){

            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            out<<QString("[%1] 未检测到游戏。\n").arg(currentTime);
            out.flush();
        }
        return;
    }
    ui->more->setText("");
    if(ui->clearallbullet->isChecked()){
        ClearAllBullet();
    }
    ui->clearallbullet->setCheckState(Qt::Unchecked);
}

void MainWindow::savedate()
{
    QString currentPath = QDir::currentPath();
    QString logDir =currentPath + QDir::separator() + "userdata";
    QDir().mkpath(logDir);
    QString filePath = logDir+ QDir::separator()+ui->username->text()+".pctb";
    QFile userfile;
    userfile.setFileName(filePath);
    if (!userfile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return ;
    }
    QTextStream outuser;
    outuser.setDevice(&userfile);
    outuser<<"This is a file head for pvz cricket tool box file.\n";
    if(!ui->isdefaultplantbook->isChecked()){
        outuser<<"Plant book start:\n";
        outuser<<current_plant_book.size();
        for(int i=0;i<current_plant_book.size();i++){
            outuser<<current_plant_book[i]<<" ";
        }
        outuser<<"\nPlant book end!\n";
    }
    if(global_forbid_plant){
    outuser<<"Global Plant Forbid:\n";
    for(int i=0;i<current_plant_book.size();i++){
        {
            if(global_forbid_plant[i]) outuser<<1<<" ";
            else outuser<<0<<" ";
        }
    }
    outuser<<"\nGlobal Plant Forbid End!\n";
    outuser.flush();
    }
    if(row_forbid_plant.size()!=0){
    outuser<<"Row Plant Forbid:\n";

    for(int i=0;i<6;i++){
        for(int j=0;j<current_plant_book.size();j++)
        if(row_forbid_plant[i][j]) outuser<<1<<" ";
        else outuser<<0<<" ";
    }
    outuser<<"\nRow Plant Forbid End!\n";
    outuser.flush();
    }

    if(col_forbid_plant.size()!=0){
        outuser<<"Col Plant Forbid:\n";
        for(int i=0;i<10;i++){
            for(int j=0;j<current_plant_book.size();j++)
            if(col_forbid_plant[i][j]) outuser<<1<<" ";
            else outuser<<0<<" ";
        }
        outuser<<"\nCol Plant Forbid End!\n";
        outuser.flush();
    }

    if(single_forbid_plant.size()!=0){
        outuser<<"Single Plant Forbid:\n";
        for(int i=0;i<current_plant_book.size();i++){
            if(!single_forbid_plant.empty()){
                outuser<<i<<" ";
                for(auto it=single_forbid_plant[i].begin();it!=single_forbid_plant[i].end();it++)
                    outuser<<*it<<" ";
            }
            outuser<<"\n";
        }
        outuser<<"\nSingle Plant Forbid End!\n";
        outuser.flush();
    }


    outuser<<"Form and Str Plain:\n";
    outuser<<ui->formtext->toPlainText();
    outuser<<"\nForm and Str Plain End!\n";
    outuser.flush();

    outuser<<"Plant Effect:\n";
    for(int i=0;i<plant_effect_inlist.size();i++){
        outuser<<plant_effect_inlist[i].planttype<<" ";
        outuser<<plant_effect_inlist[i].modifytype<<" ";
        outuser<<plant_effect_inlist[i].value_first.size()<<" ";
        for(int j=0;j<plant_effect_inlist[i].value_first.size();j++)
            outuser<<plant_effect_inlist[i].value_first[j]<<" ";
        outuser<<plant_effect_inlist[i].value_second.size()<<" ";
        for(int j=0;j<plant_effect_inlist[i].value_second.size();j++)
            outuser<<plant_effect_inlist[i].value_second[j]<<" ";
        outuser<<"\n";
    }
    outuser<<"\nPlant Effect End!\n";

    if(!ui->isdefaultplantbook_zombie->isChecked()){
        outuser<<"Zombie book start:\n";
        outuser<<current_zombie_book.size()<<" ";
        for(int i=0;i<current_zombie_book.size();i++){
            outuser<<current_zombie_book[i]<<" ";
        }
        outuser<<"\nZombie book end!\n";
    }
    outuser.flush();
    if(global_forbid_zombie.size()!=0){
        outuser<<"Global Zombie Forbid:\n";
        for(int i=0;i<current_zombie_book.size();i++){
            if(global_forbid_zombie[i]) outuser<<1<<" ";
            else outuser<<0<<" ";
        }
        outuser<<"\nGlobal Zombie Forbid End!\n";
        outuser.flush();
    }

    outuser<<"Zombie Put Time List:\n";
    outuser<<time_list.size()<<" ";
    for(int i=0;i<time_list.size();i++){
        outuser<<time_list[i]<<" "<<rate_list[i]<<" ";
    }
    outuser<<"\nZombie Put Time List End!\n";

    outuser.flush();
    ui->userinfo->setText("保存设置成功");
    userfile.close();
    xorFileData(filePath);
    return;
}

void MainWindow::on_savesettings_clicked()
{
    savedate();
}


void MainWindow::on_readsettings_clicked()
{

    QString currentPath = QDir::currentPath();
    QString logDir = currentPath + QDir::separator() + "userdata";
    QString filePath = logDir + QDir::separator() + ui->username->text() + ".pctb";
    xorFileData(filePath);
    QFile userfile(filePath);
    if (!userfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->userinfo->setText("打开文件失败，或不存在该用户");
        return;
    }

    QTextStream in(&userfile);

    QString line = in.readLine();
    if(!line.startsWith("This is a file head for pvz cricket tool box file."))
    {
        ui->infooutput->setText("用户数据解析失败");
        return;
    }
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.startsWith("Plant book start:")) {
            line = in.readLine();
            QStringList books=line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
            int size=books[0].toInt();
            temp_plant_book.reserve(size);
            for(int i=0;i<size;i++){
                temp_plant_book[i]=books[i+1];
            }
            ui->isdefaultplantbook->setCheckState(Qt::Unchecked);
            on_sureupdateplantbook_clicked();
        }
        else if (line.startsWith("Global Plant Forbid:")) {
            line = in.readLine();
            QList<int> intdata=extractIntegerNumbers(line);
            global_forbid_plant=new bool[current_plant_book.size()];
            memset(global_forbid_plant,false,sizeof(bool)*current_plant_book.size());
            for(int i=0;i<intdata.size();i++){
                if(intdata[i]==1)global_forbid_plant[i]=true;
            }
            is_global_forbid_exist=true;
        }
        else if (line.startsWith("Row Plant Forbid:")) {
            line = in.readLine();
            row_forbid_plant.resize(6);
            QList<int> intdata=extractIntegerNumbers(line);
            for(int i=0;i<6;i++){
                row_forbid_plant[i]=new bool[current_plant_book.size()];
                memset(row_forbid_plant[i],false,sizeof(bool)*current_plant_book.size());
                for(int j=0;j<current_plant_book.size();j++){
                    if(intdata[i*current_plant_book.size()+j]==1)row_forbid_plant[i][j]=true;
                }
            }
        }
        else if (line.startsWith("Col Plant Forbid:")) {
            line = in.readLine();
            col_forbid_plant.resize(10);
            QList<int> intdata=extractIntegerNumbers(line);
            for(int i=0;i<10;i++){
                col_forbid_plant[i]=new bool[current_plant_book.size()];
                memset(col_forbid_plant[i],false,sizeof(bool)*current_plant_book.size());
                for(int j=0;j<current_plant_book.size();j++){
                    if(intdata[i*current_plant_book.size()+j]==1)col_forbid_plant[i][j]=true;
                }
            }
        }
        else if (line.startsWith("Single Plant Forbid:")) {
            line = in.readLine();
            single_forbid_plant.resize(current_plant_book.size());
            while(!line.startsWith("Single Plant Forbid End")){
                QList<int> intdata=extractIntegerNumbers(line);
                if(intdata.size()==0){
                    line = in.readLine();
                    continue;
                }
                for(int i=1;i<intdata.size();i++){
                    single_forbid_plant[intdata[0]].insert(intdata[i]);
                }
                line = in.readLine();
            }
        }
        else if (line.startsWith("Form and Str Plain:")) {
            line = in.readLine();
            while(!line.startsWith("Form and Str Plain End")){
                ui->formtext->append(line);
                line = in.readLine();
            }
        }
        else if (line.startsWith("Plant Effect:")) {
            line = in.readLine();
            while(!line.startsWith("Plant Effect End")){
                PlantEffectStruct neweffect;
                QList<int> intdata=extractIntegerNumbers(line);
                if(intdata.size()==0){
                    line = in.readLine();
                    continue;
                }
                neweffect.planttype=intdata[0];
                neweffect.modifytype=intdata[1];
                int firstsize=intdata[2];
                neweffect.value_first.resize(firstsize);
                for(int i=0;i<firstsize;i++)
                    neweffect.value_first[i]=intdata[3+i];
                int secondsize=intdata[3+firstsize];
                neweffect.value_second.resize(secondsize);
                for(int i=0;i<secondsize;i++)
                    neweffect.value_second[i]=intdata[4+firstsize+i];
                plant_effect_inlist.push_back(neweffect);
                int row=ui->planteffectlist->rowCount();
                ui->planteffectlist->insertRow(ui->planteffectlist->rowCount());
                QTableWidgetItem *item = new QTableWidgetItem();
                item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled); // 启用复选框
                item->setCheckState(Qt::Unchecked); // 设置初始状态为未选中
                ui->planteffectlist->setItem(ui->planteffectlist->rowCount()-1, 0, item);
                if(neweffect.modifytype==0){
                    ui->planteffectlist->setItem(row, 1, new QTableWidgetItem(QString("%1更改子弹类型为%2").arg(ui->customtypeselectplant->itemText(neweffect.planttype)).arg(ui->customtbulletselect->itemText(neweffect.value_first[0]))));
                }
                else if(neweffect.modifytype==1){
                    QString text=ui->customtypeselectplant->itemText(neweffect.planttype)+"概率发射子弹\n";
                    for(int i=0;i<neweffect.value_first.size();i++){
                        text+=QString("%1发射概率%2%\n").arg(ui->customtbulletselect->itemText(neweffect.value_first[i])).arg(neweffect.value_second[i]);
                    }
                    ui->planteffectlist->setItem(row, 1, new QTableWidgetItem(text));
                    ui->planteffectlist->resizeRowsToContents();
                }
                else if(neweffect.modifytype==2){
                    ui->planteffectlist->setItem(row, 1, new QTableWidgetItem(QString("%1概率魅惑:%2%").arg(ui->customtbulletselect->itemText(neweffect.value_first[0])).arg(neweffect.value_second[0])));
                }
                line = in.readLine();
            }
        }
        else if (line.startsWith("Zombie book start:")) {
            line = in.readLine();
            QStringList books=line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
            int size=books[0].toInt();
            temp_zombie_book.reserve(size);
            for(int i=0;i<size;i++){
                temp_zombie_book[i]=books[i+1];
            }
            ui->isdefaultplantbook_zombie->setCheckState(Qt::Unchecked);
            on_sureupdatezombiebook_clicked();
        }
        else if (line.startsWith("Global Zombie Forbid:")) {
            line = in.readLine();
            global_forbid_zombie.resize(current_zombie_book.size());
            QList<int> intdata=extractIntegerNumbers(line);
            for(int i=0;i<intdata.size();i++){
                global_forbid_zombie[i]=intdata[i];
            }
        }
        else if (line.startsWith("Zombie Put Time List:")) {
            line = in.readLine();
            QList<double> doubledata=extractFloatingPointNumbers(line);
            time_list.resize((int)doubledata[0]);
            rate_list.resize((int)doubledata[0]);
            for(int i=1,j=0;i<doubledata.size();i++){
                time_list[j]=doubledata[i++];
                rate_list[j]=doubledata[i];
                int newRow =  ui->changetable->rowCount();
                is_tableadding=true;
                ui->changetable->insertRow(newRow);
                ui->changetable->setItem(newRow, 0, new QTableWidgetItem(QString::number(time_list[j], 'f', 2)));
                ui->changetable->setItem(newRow, 1, new QTableWidgetItem(QString::number(rate_list[j++], 'f', 2)));
                is_tableadding=false;
            }
        }
    }
    ui->userinfo->setText("读取用户设置成功！");
    userfile.close();
    xorFileData(filePath);
}

QList<int> MainWindow::extractIntegerNumbers(const QString &input) {
    QRegularExpression rx("\\b\\d+\\b"); // 匹配一个或多个数字的正则表达式
    QList<int> numbers;
    QRegularExpressionMatchIterator matchIterator = rx.globalMatch(input);

    while (matchIterator.hasNext()) {
        QRegularExpressionMatch match = matchIterator.next();
        bool ok;
        int number = match.captured(0).toInt(&ok); // 将匹配到的字符串转换为整数
        if (ok) {
            numbers << number; // 将整数添加到列表中
        }
    }

    return numbers;
}
QList<double> MainWindow::extractFloatingPointNumbers(const QString &input) {
    QRegularExpression rx("\\b\\d+(\\.\\d+)?\\b"); // 匹配一个或多个数字，可包含小数点的正则表达式
    QList<double> numbers;
    QRegularExpressionMatchIterator matchIterator = rx.globalMatch(input);

    while (matchIterator.hasNext()) {
        QRegularExpressionMatch match = matchIterator.next();
        bool ok;
        double number = match.captured(0).toDouble(&ok); // 将匹配到的字符串转换为浮点数
        if (ok) {
            numbers << number; // 将浮点数添加到列表中
        }
    }

    return numbers;
}

void MainWindow::xorFileData(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }

    QByteArray data = file.readAll();
    for (int i = 0; i < data.size(); ++i) {
        data[i] = data.at(i) ^ 0x0426;
    }

    file.seek(0);
    file.write(data);
    file.close();

}
