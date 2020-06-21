#ifndef JEUDIFFICILE_H
#define JEUDIFFICILE_H

#include <QDialog>
#include <vector>
#include <QPushButton>
#include <QAction>
#include <QWidget>
#include <QObject>

using namespace std;

namespace Ui {
class jeuDifficile;
}

class jeuDifficile : public QObject
{
    Q_OBJECT

public:
    explicit jeuDifficile();
    jeuDifficile(bool check);
    void creationGrille();
    void affichageGrille(int check);
    ~jeuDifficile();
    //jeuDifficile(const jeuDifficile &);
    jeuDifficile& operator=(const jeuDifficile &jeuMoy);
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
    Ui::jeuDifficile *ui;
signals:
    void triggered();
    void released();
    void clicked();
};

#endif // JEUDifficile_H
