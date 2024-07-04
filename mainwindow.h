#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QMainWindow>
#include "map.h"
#include "mapio.h"
#include "mapionrw.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_teste_was_clicked();

    void on_lineEdit_teste_was_editingFinished();

    void on_graphicsView_customContextMenuRequested(const QPoint &pos);

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_pushButton_DrowCity_clicked();

    void on_pushButton_testMap_clicked();

    void on_pushButton_testStreat_clicked();

    void on_pushButton_TestaddStreet_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_addCity_clicked();

    void on_pushButton_FillMap_clicked();

    void on_pushButton_AbstractMap_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    map map1;
    MapIo* mapio1;
    QGraphicsView *view;
    QGraphicsScene *scene;

protected:

};
#endif // MAINWINDOW_H
