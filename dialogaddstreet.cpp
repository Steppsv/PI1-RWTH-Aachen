#include "dialogaddstreet.h"
#include "ui_dialogaddstreet.h"

DialogAddStreet::DialogAddStreet(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAddStreet)
{
    ui->setupUi(this);
}

DialogAddStreet::~DialogAddStreet()
{
    delete ui;
}

Street* DialogAddStreet::Street_erstellen(const AbstractMap &map) const
{
    QString S1 = ui->lineEdit_S1->text();
    QString S2 = ui->lineEdit_S2->text();
    qDebug() << "Creating street from:" << S1 << " to " << S2;
    return new Street(map.findCity(S1),map.findCity(S2));
}
