#include "randzombieplace.h"
#include "ui_randzombieplace.h"

extern bool RZflag;

randzombieplace::randzombieplace(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::randzombieplace)
{
    ui->setupUi(this);
    ui->addfinish->setVisible(false);
   // ui->inittext->setVisible(false);
    //ui->inittextvalue->setVisible(false);
    ui->stopzombie->setVisible(false);
    ui->pausezombie->setVisible(false);
    //ui->timeandrate_table->setVisible(false);
    ui->timeandrate_table->setShowGrid(true);
   // ui->timeandrate_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
   // ui->timeandrate_table->setFocusPolicy(Qt::NoFocus); // 取消Item选中后的虚线边框
    ui->timeandrate_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->timeandrate_table->resizeRowsToContents();
    ui->timeandrate_table->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); // 显示垂直滑动条
    ui->timeandrate_table->setRowCount(0);
    ui->timeandrate_table->setColumnCount(2);
    connect(ui->timeandrate_table,SIGNAL(returnPressed()),this,SLOT(on_editdatalist_clicked()));
    QHeaderView* view = new QHeaderView(Qt::Horizontal);
    QStandardItemModel* model = new QStandardItemModel;
    QStringList labels;
    labels << QStringLiteral("时间节点min") << QStringLiteral("变换后速率s");
    model->setHorizontalHeaderLabels(labels);
    view->setModel(model);
    ui->timeandrate_table->setHorizontalHeader(view);
    connect(ui->stopzombie,&QPushButton::clicked,this,&randzombieplace::stopThread);
    connect(ui->pausezombie,&QPushButton::clicked,this,&randzombieplace::PauseThread);
    thread=nullptr;
    spicythread=nullptr;
    connect(ui->autospicy,&QCheckBox::stateChanged,this,&randzombieplace::autospicythread);
    //connect(ui->pausewithgame,&QCheckBox::stateChanged,this,&randzombieplace::setgamepause_zom);
    safecheck=new ZombieSafeCheck;
    connect(safecheck,&QThread::finished,this,&randzombieplace::safecheckstop);
    safecheck->start();
}

randzombieplace::~randzombieplace()
{
    delete ui;
}

void randzombieplace::closeEvent(QCloseEvent *event)
{
    RZflag=false;
    if(thread){
        StopThread();
        thread->exit();
        thread->wait(); // 等待线程结束
        delete thread; // 释放线程对象
        thread = nullptr;
    }
    if(spicythread){
        ui->autospicy->setCheckState(Qt::Unchecked);
    }
    if(safecheck){
        safecheck->status=4;
        safecheck->exit();
        safecheck->wait();
        delete safecheck;
        safecheck=nullptr;
    }
    QWidget::closeEvent(event);
}

void randzombieplace::setgamepause_zom()
{
    SetGamePause();
}

void randzombieplace::on_returnmain_clicked()
{
    if(thread) {
        QMessageBox::information(this,"提示","请终止出怪后再返回");
        return;
    }
    this->close();
}


void randzombieplace::on_resetall_clicked()
{
    if(thread) {
        QMessageBox::information(this,"提示","请终止出怪后再重置");
        return;
    }
    for(int i=this->time_list.size()-1;i>=0;i--)
        ui->timeandrate_table->removeRow(i);
    ui->zombiecol->setValue(0);
    ui->zombierow->setValue(0);
    ui->zombiechoose->setCurrentIndex(0);
    ui->initrate->setValue(0.00);
    ui->timenode->setValue(0.00);
    ui->rates->setValue(0.00);
    ui->autospicy->setCheckState(Qt::Unchecked);
    ui->pausewithgame->setCheckState(Qt::Unchecked);
    ui->addfinish->setVisible(false);
    ui->inittext->setVisible(false);
    ui->inittextvalue->setVisible(false);
    //ui->timeandrate_table->clearContents();
    ui->mowerrow->setValue(0);
    this->rate_list.clear();
    this->time_list.clear();
    this->inititial_rate=0;
    this->iffinishinput=false;
    ui->currentrate->setText(" ");
    ui->totalzombie->setText(" ");
}


void randzombieplace::on_skipandput_clicked()
{
    int row=ui->zombierow->value();
    int col=ui->zombiecol->value();
    int type=ui->zombiechoose->currentIndex();
    if(row!=0&&col!=0) PlaceZombie(row-1,col-1,type);
    else if(col==0&&row!=0) for(int i=0;i<11;i++) PlaceZombie(row-1,i,type);
    else if(row==0&&col!=0)ZombieColumPlace(col-1,type);
    else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("危险！");
        msgBox.setText("你想让屏幕充满僵尸吗？");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret = msgBox.exec();
        bool userChoice = (ret == QMessageBox::Yes);
        if (userChoice) {
            int thismaxrow=GetRowCount();
            for(int i=0;i<thismaxrow;i++)
                for(int j=0;j<11;j++)
                    PlaceZombie(i,j,type);
        } else {
            return;
        }
    }
}



void randzombieplace::on_initratesure_clicked()
{
    if(thread) {
        QMessageBox::information(this,"提示","请终止出怪后再修改");
        return;
    }
    this->inititial_rate=ui->initrate->value();
    //rate_list.clear();
    if(rate_list.size()==0)rate_list.push_back(this->inititial_rate);
    else rate_list[0]=this->inititial_rate;
    ui->inittextvalue->setText(QString::number(this->inititial_rate, 'f', 2)+"s");
    ui->inittextvalue->setVisible(true);
    ui->inittext->setVisible(true);
    ui->addfinish->setVisible(false);
}


void randzombieplace::on_addsure_clicked()
{
    if(this->iffinishinput) return;
    if(this->inititial_rate==0.00){
        QMessageBox::information(this,"提示","请首先输入初始速率！");
        ui->addfinish->setVisible(false);
        return;
    }
    else
    {
        double newtimenode=ui->timenode->value();
        double newrate=ui->rates->value();
        if(newtimenode==0||newrate==0){
            {
                QMessageBox::information(this,"提示","请确认你的数据是否正确！");
                return;
            }
        }
        if(this->time_list.size()==0) goto savedata;
        if(newtimenode==this->time_list.back()&&newrate==this->rate_list.back())
        {
            QMessageBox::information(this,"提示","与前一组数据相比没有变化，请重新输入！");
            return;
        }
  savedata:
        for (size_t i = 0; i < time_list.size(); i++) {
          if(fabs(time_list[i]-newtimenode)<0.001) {
                QMessageBox::information(this,"提示","相同时间节点已存在！");
                return;
            }
        }
        this->time_list.push_back(newtimenode);
        this->rate_list.push_back(newrate);
        ui->timeandrate_table->insertRow(this->time_list.size()-1);
       // QTableWidgetItem *item1 = new QTableWidgetItem(QString("%1 min").arg(QString::number(this->time_list.back(), 'f', 2)));
       // item1->setTextAlignment(Qt::AlignCenter);
       // ui->timeandrate_table->setItem(this->time_list.size()-1,0,item1);
       // QTableWidgetItem *item2 = new QTableWidgetItem(QString("%1 s").arg(QString::number(this->time_list[i], 'f', 2)));
       // item2->setTextAlignment(Qt::AlignCenter);
       // ui->timeandrate_table->setItem(this->time_list.size()-1,1,item2);
        vector<pair<double,double>> pairlist;
        for (size_t i = 0; i < time_list.size(); i++) {
            pairlist.push_back(std::make_pair(time_list[i], rate_list[i+1]));
        }
        sort(pairlist.begin(), pairlist.end());
        for(size_t i=0;i< pairlist.size();i++){
            time_list[i]=pairlist[i].first;
            rate_list[i+1]=pairlist[i].second;
        }
        for(size_t i = 0; i < time_list.size(); i++)
        {
            ui->timeandrate_table->setItem(i,0,new QTableWidgetItem(QString("%1").arg(QString::number(this->time_list[i], 'f', 2))));
            ui->timeandrate_table->setItem(i,1,new QTableWidgetItem(QString("%1").arg(QString::number(this->rate_list[i+1], 'f', 2))));
        }

        ui->addfinish->setVisible(true);
    }
}


void randzombieplace::on_deletedata_clicked()
{
    if(this->iffinishinput) return;
    if(time_list.size()==0)        {
        QMessageBox::information(this,"提示","当前无数据可删除！");
        return;
    }
    int currentRow=ui->timeandrate_table->currentRow();
    ui->timeandrate_table->removeRow(currentRow);
    this->time_list.erase(time_list.begin()+currentRow);
    this->rate_list.erase(rate_list.begin()+currentRow+1);
}


void randzombieplace::on_addfinish_clicked()
{
    iffinishinput=true;
    ui->addfinish->setVisible(false);
    ui->deletedata->setVisible(false);
    ui->editdatalist->setVisible(false);
}

void randzombieplace::PauseThread()
{
    thread->paused=!thread->paused;
    if(spicythread)spicythread->paused=!spicythread->paused;
    if(ui->pausewithgame->isChecked()) setgamepause_zom();
}


void randzombieplace::StopThread()
{
    thread->stopped=true;
}

void randzombieplace::on_beginput_clicked()
{
    if(thread) {
        QMessageBox::information(this,"提示","请勿重复开始！");
        return;
    }
    if(iffinishinput)
        StartThread();
    else{
        QMessageBox::information(this,"提示","请点击结束添加后再开始！");
        return;
    }
}

void randzombieplace::StartThread()
{
    ui->stopzombie->setVisible(true);
    ui->pausezombie->setVisible(true);
    ui->totalzombie->setVisible(true);
    ui->currentrate->setVisible(true);
    thread=new ZombieThread;
    thread->type=ui->zombiechoose->currentIndex();
    thread->ratetable=rate_list;
    thread->timetable=time_list;
    thread->col=ui->zombiecol->value()-1;

    connect(thread,&ZombieThread::updateValues,this,[=](int zombiecount,double currentrate){
        if(thread->paused) {
            ui->currentrate->setText(QString("已暂停出怪！"));return;
        }
        ui->totalzombie->setText(QString("当前每行一共出怪：%1个").arg(zombiecount));
        ui->currentrate->setText(QString("当前出怪速率：%1s").arg(currentrate));
    });
    thread->start();
}

void randzombieplace::stopThread()
{
    if (thread) {
        StopThread();
        thread->exit();
        thread->wait(); // 等待线程结束
        //thread->ratetable.pop_back();
        //thread->timetable.pop_back();
        delete thread; // 释放线程对象
        thread = nullptr;
        ui->totalzombie->setText(QString("终止放置"));
        ui->currentrate->setText(QString("再次点击开始可重新开始"));
        ui->stopzombie->setVisible(false);
        ui->pausezombie->setVisible(false);
        ui->addfinish->setVisible(true);
        ui->deletedata->setVisible(true);
        ui->editdatalist->setVisible(true);
        this->iffinishinput=false;
    }
}


void randzombieplace::autospicythread()
{
    if(ui->autospicy->isChecked())
    {
        spicythread=new SpiceThread;
        spicythread->start();
    }
    else
    {
        spicythread->stopped=true;
        spicythread->exit();
        spicythread->wait();
        delete spicythread;
        spicythread=nullptr;
    }
}

void randzombieplace::on_startmower_clicked()
{
    Startmower(ui->mowerrow->value());
}


void randzombieplace::on_clearmower_clicked()
{
    Clearmower(ui->mowerrow->value());
}


void randzombieplace::on_resumemower_clicked()
{
    Resumemower();
}


void randzombieplace::on_killallzombies_clicked()
{
    KillAllZombies();
}

void randzombieplace::safecheckstop()
{
    if(safecheck){
        if(safecheck->status==1){
            QMessageBox msgBox;
            msgBox.setWindowTitle("危险！");
            msgBox.setText("检测到游戏退出，请确认游戏正常运行!\n如果不想继续请点击否，若继续需要保证游戏运行！");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int ret = msgBox.exec();
            bool userChoice = (ret == QMessageBox::Yes);
            if(!userChoice){
                if(thread){
                    StopThread();
                    thread->exit();
                    thread->wait(); // 等待线程结束
                    delete thread; // 释放线程对象
                    thread = nullptr;
                }
                if(spicythread){
                    ui->autospicy->setCheckState(Qt::Unchecked);
                }
                if(safecheck){
                    safecheck->status=4;
                    safecheck->exit();
                    safecheck->wait();
                    delete safecheck;
                    safecheck=nullptr;
                }
                this->close();
            }
        }
        if(safecheck->status==2){
            if(thread){
                stopThread();
            }
            QMessageBox msgBox;
            msgBox.setWindowTitle("危险！");
            msgBox.setText("检测到游戏未进入关卡，请进入关卡再放置僵尸!\n点击否退出，点击是将重置出怪");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int ret = msgBox.exec();
            bool userChoice = (ret == QMessageBox::Yes);
            if(!userChoice){
                this->close();
            }
        }
        if(safecheck->status==3){
            if(thread){
                if(thread){
                    StopThread();
                    thread->exit();
                    thread->wait(); // 等待线程结束
                    delete thread; // 释放线程对象
                    thread = nullptr;
                }
                if(spicythread){
                    ui->autospicy->setCheckState(Qt::Unchecked);
                }
                if(safecheck){
                    safecheck->status=4;
                    safecheck->exit();
                    safecheck->wait();
                    delete safecheck;
                    safecheck=nullptr;
                }
                stopThread();
                thread->exit();
                thread->wait();
            }
            QMessageBox msgBox;
            msgBox.setWindowTitle("危险！");
            msgBox.setText("检测到已放置僵尸即将到达内存上限,请重新开始游戏，否则将引发游戏崩溃！\n点击否退出，点击是将重置出怪");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int ret = msgBox.exec();
            bool userChoice = (ret == QMessageBox::Yes);
            if(!userChoice){
                if(thread){
                    StopThread();
                    thread->exit();
                    thread->wait(); // 等待线程结束
                    delete thread; // 释放线程对象
                    thread = nullptr;
                }
                if(spicythread){
                    ui->autospicy->setCheckState(Qt::Unchecked);
                }
                if(safecheck){
                    safecheck->status=4;
                    safecheck->exit();
                    safecheck->wait();
                    delete safecheck;
                    safecheck=nullptr;
                }
                this->close();
            }
        }
        if(safecheck->status==4) return;
        safecheck->start();
    }
}


void randzombieplace::on_editdatalist_clicked()
{
    bool hasSelection = ui->timeandrate_table->selectedItems().isEmpty();
    if(hasSelection) return;
    QTableWidgetItem* item = ui->timeandrate_table->currentItem();
    ui->timeandrate_table->closePersistentEditor(item);
    int curcol=ui->timeandrate_table->currentColumn();
    if(curcol==0) time_list[ui->timeandrate_table->currentRow()]=item->text().toDouble();
    else rate_list[ui->timeandrate_table->currentRow()+1]=item->text().toDouble();
    vector<pair<double,double>> pairlist;
    for (size_t i = 0; i < time_list.size(); i++) {
        pairlist.push_back(std::make_pair(time_list[i], rate_list[i+1]));
    }
    sort(pairlist.begin(), pairlist.end());
    for(size_t i=0;i< pairlist.size();i++){
        time_list[i]=pairlist[i].first;
        rate_list[i+1]=pairlist[i].second;
    }
    for(size_t i = 0; i < time_list.size(); i++)
    {
        ui->timeandrate_table->setItem(i,0,new QTableWidgetItem(QString("%1").arg(QString::number(this->time_list[i], 'f', 2))));
        ui->timeandrate_table->setItem(i,1,new QTableWidgetItem(QString("%1").arg(QString::number(this->rate_list[i+1], 'f', 2))));
    }
}

