#include "jeu.h"
#include "ui_jeu.h"

jeu::jeu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::jeu)
{
    ui->setupUi(this);
}

jeu::~jeu()
{
    delete ui;
}
