#include "takuzu.h"


#ifndef PROJET_C_L1_IO_H
#define PROJET_C_L1_IO_H

void displayGrid(GAME game, bool helper, char none);
void inputCoordinates(COORDINATES * coords);
int inputSize();
short inputContent();
void printLives(short lives);
void multiChoiceMenu(char * elements[], int size, bool title, bool retour);
void printBanner();
void mainMenu();

#endif //PROJET_C_L1_IO_H
