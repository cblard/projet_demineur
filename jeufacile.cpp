#include "jeufacile.h"
#include "ui_jeufacile.h"
#include <QtGui>
#include <QLayout>
#include <QPixmap>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QTableWidget>
#include "clickablelabel.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define DEBUTANT 0
#define MOYEN 1
#define EXPERT 2
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

// Coup de l'utilisateur
void jouer(int *x, int *y)
{
    printf("Entrez votre coup, (ligne, colonne) -> ");
    scanf("%d %d", x, y);
    return;
}

// Affiche le plateau
void afficherPlateau(char plateau[][TAILLEMAX])
{
    int i, j;
    printf ("    ");

    for (i=0; i<TAILLE; i++)
        printf ("%d ", i);

    printf ("\n\n");

    for (i=0; i<TAILLE; i++)
    {
        printf ("%d   ", i);

        for (j=0; j<TAILLE; j++)
            printf ("%c ", plateau[i][j]);
        printf ("\n");
    }
    return;
}

// Compteur de mines dans les cases adjacentes
int compteurMinesAdjacentes(int ligne, int col, int mines[][2],
char solution[][TAILLEMAX])
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

// Fonction récursive de jeu
bool jouerUtil(char plateau[][TAILLEMAX], char solution[][TAILLEMAX],
               int mines[][2], int ligne, int col, int *caseGauche)
{

    // Si la case est déjà découverte
    if (plateau[ligne][col] != '-')
        return (false);

    int i, j;

    // Si la case choisie est une mine
    if (solution[ligne][col] == '*')
    {
        plateau[ligne][col]='*';

        for (i=0; i<MINES; i++)
            plateau[mines[i][0]][mines[i][1]]='*';

        afficherPlateau (plateau);
        printf ("\nVous avez perdu !\n");
        return (true) ;
    }

    else
    {
        // Calcul du nombre de mines adjacentes + affichage de ce nombre
        int compteur = compteurMinesAdjacentes(ligne, col, mines, solution);
        (*caseGauche)--;

        plateau[ligne][col] = compteur + '0';

        if (!compteur)
        {
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

            // NORD ------------

            // Fonction effectuée seulement si la case est "valide"
            if (estValide (ligne-1, col) == true)
            {
                if (estUneMine (ligne-1, col, solution) == false)
                    jouerUtil(plateau, solution, mines, ligne-1, col, caseGauche);
            }

            // SUD -------------

            // Fonction effectuée seulement si la case est "valide"
            if (estValide (ligne+1, col) == true)
            {
                if (estUneMine (ligne+1, col, solution) == false)
                    jouerUtil(plateau, solution, mines, ligne+1, col, caseGauche);
            }

            // EST -------------

            // Fonction effectuée seulement si la case est "valide"
            if (estValide (ligne, col+1) == true)
            {
                if (estUneMine (ligne, col+1, solution) == false)
                    jouerUtil(plateau, solution, mines, ligne, col+1, caseGauche);
            }

            // OUEST -----------

            // Fonction effectuée seulement si la case est "valide"
            if (estValide (ligne, col-1) == true)
            {
                if (estUneMine (ligne, col-1, solution) == false)
                    jouerUtil(plateau, solution, mines, ligne, col-1, caseGauche);
            }

            // NORD-EST -------

            // Fonction effectuée seulement si la case est "valide"
            if (estValide (ligne-1, col+1) == true)
            {
                if (estUneMine (ligne-1, col+1, solution) == false)
                    jouerUtil(plateau, solution, mines, ligne-1, col+1, caseGauche);
            }

            // NORD-OUEST -----

            // Fonction effectuée seulement si la case est "valide"
            if (estValide (ligne-1, col-1) == true)
            {
                if (estUneMine (ligne-1, col-1, solution) == false)
                    jouerUtil(plateau, solution, mines, ligne-1, col-1, caseGauche);
            }

            // SUD-EST --------

            // Fonction effectuée seulement si la case est "valide"
            if (estValide (ligne+1, col+1) == true)
            {
                if (estUneMine (ligne+1, col+1, solution) == false)
                    jouerUtil(plateau, solution, mines, ligne+1, col+1, caseGauche);
            }

            // SUD-OUEST ------

            // Fonction effectuée seulement si la case est "valide"
            if (estValide (ligne+1, col-1) == true)
            {
                if (estUneMine (ligne+1, col-1, solution) == false)
                    jouerUtil(plateau, solution, mines, ligne+1, col-1, caseGauche);
            }
        }

        return (false);
    }
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

// Fonction qui initialise le plateau de l'utilisateur
void initialise(char solution[][TAILLEMAX], char plateau[][TAILLEMAX])
{
    // Initialise un nombre aléatoire
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


jeuFacile::jeuFacile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::jeuFacile)
{
    creationGrille();
    QWidget *window= new QWidget;
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
    window->show();
}

jeuFacile::~jeuFacile()
{
    delete ui;
}

void jeuFacile::creationGrille(){
    bool gameOver = false;

    // Création des deux tableaux
    // La solution et le plateau affiché à l'utilisateur
    char solution[TAILLEMAX][TAILLEMAX], plateau[TAILLEMAX][TAILLEMAX];

    int caseGauche = TAILLE * TAILLE - MINES, x, y;
    int mines[MINESMAX][2]; // stores (x,y) coordinates of all mines.

    initialise (solution, plateau);

    // Place les mines aléatoirement
    placeMines (mines, solution);

    vector<vector<int>> mines2(99, vector<int>(2,0));
    for(int i=0;i<99;i++){
        for(int j=0;j<2;j++){
            mines2.at(i).at(j)=mines[i][j];
        }
    }

    vector<vector<char>> sol(25, vector<char>(25,0));
    for(int i=0;i<25;i++){
        for(int j=0;j<25;j++){
            sol.at(i).at(j)=solution[i][j];
        }
    }

    int test;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sol.at(i).at(j)!='*'){
                sol.at(i).at(j)=(char)compteurMinesAdjacentes(i,j,mines,solution);
                test=compteurMinesAdjacentes(i,j,mines,solution);
            }
        }
    }
    this->solution=sol;
    this->mines=mines2;
}
