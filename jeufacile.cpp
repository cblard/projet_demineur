#include "jeufacile.h"
#include "ui_jeufacile.h"
#include <QtGui>
#include <QLayout>
#include <QPixmap>
#include <QWidget>
#include <QLineEdit>

jeuFacile::jeuFacile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::jeuFacile)
{
    QWidget *window= new QWidget;
    window->setWindowTitle("Démineur");
    //ui->setupUi(this);
    QGridLayout *layout = new QGridLayout;
    QPixmap caseVide(":/demineur/resources/caseDemineur.png");
    //QLabel *label = new QLabel("test");
    QLineEdit *txtName= new QLineEdit;
    //label->setPixmap(caseVide);
    //layout->addWidget(label,0,1);
    //layout->addWidget(txtName,1,1);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            QLabel *label = new QLabel("test");
            label->setPixmap(caseVide.scaled(50,50,Qt::KeepAspectRatio));
            layout->addWidget(label,i,j);
        }
    }
    window->setLayout(layout);
    window->setFixedSize(500,500);
    window->show();
}

jeuFacile::~jeuFacile()
{
    delete ui;
}
