#ifndef BILL_H
#define BILL_H

#include <QWidget>

namespace Ui {
class bill;
}

class bill : public QWidget
{
    Q_OBJECT

public:
    explicit bill(QWidget *parent = 0);
    ~bill();

private:
    Ui::bill *ui;
};

#endif // BILL_H
