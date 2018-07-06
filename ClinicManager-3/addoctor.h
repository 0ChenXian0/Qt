#ifndef ADDOCTOR_H
#define ADDOCTOR_H

#include <QDialog>

namespace Ui {
class addoctor;
}

class addoctor : public QDialog
{
    Q_OBJECT

public:
    explicit addoctor(QWidget *parent = 0);
    ~addoctor();

private:

    void clearData();


private slots:
    void on_Dbutton_accepted();

//    void on_buttonBox_rejected();

//signals:
//    void signalStuInf(QVariantMap stuInfo);

private:
    Ui::addoctor *ui;
};

#endif // ADDOCTOR_H
