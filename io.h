#include "takuzu.h"


#ifndef PROJET_C_L1_IO_H
#define PROJET_C_L1_IO_H

void displayGrid(GAME game, bool helper, char none);
void inputCoordinates(COORDINATES * coords);
void multiChoiceMenu();
int inputSize();
short inputContent();
void printLives(short lives);
void multiChoiceMenu(char * elements[]);
void printBanner();

#endif //PROJET_C_L1_IO_H
