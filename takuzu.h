#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "util.h"

#define UNKNOWN -1

#ifndef TAKUZU_H
#define TAKUZU_H


struct COORDINATES {
    int posx;
    int posy;
};

typedef struct COORDINATES COORDINATES;

struct PROPOSITION {
    COORDINATES coords;
    short content;
};

typedef struct PROPOSITION PROPOSITION;

struct CASE {
	short content;
	short mask;
    COORDINATES coords;
};

typedef struct CASE CASE;
typedef struct CASE** GRID;

struct GAME{
	GRID grid;
	int size;
};

typedef struct GAME GAME;

struct COUP{
    PROPOSITION proposotion;
    struct COUP* next;
};

typedef struct COUP COUP;
typedef struct COUP* LL;

struct LOTO {
    COORDINATES coords;
    struct LOTO* next;
};

typedef struct LOTO LOTO;


GRID createGrid(int size);
GRID createGridFromMatrix(int size, short matrix[size][size]);

void freeGrid(GRID * matrix, int size);

void printGrid(GAME game, int field);
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

bool isValidCoup(GAME game, int posx, int posy, short proposition);
bool isValidGrid(GRID grid, int size);
bool isInGrid(int size, int posx, int posy);


COUP * initListCoup(PROPOSITION proposotion);
void appendCoup(PROPOSITION proposotion, LL list);
void popTailCoup(LL list);
void printCoups(LL list);



#endif
