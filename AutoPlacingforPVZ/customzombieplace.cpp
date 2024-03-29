#include "customzombieplace.h"
#include "ui_customzombieplace.h"
extern bool CZflag;
customzombieplace::customzombieplace(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::customzombieplace)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->zombielist->setFrameShape(QListWidget::NoFrame);
    ui->zombielist->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->totalprint->setReadOnly(true);
    ui->zombiearmor1->setReadOnly(true);
    ui->zombiearmor2->setReadOnly(true);
    ui->zombiename->setReadOnly(true);
    ui->zombietype->setReadOnly(true);
    ui->xcor->setReadOnly(true);
    ui->ycor->setReadOnly(true);
    ui->rowbelong->setReadOnly(true);
    //ui->ischarm->setCheckable(false);
    ui->ischarm->setEnabled(false);
}

bool customzombieplace::SaveCheck()
{
    this->is_game_on=CheckGameOn();//检查游戏是否运行
    if(!this->is_game_on) {
        if(zMoniter!=nullptr)
            if(zMoniter->thread_survive==true){
                zMoniter->thread_survive=false;
                zMoniter->exit();
                zMoniter->wait();
                delete zMoniter;
                zMoniter=nullptr;
            }
        ui->realtime->setCheckState(Qt::Unchecked);
        return false;
    }
    this->is_board_on=CheckBoardOn();//检查关卡是否运行
    if(!this->is_board_on) {
        if(zMoniter!=nullptr)
            if(zMoniter->thread_survive==true){
                zMoniter->thread_survive=false;
                zMoniter->exit();
                zMoniter->wait();
                delete zMoniter;
                zMoniter=nullptr;
            }
        ui->realtime->setCheckState(Qt::Unchecked);
        return false;
    }
    return true;
}

customzombieplace::~customzombieplace()
{
    delete ui;
}

void customzombieplace::closeEvent(QCloseEvent *event)
{
    CZflag=false;
    QWidget::closeEvent(event);
}

void customzombieplace::on_reset_clicked()
{
    ui->armor_1->setText("");
    ui->armor_2->setText("");
    ui->batchcheck->setCheckState(Qt::Unchecked);
    ui->batchnum->setValue(1);
    ui->row->setValue(1);
    ui->col->setValue(1);
    ui->bodyblood->setText("");
    ui->zombiechoose->setCurrentText(0);
}


void customzombieplace::on_singleplace_clicked()
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
    uint32_t body_blood=-1;
    uint32_t armor1_body=-1;
    uint32_t armor2_body=-1;
    if(!ui->bodyblood->text().isEmpty()){
        bool ok=true;
        int value=ui->bodyblood->text().toInt(&ok);
        if(!ok){
            QMessageBox::information(this,"提示","请输入整数！");
            return;
        }
        body_blood=value;
    }
    if(!ui->armor_1->text().isEmpty()){
        bool ok=true;
        int value=ui->armor_1->text().toInt(&ok);
        if(!ok){
            QMessageBox::information(this,"提示","请输入整数！");
            return;
        }
        armor1_body=value;
    }
    if(!ui->armor_2->text().isEmpty()){
        bool ok=true;
        int value=ui->armor_2->text().toInt(&ok);
        if(!ok){
            QMessageBox::information(this,"提示","请输入整数！");
            return;
        }
        armor2_body=value;
    }
    int batchnum=1;
    if(ui->batchcheck->isChecked())batchnum=ui->batchnum->value();
    vector<uint32_t>offsetlist;
    for(int i=0;i<batchnum;i++){
        uint32_t next_offset=ReadMemory<uint32_t>({lawn,board,zombie_next_offset});
        uint32_t offset=ReadMemory<uint32_t>({lawn,board,zombie_offset});
        offset=next_offset*zombie_struct_size+offset;
        offsetlist.push_back(offset);
        PlaceZombie(ui->row->value()-1,ui->col->value()-1,ui->zombiechoose->currentIndex());
    }
    if(body_blood!=-1){
        for(int i=0;i<offsetlist.size();i++)
        WriteMemory<uint32_t>(body_blood,{offsetlist[i]+zombie_body_blood});
    }
    if(armor1_body!=-1){
        for(int i=0;i<offsetlist.size();i++)
        WriteMemory<uint32_t>(body_blood,{offsetlist[i]+zombie_armor1_body});
    }
    if(armor2_body!=-1){
        for(int i=0;i<offsetlist.size();i++)
        WriteMemory<uint32_t>(body_blood,{offsetlist[i]+zombie_armor2_body});
    }
}


void customzombieplace::on_rowplace_clicked()
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
    uint32_t body_blood=-1;
    uint32_t armor1_body=-1;
    uint32_t armor2_body=-1;
    if(!ui->bodyblood->text().isEmpty()){
        bool ok=true;
        int value=ui->bodyblood->text().toInt(&ok);
        if(!ok){
            QMessageBox::information(this,"提示","请输入整数！");
            return;
        }
        body_blood=value;
    }
    if(!ui->armor_1->text().isEmpty()){
        bool ok=true;
        int value=ui->armor_1->text().toInt(&ok);
        if(!ok){
            QMessageBox::information(this,"提示","请输入整数！");
            return;
        }
        armor1_body=value;
    }
    if(!ui->armor_2->text().isEmpty()){
        bool ok=true;
        int value=ui->armor_2->text().toInt(&ok);
        if(!ok){
            QMessageBox::information(this,"提示","请输入整数！");
            return;
        }
        armor2_body=value;
    }
    int batchnum=1;
    if(ui->batchcheck->isChecked())batchnum=ui->batchnum->value();
    //int maxrow=GetRowCount();
    vector<uint32_t>offsetlist;
    for(int COL=0;COL<10;COL++){
    for(int i=0;i<batchnum;i++){
        uint32_t next_offset=ReadMemory<uint32_t>({lawn,board,zombie_next_offset});
        uint32_t offset=ReadMemory<uint32_t>({lawn,board,zombie_offset});
        offset=next_offset*zombie_struct_size+offset;
        offsetlist.push_back(offset);
        PlaceZombie(ui->row->value()-1,COL,ui->zombiechoose->currentIndex());
    }
    }
    if(body_blood!=-1){
        for(int i=0;i<offsetlist.size();i++)
            WriteMemory<uint32_t>(body_blood,{offsetlist[i]+zombie_body_blood});
    }
    if(armor1_body!=-1){
        for(int i=0;i<offsetlist.size();i++)
            WriteMemory<uint32_t>(body_blood,{offsetlist[i]+zombie_armor1_body});
    }
    if(armor2_body!=-1){
        for(int i=0;i<offsetlist.size();i++)
            WriteMemory<uint32_t>(body_blood,{offsetlist[i]+zombie_armor2_body});
    }
}


void customzombieplace::on_colplace_clicked()
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
    uint32_t body_blood=-1;
    uint32_t armor1_body=-1;
    uint32_t armor2_body=-1;
    if(!ui->bodyblood->text().isEmpty()){
        bool ok=true;
        int value=ui->bodyblood->text().toInt(&ok);
        if(!ok){
            QMessageBox::information(this,"提示","请输入整数！");
            return;
        }
        body_blood=value;
    }
    if(!ui->armor_1->text().isEmpty()){
        bool ok=true;
        int value=ui->armor_1->text().toInt(&ok);
        if(!ok){
            QMessageBox::information(this,"提示","请输入整数！");
            return;
        }
        armor1_body=value;
    }
    if(!ui->armor_2->text().isEmpty()){
        bool ok=true;
        int value=ui->armor_2->text().toInt(&ok);
        if(!ok){
            QMessageBox::information(this,"提示","请输入整数！");
            return;
        }
        armor2_body=value;
    }
    int batchnum=1;
    if(ui->batchcheck->isChecked())batchnum=ui->batchnum->value();
    int maxrow=GetRowCount();
    vector<uint32_t>offsetlist;
    for(int ROW=0;ROW<maxrow;ROW++){
        for(int i=0;i<batchnum;i++){
            uint32_t next_offset=ReadMemory<uint32_t>({lawn,board,zombie_next_offset});
            uint32_t offset=ReadMemory<uint32_t>({lawn,board,zombie_offset});
            offset=next_offset*zombie_struct_size+offset;
            offsetlist.push_back(offset);
            PlaceZombie(ROW,ui->col->value()-1,ui->zombiechoose->currentIndex());
        }
    }
        if(body_blood!=-1){
            for(int i=0;i<offsetlist.size();i++)
                WriteMemory<uint32_t>(body_blood,{offsetlist[i]+zombie_body_blood});
        }
        if(armor1_body!=-1){
            for(int i=0;i<offsetlist.size();i++)
                WriteMemory<uint32_t>(body_blood,{offsetlist[i]+zombie_armor1_body});
        }
        if(armor2_body!=-1){
            for(int i=0;i<offsetlist.size();i++)
                WriteMemory<uint32_t>(body_blood,{offsetlist[i]+zombie_armor2_body});
        }
}


void customzombieplace::ShowZombie()
{
    if(!SaveCheck()) {
         return;
    }
    int currentrow=ui->zombielist->currentRow();
    ui->zombielist->clear();
    indexnum.clear();
    unordered_set<size_t>nowoffsetnum=zMoniter->offsetnum;
    for(auto iter=nowoffsetnum.begin();iter!=nowoffsetnum.end();iter++)
    {
        ui->zombielist->addItem(QString("%1行  %2").arg(zMoniter->zombie_info_list[*iter].row+1).arg(zombie_book[zMoniter->zombie_info_list[*iter].type]));
        indexnum.push_back(*iter);
    }
    if(currentrow==-1) return;
    ui->zombielist->setCurrentRow(currentrow);
    if(!zMoniter)return;
    if(zMoniter->thread_survive==false) return;
    if(zMoniter->zombie_info_list.size()==0) return;
    ui->zombiearmor1->setText(QString("%1").arg(armor1_book[zMoniter->zombie_info_list[indexnum[currentrow]].armor1_type]));
    ui->zombiearmor2->setText(QString("%1").arg(armor2_book[zMoniter->zombie_info_list[indexnum[currentrow]].armor2_type]));
    ui->zombiearmor1blood->setText(QString("%1").arg(zMoniter->zombie_info_list[indexnum[currentrow]].armor1_blood));
    ui->zombiearmor2blood->setText(QString("%1").arg(zMoniter->zombie_info_list[indexnum[currentrow]].armor2_blood));
    ui->zombietype->setText(QString("%1").arg(zMoniter->zombie_info_list[indexnum[currentrow]].type));
    ui->zombiename->setText(QString("%1").arg(zombie_book[zMoniter->zombie_info_list[indexnum[currentrow]].type]));
    ui->zombiebody->setText(QString("%1").arg(zMoniter->zombie_info_list[indexnum[currentrow]].body_blood));
    ui->rowbelong->setText(QString("%1").arg(zMoniter->zombie_info_list[indexnum[currentrow]].row+1));
    ui->xcor->setText(QString("%1").arg(zMoniter->zombie_info_list[indexnum[currentrow]].x_corordinate));
    ui->ycor->setText(QString("%1").arg(zMoniter->zombie_info_list[indexnum[currentrow]].y_corordinate));
    ui->slowdown->setValue(zMoniter->zombie_info_list[indexnum[currentrow]].slow_down_time);
    ui->buttertime->setValue(zMoniter->zombie_info_list[indexnum[currentrow]].butter_down_time);
    ui->freezetime->setValue(zMoniter->zombie_info_list[indexnum[currentrow]].froze_down_time);
    ui->shiningtime->setValue(zMoniter->zombie_info_list[indexnum[currentrow]].shining_down_time);
    if(zMoniter->zombie_info_list[indexnum[currentrow]].ishypno==true) ui->ischarm->setCheckState(Qt::Checked);
    else ui->ischarm->setCheckState(Qt::Unchecked);
}

void customzombieplace::on_realtime_stateChanged(int arg1)
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
    if(ui->realtime->isChecked()){
        //ui->zombielist->clear();
        if(!zMoniter){
            zMoniter=new ZombieMoniter;
            zMoniter->zombie_info_list.resize(1024);
        }
        zMoniter->thread_survive=true;
        connect(zMoniter,&ZombieMoniter::updateValue,this,[=](uint32_t num,QDateTime ctime){
            //qDebug()<<num<<" this is update "<<" "<<"\n";
            if(!zMoniter) return;
            if(zMoniter->thread_survive==false) return;
            //qDebug()<<num<<" this is update "<<zMoniter->zombie_info_list[num].type<<" "<<"\n";
            int msecsDiff = this->start_counting_time.msecsTo(ctime);
            int minutes = msecsDiff / (60 * 1000);
            int seconds = (msecsDiff % (60 * 1000)) / 1000;
            int milliseconds = msecsDiff % 1000;
            for(auto &info:zombie_totall_list){
                if(zMoniter->zombie_info_list[num].zombie_address==info.zombie_address)
                {
                    if(info.isdead==true) continue;
                    if(zMoniter->zombie_info_list[num].type!=info.type){
                        info.isdead=true;
                        info.dead_time=ctime;
                        if(ui->ignoreblindbox->isChecked()&&info.type==2) ;
                        else {
                            if(this->iscounting)  {
                               // qDebug()<<info.mower_is_dead<<" 1\n";
                                if(!info.mower_is_dead)
                                    ui->totalprint->append(QString("[%1:%2:%3] %4死亡于第%5行").arg(minutes)
                                                       .arg(seconds).arg(milliseconds).arg(zombie_book[info.type]).arg(info.row+1));
                                else ui->totalprint->append(QString("[%1:%2:%3] %4死亡于第%5行 (小推车已启动)").arg(minutes)
                                                               .arg(seconds).arg(milliseconds).arg(zombie_book[info.type]).arg(info.row+1));
                            }
                        }
                        ZombieStatistic newzomb;
                        newzomb.row=zMoniter->zombie_info_list[num].row;
                        newzomb.zombie_address=zMoniter->zombie_info_list[num].zombie_address;
                        newzomb.first_moniter_time=ctime;
                        newzomb.isdead=false;
                        uint32_t moweroffset=ReadMemory<uint32_t>({lawn,board,lawn_mower});
                        auto mowerstatus = ReadMemory<uint32_t>({moweroffset + lawn_mower_state + lawn_mower_next * newzomb.row});
                        //qDebug()<<mowerstatus<<"\n";
                        if(mowerstatus!=1) newzomb.mower_is_dead=true;
                        else newzomb.mower_is_dead=false;
                        if(zMoniter->zombie_info_list[num].armor1_blood>0||zMoniter->zombie_info_list[num].armor2_blood>0){
                            newzomb.body_init_blood=zMoniter->zombie_info_list[num].armor1_blood>zMoniter->zombie_info_list[num].armor2_blood?
                                                          zMoniter->zombie_info_list[num].armor1_blood:zMoniter->zombie_info_list[num].armor2_blood;
                        }
                        else newzomb.body_init_blood=zMoniter->zombie_info_list[num].body_blood;

                        newzomb.type=zMoniter->zombie_info_list[num].type;
                        zombie_totall_list.push_back(newzomb);
                        if(ui->ignoreblindbox->isChecked()&&newzomb.type==2){
                            ShowZombie();
                            return;
                        }
                        if(this->iscounting)  {
                            if(newzomb.mower_is_dead){
                                if(newzomb.body_init_blood>0.8*full_blood_book[newzomb.type]){
                                    ui->totalprint->append(QString("※※※[%1:%2:%3] %4产生于第%5行，监测初始血量为：%6（满血）(小推车已启动)").arg(minutes)
                                                               .arg(seconds).arg(milliseconds).arg(zombie_book[newzomb.type]).arg(newzomb.row+1).arg(zMoniter->zombie_info_list[num].armor1_blood
                                                                    + zMoniter->zombie_info_list[num].armor2_blood+zMoniter->zombie_info_list[num].body_blood));
                                }
                                else ui->totalprint->append(QString("[%1:%2:%3] %4产生于第%5行，监测初始血量为：%6(小推车已启动)").arg(minutes)
                                                               .arg(seconds).arg(milliseconds).arg(zombie_book[newzomb.type]).arg(newzomb.row+1).arg(zMoniter->zombie_info_list[num].armor1_blood
                                                                    + zMoniter->zombie_info_list[num].armor2_blood+zMoniter->zombie_info_list[num].body_blood));
                            }
                            else{
                                if(newzomb.body_init_blood>0.8*full_blood_book[newzomb.type]){
                                    ui->totalprint->append(QString("※※※[%1:%2:%3] %4产生于第%5行，监测初始血量为：%6（满血）").arg(minutes)
                                                               .arg(seconds).arg(milliseconds).arg(zombie_book[newzomb.type]).arg(newzomb.row+1).arg(zMoniter->zombie_info_list[num].armor1_blood
                                                                    + zMoniter->zombie_info_list[num].armor2_blood+zMoniter->zombie_info_list[num].body_blood));
                                }
                                else ui->totalprint->append(QString("[%1:%2:%3] %4产生于第%5行，监测初始血量为：%6").arg(minutes)
                                                               .arg(seconds).arg(milliseconds).arg(zombie_book[newzomb.type]).arg(newzomb.row+1).arg(zMoniter->zombie_info_list[num].armor1_blood
                                                                    + zMoniter->zombie_info_list[num].armor2_blood+zMoniter->zombie_info_list[num].body_blood));
                            }
                        }
                        ShowZombie();
                        return;
                    }
                    else{
                        ShowZombie();
                        return;
                    }
                }
            }

            ZombieStatistic newzomb;
            newzomb.zombie_address=zMoniter->zombie_info_list[num].zombie_address;
            newzomb.first_moniter_time=ctime;
            newzomb.isdead=false;
            newzomb.row=zMoniter->zombie_info_list[num].row;
            uint32_t moweroffset=ReadMemory<uint32_t>({lawn,board,lawn_mower});
            auto mowerstatus = ReadMemory<uint32_t>({moweroffset + lawn_mower_state + lawn_mower_next * newzomb.row});
            //qDebug()<<mowerstatus<<"\n";
            if(mowerstatus!=1) newzomb.mower_is_dead=true;
            else newzomb.mower_is_dead=false;
            if(zMoniter->zombie_info_list[num].armor1_blood>0||zMoniter->zombie_info_list[num].armor2_blood>0){
                newzomb.body_init_blood=zMoniter->zombie_info_list[num].armor1_blood>zMoniter->zombie_info_list[num].armor2_blood?
                                              zMoniter->zombie_info_list[num].armor1_blood:zMoniter->zombie_info_list[num].armor2_blood;
            }
            else newzomb.body_init_blood=zMoniter->zombie_info_list[num].body_blood;
            newzomb.type=zMoniter->zombie_info_list[num].type;
            zombie_totall_list.push_back(newzomb);
            if(ui->ignoreblindbox->isChecked()&&newzomb.type==2){
                ShowZombie();
                return;
            }
            if(this->iscounting)  {
                if(newzomb.mower_is_dead){
                    if(newzomb.body_init_blood>0.8*full_blood_book[newzomb.type]){
                        ui->totalprint->append(QString("※※※[%1:%2:%3] %4产生于第%5行，监测初始血量为：%6（满血）(小推车已启动)").arg(minutes)
                                                   .arg(seconds).arg(milliseconds).arg(zombie_book[newzomb.type]).arg(newzomb.row+1).arg(zMoniter->zombie_info_list[num].armor1_blood
                                                        + zMoniter->zombie_info_list[num].armor2_blood+zMoniter->zombie_info_list[num].body_blood));
                    }
                    else ui->totalprint->append(QString("[%1:%2:%3] %4产生于第%5行，监测初始血量为：%6(小推车已启动)").arg(minutes)
                                                   .arg(seconds).arg(milliseconds).arg(zombie_book[newzomb.type]).arg(newzomb.row+1).arg(zMoniter->zombie_info_list[num].armor1_blood
                                                        + zMoniter->zombie_info_list[num].armor2_blood+zMoniter->zombie_info_list[num].body_blood));
                }
                else{
                    if(newzomb.body_init_blood>0.8*full_blood_book[newzomb.type]){
                    ui->totalprint->append(QString("※※※[%1:%2:%3] %4产生于第%5行，监测初始血量为：%6（满血）").arg(minutes)
                                               .arg(seconds).arg(milliseconds).arg(zombie_book[newzomb.type]).arg(newzomb.row+1).arg(zMoniter->zombie_info_list[num].armor1_blood
                                                    + zMoniter->zombie_info_list[num].armor2_blood+zMoniter->zombie_info_list[num].body_blood));
                    }
                    else ui->totalprint->append(QString("[%1:%2:%3] %4产生于第%5行，监测初始血量为：%6").arg(minutes)
                                               .arg(seconds).arg(milliseconds).arg(zombie_book[newzomb.type]).arg(newzomb.row+1).arg(zMoniter->zombie_info_list[num].armor1_blood
                                                    + zMoniter->zombie_info_list[num].armor2_blood+zMoniter->zombie_info_list[num].body_blood));
                }
            }
            ShowZombie();
            return;

        });
        connect(zMoniter,&ZombieMoniter::deadzombie,this,[=](uint32_t num,QDateTime ctime){
            if(!zMoniter) return;
            if(zMoniter->thread_survive==false) return;
            int msecsDiff = this->start_counting_time.msecsTo(ctime);
            int minutes = msecsDiff / (60 * 1000);
            int seconds = (msecsDiff % (60 * 1000)) / 1000;
            int milliseconds = msecsDiff % 1000;
            for(auto &info:zombie_totall_list){
                 if(zMoniter->zombie_info_list[num].zombie_address==info.zombie_address)
                {
                    if(info.isdead==true)continue;
                    info.isdead=true;
                    info.dead_time=ctime;
                    uint32_t moweroffset=ReadMemory<uint32_t>({lawn,board,lawn_mower});
                    auto mowerstatus = ReadMemory<uint32_t>({moweroffset + lawn_mower_state + lawn_mower_next * info.row});

                    if(mowerstatus!=1) info.mower_is_dead=true;
                    if(ui->ignoreblindbox->isChecked()&&info.type==2) ;
                    else {
                        if(!info.mower_is_dead)
                            ui->totalprint->append(QString("[%1:%2:%3] %4死亡于第%5行").arg(minutes)
                                                       .arg(seconds).arg(milliseconds).arg(zombie_book[info.type]).arg(info.row+1));
                        else ui->totalprint->append(QString("[%1:%2:%3] %4死亡于第%5行 (小推车已启动)").arg(minutes)
                                                       .arg(seconds).arg(milliseconds).arg(zombie_book[info.type]).arg(info.row+1));
                    }
                    ShowZombie();
                    return;
                }
            }
        });
        zMoniter->start();
        return;
    }

     else if(!ui->realtime->isChecked())
        if(zMoniter){
        zMoniter->thread_survive=false;
        zMoniter->exit();
        zMoniter->wait();
        disconnect(zMoniter,&ZombieMoniter::updateValue,nullptr,nullptr);
        disconnect(zMoniter,&ZombieMoniter::deadzombie,nullptr,nullptr);

       // zMoniter->zombie_info_list.clear();
       // delete zMoniter;
        //zMoniter=nullptr;
    }
}


void customzombieplace::on_zombielist_currentRowChanged(int currentRow)
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
    if(!zMoniter)return;
    if(ui->zombielist->currentRow()==-1) return;
    ui->zombiearmor1->setText(QString("%1").arg(armor1_book[zMoniter->zombie_info_list[indexnum[ui->zombielist->currentRow()]].armor1_type]));
    ui->zombiearmor2->setText(QString("%1").arg(armor2_book[zMoniter->zombie_info_list[indexnum[ui->zombielist->currentRow()]].armor2_type]));
    ui->zombiearmor1blood->setText(QString("%1").arg(zMoniter->zombie_info_list[indexnum[ui->zombielist->currentRow()]].armor1_blood));
    ui->zombiearmor2blood->setText(QString("%1").arg(zMoniter->zombie_info_list[indexnum[ui->zombielist->currentRow()]].armor2_blood));
    ui->zombietype->setText(QString("%1").arg(zMoniter->zombie_info_list[indexnum[ui->zombielist->currentRow()]].type));
    ui->zombiename->setText(QString("%1").arg(zombie_book[zMoniter->zombie_info_list[indexnum[ui->zombielist->currentRow()]].type]));
    ui->zombiebody->setText(QString("%1").arg(zMoniter->zombie_info_list[indexnum[ui->zombielist->currentRow()]].body_blood));
    ui->rowbelong->setText(QString("%1").arg(zMoniter->zombie_info_list[indexnum[ui->zombielist->currentRow()]].row+1));
    ui->xcor->setText(QString("%1").arg(zMoniter->zombie_info_list[indexnum[ui->zombielist->currentRow()]].x_corordinate));
    ui->ycor->setText(QString("%1").arg(zMoniter->zombie_info_list[indexnum[ui->zombielist->currentRow()]].y_corordinate));
    ui->slowdown->setValue(zMoniter->zombie_info_list[indexnum[ui->zombielist->currentRow()]].slow_down_time);
    ui->buttertime->setValue(zMoniter->zombie_info_list[indexnum[ui->zombielist->currentRow()]].butter_down_time);
    ui->freezetime->setValue(zMoniter->zombie_info_list[indexnum[ui->zombielist->currentRow()]].froze_down_time);
    ui->shiningtime->setValue(zMoniter->zombie_info_list[indexnum[ui->zombielist->currentRow()]].shining_down_time);
    if(zMoniter->zombie_info_list[indexnum[ui->zombielist->currentRow()]].ishypno==true) ui->ischarm->setCheckState(Qt::Checked);
    else ui->ischarm->setCheckState(Qt::Unchecked);
}


void customzombieplace::on_pushButton_clicked()
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
    if(ui->zombielist->currentRow()==-1)return;
    bool ishypnoed=ui->ischarm->isChecked();
    ishypnoed=!ishypnoed;
    WriteMemory<bool>(ishypnoed,{zMoniter->zombie_info_list[indexnum[ui->zombielist->currentRow()]].zombie_address+zombie_ishypno});
}


void customzombieplace::on_isdead_stateChanged(int arg1)
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
    if(ui->isdead->isChecked()){
        WriteMemory<uint32_t>(3,{zMoniter->zombie_info_list[ui->zombielist->currentRow()].zombie_address+zombie_status});
    }
    on_zombielist_currentRowChanged(ui->zombielist->currentRow());
    ui->isdead->setCheckState(Qt::Unchecked);
}


void customzombieplace::on_startcount_clicked()
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
    ui->totalprint->clear();
    if(!zMoniter){
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString currentTime = currentDateTime.toString("yyyy-MM-dd hh:mm:ss.zzz");
        ui->totalprint->append(QString("\n[%1]未开启实时监控，请先于上一页打开实时显示!\n").arg(currentTime));
        return;
    }
    if(this->zMoniter->thread_survive==false){
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString currentTime = currentDateTime.toString("yyyy-MM-dd hh:mm:ss.zzz");
        ui->totalprint->append(QString("\n[%1]未开启实时监控，请先于上一页打开实时显示!\n").arg(currentTime));
        return;
    }
    if(this->iscounting) {
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString currentTime = currentDateTime.toString("yyyy-MM-dd hh:mm:ss.zzz");
        ui->totalprint->append(QString("\n[%1]Couting already started, do not repeatedly click!\n").arg(currentTime));
        return;
    }
    this->iscounting=true;
    this->iscounted=false;
    this->start_counting_time=QDateTime::currentDateTime();
    QString currentTime = start_counting_time.toString("yyyy-MM-dd hh:mm:ss.zzz");
    ui->totalprint->append(QString("[%1]Start Couting:\n").arg(currentTime));
}


void customzombieplace::on_stopcount_clicked()
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
    this->iscounting=false;
    this->iscounted=true;
    vector<ZombieStatistic> endlist=this->zombie_totall_list;
    int count[33]={0};
    int total=0;
    int countrow[6]={0};
    for(int i=0;i<endlist.size();i++){
        if(!endlist[i].isdead)continue;
        count[endlist[i].type]++;
        countrow[endlist[i].row]++;
        total++;
    }

    if(ui->ignoreblindbox->isChecked()){
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString currentTime = currentDateTime.toString("yyyy-MM-dd hh:mm:ss.zzz");
        ui->totalprint->append(QString("\n[%1]统计忽略了盲盒僵尸\n").arg(currentTime));
        total-=count[2];
    }

    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentTime = currentDateTime.toString("yyyy-MM-dd hh:mm:ss.zzz");
    ui->totalprint->append(QString("[%1]本次统计过程一共击杀%2个僵尸\n").arg(currentTime).arg(total));
    for(int i=0;i<33;i++){
        if(i==2&&ui->ignoreblindbox->isChecked()) continue;
        ui->totalprint->append(QString("【%1】%2个").arg(zombie_book[i]).arg(count[i]));
    }
    if(ui->rowdetails->isChecked()){
        int max_row=GetRowCount();
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString currentTime = currentDateTime.toString("yyyy-MM-dd hh:mm:ss.zzz");
        ui->totalprint->append(QString("[%1]下面为行详细统计信息：\n").arg(currentTime));
        for(int i=0;i<max_row;i++){
            int currentrowcont=0;
            int mowerbefore=0;
            ui->totalprint->append(QString("[第%1行]统计信息：本行一共击杀%2个僵尸(此数据含路障/盲盒，但下方展示列表根据选择是否展示),下面为每个僵尸信息：").arg(i+1).arg(countrow[i]));
            for(int j=0;j<endlist.size();j++){
                if(endlist[j].row!=i) continue;
                if(ui->ignoreblindbox->isChecked()&&endlist[j].type==2) continue;
                int msecsDiff = this->start_counting_time.msecsTo(endlist[j].dead_time);
                int minutes = msecsDiff / (60 * 1000);
                int seconds = (msecsDiff % (60 * 1000)) / 1000;
                int milliseconds = msecsDiff % 1000;
                if(endlist[j].mower_is_dead){
                    if(endlist[j].body_init_blood>0.8*full_blood_book[endlist[j].type]){

                        ui->totalprint->append(QString("[%1:%2:%3] 击杀%4 (满血)(小推车已启动)").arg(minutes)
                                                   .arg(seconds).arg(milliseconds).arg(zombie_book[endlist[j].type]));
                    }
                    else ui->totalprint->append(QString("[%1:%2:%3] 击杀%4 (小推车已启动)").arg(minutes)
                                                   .arg(seconds).arg(milliseconds).arg(zombie_book[endlist[j].type]));
                    currentrowcont++;
                    mowerbefore++;
                    continue;
                }
                if(endlist[j].body_init_blood>0.8*full_blood_book[endlist[j].type]){

                    ui->totalprint->append(QString("[%1:%2:%3] 击杀%4 (满血)").arg(minutes)
                                               .arg(seconds).arg(milliseconds).arg(zombie_book[endlist[j].type]));
                }
                else ui->totalprint->append(QString("[%1:%2:%3] 击杀%4").arg(minutes)
                                           .arg(seconds).arg(milliseconds).arg(zombie_book[endlist[j].type]));
                currentrowcont++;
            }
            ui->totalprint->append(QString("[第%1行]统计信息：综上不含路障/盲盒的数量为%2个").arg(i+1).arg(currentrowcont));
            ui->totalprint->append(QString("[第%1行]统计信息：小推车启动前击杀的数量为%2个").arg(i+1).arg(currentrowcont-mowerbefore));
            ui->totalprint->append(QString("\n"));
        }
    }
}


void customzombieplace::on_tofile_clicked()
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
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentTime = currentDateTime.toString("yyyy-MM-dd-hh-mm-ss");
    QString textContent=ui->totalprint->toPlainText();
    QString filePath = currentTime+".txt";
    //qDebug()<<filePath;
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        ui->totalprint->append(QString("保存文件失败：%1").arg(file.errorString()));
        return ;
    }
    QTextStream out(&file);
    out << textContent;
    file.close();
    ui->totalprint->append(QString("保存文件成功，请在当前程序所在文件夹寻找文件：%1").arg(filePath));
    return;
}


void customzombieplace::on_exitbutton_clicked()
{
    if(zMoniter){
        if(zMoniter->thread_survive=true){
            zMoniter->thread_survive=false;
            zMoniter->exit();
            zMoniter->wait();
            delete zMoniter;
            zMoniter=nullptr;
        }
    }
    this->close();
}

