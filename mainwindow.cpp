#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jeu.h"
#include "jeufacile.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
}

