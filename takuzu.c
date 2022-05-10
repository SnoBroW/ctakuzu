#include <string.h>
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
    
    if (!isInGrid(game.size, posx, posy)) {
        return false;
    }

    int maxToCheck = game.size * 2 - 2,
            cptGeneral = 0,
            cptAdj = 0,
            cptSecondRound = 0,
            cptValid = 0,
            diffx,
            diffy;

    bool rule1 = true, rule2 = true, rule3 = true;

    int cpt1 = 0, cpt0 = 0;

    COORDINATES * toCheckFirstRound = malloc(maxToCheck * sizeof(COORDINATES));
    COORDINATES * adjacent = malloc(4 * sizeof(COORDINATES));
    COORDINATES * toCheckSecondRound = malloc((maxToCheck - 4) * sizeof(COORDINATES));

    for (int i = 0; i < game.size; ++i) {
        for (int j = 0; j < game.size; ++j) {
            if ((game.grid[i][j].coords.posx == posx || game.grid[i][j].coords.posy == posy) &&
                !(game.grid[i][j].coords.posx == posx && game.grid[i][j].coords.posy == posy)) {
                toCheckFirstRound[cptGeneral++] = game.grid[i][j].coords;
            }
        }
    }

    for (int i = 0; i < maxToCheck; ++i) {
        diffx = abs(toCheckFirstRound[i].posx - posx);
        diffy = abs(toCheckFirstRound[i].posy - posy);
        if (diffx <= 1 && diffy <= 1) {
            adjacent[cptAdj++] = toCheckFirstRound[i];
        }
    }

    for (int i = 0; i < sizeof(adjacent) / sizeof(COORDINATES); ++i) {
        if (proposition != game.grid[adjacent[i].posx][adjacent[i].posy].content) {
            cptValid++;
        } else {
            toCheckSecondRound[cptSecondRound++] = getCaseByPos(game, adjacent[i].posx - (posx - adjacent[i].posx),
                                                                adjacent[i].posy -
                                                                (posy - adjacent[i].posy)).coords;
        }
    }

    if (cptValid == 4) {
        rule2 = true;
    }

    for (int i = 0; i < cptSecondRound; ++i) {
        if (game.grid[toCheckSecondRound[i].posx][toCheckSecondRound[i].posy].content == proposition) {
            rule2 = false;
        }
    }

    free(toCheckFirstRound);
    free(adjacent);
    free(toCheckSecondRound);

    proposition ? cpt1++ : cpt0++;

    for (int i = 0; i < game.size; ++i) {
        if(i != posy) {
            game.grid[posx][i].content ? cpt1++ : cpt0++;
        }
    }

    if(cpt1 != cpt0) {
        rule1 = false;
    }

    cpt1 = 0;
    cpt0 = 0;

    proposition ? cpt1++ : cpt0++;

    for (int i = 0; i < game.size; ++i) {
        if(i != posx) {
            game.grid[i][posy].content ? cpt1++ : cpt0++;
        }
    }

    if(cpt1 != cpt0) {
        rule1 = false;
    }

    for (int i = 0; i < game.size; ++i) {
        if((i == posx) && (memcmp(game.grid[i], game.grid[posx], sizeof(CASE) * game.size) != 0)) {
            rule3 = false;
        }
        else {
            rule3 = true;
        }
    }

    // LET ME THINK...

    return rule1 && rule2 && rule3;

}


void fillGridWithMatrix(GAME * game, short matrix[game->size][game->size]) {
    for (int i = 0; i < game->size; ++i) {
        for (int j = 0; j < game->size; ++j) {
            game->grid[i][j].content = matrix[i][j];
        }
    }
}


// rules:
// 1- same amount of ones and zeroes in one line / column
// 2- max two of the same number in a row
// 3- lines cant be the same