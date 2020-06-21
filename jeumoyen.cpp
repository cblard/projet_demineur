#include "jeumoyen.h"
#include "ui_jeumoyen.h"
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
#include "clickablelabel2.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define TAILLEMAX2 25
#define MINESMAX 99
#define MOVESIZE 526 // (25 * 25 - 99)

int TAILLE2=16 ; // taille du plateau
int MINES2=40 ; // nombre de mines du plateau

// Fonction qui vérifie si la cellule en paramètre
// est une case valide ou non
bool estValide2(int ligne, int col)
{
    // Retourne "true" si la ligne et la colonne
    // sont bien dans le plateau
    return (ligne >= 0) && (ligne < TAILLE2) &&
            (col >= 0) && (col < TAILLE2);
}

// Fonction qui vérifie si la cellule en paramètre
// est une bombe ou non
bool estUneMine2 (int ligne, int col, char plateau[][TAILLEMAX2])
{
    if (plateau[ligne][col] == '*')
        return (true);
    else
        return (false);
}

// Compteur de mines dans les cases adjacentes
int compteurMinesAdjacentes2(int ligne, int col, int mines[][2],
char solution[][TAILLEMAX2])
{

    int i;
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
    if (estValide2 (ligne-1, col) == true)
    {
        if (estUneMine2 (ligne-1, col, solution) == true)
            compteur++;
    }

    // SUD ---------------

    // Fonction effectuée seulement si la case est "valide"
    if (estValide2 (ligne+1, col) == true)
    {
        if (estUneMine2 (ligne+1, col, solution) == true)
            compteur++;
    }

    // EST ---------------

    // Fonction effectuée seulement si la case est "valide"
    if (estValide2 (ligne, col+1) == true)
    {
        if (estUneMine2 (ligne, col+1, solution) == true)
            compteur++;
    }

    // OUEST ------------

    // Fonction effectuée seulement si la case est "valide"
    if (estValide2 (ligne, col-1) == true)
    {
        if (estUneMine2 (ligne, col-1, solution) == true)
            compteur++;
    }

    // NORD-EST ---------

    // Fonction effectuée seulement si la case est "valide"
    if (estValide2 (ligne-1, col+1) == true)
    {
        if (estUneMine2 (ligne-1, col+1, solution) == true)
            compteur++;
    }

    // NORD-OUEST ------

    // Fonction effectuée seulement si la case est "valide"
    if (estValide2 (ligne-1, col-1) == true)
    {
        if (estUneMine2 (ligne-1, col-1, solution) == true)
            compteur++;
    }

    // SUD-EST ---------

    // Fonction effectuée seulement si la case est "valide"
    if (estValide2 (ligne+1, col+1) == true)
    {
        if (estUneMine2 (ligne+1, col+1, solution) == true)
            compteur++;
    }

    // SUD-OUEST ------

    // Fonction effectuée seulement si la case est "valide"
    if (estValide2 (ligne+1, col-1) == true)
    {
        if (estUneMine2 (ligne+1, col-1, solution) == true)
            compteur++;
    }

    return (compteur);
}

// Fonction qui place les mines aléatoirement
// au début du jeu
void placeMines2(int mines[][2], char solution[][TAILLEMAX2])
{
    bool mark[TAILLEMAX2*TAILLEMAX2];

    memset (mark, false, sizeof (mark));
    // memset : Convertit le deuxième paramètre en unsigned char
    // et le copie dans l'objet pointé par le premier paramètre
    // de taille du 3ème paramètre


    // Boucle tant que toutes les mines n'ont pas été créées
    for (int i=0; i<MINES2; )
    {
        int random = rand() % (TAILLE2*TAILLE2);
        int x = random / TAILLE2;
        int y = random % TAILLE2;

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
void initialise2(char solution[][TAILLEMAX2], char plateau[][TAILLEMAX2])
{
    // initialise2 un nombre aléatoire
    // Pour que les grilles ne se ressemblent pas
    srand(time (NULL));

    // Toutes les cases sont vidées et affichées -
    for (int i=0; i<TAILLE2; i++)
    {
        for (int j=0; j<TAILLE2; j++)
        {
            plateau[i][j] = solution[i][j] = '-';
        }
    }

    return;
}

// Fonction qui va replacer une mine pour que le premier coup
// de l'utilisateur ne soit pas une mine
void replaceMine2 (int ligne, int col, char plateau[][TAILLEMAX2])
{
    for (int i=0; i<TAILLE2; i++)
    {
        for (int j=0; j<TAILLE2; j++)
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

void jeuMoyen::abandon(){
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
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            ClickableLabel2 *label = new ClickableLabel2(i,j,this->solution);
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
    window->setFixedSize(700,700);
    window->show();
}

jeuMoyen::jeuMoyen(bool check){
    //creationGrille();
    windowSolution= new QWidget;
    windowSolution->setWindowTitle("Démineur");
    QGridLayout *layout = new QGridLayout;
    QPixmap caseVide(":/demineur/resources/caseDemineur.png");
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            ClickableLabel2 *label = new ClickableLabel2(i,j,this->solution);
            label->setPixmap(caseVide.scaled(39,39,Qt::KeepAspectRatio));
            layout->addWidget(label,i,j);
        }
    }
    windowSolution->setLayout(layout);
    windowSolution->setFixedSize(1000,700);
    window->close();
    windowSolution->show();
}

jeuMoyen::jeuMoyen(): ui(new Ui::jeuMoyen)
{
    creationGrille();
}

jeuMoyen::~jeuMoyen()
{
    delete ui;
}

vector<vector<char>> jeuMoyen::getSolution(){
    return solution;
}

void jeuMoyen::affichageGrille(int check){
    window->setWindowTitle("Démineur");
    QGridLayout *layout = new QGridLayout;
    QPixmap caseVide(":/demineur/resources/caseDemineur.png");
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            ClickableLabel2 *label = new ClickableLabel2(i,j,this->solution);
            label->setPixmap(caseVide.scaled(44,44,Qt::KeepAspectRatio));
            layout->addWidget(label,i,j);
        }
    }
    window->setLayout(layout);
    window->setFixedSize(700,700);
    if(check==1) window->show();
}

void jeuMoyen::creationGrille(){
    bool gameOver = false;

    // Création des deux tableaux
    // La solution et le plateau affiché à l'utilisateur
    char solution[TAILLEMAX2][TAILLEMAX2], plateau[TAILLEMAX2][TAILLEMAX2];

    int caseGauche = TAILLE2 * TAILLE2 - MINES2, x, y;
    int mines[MINESMAX][2]; // stores (x,y) coordinates of all mines.

    initialise2 (solution, plateau);

    // Place les mines aléatoirement
    placeMines2 (mines, solution);

    vector<vector<int>> mines2(99, vector<int>(2,0));
    for(int i=0;i<99;i++){
        for(int j=0;j<2;j++){
            mines2.at(i).at(j)=mines[i][j];
        }
    }

    vector<vector<char>> sol(40, vector<char>(40,0));
    for(int i=0;i<40;i++){
        for(int j=0;j<40;j++){
            sol.at(i).at(j)=solution[i][j];
        }
    }
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            if(sol.at(i).at(j)!='*'){
                sol.at(i).at(j)=(char)compteurMinesAdjacentes2(i,j,mines,solution);
            }
        }
    }
    this->solution=sol;
    this->mines=mines2;
}

jeuMoyen& jeuMoyen::operator=(const jeuMoyen &jeuMoy){
    solution=jeuMoy.solution;
    mines=jeuMoy.mines;
    window=jeuMoy.window;
    windowSolution=jeuMoy.windowSolution;
    boutonAbandon=jeuMoy.boutonAbandon;
    boutonAide=jeuMoy.boutonAide;
    abandonner=jeuMoy.abandonner;
}

