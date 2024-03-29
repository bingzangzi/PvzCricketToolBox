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


private:
    Ui::versioninfo *ui;

protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_pushButton_clicked();
};

#endif // VERSIONINFO_H
