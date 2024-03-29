#include "customplantplace.h"
#include "ui_customplantplace.h"
extern bool CPflag;
customplantplace::customplantplace(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::customplantplace)
{
    ui->setupUi(this);
    ui->lineEdit->setReadOnly(true);
    while(!SaveCheck())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("危险！");
        msgBox.setText("检测到游戏退出，请确认游戏正常运行!\n如果不想继续请点击否，若继续需要保证游戏运行！");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret = msgBox.exec();
        bool userChoice = (ret == QMessageBox::Yes);
        if(!userChoice){
            on_exitbutton_clicked();
        }
    }
    InitCustomPlantList();
    UpdatePlantList();
        ui->isrealtime->setVisible(false);
        ui->planttype->setChecked(true);
        ui->forminfo->setVisible(false);
        ui->plantplace->setVisible(false);
        ui->forminfo->setReadOnly(true);
        ui->infodisplayhere->setText("初始化完成");
        ShowGrid();
        connect(ui->planttype,&QRadioButton::toggled,this, [this](){
            ShowGrid();
        });
        connect(ui->blood,&QRadioButton::toggled,this, [this](){
            ShowGrid();
        });
        connect(ui->attackinterval,&QRadioButton::toggled,this, [this](){
            ShowGrid();
        });
        connect(ui->formtostr,&QRadioButton::toggled,this, [this](){
            ShowGrid();
        });
        connect(ui->strtoform,&QRadioButton::toggled,this, [this](){
            ShowGrid();
        });
        connect(ui->customplace,&QRadioButton::toggled,this, [this](){
            ShowGrid();
        });
        connect(ui->setshine,&QRadioButton::toggled,this, [this](){
            ShowGrid();
        });
        connect(ui->realmoniter,&QCheckBox::stateChanged,this,[this](){
            if(ui->realmoniter->isChecked()) StartMoniter();
            else if(!ui->realmoniter->isChecked()){
                if(pMoniter==nullptr)return;
                pMoniter->thread_survive=false;
                pMoniter->exit();
                pMoniter->wait();
                delete pMoniter;
                pMoniter=nullptr;
            }
        });
}

customplantplace::~customplantplace()
{
    delete ui;
}

void customplantplace::closeEvent(QCloseEvent *event)
{
    CPflag=false;

    QWidget::closeEvent(event);
}

void customplantplace::on_exitbutton_clicked()
{
    if(pMoniter==nullptr||!pMoniter) {
        this->close();
        return;
    }
    pMoniter->thread_survive=false;
    pMoniter->exit();
    pMoniter->wait();
    delete pMoniter;
    pMoniter=nullptr;
    this->close();
}

bool customplantplace::SaveCheck()
{
    this->is_game_on=CheckGameOn();//检查游戏是否运行
    if(!this->is_game_on) {
        ui->infodisplayhere->setText("当前游戏未运行");
        if(pMoniter!=nullptr)
        if(pMoniter->thread_survive==true){
            pMoniter->thread_survive=false;
            pMoniter->exit();
            pMoniter->wait();
            delete pMoniter;
            pMoniter=nullptr;
        }
        return false;
    }
    this->is_board_on=CheckBoardOn();//检查关卡是否运行
    if(!this->is_board_on) {
        ui->infodisplayhere->setText("当前不在关卡内");
        if(pMoniter!=nullptr)
        if(pMoniter->thread_survive==true){
            pMoniter->thread_survive=false;
            pMoniter->exit();
            pMoniter->wait();
            delete pMoniter;
            pMoniter=nullptr;
        }
        return false;
    }
    return true;
}

void customplantplace::showgrid_slot(bool checked)
{
    if(checked) ShowGrid();
}

void customplantplace::ShowGrid()
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
            on_exitbutton_clicked();
        }
    }

    if(ui->planttype->isChecked()){
        ui->textedit->setVisible(false);
        ui->includeblood->setVisible(false);
        ui->includeinterval->setVisible(false);
        ui->updateplant->setText("更新植物列表");
        for(auto& info :this-> plant_info_list)
        {
            info->combobox->setVisible(true);
            ui->deleteplant->setText("删除");
            info->text->setVisible(false);
            info->check->setVisible(true);
            info->combobox->setFixedWidth(80);
            //disconnect(info->combobox, QOverload<int>::of(&QComboBox::currentIndexChanged), nullptr, nullptr);
        }
        for(auto& info:this->custom_info_list)
        {
            info->bloodline->setVisible(false);
            disconnect(ui->includeblood,&QCheckBox::stateChanged,nullptr,nullptr);
            info->intervalline->setVisible(false);
            disconnect(ui->includeinterval,&QCheckBox::stateChanged,nullptr,nullptr);
            info->combobox->setVisible(false);
        }
        ui->plantplace->setText("这个按钮似乎没用");
        ui->forminfo->setVisible(false);
        ui->isrealtime->setVisible(false);
    }
    else if(ui->blood->isChecked()){
        ui->isrealtime->setVisible(true);
        ui->textedit->setVisible(false);
        ui->updateplant->setText("更新植物列表");
        ui->forminfo->setVisible(false);
        ui->deleteplant->setText("更新当前植物血量");
        ui->plantplace->setVisible(true);
        ui->plantplace->setText("确认修改血量");
        ui->includeblood->setVisible(false);
        ui->includeinterval->setVisible(false);
        for(auto& info : this->plant_info_list)
        {
            info->combobox->setVisible(true);
            info->text->setVisible(true);
            info->check->setVisible(false);
            info->combobox->setFixedWidth(60);
            QMetaObject::Connection con;
            if(info->planttype[0]!=-1)
            {
                info->text->setText(QString("%1").arg(info->plantmoniters[info->combobox->currentIndex()]->object_blood));
                con = connect(info->combobox,QOverload<int>::of(&QComboBox::currentIndexChanged), [&](int index){
            info->text->setText(QString("%1").arg(info->plantmoniters[info->combobox->currentIndex()]->object_blood));
            });
            info->text->setReadOnly(false);
            connect(info->text,&QLineEdit::returnPressed, this,[&](){
                QString text=info->text->text();
                bool ok;
                int value=text.toInt(&ok);
                if(ok){
                    WriteMemory<uint32_t>(value,{ info->plantmoniters[info->combobox->currentIndex()]->object_address+plant_blood});
                    on_plantplace_clicked();
                    ui->infodisplayhere->setText("修改完成");
                }
                else{
                    QMessageBox::information(this,"提示","请输入一个整数！");
                    info->text->setText(QString("%1").arg(info->plantmoniters[info->combobox->currentIndex()]->object_blood));
                }
            });
            }
        }
        for(auto& info:this->custom_info_list)
        {
            info->bloodline->setVisible(false);
            disconnect(ui->includeblood,&QCheckBox::stateChanged,nullptr,nullptr);
            info->intervalline->setVisible(false);
            disconnect(ui->includeinterval,&QCheckBox::stateChanged,nullptr,nullptr);
            info->combobox->setVisible(false);
        }
    }
    else if(ui->attackinterval->isChecked()){
        ui->deleteplant->setText("更新当前植物攻速");
        ui->updateplant->setText("更新植物列表");
        ui->plantplace->setVisible(true);
        ui->textedit->setVisible(false);
        ui->plantplace->setText("确认修改攻速");
        ui->isrealtime->setVisible(false);
        ui->forminfo->setVisible(false);
        ui->includeblood->setVisible(false);
        ui->includeinterval->setVisible(false);
        for(auto& info : this->plant_info_list)
        {
            info->text->setVisible(true);
            info->check->setVisible(false);
            info->combobox->setVisible(true);
            info->combobox->setFixedWidth(60);
            if(info->planttype[0]!=-1)
            {info->text->setText(QString("%1").arg(info->plantmoniters[info->combobox->currentIndex()]->object_attack_interval));
                disconnect(info->combobox, QOverload<int>::of(&QComboBox::currentIndexChanged), nullptr, nullptr);
                connect(info->combobox,QOverload<int>::of(&QComboBox::currentIndexChanged), [&](int index){
                    info->text->setText(QString("%1").arg(info->plantmoniters[info->combobox->currentIndex()]->object_attack_interval));
                });
                info->text->setReadOnly(false);
                connect(info->text,&QLineEdit::returnPressed, this,[&](){
                    QString text=info->text->text();
                    bool ok;
                    int value=text.toInt(&ok);
                    if(ok){
                        WriteMemory<uint32_t>(value,{ info->plantmoniters[info->combobox->currentIndex()]->object_address+plant_attack_interval});
                        on_plantplace_clicked();
                        ui->infodisplayhere->setText("修改完成");
                    }
                    else{
                        QMessageBox::information(this,"提示","请输入一个整数！");
                        info->text->setText(QString("%1").arg(info->plantmoniters[info->combobox->currentIndex()]->object_attack_interval));
                    }
                });
            }
        }
        for(auto& info:this->custom_info_list)
        {
            info->bloodline->setVisible(false);
            disconnect(ui->includeblood,&QCheckBox::stateChanged,nullptr,nullptr);
            info->intervalline->setVisible(false);
            disconnect(ui->includeinterval,&QCheckBox::stateChanged,nullptr,nullptr);
            info->combobox->setVisible(false);
        }
    }
    else if(ui->setshine->isChecked()){
        ui->deleteplant->setText("这个按钮似乎没用");
        ui->updateplant->setText("更新植物列表");
        ui->plantplace->setVisible(true);
        ui->includeblood->setVisible(false);
        ui->includeinterval->setVisible(false);
        ui->plantplace->setText("开始发光");
        ui->textedit->setVisible(false);
        ui->forminfo->setVisible(false);
        ui->isrealtime->setVisible(false);
        for(auto& info : this->plant_info_list)
        {
            info->text->setVisible(true);
            info->check->setVisible(false);
            info->combobox->setVisible(true);
            info->combobox->setFixedWidth(60);
            if(info->planttype[0]!=-1)
            {info->text->setText(QString("%1").arg(0));
                disconnect(info->combobox, QOverload<int>::of(&QComboBox::currentIndexChanged), nullptr, nullptr);
                connect(info->combobox,QOverload<int>::of(&QComboBox::currentIndexChanged), [&](int index){
                    info->text->setText(QString("%1").arg(0));
                });
                info->text->setReadOnly(false);
                connect(info->text,&QLineEdit::returnPressed, this,[&](){
                    QString text=info->text->text();
                    bool ok;
                    int value=text.toInt(&ok);
                    if(ok){
                        on_plantplace_clicked();
                    }
                    else{
                        QMessageBox::information(this,"提示","请输入一个整数！");
                        info->text->setText(QString("%1").arg(info->plantmoniters[info->combobox->currentIndex()]->object_attack_interval));
                    }
                });
            }
        }
        for(auto& info:this->custom_info_list)
        {
            info->bloodline->setVisible(false);
            disconnect(ui->includeblood,&QCheckBox::stateChanged,nullptr,nullptr);
            info->intervalline->setVisible(false);
            disconnect(ui->includeinterval,&QCheckBox::stateChanged,nullptr,nullptr);
            info->combobox->setVisible(false);
        }
    }

    else if(ui->strtoform->isChecked()){
        ui->includeblood->setVisible(true);
        ui->includeinterval->setVisible(true);
        ui->forminfo->setVisible(true);
        for(auto& info : this->plant_info_list)
        {
            info->text->setVisible(false);
            info->check->setVisible(false);
            info->combobox->setVisible(false);
        }
        for(auto& info:this->custom_info_list)
        {
            info->bloodline->setVisible(false);
            disconnect(ui->includeblood,&QCheckBox::stateChanged,nullptr,nullptr);
            info->intervalline->setVisible(false);
            disconnect(ui->includeinterval,&QCheckBox::stateChanged,nullptr,nullptr);
            info->combobox->setVisible(false);
        }
        ui->updateplant->setText("粘贴");
        ui->deleteplant->setText("复制");
        ui->plantplace->setVisible(true);
        ui->plantplace->setText("转化");
        ui->isrealtime->setVisible(false);
        ui->textedit->setVisible(true);
        ui->textedit->setReadOnly(false);

    }
    //阵型转字符串
    else if(ui->formtostr->isChecked()){
        for(auto& info : this->plant_info_list)
        {
            info->text->setVisible(false);
            info->check->setVisible(false);
            info->combobox->setVisible(false);
        }
        for(auto& info:this->custom_info_list)
        {
            info->bloodline->setVisible(false);
            disconnect(ui->includeblood,&QCheckBox::stateChanged,nullptr,nullptr);
            info->intervalline->setVisible(false);
            disconnect(ui->includeinterval,&QCheckBox::stateChanged,nullptr,nullptr);
            info->combobox->setVisible(false);
        }
        ui->deleteplant->setText("复制");
        ui->forminfo->setVisible(true);
        ui->updateplant->setText("粘贴");
        ui->plantplace->setVisible(true);
        ui->plantplace->setText("转化");
        ui->includeblood->setVisible(true);
        ui->includeinterval->setVisible(true);
        ui->isrealtime->setVisible(false);
        ui->textedit->setVisible(true);
        ui->textedit->setReadOnly(true);

    }
    //自定义种植
    else if(ui->customplace->isChecked()){
        for(auto& info : this->plant_info_list)
        {
            info->text->setVisible(false);
            info->check->setVisible(false);
            info->combobox->setVisible(false);
        }
        for(int i=0;i<now_map_row*10;i++)
        {
            if(ui->includeblood->isChecked())custom_info_list[i]->bloodline->setVisible(true);
            connect(ui->includeblood,&QCheckBox::stateChanged,this,[=](){
                if(ui->includeblood->isChecked())custom_info_list[i]->bloodline->setVisible(true);
                else custom_info_list[i]->bloodline->setVisible(false);
            });
            if(ui->includeinterval->isChecked())custom_info_list[i]->intervalline->setVisible(true);
            connect(ui->includeinterval,&QCheckBox::stateChanged,this,[=](){
                if(ui->includeinterval->isChecked())custom_info_list[i]->intervalline->setVisible(true);
                else custom_info_list[i]->intervalline->setVisible(false);
            });
            custom_info_list[i]->combobox->setVisible(true);
        }
        ui->includeblood->setVisible(true);
        ui->includeinterval->setVisible(true);
        ui->forminfo->setVisible(false);
        ui->deleteplant->setText("排山倒海");
        ui->forminfo->setVisible(true);
        ui->updateplant->setText("横扫千军");
        ui->plantplace->setVisible(true);
        ui->plantplace->setText("种植");
        ui->textedit->setVisible(false);
        ui->includeblood->setVisible(true);
        ui->includeinterval->setVisible(true);
        ui->isrealtime->setVisible(false);
        ui->forminfo->setVisible(false);
    }
}

void customplantplace::InitPlantList()
{
    int max_row=GetRowCount();
    this->now_map_row=max_row;
    this->plant_info_list.resize(6*10);
    for(int i=0;i<6*10;i++){
        InfoDisplay* newdisplay=new InfoDisplay;
        newdisplay->layout=new QHBoxLayout;
        newdisplay->check=new QCheckBox("");
        newdisplay->combobox=new QComboBox();
        newdisplay->combobox->setFixedWidth(80);
        newdisplay->text=new QLineEdit();
        newdisplay->text->setReadOnly(true);
        newdisplay->layout->addWidget(newdisplay->check);
        newdisplay->layout->addWidget(newdisplay->combobox);
        newdisplay->layout->addWidget(newdisplay->text);
        newdisplay->planttype.push_back(-1);
        newdisplay->row=i/10;
        newdisplay->col=i%10;
        this->plant_info_list[i]=newdisplay;
    }
    for(auto& info : this->plant_info_list)
        ui->gridLayout->addLayout(info->layout,info->row,info->col+10);
    ui->scrollAreaWidgetContents->setLayout(ui->gridLayout);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
    ui->scrollArea->setWidgetResizable(true);
}

void customplantplace::UpdatePlantList()
{
    //首先清空原有植物列表
    if(!this->plant_info_list.empty()){
    for (auto& info : this->plant_info_list) {
        info->plantmoniters.clear();
        info->planttype.clear();
        info->planttype.push_back(-1);
        info->combobox->clear();
        info->check->setChecked(false);
        info->text->setText("");
    }
    }
    int max_row=GetRowCount();
    if(max_row!=this->now_map_row) InitPlantList();
    //clearLayout(ui->gridLayout);
    //this->plant_info_list.clear();

    auto Plant_Current_Count=ReadMemory<uint32_t>({lawn,board,plant_curren_count});
    auto Plant_count_max = ReadMemory<uint32_t>({lawn, board, plant_count_max});
    auto Plant_Offset=ReadMemory<uint32_t>({lawn,board,plant_offset});
    uint32_t count=0;
    for(size_t i=0;i<Plant_count_max&&count<Plant_Current_Count;i++){
        auto isdead=ReadMemory<bool>({Plant_Offset+plant_dead+i*plant_single_size});
        int blood=ReadMemory<uint32_t>({Plant_Offset+plant_blood+i*plant_single_size});
        if(isdead||blood==0) continue;
        uint32_t row=ReadMemory<uint32_t>({Plant_Offset+plant_row+i*plant_single_size});
        uint32_t col=ReadMemory<uint32_t>({Plant_Offset+plant_col+i*plant_single_size});
        uint32_t type=ReadMemory<uint32_t>({Plant_Offset+plant_type+i*plant_single_size});
        uint32_t attack_interval=ReadMemory<uint32_t>({Plant_Offset+plant_attack_interval+i*plant_single_size});
        if(row*10+col>max_row*10) continue;
        if(this->plant_info_list[row*10+col]->planttype[0]!=-1)this->plant_info_list[row*10+col]->planttype.push_back(type);
        else this->plant_info_list[row*10+col]->planttype[0]=type;
       // plant_info_list[row*10+col]->row=row;
       // plant_info_list[row*10+col]->col=col;
        PlantBloodMoniter* newplant=new PlantBloodMoniter;
        newplant->object_type=type;
        newplant->object_col=col;
        newplant->object_row=row;
        newplant->object_attack_interval=attack_interval;
        newplant->object_address=Plant_Offset+i*plant_single_size;
        newplant->object_blood=blood;
        //newplant->start();
        this->plant_info_list[row*10+col]->plantmoniters.push_back(newplant);
        this->plant_info_list[row*10+col]->combobox->addItem(QString("%1").arg(plant_book[type]));

        count++;
    }
    this->next_plant_position=ReadMemory<uint32_t>({lawn,board,plant_next_plant_position});

}

void customplantplace::on_updateplant_clicked()
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
            on_exitbutton_clicked();
        }
        else return;
    }
    if(ui->customplace->isChecked()){
        for(int i=0;i<now_map_row;i++){
            for(int j=0;j<10;j++){
                if(custom_info_list[j+i*10]->combobox->currentIndex()==0) continue;
                else{
                    for(int k=0;k<10;k++){
                        custom_info_list[k+i*10]->combobox->setCurrentIndex(custom_info_list[j+i*10]->combobox->currentIndex());
                        custom_info_list[k+i*10]->bloodline->setText(custom_info_list[j+i*10]->bloodline->text());
                        custom_info_list[k+i*10]->intervalline->setText(custom_info_list[j+i*10]->intervalline->text());
                    }
                }
            }
        }
        return;
    }
    bool ismoniter=ui->realmoniter->isChecked();
    if(pMoniter){
        pMoniter->thread_survive=false;
        pMoniter->exit();
        pMoniter->wait();
        delete pMoniter;
        pMoniter=nullptr;
    }

    if(ui->strtoform->isChecked()||ui->formtostr->isChecked()){
        ui->textedit->paste();
        return;
    }
    UpdatePlantList();
    if(ismoniter)
    {
        ui->realmoniter->setCheckState(Qt::Checked);
        StartMoniter();
    }
    ShowGrid();
    ui->infodisplayhere->setText("已完成列表更新");
}

void customplantplace::clearLayout(QLayout *layout) {
    if(!SaveCheck()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("危险！");
        msgBox.setText("检测到游戏退出，请确认游戏正常运行!\n如果不想继续请点击否，若继续需要保证游戏运行！");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret = msgBox.exec();
        bool userChoice = (ret == QMessageBox::Yes);
        if(!userChoice){
            on_exitbutton_clicked();
        }
        else return;
    }
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->layout() != nullptr) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget() != nullptr) {
            delete item->widget();
        }
        delete item;
    }
}

void customplantplace::on_isrealtime_stateChanged(int arg1)
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
            on_exitbutton_clicked();
        }
        else return;
    }
    if(ui->isrealtime->isChecked()){
        if(!pMoniter){
            StartMoniter();
        }
        pMoniter->blood_moniter=true;
    }
    else{
        pMoniter->blood_moniter=false;

    }
}


void customplantplace::on_deleteplant_clicked()
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
            on_exitbutton_clicked();
        }
        else return;
    }
    if(ui->blood->isChecked()){
        for (auto& info : this->plant_info_list) {
            for (auto* moniter : info->plantmoniters) {
                moniter->object_blood=ReadMemory<uint32_t>({moniter->object_address+plant_blood});
            }
        }
        ShowGrid();
        return;
    }
    if(ui->planttype->isChecked()){
        for (auto& info : this->plant_info_list) {
            if(info->check->isChecked()){
                DeleteGivenAddrPlant(info->plantmoniters[info->combobox->currentIndex()]->object_address);
                //delete info->plantmoniters[info->combobox->currentIndex()];
                info->plantmoniters.erase(info->plantmoniters.begin()+info->combobox->currentIndex());
                info->planttype.erase(info->planttype.begin()+info->combobox->currentIndex());
                if(info->planttype.size()==0) info->planttype.push_back(-1);
                info->combobox->removeItem(info->combobox->currentIndex());
            }
        }
        ShowGrid();
        return;
    }
    if(ui->attackinterval->isChecked()){
        for (auto& info : this->plant_info_list) {
            for (auto* moniter : info->plantmoniters) {
                moniter->object_attack_interval=ReadMemory<uint32_t>({moniter->object_address+plant_attack_interval});
            }
        }
        ShowGrid();
        return;
    }
    if(ui->strtoform->isChecked()||ui->formtostr->isChecked()){
        ui->textedit->copy();
        return;
    }
    if(ui->customplace->isChecked()){
        for(int i=0;i<10;i++){
            for(int j=0;j<now_map_row;j++){
                if(custom_info_list[j*10+i]->combobox->currentIndex()==0) continue;
                else{
                    for(int k=0;k<now_map_row;k++){
                        custom_info_list[k*10+i]->combobox->setCurrentIndex(custom_info_list[j*10+i]->combobox->currentIndex());
                        custom_info_list[k*10+i]->bloodline->setText(custom_info_list[j*10+i]->bloodline->text());
                        custom_info_list[k*10+i]->intervalline->setText(custom_info_list[j*10+i]->intervalline->text());
                    }
                }
            }
        }
        return;
    }
}


void customplantplace::on_clear_clicked()
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
            on_exitbutton_clicked();
        }
        else return;
    }
    if(ui->strtoform->isChecked()||ui->formtostr->isChecked()){
        ui->textedit->clear();
        return;
    }
    if(ui->customplace->isChecked()){
        for(auto &info:custom_info_list){
            info->bloodline->setText("");
            info->intervalline->setText("");
            info->combobox->setCurrentIndex(0);
        }
    }
    if(pMoniter||pMoniter!=nullptr){
    pMoniter->thread_survive=false;
    pMoniter->exit();
    pMoniter->wait();
    delete pMoniter;
    pMoniter=nullptr;
    }
    if(!this->plant_info_list.empty()){
        for (auto& info : this->plant_info_list) {
            for(auto *moni:info->plantmoniters){
                delete moni;
            }
            info->plantmoniters.clear();
            info->planttype.clear();
            info->planttype.push_back(-1);
            disconnect(info->combobox, QOverload<int>::of(&QComboBox::currentIndexChanged), nullptr, nullptr);
            info->combobox->clear();
            info->check->setChecked(false);
            info->text->setText("");
        }
    }
    //InitPlantList();
    ShowGrid();
    ui->infodisplayhere->setText("已完成列表清空");
}


void customplantplace::on_plantplace_clicked()
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
            on_exitbutton_clicked();
        }
        else return;
    }
    if(ui->planttype->isChecked()){
        ui->infodisplayhere->setText("无事发生");
        return;
    }
    if(ui->blood->isChecked()){
        if(ui->isrealtime->isChecked()){
            QMessageBox::information(this,"提示","请先暂停实时血量显示");
            return;
        }
        for (auto& info : this->plant_info_list) {
            if(info->planttype[0]==-1)continue;
            WriteMemory<uint32_t>(info->text->text().toInt(),{info->plantmoniters[info->combobox->currentIndex()]->object_address+plant_blood});
        }
        ui->infodisplayhere->setText("修改完成");
        return;
    }
    if(ui->attackinterval->isChecked()){
        for (auto& info : this->plant_info_list) {
            if(info->planttype[0]==-1)continue;
            WriteMemory<uint32_t>(info->text->text().toInt(),{info->plantmoniters[info->combobox->currentIndex()]->object_address+plant_attack_interval});
        }
        ui->infodisplayhere->setText("修改完成");
        return;
    }
    if(ui->setshine->isChecked()){
        for (auto& info : this->plant_info_list) {
            if(info->planttype[0]==-1)continue;
            WriteMemory<uint32_t>(info->text->text().toInt(),{info->plantmoniters[info->combobox->currentIndex()]->object_address+plant_shine_time});
        }
        ui->infodisplayhere->setText("开始发光！");
        return;
    }
    if(ui->strtoform->isChecked()){
        /*if(pMoniter){
            pMoniter->thread_survive=false;
            pMoniter->exit();
            pMoniter->wait();
            delete pMoniter;
            pMoniter=nullptr;
        }*/
        QString str=ui->textedit->toPlainText();
        QRegularExpression separator("[^\\d]+");
        QStringList list = str.split(separator, Qt::SkipEmptyParts);
        vector<int>rowlist;
        vector<int>typelist;
        vector<int>collist;
        vector<int>bloodlist;
        vector<int>intervallist;
        int count=0;
        for (const QString &numStr : list) {
            bool ok;
            int intValue = numStr.toInt(&ok);
            if(count==0) {
                typelist.push_back(intValue);
                count++;
            }
            else if(count==1) {
                rowlist.push_back(intValue-1);
                count++;
            }
            else if(count==2) {
                collist.push_back(intValue-1);
                if(!ui->includeblood->isChecked()){
                    count=0;
                }
                else count++;
            }
            else if(count==3)
            {
                bloodlist.push_back(intValue);
                if(!ui->includeinterval->isChecked()){
                    count=0;
                }
                else count++;
            }
            else if(count==4){
                intervallist.push_back(intValue);
                count=0;
            }
        }
        //vector<uint32_t> nextplantposition;
        vector<uint32_t> nextplantposition;
        uint32_t offset=ReadMemory<uint32_t>({lawn,board,plant_offset});
        for(int i=0;i<typelist.size();i++){
            uint32_t next=ReadMemory<uint32_t>({lawn,board,plant_next_plant_position});
            nextplantposition.push_back(offset+next*plant_single_size);
            PlacePlant(rowlist[i],collist[i],typelist[i]);
        }
        if(ui->includeblood->isChecked())
        {
            for(int i=0;i<bloodlist.size();i++){
                if(bloodlist[i]==-1) continue;
                WriteMemory<uint32_t>(bloodlist[i],{nextplantposition[i]+plant_blood});
            }
        }

        if(ui->includeinterval->isChecked()){
            for(int i=0;i<intervallist.size();i++){
                if(intervallist[i]==-1)continue;
            WriteMemory<uint32_t>(intervallist[i],{nextplantposition[i]+plant_attack_interval});
            }
        }
        ui->infodisplayhere->setText("转化完成！");
        return;
    }

    if(ui->formtostr->isChecked()){
        for(auto *info:this->plant_info_list){
            for(auto *moni:info->plantmoniters){
                QString str=QString("%1 %2 %3").arg(moni->object_type).arg(info->row+1).arg(info->col+1);
                if(ui->includeblood->isChecked())str+=QString(" %1").arg(moni->object_blood);
                if(ui->includeinterval->isChecked())str+=QString(" %1").arg(moni->object_attack_interval);
                str+=QString(";");
                ui->textedit->append(str);
            }
        }
        ui->infodisplayhere->setText("转化完成！");
        return;
    }

    if(ui->customplace->isChecked()){
        for(int i=0;i<now_map_row*10;i++){
            if(custom_info_list[i]->combobox->currentIndex()==0) continue;
            else{
                bool ok=true;
                uint32_t nowblood;
                uint32_t nowinterval;
                if(ui->includeblood->isChecked())nowblood=custom_info_list[i]->bloodline->text().toInt(&ok);
                if(!ok){
                    QMessageBox::information(this,"提示","请输入整数！");
                    return;
                }
                if(ui->includeinterval->isChecked())nowinterval=custom_info_list[i]->intervalline->text().toInt(&ok);
                if(!ok){
                    QMessageBox::information(this,"提示","请输入整数！");
                    return;
                }
                uint32_t offset=ReadMemory<uint32_t>({lawn,board,plant_offset});
                uint32_t next=ReadMemory<uint32_t>({lawn,board,plant_next_plant_position});
                next=offset+next*plant_single_size;
                PlacePlant(custom_info_list[i]->row,custom_info_list[i]->col,custom_info_list[i]->combobox->currentIndex()-1);
                if(ui->includeblood->isChecked())WriteMemory<uint32_t>(nowblood,{next+plant_blood});
                if(ui->includeinterval->isChecked())WriteMemory<uint32_t>(nowinterval,{next+plant_attack_interval});
            }
        }
    }
}

void customplantplace::StartMoniter()
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
            on_exitbutton_clicked();
        }
        else return;
    }
    this->pMoniter=new PlantMoniter;
    for(int i=0;i<this->plant_info_list.size();i++){
        if(this->plant_info_list[i]->plantmoniters.size()==0)continue;
        for(int j=0;j<this->plant_info_list[i]->plantmoniters.size();j++){
            this->pMoniter->moniters.push_back(this->plant_info_list[i]->plantmoniters[j]);
            this->pMoniter->pointer.push_back(j);
        }
    }
    this->pMoniter->thread_survive=true;
    connect(this->pMoniter,&PlantMoniter::threadend,this,[=](){
        ui->realmoniter->setCheckState(Qt::Unchecked);
        if(!SaveCheck()) {
            QMessageBox msgBox;
            msgBox.setWindowTitle("危险！");
            msgBox.setText("检测到游戏退出，请确认游戏正常运行!\n如果不想继续请点击否，若继续需要保证游戏运行！");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int ret = msgBox.exec();
            bool userChoice = (ret == QMessageBox::Yes);
            if(!userChoice){
                on_exitbutton_clicked();
            }
            else return;
        }
    });
    connect(this->pMoniter,&PlantMoniter::updateValues,this,[=](int changetype,int p0,int p1){
        if(changetype==2){
            if(this->pMoniter->blood_moniter){
                if(this->plant_info_list[p0]->combobox->currentIndex()==p1)this->plant_info_list[p0]->text->setText(QString("%1").arg(this->plant_info_list[p0]->plantmoniters[p1]->object_blood));
            }
        }
        else if(changetype==1){
            auto plantcurrentcount=ReadMemory<uint32_t>({lawn,board,plant_curren_count});
            if(plantcurrentcount==0){
                disconnect(this->pMoniter,&PlantMoniter::threadend,nullptr,nullptr);
                pMoniter->thread_survive=false;
                on_updateplant_clicked();
                ui->realmoniter->setCheckState(Qt::Checked);
                return;
            }
            this->plant_info_list[p0]->plantmoniters.erase(this->plant_info_list[p0]->plantmoniters.begin()+p1);
            this->plant_info_list[p0]->planttype.erase(this->plant_info_list[p0]->planttype.begin()+p1);
            if(this->plant_info_list[p0]->planttype.size()==0) this->plant_info_list[p0]->planttype.push_back(-1);
            if(this->plant_info_list[p0]->combobox->currentIndex()==p1)this->plant_info_list[p0]->text->setText("");
            if(this->plant_info_list[p0]->combobox->count()==1) disconnect(this->plant_info_list[p0]->combobox, QOverload<int>::of(&QComboBox::currentIndexChanged), nullptr, nullptr);
            this->plant_info_list[p0]->combobox->removeItem(p1);
            ShowGrid();
        }
        else if(changetype==3){
            unordered_set<uint32_t> list;
            for(int i=0;i<this->pMoniter->moniters.size();i++)list.insert(this->pMoniter->moniters[i]->object_address);
            auto Plant_count_max = ReadMemory<uint32_t>({lawn, board, plant_count_max});
            auto Plant_Offset=ReadMemory<uint32_t>({lawn,board,plant_offset});
            for(size_t i=0;i<Plant_count_max;i++){
                if(list.find(Plant_Offset+i*plant_single_size)!=list.end()) continue;
                auto isdead=ReadMemory<bool>({Plant_Offset+plant_dead+i*plant_single_size});
                int blood=ReadMemory<uint32_t>({Plant_Offset+plant_blood+i*plant_single_size});
                if(isdead||blood==0) continue;
                auto row=ReadMemory<uint32_t>({Plant_Offset+plant_row+i*plant_single_size});
                auto col=ReadMemory<uint32_t>({Plant_Offset+plant_col+i*plant_single_size});
                auto type=ReadMemory<uint32_t>({Plant_Offset+plant_type+i*plant_single_size});
                auto attack_interval=ReadMemory<uint32_t>({Plant_Offset+plant_attack_interval+i*plant_single_size});
                if(this->plant_info_list[row*10+col]->planttype[0]!=-1)this->plant_info_list[row*10+col]->planttype.push_back(type);
                else this->plant_info_list[row*10+col]->planttype[0]=type;
                // plant_info_list[row*10+col]->row=row;
                // plant_info_list[row*10+col]->col=col;
                PlantBloodMoniter* newplant=new PlantBloodMoniter;
                newplant->object_type=type;
                newplant->object_col=col;
                newplant->object_row=row;
                newplant->object_attack_interval=attack_interval;
                newplant->object_address=Plant_Offset+i*plant_single_size;
                newplant->object_blood=blood;
                this->plant_info_list[row*10+col]->plantmoniters.push_back(newplant);
                this->plant_info_list[row*10+col]->combobox->addItem(QString("%1").arg(plant_book[type]));
                this->pMoniter->moniters.push_back(newplant);
                this->pMoniter->pointer.push_back(this->plant_info_list[row*10+col]->plantmoniters.size()-1);
              /*  if( this->plant_info_list[row*10+col]->combobox->count()==1){
                    if(ui->blood->isChecked())
                        this->plant_info_list[row*10+col]->text->setText(QString("%1").arg(this->plant_info_list[row*10+col]->plantmoniters.back()->object_blood));
                    if(ui->attackinterval->isChecked())
                        this->plant_info_list[row*10+col]->text->setText(QString("%1").arg(this->plant_info_list[row*10+col]->plantmoniters.back()->object_attack_interval));
                }*/
            }
            ShowGrid();

        }
    });
    this->pMoniter->nextplantposiition=ReadMemory<uint32_t>({lawn,board,plant_next_plant_position});
    this->pMoniter->start();
}

void customplantplace::InitCustomPlantList()
{
    //int max_row=GetRowCount();
    //this->now_map_row=max_row;
    this->custom_info_list.resize(60);
    for(int i=0;i<60;i++){
        CustomPlant* newdisplay=new CustomPlant;
        newdisplay->layout=new QHBoxLayout;
        newdisplay->bloodline=new QLineEdit;
        newdisplay->intervalline=new QLineEdit;
        newdisplay->combobox=new QComboBox();
        newdisplay->combobox->setFixedWidth(100);
        newdisplay->row=i/10;
        newdisplay->col=i%10;
        newdisplay->combobox->addItem(QString("%1行%2列").arg(newdisplay->row+1).arg(newdisplay->col+1));
        for(int j=0;j<48;j++){
            newdisplay->combobox->addItem(QString("[%1]%2").arg(j).arg(plant_book[j]));
        }
        newdisplay->layout->addWidget(newdisplay->combobox);
        newdisplay->layout->addWidget(newdisplay->bloodline);
        newdisplay->layout->addWidget(newdisplay->intervalline);

        this->custom_info_list[i]=newdisplay;
    }
    for(auto& info : this->custom_info_list)
        ui->gridLayout->addLayout(info->layout,info->row,info->col);
    ui->scrollAreaWidgetContents->setLayout(ui->gridLayout);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
    ui->scrollArea->setWidgetResizable(true);
}
