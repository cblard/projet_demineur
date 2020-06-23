#ifndef JEUPerso_H
#define JEUPerso_H

#include <QDialog>
#include <vector>
#include <QPushButton>
#include <QAction>
#include <QWidget>
#include <QObject>

using namespace std;

namespace Ui {
class jeuPerso;
}

class jeuPerso : public QObject
{
    Q_OBJECT

public:
    explicit jeuPerso(int taille, int nbMines);
    jeuPerso();
    jeuPerso(bool check);
    void creationGrille();
    void affichageGrille(int check);
    ~jeuPerso();
    //jeuPerso(const jeuPerso &);
    jeuPerso& operator=(const jeuPerso &jeuMoy);
    vector<vector<char>> getSolution();
    int taille;
    int nbMines;
    int tailleFenetre;
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
    Ui::jeuPerso *ui;
signals:
    void triggered();
    void released();
    void clicked();
};

#endif // JEUPerso_H
