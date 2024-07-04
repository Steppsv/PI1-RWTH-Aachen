#ifndef DIALOGADDCITY_H
#define DIALOGADDCITY_H

#include <QDialog>
#include "city.h"

namespace Ui {
class DialogAddCity;
}

class DialogAddCity : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddCity(QWidget *parent = nullptr);
    ~DialogAddCity();

    City* City_erstellen() const;


private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogAddCity *ui;
};

#endif // DIALOGADDCITY_H
