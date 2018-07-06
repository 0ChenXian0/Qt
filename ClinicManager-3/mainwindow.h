#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"patient.h"
#include"doctor.h"
#include"bill.h"
#include"addpatient.h"
#include"addoctor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum Operate
    {
        Adds ,
        Edits
    };

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initUI();//显示函数

    void createCornerVtn();//角落创建按钮

    void buttonJmp();

    void initAddPat();

private  slots:
    void buttonTo();

    void onBtnAdo();

//    void onBtnEdit();

//    void onBtnDel();

    void onBtnRefresh();

    void PxecAddSql(QVariantMap stuInfo);

    void PxecEditSql(QVariantMap stuInfo);

//    void ExecDelSql(QString id);

private:
    Ui::MainWindow *ui;

    patient *m_ppatient;

    doctor *m_pdoctor;

    bill *m_pbill;

    AddPatient *m_PAddPatient;

    addoctor *m_paddoctor;

    Operate m_operate;


};

#endif // MAINWINDOW_H
