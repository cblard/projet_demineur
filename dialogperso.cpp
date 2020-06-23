#include "mainwindow.h"
#include "dialogPerso.h"
#include "ui_dialogperso.h"
#include "jeuperso.h"
#include <QDebug>

dialogPerso::dialogPerso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogPerso)
{
    ui->setupUi(this);
}

dialogPerso::dialogPerso(vector<vector<char>> solution, int taille, int mines, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogPerso)
{
    this->solution=solution;
    jeuPers.taille=taille;
    jeuPers.nbMines=mines;
    jeuPers.solution=solution;
    ui->setupUi(this);
}


dialogPerso::~dialogPerso()
{
    delete ui;
}

void dialogPerso::on_pushButton_clicked()
{
    jeuPers.abandon();
}
