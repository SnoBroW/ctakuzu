#include "takuzu.h"


#ifndef PROJET_C_L1_IO_H
#define PROJET_C_L1_IO_H



// ctakuzu - io.h
// Albane Coiffe, Gabriel Durieux
// regroupe toutes les fonctions d'entrée/sortie/menu




// ------------------- input -------------------

// demande l'entrée de coordonnées
// sécurisée
void inputCoordinates(COORDINATES * coords);

// demande l'entrée d'un contenu de case, soit 0 ou 1
// la sortie est %2, on a vu mieux comme saisie sécurisée mais ça marche
short inputContent();

// demande le choix d'une taille, parmi 4, 8 ou 16
// sécurisée
int inputSize();


// ------------------- output -------------------

// afficher une grille de jeu
// helper permet de choisir d'afficher ou non les numéros de lignes/colonnes
// none définit le caractère à utiliser pour les positions masquées
void displayGrid(GAME game, bool helper, char none);

// affiche les vies avec des jolis coeurs tout mignons
void printLives(short lives);


// ------------------- output -------------------

// fonction de menu modulaire, prend en paramètre un tableau de strings, ainsi que la taille de ce tableau
// title permet d'afficher l'élément 0 du tableau comme un titre
// retour le dernier element avec un saut de ligne, et le numéro de choix 0
int multiChoiceMenu(char * elements[], int size, bool title, bool retour);

// menu principal, permet l'appel de toutes les autres fonctions
void mainMenu();



// ------------------- autres -------------------

// affiche la bannière 'ctakuzu' au lancement du programme
void printBanner();

#endif //PROJET_C_L1_IO_H
