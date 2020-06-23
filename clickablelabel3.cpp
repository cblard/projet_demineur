#include "ClickableLabel3.h"
#include <QMouseEvent>
#include <QMessageBox>

ClickableLabel3::ClickableLabel3(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {
}

ClickableLabel3::ClickableLabel3(int abs, int ord, vector<vector<char>> solution, QWidget* parent, Qt::WindowFlags f) : QLabel(parent){
    this->abs=abs;
    this->ord=ord;
    this->solution=solution;
}

void ClickableLabel3::mousePressEvent(QMouseEvent* event){
    QPixmap flag(":/demineur/resources/flag.png");
    QPixmap caseVide(":/demineur/resources/caseDemineur.png");
    if(event->button()==Qt::RightButton){
        if(checkFlag==false){
            this->setPixmap(flag.scaled(25,25,Qt::KeepAspectRatio));
            this->update();
        }
        if(checkFlag==true){
            this->setPixmap(caseVide.scaled(25,25,Qt::KeepAspectRatio));
            this->update();
        }
        checkFlag=!checkFlag;
    }
    if(event->button()==Qt::LeftButton) comparerCases();
}

ClickableLabel3::~ClickableLabel3() {}

void ClickableLabel3::comparerCases(){
    QPixmap gameover(":/demineur/resources/gameover.png");
    QPixmap bombe(":/demineur/resources/bomb.png");
    QPixmap case0(":/demineur/resources/0.png");
    QPixmap case1(":/demineur/resources/1.png");
    QPixmap case2(":/demineur/resources/2.png");
    QPixmap case3(":/demineur/resources/3.png");
    QPixmap case4(":/demineur/resources/4.png");
    QPixmap case5(":/demineur/resources/5.png");
    QPixmap case6(":/demineur/resources/6.png");
    QPixmap case7(":/demineur/resources/7.png");
    QPixmap case8(":/demineur/resources/8.png");
    if(solution.at(abs).at(ord)=='*'){
        this->setPixmap(bombe.scaled(25,25,Qt::KeepAspectRatio));
        this->update();
        QMessageBox msgBox;
        msgBox.setIconPixmap(gameover.scaled(50,50,Qt::KeepAspectRatio));
        msgBox.setText("      PERDU !");
        msgBox.setWindowTitle("Partie terminée");
        msgBox.setStyleSheet("QLabel{min-width: 100px;}");
        msgBox.exec();
    }
    if(solution.at(abs).at(ord)==0){
        this->setPixmap(case0.scaled(25,25,Qt::KeepAspectRatio));
        this->update();
    }
    if(solution.at(abs).at(ord)==1){
        this->setPixmap(case1.scaled(25,25,Qt::KeepAspectRatio, Qt::SmoothTransformation));
        this->update();
    }
    if(solution.at(abs).at(ord)==2){
        this->setPixmap(case2.scaled(25,25,Qt::KeepAspectRatio));
        this->update();
    }
    if(solution.at(abs).at(ord)==3){
        this->setPixmap(case3.scaled(25,25,Qt::KeepAspectRatio));
        this->update();
    }
    if(solution.at(abs).at(ord)==4){
        this->setPixmap(case4.scaled(25,25,Qt::KeepAspectRatio));
        this->update();
    }
    if(solution.at(abs).at(ord)==5){
        this->setPixmap(case5.scaled(25,25,Qt::KeepAspectRatio));
        this->update();
    }
    if(solution.at(abs).at(ord)==6){
        this->setPixmap(case6.scaled(25,25,Qt::KeepAspectRatio));
        this->update();
    }
    if(solution.at(abs).at(ord)==7){
        this->setPixmap(case7.scaled(25,25,Qt::KeepAspectRatio));
        this->update();
    }
    if(solution.at(abs).at(ord)==8){
        this->setPixmap(case8.scaled(25,25,Qt::KeepAspectRatio));
        this->update();
    }
}
