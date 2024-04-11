#ifndef VERSIONINFO_H
#define VERSIONINFO_H

#include <QWidget>

namespace Ui {
class versioninfo;
}

class versioninfo : public QWidget
{
    Q_OBJECT

public:
    explicit versioninfo(QWidget *parent = nullptr);
    ~versioninfo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::versioninfo *ui;
};

#endif // VERSIONINFO_H
