#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "util.h"


#ifndef TAKUZU_H
#define TAKUZU_H


struct COORDINATES {
    int posx;
    int posy;
};

typedef struct COORDINATES COORDINATES;

struct CASE {

	short content;
	short mask;

    COORDINATES coords;
};

typedef struct CASE CASE;
typedef struct CASE** GRID;

struct GAME {
	GRID grid;
	int size;
};

typedef struct GAME GAME;



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


void solveGrid(GAME);
void generateMask(GAME);
void generateGrid(GAME);

CASE getCaseByPos(GAME game, int posx, int posy);

bool isValid(GAME game, int posx, int posy, short proposition);
bool isInGrid(int size, int posx, int posy);



#endif
