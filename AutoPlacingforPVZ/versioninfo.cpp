#include "versioninfo.h"
#include "ui_versioninfo.h"
extern bool Verflag;
versioninfo::versioninfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::versioninfo)
{
    ui->setupUi(this);
}

versioninfo::~versioninfo()
{
    delete ui;
}


void versioninfo::closeEvent(QCloseEvent *event)
{
    Verflag=false;
    QWidget::closeEvent(event);
}

void versioninfo::on_pushButton_clicked()
{
    this->close();
}

