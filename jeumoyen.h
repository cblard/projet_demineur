#ifndef JEUMOYEN_H
#define JEUMOYEN_H

#include <QDialog>
#include <vector>
#include <QPushButton>
#include <QAction>
#include <QWidget>
#include <QObject>

using namespace std;

namespace Ui {
class jeuMoyen;
}

class jeuMoyen : public QObject
{
    Q_OBJECT

public:
    explicit jeuMoyen();
    jeuMoyen(bool check);
    void creationGrille();
    void affichageGrille(int check);
    ~jeuMoyen();
    //jeuMoyen(const jeuMoyen &);
    jeuMoyen& operator=(const jeuMoyen &jeuMoy);
    vector<vector<char>> getSolution();

    vector<vector<char>> solution;
    vector<vector<int>> mines;
    QWidget *window= new QWidget;
    QWidget *windowSolution = new QWidget;
    QPushButton *boutonAbandon=new QPushButton("Abandonner");
    QPushButton *boutonAide=new QPushButton("Besoin d'aide ?");
    QAction *abandonner=new QAction("Abandonner");
public slots:
    void abandon();
private:
    Ui::jeuMoyen *ui;
signals:
    void triggered();
    void released();
    void clicked();
};

#endif // JEUMOYEN_H
