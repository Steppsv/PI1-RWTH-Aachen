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
    bool ok1, ok2, ok3 = 1;
    int nameTest = 0;
    QString name = ui->lineEdit_cityname->text();

    for( int i = 0; i<name.size(); i++)
    {
        if( name[i] >= '0' && name[i] <= '9')
        {
            qDebug() << "Falsches City name";
            ok3 = 0;
        }

    }

    int X = ui->lineEdit_coordX->text().toInt(&ok1);
    int Y = ui->lineEdit_coordY->text().toInt(&ok2);
    if( !ok1 || !ok2 )
        qDebug() << "Falsche koordinate";
    if(!ok1+!ok2+!ok3)
    {                     // If ok1 or ok2 not ok, also 0 => return 6666 und restart window
        return new City(name, 6666, Y);
    }
    qDebug() << "Creating city with name:" << name << ", " << X << " " << Y;
    return new City(name,X,Y);
}




void DialogAddCity::on_buttonBox_accepted()
{

}

