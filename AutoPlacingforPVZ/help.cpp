#include "help.h"
#include "ui_help.h"
extern bool Helpflag;
help::help(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::help)
{
    ui->setupUi(this);
    on_radioButton_clicked();
    ui->radioButton->setChecked(true);
}

help::~help()
{
    delete ui;
}

void help::closeEvent(QCloseEvent *event)
{
    Helpflag=false;
    QWidget::closeEvent(event);
}
void help::on_pushButton_clicked()
{
    this->close();
}


void help::on_radioButton_clicked()
{
    ui->softinfo->raise();
}


void help::on_radioButton_2_clicked()
{
    ui->mainmenu->raise();
}


void help::on_radioButton_3_clicked()
{
    ui->settting->raise();
}


void help::on_radioButton_4_clicked()
{
    ui->randplant->raise();
}


void help::on_radioButton_5_clicked()
{
    ui->customplant->raise();
}


void help::on_radioButton_6_clicked()
{
    ui->randzombie->raise();
}


void help::on_radioButton_7_clicked()
{
    ui->custmzombie->raise();
}


void help::on_radioButton_8_clicked()
{
    ui->future->raise();
}

