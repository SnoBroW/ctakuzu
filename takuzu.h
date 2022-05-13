#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "util.h"


#ifndef TAKUZU_H
#define TAKUZU_H


typedef struct {
    int posx;
    int posy;
} COORDINATES;

typedef struct {

	short content;
	short mask;

    COORDINATES coords;
} CASE;

typedef struct CASE** GRID;

typedef struct {
	GRID grid;
	int size;
} GAME;

typedef struct {
    

} MAILLON;





GRID createGrid(int size);
GRID createGridFromMatrix(int size, short matrix[size][size]);

void freeGrid(GRID * matrix, int size);

void printGrid(GAME game, int field);
// Used for debug only
// Field designates the field to print
// 0: content
// 1: mask

void printCase(CASE toPrint);

GAME createGame(int size);
void freeGame(GAME * game);

GAME initGame(GAME game, GRID grid);


void solveGrid(GRID);
void generateMask(GAME);
void generateGrid(GAME);

CASE getCaseByPos(GAME game, int posx, int posy);

bool isValid(GAME game, int posx, int posy, short proposition);
bool isInGrid(int size, int posx, int posy);



#endif
