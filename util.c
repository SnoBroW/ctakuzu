#include "util.h"


// ctakuzu - util.c
// Albane Coiffe, Gabriel Durieux
// fonctions utiles sans catégorie



void initRand() {
    time_t t;
    srand(time(&t));
}

int getRandomBit() {
    return rand() % 2;
}