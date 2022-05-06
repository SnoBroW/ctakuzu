#include "takuzu.h"


void solveGrid(GAME game) {
    for (int i = 0; i < game.size; i++) {
        for (int j = 0; j < game.size; ++j) {

        }
    }
}

void generateMask(GAME game) {
    for (int i = 0; i < game.size; i++) {
        for (int j = 0; j < game.size; ++j) {
            (*(game.grid + i) + j)->mask = (short) getRandom();
        }
    }
}


void generateGrid(GAME game) {


}

CASE getCaseByPos(GAME game, int posx, int posy) {
    for (int i = 0; i < game.size; ++i) {
        for (int j = 0; j < game.size; ++j) {
            if(game.grid[i][j].coords.posx == posx && game.grid[i][j].coords.posy == posy) {
                return game.grid[i][j];
            }
        }
    }
}


bool isInGrid(int size, int posx, int posy) {
    return ((posx < size) && (posy < size)) ? true : false;
}
// Pour Albane: opérateur ternaire, condition ? siVrai : siFaux



bool isValid(GAME game, int posx, int posy, short proposition) {
    int maxToCheck = game.size * 2 - 2,
    cptGeneral = 0,
    cptAdj = 0,
    cptValid = 0,
    diffx,
    diffy;

    COORDINATES * toCheck = (COORDINATES *) malloc(maxToCheck * sizeof(COORDINATES));
    COORDINATES * adjacent = (COORDINATES *) malloc(4 * sizeof(COORDINATES));

    if(!isInGrid(game.size, posx, posy)) {
        return false;
    }

    for (int i = 0; i < game.size; ++i) {
        for (int j = 0; j < game.size; ++j) {
            if((game.grid[i][j].coords.posx == posx || game.grid[i][j].coords.posy == posy) && !(game.grid[i][j].coords.posx == posx && game.grid[i][j].coords.posy == posy)) {
                toCheck[cptGeneral++] = game.grid[i][j].coords;
            }
        }
    }

    for (int i = 0; i < maxToCheck; ++i) {
        diffx = abs(toCheck[i].posx - posx);
        diffy = abs(toCheck[i].posy - posy);
        if(diffx <= 1 && diffy <= 1) {
            if(isInGrid(game.size, toCheck[i].posx, toCheck[i].posy)) {
                adjacent[cptAdj++] = toCheck[i];
                printf("%d %d\n", toCheck[i].posx, toCheck[i].posy);
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        if(proposition != (game.grid[adjacent[i].posx][adjacent[i].posy]).content) {
            cptValid++;
        }
        if(cptValid == 4) {
            return true;
        }
        else {

        }

    }

    free(toCheck);
    free(adjacent);

    return false;

}



// rules:
// 1- same amount of ones and zeroes in one line / column
// 2- max two of the same number in a row
// 3- lines cant be the same