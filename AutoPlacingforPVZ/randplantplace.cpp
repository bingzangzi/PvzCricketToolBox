#include "randplantplace.h"
#include "ui_randplantplace.h"
extern bool RPflag;
extern int MaxRow;
extern int MaxCol;
extern bool Animatedflag;
QCheckBox*** checkboxes;
//extern bool plantIfAllow[48];

RandPlantPlace::RandPlantPlace(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RandPlantPlace)
{
    ui->setupUi(this);
    ui->sure_plant->setVisible(false); // 初始时隐藏
    ui->finished->setVisible(false); // 初始时隐藏
    ui->reset_select->setVisible(false); // 初始时隐藏
    ui->label_4->setVisible(false);
    InitForbidPlant();
}

RandPlantPlace::~RandPlantPlace()
{
    delete ui;
}

void RandPlantPlace::closeEvent(QCloseEvent *event)
{
    RPflag=false;
    QWidget::closeEvent(event);
}

void RandPlantPlace::on_rowcol_sure_clicked()
{
    if(ui->rowcol_sure->text()=="确 认"){
        MaxRow=ui->maxrow->value();
        MaxCol=ui->maxcol->value();
        checkboxes=new QCheckBox**[MaxRow];
        for(int i=0;i<MaxRow;i++)
        {
            checkboxes[i]=new QCheckBox*[MaxCol];
        }
        for(int i=0;i<MaxRow;i++)
        {
            for(int j=0;j<MaxCol;j++){
                QCheckBox *checkBox = new QCheckBox(QString::number(i+1)+"行"+QString::number(j+1)+"列", this);
                ui->select_noneed->addWidget(checkBox, i, j);
                checkboxes[i][j]=checkBox;
            }
        }
        ui->sure_plant->setVisible(true);
        ui->reset_select->setVisible(true);
        ui->rowcol_sure->setText("重 置");
        ui->label_4->setVisible(true);
        ui->finished->setVisible(false);
    }
    else{
        ui->rowcol_sure->setText("确 认");
        ui->maxcol->setValue(1);
        ui->maxrow->setValue(1);
        for (int i = 0; i < MaxRow; i++)
        {
            for(int j=0;j<MaxCol;j++)
            {
                delete checkboxes[i][j];
            }
        }
        free(checkboxes);
        ui->label_4->setVisible(false);
        ui->finished->setVisible(false);
        MaxRow=1;
        MaxCol=1;
    }
}

void RandPlantPlace::sure_plant()
{
    if(!SaveCheck()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("危险！");
        msgBox.setText("检测到游戏退出，请确认游戏正常运行!\n如果不想继续请点击否，若继续需要保证游戏运行！");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret = msgBox.exec();
        bool userChoice = (ret == QMessageBox::Yes);
        if(!userChoice){
            on_exit_button_clicked();
        }
        else return;
    }
    auto Plant_count_max = ReadMemory<uint32_t>({lawn, board, plant_count_max});
    if(Plant_count_max>maxallowplant){
        QMessageBox::information(this,"提示","当前已种植过的植物接近上限\n强烈建议重新开始关卡，否则将触发内存上限引发崩溃！");
        return;
    }
    //if(checkboxes) return;
    bool **noneedposition=new bool*[MaxRow];
    //memset(noneedposition, initValue, sizeof(bool*) * MaxRow);
    if(ui->change_mode->text()=="切换至选择种植模式"){
        for (int i = 0; i < MaxRow; i++) {
            noneedposition[i]=new bool[MaxCol];
            memset(noneedposition[i], false, sizeof(bool) * MaxCol);
        }

        for (int i = 0; i < MaxRow; i++)
        {

            for(int j=0;j<MaxCol;j++)
                if (checkboxes[i][j]->isChecked())
                {

                    noneedposition[i][j]=true;
                }
        }
    }
    else{
        for (int i = 0; i < MaxRow; i++) {
            noneedposition[i]=new bool[MaxCol];
            memset(noneedposition[i], true, sizeof(bool) * MaxCol);
        }

        for (int i = 0; i < MaxRow; i++)
        {

            for(int j=0;j<MaxCol;j++)
                if (checkboxes[i][j]->isChecked())
                {

                    noneedposition[i][j]=false;
                }
        }
    }
    if(ui->animatedplant->isChecked()) Animatedflag=true;
    else Animatedflag=false;
    vector<int> gift = { 16,30,33 };
    RandInit(forbid_plant_list,gift);

    if(RandForm(noneedposition)){
        ui->finished->setText("种植完成！");
        ui->finished->setVisible(true);
    }
    else
    {
        //ui->finished->setText("种植终止！");
        ui->finished->setVisible(false);
    }
    //if(threadpool.waitForThread(0))
}

void RandPlantPlace::on_sure_plant_clicked()
{
    if(!SaveCheck()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("危险！");
        msgBox.setText("检测到游戏退出，请确认游戏正常运行!\n如果不想继续请点击否，若继续需要保证游戏运行！");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret = msgBox.exec();
        bool userChoice = (ret == QMessageBox::Yes);
        if(!userChoice){
            on_exit_button_clicked();
        }
        else return;
    }
    if(ui->sure_plant->text()=="确 认 种 植")
    {
        sure_plant();
        //RandPlantPlace obj;
       // MyThread* newthread = new MyThread();
       // newthread->setMemberFunction(&RandPlantPlace::sure_plant,&obj);
        //newthread->start();
       // ui->sure_plant->setText("终 止 种 植");
        //if(newthread->wait()) ui->sure_plant->setText("确 认 种 植");

    }
    else
    {
       // threadpool.CallStop(0);
        ui->sure_plant->setText("确 认 种 植");
    }
}


void RandPlantPlace::on_reset_select_clicked()
{
    if(!checkboxes) return;
    for (int i = 0; i < MaxRow; i++)
    {
        for(int j=0;j<MaxCol;j++)
        {
            checkboxes[i][j]->setCheckState(Qt::Unchecked);
        }
    }
    ui->finished->setVisible(false);
}


void RandPlantPlace::on_change_mode_clicked()
{
    if(ui->change_mode->text()=="切换至选择种植模式"){
        ui->label_4->setText("请选择需要种植的位置（默认不种植）：");
        ui->change_mode->setText("切换至选择不种植模式");
        ui->currentmode->setText("当前为选择种植模式");
        ui->finished->setVisible(false);
    }
    else{
        ui->label_4->setText("请选择不需要种植的位置（默认全部种植）：");
        ui->change_mode->setText("切换至选择种植模式");
        ui->currentmode->setText("当前为选择不种植模式");
        ui->finished->setVisible(false);
    }
}



void RandPlantPlace::on_clearallplant_clicked()
{
    if(!SaveCheck()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("危险！");
        msgBox.setText("检测到游戏退出，请确认游戏正常运行!\n如果不想继续请点击否，若继续需要保证游戏运行！");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret = msgBox.exec();
        bool userChoice = (ret == QMessageBox::Yes);
        if(!userChoice){
            on_exit_button_clicked();
        }
        else return;
    }
    ClearAllPlants();
    ui->finished->setText("已清空植物！");
    ui->finished->setVisible(true);
}


void RandPlantPlace::on_exit_button_clicked()
{
    this->close();
}

void RandPlantPlace::InitForbidPlant()
{
    boxes.resize(48);
    for(int i=0;i<48;i++){
        QCheckBox *newbox=new QCheckBox;
        newbox->setText(QString("%1").arg(plant_book[i]));
        ui->forbidarea->addWidget(newbox,i/8,i%8);
        boxes[i]=newbox;
    }
    for(int i=0;i<this->forbid_plant_list.size();i++){
        boxes[forbid_plant_list[i]]->setCheckState(Qt::Checked);
    }
}

void RandPlantPlace::on_allselct_clicked()
{
    for(int i=0;i<boxes.size();i++){
        boxes[i]->setCheckState(Qt::Checked);
    }
    ui->label->setText("全选成功！");
}


void RandPlantPlace::on_resetbutton_clicked()
{
    for(int i=0;i<boxes.size();i++){
        boxes[i]->setCheckState(Qt::Unchecked);
    }
    ui->label->setText("已重置！");
}


void RandPlantPlace::on_forbidsure_clicked()
{
    this->forbid_plant_list.clear();
    for(int i=0;i<boxes.size();i++){
        if(boxes[i]->isChecked())forbid_plant_list.push_back(i);
    }
    ui->label->setText("已记录！");
}


bool RandPlantPlace::SaveCheck()
{
    this->is_game_on=CheckGameOn();//检查游戏是否运行
    if(!this->is_game_on) {
        return false;
    }
    this->is_board_on=CheckBoardOn();//检查关卡是否运行
    if(!this->is_board_on) {
        return false;
    }
    return true;
}
