#ifndef GETVALUE_H
#define GETVALUE_H

#include <QWidget>
#include <QSpinBox>
#include <vector>
#include <QDialog>
namespace Ui {
class GetValue;
}

class GetValue : public QWidget
{
    Q_OBJECT

public:
    explicit GetValue(int,QWidget *parent = nullptr);
    ~GetValue();
    int num;
    std::vector<QSpinBox*>boxes;
    std::vector<int>values;
signals:
    void updatevalue(std::vector<int>);
private slots:
    void on_pushButton_clicked();
    void closeEvent(QCloseEvent *event);

private:
    Ui::GetValue *ui;
};

#endif // GETVALUE_H
