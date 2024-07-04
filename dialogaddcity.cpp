#include "dialogaddcity.h"
#include "ui_dialogaddcity.h"

DialogAddCity::DialogAddCity(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAddCity)
{
    ui->setupUi(this);
}

DialogAddCity::~DialogAddCity()
{
    delete ui;
}

City* DialogAddCity::City_erstellen() const
{
    QString name = ui->lineEdit_cityname->text();
    int X = ui->lineEdit_coordX->text().toInt();
    int Y = ui->lineEdit_coordY->text().toInt();
    qDebug() << "Creating city with name:" << name << ", " << X << " " << Y;
    return new City(name,X,Y);
}




void DialogAddCity::on_buttonBox_accepted()
{

}

