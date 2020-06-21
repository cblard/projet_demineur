#ifndef JEUFACILE_H
#define JEUFACILE_H

#include <QDialog>
#include <vector>
#include <QPushButton>
#include <QAction>
#include <QWidget>
#include <QObject>

using namespace std;

namespace Ui {
class jeuFacile;
}

class jeuFacile : public QObject
{
    Q_OBJECT

public:
    explicit jeuFacile();
    jeuFacile(bool check);
    void creationGrille();
    void affichageGrille(int check);
    ~jeuFacile();
    //jeuFacile(const jeuFacile &);
    jeuFacile& operator=(const jeuFacile &jeuMoy);
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
    Ui::jeuFacile *ui;
signals:
    void triggered();
    void released();
    void clicked();
};

#endif // JEUFACILE_H
