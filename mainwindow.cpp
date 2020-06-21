#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jeufacile.h"
#include "jeumoyen.h"
#include "jeudifficile.h"
#include "dialogmoyen.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(jeuMoyen jeuMoyen, QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_facile_clicked()
{
    this->close();
    class jeuFacile jeuFac;
    jeuFac.affichageGrille(1);
}

void MainWindow::on_moyen_clicked()
{
    this->close();
    class jeuMoyen jeuMoy;
    jeuMoy.affichageGrille(1);
    class dialogMoyen dialogMoy(jeuMoy.solution);
    dialogMoy.exec();
}

void MainWindow::on_difficile_clicked()
{
    this->close();
    class jeuDifficile jeuDif;
    jeuDif.affichageGrille(1);
}
