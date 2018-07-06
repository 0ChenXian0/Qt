#ifndef DOCTOR_H
#define DOCTOR_H

#include <QWidget>

namespace Ui {
class doctor;
}

class doctor : public QWidget
{
    Q_OBJECT

public:
    explicit doctor(QWidget *parent = 0);
    ~doctor();

private:
    Ui::doctor *ui;
};

#endif // DOCTOR_H
