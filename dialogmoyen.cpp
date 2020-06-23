#include "mainwindow.h"
#include "dialogmoyen.h"
#include "ui_dialogmoyen.h"
#include "jeumoyen.h"
#include <QDebug>

dialogMoyen::dialogMoyen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogMoyen)
{
    ui->setupUi(this);
}

dialogMoyen::dialogMoyen(vector<vector<char>> solution, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogMoyen)
{
    this->solution=solution;
    jeuMoy.solution=solution;
    ui->setupUi(this);
}


dialogMoyen::~dialogMoyen()
{
    delete ui;
}

void dialogMoyen::on_pushButton_clicked()
{
    jeuMoy.abandon();
}
