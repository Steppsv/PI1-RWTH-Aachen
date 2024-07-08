#ifndef DIALOGADDSTREET_H
#define DIALOGADDSTREET_H

#include <QDialog>
#include "Street.h"
#include "map.h"

namespace Ui {
class DialogAddStreet;
}

class DialogAddStreet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddStreet(QWidget *parent = nullptr);
    ~DialogAddStreet();
    Street* Street_erstellen(const AbstractMap &map) const;

private:
    Ui::DialogAddStreet *ui;
};

#endif // DIALOGADDSTREET_H
