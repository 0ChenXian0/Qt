#ifndef PATIENT_H
#define PATIENT_H

#include <QWidget>

namespace Ui {
class patient;
}

class patient : public QWidget
{
    Q_OBJECT

public:
    explicit patient(QWidget *parent = 0);
    ~patient();

private slots:
    void on_pushButton_clicked();

private:
    Ui::patient *ui;
};

#endif // PATIENT_H
