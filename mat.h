#include <stdio.h>
#include <stdlib.h>

#include "takuzu.h"


#ifndef MAT_H
#define MAT_H


GRID createMatrix(int size);

void freeMatrix(GRID * matrix, int size);

void printMatrix(GAME game, int field);
// Used for debug only
// Field designates the field to print
// 0: content
// 1: mask
// 2: content and mask xor'd

void printCase(CASE toPrint);

GAME createGame(int size);
void freeGame(GAME * game);



#endif
