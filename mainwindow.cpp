#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "city.h"
#include "street.h"
#include "map.h"
#include "dialogaddcity.h"
#include "dialog_dijkstraein.h"
#include "dijkstra.h"
#include <QString>
#include <QDebug>
#include <QRandomGenerator>
#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
//#include <cstdlib>
#include <QFileDialog>
#include <QWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,mapio1(new MapIoNrw)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, 500, 500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_teste_was_clicked()
{
    QString str1= "Test";
    qDebug() << str1;

    scene->addRect( QRandomGenerator::global()->bounded(256)/2.56,QRandomGenerator::global()->bounded(256)/2.56,QRandomGenerator::global()->bounded(256)/2.56,QRandomGenerator::global()->bounded(256)/2.56,QPen(Qt::magenta),QBrush(Qt::red, Qt::SolidPattern));

}


void MainWindow::on_lineEdit_teste_was_editingFinished()
{
    QString str1= ui->lineEdit_teste_was->text();
    int Zahl;
    bool istZahl;
    Zahl = str1.toInt(&istZahl);
    if(istZahl){
        qDebug() << Zahl+4;
    } else {
        qDebug() << str1;
    }
}

// void MainWindow::QGraphicsScene()
// {
//     QGraphicsView view;
//     QGraphicsScene scene;
// }

void MainWindow::on_graphicsView_customContextMenuRequested(const QPoint &pos)
{

}


void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    scene->clear();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgAbout;

    msgAbout.about(this, "info","Subscribe my instagram");
}


void MainWindow::on_pushButton_DrowCity_clicked()
{
    City Cal("California", 100, 100);
    City Man("Mancheten", 200, 100);
    Cal.draw(*scene);
    Man.draw(*scene);

}


void MainWindow::on_pushButton_testMap_clicked()
{
    City Cal("California", 100, 100);
    City Man("Mancheten", 200, 100);
    map1.addCity(&Cal);
    map1.addCity(&Man);
    map1.draw(scene);
}


void MainWindow::on_pushButton_testStreat_clicked()
{
    City Cal("California", 100, 100);
    City Man("Mancheten", 200, 100);
    map1.addCity(&Cal);
    map1.addCity(&Man);
    map1.draw(scene);
    Street str1(&Cal,&Man);
    str1.draw(*scene);
}


void MainWindow::on_pushButton_TestaddStreet_clicked()
{
    City Cal("California", 100, 100);
    City Man("Mancheten", 200, 100);
    Street str1(&Cal,&Man);

    if( map1.addStreet(&str1) )
        str1.draw(*scene);

    map1.addCity(&Cal);
    map1.addCity(&Man);
    map1.draw(scene);

    if( map1.addStreet(&str1) )
        str1.draw(*scene);

}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1)
    {
        ui->pushButton_teste_was->hide();
        ui->pushButton_DrowCity->hide();
        ui->pushButton_testMap->hide();
        ui->pushButton_testStreat->hide();
        ui->pushButton_TestaddStreet->hide();
        ui->pushButton_AbstractMap->hide();

    }
    else
    {
        ui->pushButton_teste_was->show();
        ui->pushButton_DrowCity->show();
        ui->pushButton_testMap->show();
        ui->pushButton_testStreat->show();
        ui->pushButton_TestaddStreet->show();
        ui->pushButton_AbstractMap->show();
    }
}


void MainWindow::on_pushButton_addCity_clicked()
{
    DialogAddCity dialog(this);
    if(dialog.exec() == QDialog::Accepted)
    {
        qDebug() << "Dialog accepted! ";
        City* neu_city = dialog.City_erstellen();
        if(neu_city)
        {
            map1.addCity(neu_city);
            neu_city->draw(*scene);
        }
    }
}

void MainWindow::on_pushButton_FillMap_clicked()
{
    mapio1->fillMap(map1);
    map1.draw(scene);
}


void MainWindow::on_pushButton_AbstractMap_clicked()
{
    map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map1.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}



void MainWindow::on_pushButton_clicked()
{
    Dialog_DijkstraEin dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        if (Dijkstra::search(map1, dialog.Get_LC1(), dialog.Get_LC2()).isEmpty())
        {
            qDebug() << "There is no street, that can connect this cities!";
        }
        else
        {
            qDebug() << "Way was found:";
            // Draw the path in red
            for (Street* street : Dijkstra::search(map1, dialog.Get_LC1(), dialog.Get_LC2()))
            {
                street->drawRed(*scene);
            }
        }

    }
    else
    {
        qDebug() << "Dialog rejected";
    }
}

