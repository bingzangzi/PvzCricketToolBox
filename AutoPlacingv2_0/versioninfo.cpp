#include "versioninfo.h"
#include "ui_versioninfo.h"

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

void versioninfo::on_pushButton_clicked()
{
    this->close();
}

