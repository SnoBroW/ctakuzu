#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "util.h"

#define UNKNOWN -1

#ifndef TAKUZU_H
#define TAKUZU_H



// ctakuzu - takuzu.h
// Albane Coiffe, Gabriel Durieux
// regroupe toutes les fonctions principales du takuzu



// --------------------- structures ---------------------

// les coordonnées
struct COORDINATES {
    int posx;
    int posy;
};
typedef struct COORDINATES COORDINATES;

// les coordonnées et une proposition
struct MOVE {
    COORDINATES coords;
    short content;
};
typedef struct MOVE MOVE;

// une case, avec un contenu et un masque
struct CASE {
	short content;
	short mask;
    COORDINATES coords;
};
typedef struct CASE CASE;

// la grille de jeu
typedef struct CASE** GRID;

// la structure jeu, regroupant une grille et sa taille
// evite de passer la taille en argument dans chaque fonction
struct GAME{
	GRID grid;
	int size;
};
typedef struct GAME GAME;

// maillon de la LLC de coups
struct MOVELINK{
    MOVE proposotion;
    struct MOVELINK* next;
};
typedef struct MOVELINK MOVELINK;

// LLC de coups
typedef struct MOVELINK* MOVELL;

// maillon de la LLC de positions
struct POSLINK {
    COORDINATES coords;
    struct POSLINK* next;
	int id;
};
typedef struct POSLINK POSLINK;

// LLC de positions
typedef struct POSLINK* POSLL;



// --------------------- allocation / libération ---------------------

// crée la structure game à partir d'une taille
GAME createGame(int size);

// libère la strucutre game
void freeGame(GAME * game);

// alloue une grille de taille size
GRID createGrid(int size);

// alloue une grille à partir d'un tableau entré dans grids.h
GRID createGridFromMatrix(int size, short matrix[size][size]);

// fait correspondre une taille entrée avec une allocation de grille entrée dans grids.h
void matchMatrixAndGridSize(GAME * game);

// remplit la grille de -1 (contenu inconnu) à partir d'un masque
void applyHolesInGrid(GAME * game);

// libère une grille
void freeGrid(GRID * matrix, int size);




// --------------------- affichage ---------------------

// affiche une grille
// field permet de sélectionner le champ à afficher:
// 0: content
// 1: mask
void printGrid(GAME game, int field);

// affiche les règles non respectées
void printRule(bool rule1, bool rule2, bool rule3);

// affiche le contenu d'une case
// non utilisée
void printCase(CASE toPrint);



// --------------------- calculs ---------------------

// génère un masque aléatoirement
void generateMask(GAME game);

// renvoie la valeur d'une case de la grille à partir de ses coordonnées
CASE getCaseByPos(GAME game, int posx, int posy);

// vérifie si une case fait partie de la grille
bool isInGrid(int size, int posx, int posy);

// vérifie la validité d'un coup selon les trois règles
bool isValidMove(GAME game, int posx, int posy, short proposition);

// vérifie la validité d'une grille entière selon les trois règles
bool isValidGrid(GRID grid, int size);



// --------------------- listes chainées ---------------------

// ------ LLC de coups ------

// alloue le premier maillon de la LLC de coups
MOVELINK * initMoveList(MOVE move);

// ajouter un coup à la LLC
void appendMove(MOVE move, MOVELL list);

// supprimer le dernier coup de la LLC
void popTailMove(MOVELL list);

// afficher tous les coups
// non utilisée
void printMoves(MOVELL list);

// ------ LLC de positions ------

// initialise le premier maillon de la LLC de positions
POSLINK * initUnknownList(GAME game);

// tire une position aléatoire dans la LLC
POSLINK * drawRandomPosition(POSLL list, int random);

// revoie la taille de la LLC
int getUnknownListSize(POSLL list);

// supprime un maillon de la LLC
void popUnknown(POSLL list, int id);

// afficher toutes les positions
// non utilisée
void printUnknown(POSLL list);


#endif
