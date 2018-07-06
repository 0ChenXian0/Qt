#ifndef ADDPATIENT_H
#define ADDPATIENT_H
#include<QTextEdit>
#include <QDialog>

namespace Ui {
class AddPatient;
}

class AddPatient : public QDialog
{
    Q_OBJECT

public:
    explicit AddPatient(QWidget *parent = 0);
    ~AddPatient();

    void setEditData(QStringList rowData);

private:
    void InputFrom();

    void clearData();
    QTextEdit *textE;

private slots:
    void on_Pbutton_accepted();

//    void on_buttonBox_rejected();

signals:
    void signalStuInf(QVariantMap stuInfo);

private:
    Ui::AddPatient *ui;
};

#endif // ADDPATIENT_H
