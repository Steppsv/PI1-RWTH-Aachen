#include "dialog_dijkstraein.h"
#include "ui_dialog_dijkstraein.h"
Dialog_DijkstraEin::Dialog_DijkstraEin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_DijkstraEin)
{
    ui->setupUi(this);
}

Dialog_DijkstraEin::~Dialog_DijkstraEin()
{
    delete ui;
}

QString Dialog_DijkstraEin::Get_LC1()
{
    QString name = ui->lineEdit_C1->text();
    return name;
}
QString Dialog_DijkstraEin::Get_LC2()
{
    return ui->lineEdit_C2->text();
}
