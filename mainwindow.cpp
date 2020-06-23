#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jeufacile.h"
#include "jeumoyen.h"
#include "jeudifficile.h"
#include "jeuperso.h"
#include "dialogfacile.h"
#include "dialogmoyen.h"
#include "dialogdifficile.h"
#include "dialogperso.h"
#include <QLineEdit>

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
    dialogFacile dialogFac(jeuFac.solution);
    dialogFac.exec();
}

void MainWindow::on_moyen_clicked()
{
    this->close();
    jeuMoyen jeuMoy;
    jeuMoy.affichageGrille(1);
    dialogMoyen dialogMoy(jeuMoy.solution);
    dialogMoy.exec();
}

void MainWindow::on_difficile_clicked()
{
    this->close();
    jeuDifficile jeuDif;
    jeuDif.affichageGrille(1);
    dialogDifficile dialogDif(jeuDif.solution);
    dialogDif.exec();

}

void MainWindow::on_perso_clicked()
{
    int taille=ui->taille->toPlainText().toInt();
    int mines=ui->nbMines->toPlainText().toInt();
    if(taille>0 && taille<24 && mines>0 && mines<99 && mines<taille*taille){
        this->close();
        jeuPerso jeuPers(taille, mines);
        jeuPers.affichageGrille(1);
        dialogPerso dialogPers(jeuPers.solution, taille, mines);
        dialogPers.exec();
    }
}
