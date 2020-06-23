#include "mainwindow.h"
#include "dialogdifficile.h"
#include "ui_dialogdifficile.h"
#include "jeudifficile.h"
#include <QDebug>

dialogDifficile::dialogDifficile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogDifficile)
{
    ui->setupUi(this);
}

dialogDifficile::dialogDifficile(vector<vector<char>> solution, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogDifficile)
{
    this->solution=solution;
    jeuDif.solution=solution;
    ui->setupUi(this);
}


dialogDifficile::~dialogDifficile()
{
    delete ui;
}

void dialogDifficile::on_pushButton_clicked()
{
    jeuDif.abandon();
}
