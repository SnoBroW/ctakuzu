#include "mat.h"
#include "takuzu.h"


GRID createGrid(int size) {
    
    GRID matrix = (GRID) calloc(size, size * sizeof(CASE *));
    int cpt = 0;

    for (int i = 0; i < size; i++) {
        *(matrix + i) = calloc(size, size * sizeof(CASE));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j].coords.posx = j;
            matrix[i][j].coords.posy = i;
        }
    }

    return matrix;
}

void freeGrid(GRID * matrix, int size) {
    for (int i = 0; i < size; ++i) {
        free(*(*matrix + i));
    }
    free(*matrix);
}


void printGrid(GAME game, int field) {
    for (int i = 0; i < game.size; i++) {
        for (int j = 0; j < game.size; j++) {
            switch(field) {
                case 0:
                    printf("%d ", game.grid[i][j].content);
                    break;
                case 1:
                    printf("%d ", game.grid[i][j].mask);
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
}


void printCase(CASE toPrint) {

  printf("\ncontent: %d\nmask: %d\n\nY: %d\nX: %d\n\n",
    toPrint.content,
    toPrint.mask,
    toPrint.coords.posy,
    toPrint.coords.posx
    );
}

GAME createGame(int size) {
    GAME game;

    GRID grid = createGrid(size);

    game.grid = grid;
    game.size = size;

    initRand();
    generateMask(game);

    return game;
}

void freeGame(GAME * game) {
    freeGrid(&game->grid, game->size);
}