#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {
}

ClickableLabel::ClickableLabel(int abs, int ord, vector<vector<char>> solution, QWidget* parent, Qt::WindowFlags f) : QLabel(parent){
    this->abs=abs;
    this->ord=ord;
    this->solution=solution;
}

ClickableLabel::~ClickableLabel() {}

/*void ClickableLabel::mouse(QMouseEvent *event){
    QPixmap flag(":/demineur/resources/flag.png");
    this->setPixmap(flag.scaled(50,50,Qt::KeepAspectRatio));
    this->update();
}*/

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    comparerCases();
    emit clicked();
}

void ClickableLabel::comparerCases(){
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
        this->setPixmap(bombe.scaled(50,50,Qt::KeepAspectRatio));
        this->update();
    }
    if(solution.at(abs).at(ord)==0){
        this->setPixmap(case0.scaled(50,50,Qt::KeepAspectRatio));
        this->update();
    }
    if(solution.at(abs).at(ord)==1){
        //this->close();
        this->setPixmap(case1.scaled(50,50,Qt::KeepAspectRatio));
        this->update();
    }
    if(solution.at(abs).at(ord)==2){
        this->setPixmap(case2.scaled(50,50,Qt::KeepAspectRatio));
        this->update();
    }
    if(solution.at(abs).at(ord)==3){
        this->setPixmap(case3.scaled(50,50,Qt::KeepAspectRatio));
        this->update();
    }
    if(solution.at(abs).at(ord)==4){
        this->setPixmap(case4.scaled(50,50,Qt::KeepAspectRatio));
        this->update();
    }
    if(solution.at(abs).at(ord)==5){
        this->setPixmap(case5.scaled(50,50,Qt::KeepAspectRatio));
        this->update();
    }
    if(solution.at(abs).at(ord)==6){
        this->setPixmap(case6.scaled(50,50,Qt::KeepAspectRatio));
        this->update();
    }
    if(solution.at(abs).at(ord)==7){
        this->setPixmap(case7.scaled(50,50,Qt::KeepAspectRatio));
        this->update();
    }
    if(solution.at(abs).at(ord)==8){
        this->setPixmap(case8.scaled(50,50,Qt::KeepAspectRatio));
        this->update();
    }
}
