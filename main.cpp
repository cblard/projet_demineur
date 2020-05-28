#include<bits/stdc++.h>
using namespace std;

#define DEBUTANT 0
#define MOYEN 1
#define EXPERT 2
#define TAILLEMAX 25
#define MINESMAX 99
#define MOVESIZE 526 // (25 * 25 - 99)

int TAILLE ; // taille du plateau
int MINES ; // nombre de mines du plateau

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

// Fonction qui affiche les mines
void afficherSolution (char solution[][TAILLEMAX])
{
    printf ("Les mines sont placées ici : \n");
    afficherPlateau (solution);
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

// A Function to play Minesweeper game
void jouer ()
{
    // Création d'une variable qui vérifie si le jeu n'est pas terminé
    bool gameOver = false;

    // Création des deux tableaux
    // La solution et le plateau affiché à l'utilisateur
    char solution[TAILLEMAX][TAILLEMAX], plateau[TAILLEMAX][TAILLEMAX];

    int caseGauche = TAILLE * TAILLE - MINES, x, y;
    int mines[MINESMAX][2]; // stores (x,y) coordinates of all mines.

    initialise (solution, plateau);

    // Place les mines aléatoirement
    placeMines (mines, solution);

    /* Fonction pour afficher la solution
    afficherSolution(solution);*/

    int nombreCoups = 0;
    while (gameOver == false)
     {
        printf ("Plateau : \n");
        afficherPlateau (plateau);
        jouer (&x, &y);

        // Pour garantir que le premier coup n'est pas une mine
        if (nombreCoups == 0)
        {
            if (estUneMine (x, y, solution) == true)
                replaceMine (x, y, solution);
        }
        nombreCoups ++;

        gameOver = jouerUtil (plateau, solution, mines, x, y, &caseGauche);

        if ((gameOver == false) && (caseGauche == 0))
         {
            printf ("\nVous avez gagné !!\n");
            gameOver = true;
         }
    }
    return;
}

// Une fonction pour choisir le niveau de difficulté
void choixNiveauDifficulte ()
{
    /*
    --> DEBUTANT = 9 * 9 et 10 mines
    --> MOYEN = 16 * 16 et 40 mines
    --> EXPERT = 24 * 24 et 99 mines
    */

    int niveau;

    printf ("Choisissez le niveau de difficulté : \n");
    printf ("0 pour DEBUTANT (9 * 9 et 10 mines)\n");
    printf ("1 pour MOYEN (16 * 16 et 40 mines)\n");
    printf ("2 pour EXPERT (24 * 24 et 99 mines)\n");

    scanf ("%d", &niveau);

    if (niveau == DEBUTANT)
    {
        TAILLE = 9;
        MINES = 10;
    }

    if (niveau == MOYEN)
    {
        TAILLE = 16;
        MINES = 40;
    }

    if (niveau == EXPERT)
    {
        TAILLE = 24;
        MINES = 99;
    }

    return;
}

int main()
{
    /* Choisissez le niveau de difficulté :
    --> DEBUTANT = 9 * 9 et 10 mines
    --> MOYEN = 16 * 16 et 40 minutes
    --> EXPERT = 24 * 24 et 99 minutes
    */
    choixNiveauDifficulte ();
    jouer ();

    return (0);
}
