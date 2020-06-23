#include "jeuFacile.h"
#include "ui_jeuFacile.h"
#include <QtGui>
#include <QLayout>
#include <QPixmap>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QTableWidget>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>
#include <QDebug>
#include <QDialog>
#include "clickablelabel.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define TAILLEMAX 25
#define MINESMAX 99
#define MOVESIZE 526 // (25 * 25 - 99)

int TAILLE=9 ; // taille du plateau
int MINES=10 ; // nombre de mines du plateau

// Fonction qui vérifie si la cellule en paramètre
// est une case valide ou non
bool estValide(int ligne, int col)
{
    // Retourne "true" si la ligne et la colonne
    // sont bien dans le plateau
    return (ligne >= 0) && (ligne < TAILLE) &&
            (col >= 0) && (col < TAILLE);
}

// Fonction qui vérifie si la cellule en paramètre
// est une bombe ou non
bool estUneMine (int ligne, int col, char plateau[][TAILLEMAX])
{
    if (plateau[ligne][col] == '*')
        return (true);
    else
        return (false);
}

// Compteur de mines dans les cases adjacentes
int compteurMinesAdjacentes(int ligne, int col, int mines[][2],
char solution[][TAILLEMAX])
{
    int compteur = 0;

    /* Compte les mines dans les 8 cases adjacentes
        NO  -  N  -  NE
        O   -  C  -  E
        SO  -  S  -  SE
        C --> Case concernée (ligne, col)
        N --> Nord           (ligne-1, col)
        S --> Sud            (ligne+1, col)
        E --> Est            (ligne, col+1)
        O --> Ouest          (ligne, col-1)
        NE--> Nord-Est       (ligne-1, col+1)
        NO--> Nord-Ouest     (ligne-1, col-1)
        SE--> Sud-Est        (ligne+1, col+1)
        SO--> Sud-Ouest      (ligne+1, col-1)
    */

    // NORD --------------

    // Fonction effectuée seulement si la case est "valide"
    if (estValide (ligne-1, col) == true)
    {
        if (estUneMine (ligne-1, col, solution) == true)
            compteur++;
    }

    // SUD ---------------

    // Fonction effectuée seulement si la case est "valide"
    if (estValide (ligne+1, col) == true)
    {
        if (estUneMine (ligne+1, col, solution) == true)
            compteur++;
    }

    // EST ---------------

    // Fonction effectuée seulement si la case est "valide"
    if (estValide (ligne, col+1) == true)
    {
        if (estUneMine (ligne, col+1, solution) == true)
            compteur++;
    }

    // OUEST ------------

    // Fonction effectuée seulement si la case est "valide"
    if (estValide (ligne, col-1) == true)
    {
        if (estUneMine (ligne, col-1, solution) == true)
            compteur++;
    }

    // NORD-EST ---------

    // Fonction effectuée seulement si la case est "valide"
    if (estValide (ligne-1, col+1) == true)
    {
        if (estUneMine (ligne-1, col+1, solution) == true)
            compteur++;
    }

    // NORD-OUEST ------

    // Fonction effectuée seulement si la case est "valide"
    if (estValide (ligne-1, col-1) == true)
    {
        if (estUneMine (ligne-1, col-1, solution) == true)
            compteur++;
    }

    // SUD-EST ---------

    // Fonction effectuée seulement si la case est "valide"
    if (estValide (ligne+1, col+1) == true)
    {
        if (estUneMine (ligne+1, col+1, solution) == true)
            compteur++;
    }

    // SUD-OUEST ------

    // Fonction effectuée seulement si la case est "valide"
    if (estValide (ligne+1, col-1) == true)
    {
        if (estUneMine (ligne+1, col-1, solution) == true)
            compteur++;
    }

    return (compteur);
}

// Fonction qui place les mines aléatoirement
// au début du jeu
void placeMines(int mines[][2], char solution[][TAILLEMAX])
{
    bool mark[TAILLEMAX*TAILLEMAX];

    memset (mark, false, sizeof (mark));
    // memset : Convertit le deuxième paramètre en unsigned char
    // et le copie dans l'objet pointé par le premier paramètre
    // de taille du 3ème paramètre


    // Boucle tant que toutes les mines n'ont pas été créées
    for (int i=0; i<MINES; )
    {
        int random = rand() % (TAILLE*TAILLE);
        int x = random / TAILLE;
        int y = random % TAILLE;

        // Ajoute une mine dans cette case
        // Si elle n'est pas déjà occupée par une mine

        if (mark[random] == false)
        {
            // Ligne de la mine
            mines[i][0]= x;
            // Colonne de la mine
            mines[i][1] = y;

            // Place la mine
            solution[mines[i][0]][mines[i][1]] = '*';
            mark[random] = true;
            i++;
        }
    }

    return;
}

// Fonction qui initialise2 le plateau de l'utilisateur
void initialise(char solution[][TAILLEMAX], char plateau[][TAILLEMAX])
{
    // initialise2 un nombre aléatoire
    // Pour que les grilles ne se ressemblent pas
    srand(time (NULL));

    // Toutes les cases sont vidées et affichées -
    for (int i=0; i<TAILLE; i++)
    {
        for (int j=0; j<TAILLE; j++)
        {
            plateau[i][j] = solution[i][j] = '-';
        }
    }

    return;
}

// Fonction qui va replacer une mine pour que le premier coup
// de l'utilisateur ne soit pas une mine
void replaceMine (int ligne, int col, char plateau[][TAILLEMAX])
{
    for (int i=0; i<TAILLE; i++)
    {
        for (int j=0; j<TAILLE; j++)
        {
            if (plateau[i][j] != '*')
            {
                plateau[i][j] = '*';
                plateau[ligne][col] = '-';
                return;
            }
        }
    }
    return;
}

void jeuFacile::abandon(){
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
    QWidget* window= new QWidget;
    window->setWindowTitle("Démineur");
    QGridLayout *layout = new QGridLayout;
    QPixmap caseVide(":/demineur/resources/caseDemineur.png");
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            ClickableLabel *label = new ClickableLabel(i,j,this->solution);
            switch(solution[i][j]){
            case '*':   label->setPixmap(bombe.scaled(39,39,Qt::KeepAspectRatio));
                layout->addWidget(label,i,j); break;
            case 0:     label->setPixmap(case0.scaled(39,39,Qt::KeepAspectRatio));
                layout->addWidget(label,i,j); break;
            case 1:     label->setPixmap(case1.scaled(39,39,Qt::KeepAspectRatio));
                layout->addWidget(label,i,j); break;
            case 2:     label->setPixmap(case2.scaled(39,39,Qt::KeepAspectRatio));
                layout->addWidget(label,i,j); break;
            case 3:     label->setPixmap(case3.scaled(39,39,Qt::KeepAspectRatio));
                layout->addWidget(label,i,j); break;
            case 4:     label->setPixmap(case4.scaled(39,39,Qt::KeepAspectRatio));
                layout->addWidget(label,i,j); break;
            case 5:     label->setPixmap(case5.scaled(39,39,Qt::KeepAspectRatio));
                layout->addWidget(label,i,j); break;
            case 6:     label->setPixmap(case6.scaled(39,39,Qt::KeepAspectRatio));
                layout->addWidget(label,i,j); break;
            case 7:     label->setPixmap(case7.scaled(39,39,Qt::KeepAspectRatio));
                layout->addWidget(label,i,j); break;
            case 8:     label->setPixmap(case8.scaled(39,39,Qt::KeepAspectRatio));
                layout->addWidget(label,i,j); break;
            }
        }
    }
    window->setLayout(layout);
    window->setFixedSize(500,500);
    window->show();
}

jeuFacile::jeuFacile(bool check){
    //creationGrille();
    windowSolution= new QWidget;
    windowSolution->setWindowTitle("Démineur");
    QGridLayout *layout = new QGridLayout;
    QPixmap caseVide(":/demineur/resources/caseDemineur.png");
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            ClickableLabel *label = new ClickableLabel(i,j,this->solution);
            label->setPixmap(caseVide.scaled(39,39,Qt::KeepAspectRatio));
            layout->addWidget(label,i,j);
        }
    }
    windowSolution->setLayout(layout);
    windowSolution->setFixedSize(1000,700);
    window->close();
    windowSolution->show();
}

jeuFacile::jeuFacile(): ui(new Ui::jeuFacile)
{
    creationGrille();
}

jeuFacile::~jeuFacile()
{
    delete ui;
}

vector<vector<char>> jeuFacile::getSolution(){
    return solution;
}

void jeuFacile::affichageGrille(int check){
    window->setWindowTitle("Démineur");
    QGridLayout *layout = new QGridLayout;
    QPixmap caseVide(":/demineur/resources/caseDemineur.png");
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            ClickableLabel *label = new ClickableLabel(i,j,this->solution);
            label->setPixmap(caseVide.scaled(50,50,Qt::KeepAspectRatio));
            layout->addWidget(label,i,j);
        }
    }
    window->setLayout(layout);
    window->setFixedSize(500,500);
    if(check==1) window->show();
}

void jeuFacile::creationGrille(){
    // Création des deux tableaux
    // La solution et le plateau affiché à l'utilisateur
    char solution[TAILLEMAX][TAILLEMAX], plateau[TAILLEMAX][TAILLEMAX];
    int mines[MINESMAX][2]; // stores (x,y) coordinates of all mines.

    initialise (solution, plateau);

    // Place les mines aléatoirement
    placeMines (mines, solution);

    vector<vector<int>> MINES(99, vector<int>(2,0));
    for(int i=0;i<99;i++){
        for(int j=0;j<2;j++){
            MINES.at(i).at(j)=mines[i][j];
        }
    }

    vector<vector<char>> sol(10, vector<char>(10,0));
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            sol.at(i).at(j)=solution[i][j];
        }
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sol.at(i).at(j)!='*'){
                sol.at(i).at(j)=(char)compteurMinesAdjacentes(i,j,mines,solution);
            }
        }
    }
    this->solution=sol;
    this->mines=MINES;
}

jeuFacile& jeuFacile::operator=(const jeuFacile &jeuMoy){
    solution=jeuMoy.solution;
    mines=jeuMoy.mines;
    window=jeuMoy.window;
    windowSolution=jeuMoy.windowSolution;
    boutonAbandon=jeuMoy.boutonAbandon;
    boutonAide=jeuMoy.boutonAide;
    abandonner=jeuMoy.abandonner;
}
