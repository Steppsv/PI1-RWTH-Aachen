#ifndef DIALOG_DIJKSTRAEIN_H
#define DIALOG_DIJKSTRAEIN_H
#include <QDialog>

namespace Ui {
class Dialog_DijkstraEin;
}

class Dialog_DijkstraEin : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_DijkstraEin(QWidget *parent = nullptr);
    ~Dialog_DijkstraEin();
    QString Get_LC1();
    QString Get_LC2();

private:
    Ui::Dialog_DijkstraEin *ui;
};

#endif // DIALOG_DIJKSTRAEIN_H
