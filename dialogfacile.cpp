#include "mainwindow.h"
#include "dialogfacile.h"
#include "ui_dialogfacile.h"
#include "jeufacile.h"
#include <QDebug>

dialogFacile::dialogFacile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogFacile)
{
    ui->setupUi(this);
}

dialogFacile::dialogFacile(vector<vector<char>> solution, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogFacile)
{
    this->solution=solution;
    jeuFac.solution=solution;
    ui->setupUi(this);
}


dialogFacile::~dialogFacile()
{
    delete ui;
}

void dialogFacile::on_pushButton_clicked()
{
    jeuFac.abandon();
}
