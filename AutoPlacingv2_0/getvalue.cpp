#include "getvalue.h"
#include "ui_getvalue.h"

GetValue::GetValue(int getnum,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GetValue)
{
    num=getnum;
    ui->setupUi(this);
    int count=0;
    int avr=100/num;
    for(int i=0;i<num;i++){
        QSpinBox* newspin=new QSpinBox;
        newspin->setMaximum(99);
        newspin->setMinimum(1);
        newspin->setSingleStep(1);
        newspin->setValue(avr);
        count+=avr;
        ui->verticalLayout->addWidget(newspin);
        boxes.push_back(newspin);
        values.push_back(avr);
    }
    if(count!=100){
        boxes.back()->setValue(100-(avr)*(num-1));
        values.back()=100-(avr)*(num-1);
    }
}

GetValue::~GetValue()
{
    delete ui;
}

void GetValue::on_pushButton_clicked()
{
    int count=0;

    for(int i=0;i<boxes.size();i++){
        count+=boxes[i]->value();
        values[i]=boxes[i]->value();
    }
    if(count!=100){
        ui->lineEdit->setText("和不为100，请检查数据");
        return;
    }
    emit updatevalue(values);
    ui->lineEdit->setText("设置完成，你可以关闭本窗口了");
}

void GetValue::closeEvent(QCloseEvent *event)
{
    emit updatevalue(values);
    QWidget::closeEvent(event);
}
