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

struct MOVE {
    COORDINATES coords;
    short content;
};

typedef struct MOVE MOVE;

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

struct MOVELINK{
    MOVE proposotion;
    struct MOVELINK* next;
};

typedef struct MOVELINK MOVELINK;
typedef struct MOVELINK* MOVELL;

struct POSLINK {
    COORDINATES coords;
    struct POSLINK* next;
	int id;
};

typedef struct POSLINK POSLINK;
typedef struct POSLINK* POSLL;


GRID createGrid(int size);
GRID createGridFromMatrix(int size, short matrix[size][size]);
void matchMatrixAndGridSize(GAME * game);
void freeGrid(GRID * matrix, int size);
void printGrid(GAME game, int field);
void printCase(CASE toPrint);
GAME createGame(int size);
void freeGame(GAME * game);
void applyHolesInGrid(GAME * game);
void solveGrid(GAME game);
void generateMask(GAME game);
void generateGrid(GAME game);
CASE getCaseByPos(GAME game, int posx, int posy);
bool isInGrid(int size, int posx, int posy);
void printRule(bool rule1, bool rule2, bool rule3);
bool isValidMove(GAME game, int posx, int posy, short proposition);
bool isValidGrid(GRID grid, int size);
MOVELINK * initMoveList(MOVE move);
void appendMove(MOVE move, MOVELL list);
void popTailMove(MOVELL list);
void printMoves(MOVELL list);

POSLINK * initUnknownList(GAME game);
COORDINATES drawRandomPosition(POSLL list, int temp);
int getUnknownListSize(POSLL list);
void printUnknown(POSLL list);

#endif
