#include "takuzu.h"


#ifndef PROJET_C_L1_GAME_H
#define PROJET_C_L1_GAME_H



// ctakuzu - game.h
// Albane Coiffe, Gabriel Durieux
// regroupe toutes les fonctionalités


// déroulement du jeu dans une boucle while, jusqu'a la victoire ou la défaite du joueur
void playGame(GAME game);

// résout une grille (pas finie)
void solveGrid(GAME game);

// génère une grille (pas commencée)
void generateGrid(GAME game);


#endif