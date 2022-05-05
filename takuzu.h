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
	short xor;

    COORDINATES coords;
};

typedef struct CASE CASE;
typedef struct CASE** GRID;

struct GAME {
	GRID grid;
	int size;
};

typedef struct GAME GAME;


void solveGrid(GAME);
void generateMask(GAME);
void generateGrid(GAME);

CASE getCaseByPos(GAME game, int posx, int posy);

bool isValid(GAME game, int posx, int posy, short proposition);
bool isInGrid(int size, int posx, int posy);


#endif
