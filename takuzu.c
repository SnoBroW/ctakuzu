#include <string.h>


#include "takuzu.h"
#include "grids.h"

// ctakuzu - takuzu.c
// Albane Coiffe, Gabriel Durieux
// regroupe toutes les fonctions principales du takuzu


GRID createGrid(int size) {

    GRID matrix = (GRID) calloc(size, size * sizeof(CASE *));

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

GRID createGridFromMatrix(int size, short matrix[size][size]) {
    GRID grid = createGrid(size);

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            grid[i][j].content = matrix[i][j];
        }
    }
    return grid;
}



void matchMatrixAndGridSize(GAME * game) {
    switch (game->size) {
        case 4:
            game->grid = createGridFromMatrix(game->size, grid1);
            break;
        case 8:
            game->grid = createGridFromMatrix(game->size, grid2);
            break;
        case 16:
            game->grid = createGridFromMatrix(game->size, grid3);
            break;
    }
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

    if(size == -1){
        size = 4;
    }

    game.size = size;

    return game;
}

void freeGame(GAME * game) {
    freeGrid(&game->grid, game->size);
}

void applyHolesInGrid(GAME * game) {
    for (int i = 0; i < game->size; ++i) {
        for (int j = 0; j < game->size; ++j) {
            if(!(game->grid[i][j].mask)) {
                game->grid[i][j].content = -1;
            }
        }
    }
}


void generateMask(GAME game) {
    for (int i = 0; i < game.size; i++) {
        for (int j = 0; j < game.size; ++j) {
            (*(game.grid + i) + j)->mask = (short) getRandomBit();
        }
    }
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


void printRule(bool rule1, bool rule2, bool rule3) {
    printf("\n\n");
    if(!rule1) {
        printf("\nPas le même nombre de 0 et de 1 !");
    }
    if(!rule2) {
        printf("\nPlus de deux chiffres égaux alignés !");
    }
    if(!rule3) {
        printf("\nDeux fois la même ligne / colonne !");
    }
}


bool isValidMove(GAME game, int posx, int posy, short proposition) {
    
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

    short ** rotatedGrid;

    COORDINATES * toCheckFirstRound = malloc(maxToCheck * sizeof(COORDINATES));
    COORDINATES * adjacent = malloc(4 * sizeof(COORDINATES));
    COORDINATES * toCheckSecondRound = malloc((maxToCheck - 4) * sizeof(COORDINATES));
    COORDINATES temp;

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
        }
        else {
            toCheckSecondRound[cptSecondRound++] = (getCaseByPos(game, adjacent[i].posx - (posx - adjacent[i].posx),adjacent[i].posy - (posy - adjacent[i].posy))).coords;
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

    rotatedGrid = malloc(game.size * game.size * sizeof(short));
    for (int i = 0; i < game.size; ++i) {
        rotatedGrid[i] = malloc(game.size * sizeof(short));
        for (int j = 0; j < game.size; ++j) {
            rotatedGrid[i][j] = game.grid[j][i].content;
        }
    }

    for (int i = 0; i < game.size; ++i) {
        if((i == posx) && (memcmp(game.grid[i], game.grid[posx], sizeof(CASE) * game.size) != 0)) {
            rule3 = false;
        }
    }

    for (int i = 0; i < game.size; ++i) {
        if((i == posy) && (memcmp(rotatedGrid[i], rotatedGrid[posy], sizeof(CASE) * game.size) != 0)) {
            rule3 = false;
        }
    }

    for (int i = 0; i < game.size; ++i) {
        free(rotatedGrid[i]);
    }

    free(rotatedGrid);

    // LET ME THINK...

    printRule(rule1, rule2, rule3);

    return rule1 && rule2 && rule3;
}

bool isValidGrid(GRID grid, int size) {
    bool rule1 = true, rule2 = true, rule3 = true;
    short ** rotatedGrid, lastContent = -1;
    int cpt = 0, cpt0 = 0, cpt1 = 0, cptUk = 0;

    rotatedGrid = malloc(size * size * sizeof(short));
    for (int i = 0; i < size; ++i) {
        rotatedGrid[i] = malloc(size * sizeof(short));
        for (int j = 0; j < size; ++j) {
            rotatedGrid[i][j] = grid[j][i].content;
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(grid[i][j].content == 1){
                cpt1++;
            }
            else if(grid[i][j].content == 0){
                cpt0++;
            }
            else {
                cptUk++;
            }
        }
        if(cpt1 != cpt0 && !cptUk) {
            rule1 = false;
        }
        cpt0 = 0;
        cpt1 = 0;
        cptUk = 0;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(rotatedGrid[i][j] == 1){
                cpt1++;
            }
            else if(rotatedGrid[i][j] == 0){
                cpt0++;
            }
            else {
                cptUk++;
            }
        }
        if(cpt1 != cpt0 && !cptUk) {
            rule1 = false;
        }
        cpt0 = 0;
        cpt1 = 0;
        cptUk = 0;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(grid[i][j].content == 1){
                cpt1++;
                cpt0 = 0;
            }
            else if(grid[i][j].content == 0){
                cpt0++;
                cpt1 = 0;
            }
            else {
                cpt0 = 0;
                cpt1 = 0;
            }
            if(cpt1 > 2 || cpt0 > 2) {
                rule2 = false;
            }
        }
    }

    cpt0 = 0;
    cpt1 = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(rotatedGrid[i][j] == 1){
                cpt0 = 0;
                cpt1++;
            }
            else if(rotatedGrid[i][j] == 0){
                cpt1 = 0;
                cpt0++;
            }
            else {
                cpt0 = 0;
                cpt1 = 0;
            }
            if(cpt1 > 2 || cpt0 > 2) {
                rule2 = false;
            }
        }
        cpt0 = 0;
        cpt1 = 0;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(grid[i][j].content == -1) {
                cptUk++;
            }
        }
        for (int j = i; j < size; ++j) {
            if(i != j && memcmp(grid[i], grid[j], sizeof(CASE) * size) == 0 && cptUk) {
                rule3 = false;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(rotatedGrid[i][j] == -1) {
                cptUk++;
            }
        }
        for (int j = i; j < size; ++j) {
            if(i != j && memcmp(rotatedGrid[i], rotatedGrid[j], sizeof(CASE) * size) == 0 && !cptUk) {
                rule3 = false;
            }
        }
        cptUk = 0;
    }

    for (int i = 0; i < size; ++i) {
        free(rotatedGrid[i]);
    }

    free(rotatedGrid);

    return rule1 && rule2 && rule3;
}

// rules:
// 1- same amount of ones and zeroes in one line / column
// 2- max two of the same number in a row
// 3- lines cant be the same


MOVELINK * initMoveList(MOVE move) {
    MOVELL list = malloc(sizeof(MOVELINK));
    list->proposotion = move;
    list->next = NULL;
    return list;
}

void appendMove(MOVE move, MOVELL list) {
    MOVELINK * coup = malloc(sizeof(MOVELINK));
    coup->proposotion = move;
    coup->next = NULL;

    MOVELINK * tmp = list;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = coup;
}

void popTailMove(MOVELL list) {
    if(list != NULL) {
        if(list->next == NULL) {
            free(list);
            list = NULL;
        }
        else {
            MOVELINK * tmp = list;
            MOVELINK * ptmp = NULL;
            while(tmp->next != NULL) {
                ptmp = tmp;
                tmp = tmp->next;
            }
            ptmp->next = NULL;
            free(ptmp);
        }
    }
}

void freeMoveList();


// only for debug
void printMoves(MOVELL list) {
    while(list != NULL) {
        printf("%d @ %d %d\n", list->proposotion.content, list->proposotion.coords.posx, list->proposotion.coords.posy);
        list = list->next;
    }
}

POSLINK * initUnknownList(GAME game) {
    POSLL list = malloc(sizeof(POSLINK));
    POSLL next;

    int id = 0;

    list->next = NULL;
    list->id = id;

    for (int i = 0; i < game.size; ++i) {
        for (int j = 0; j < game.size; ++j) {
            if(game.grid[i][j].content == -1) {
                if(id == 0) {
                    list->coords = game.grid[i][j].coords;
                    id++;
                }
                else {
                    POSLL tmp = list;

                    next = malloc(sizeof(POSLINK));
                    next->coords = game.grid[i][j].coords;
                    next->next = NULL;
                    next->id = id++;

                    while (tmp->next != NULL) {
                        tmp = tmp->next;
                    }
                    tmp->next = next;
                }
            }
        }
    }

    return list;
}

POSLINK * drawRandomPosition(POSLL list, int random) {
    POSLL tmp = list;
    for (int i = 0; i < random; ++i) {
        tmp = tmp->next;
    }
    if(tmp != NULL && tmp->id == random) {
        return tmp;
    }
    else {
        return NULL;
    }
}

int getUnknownListSize(POSLL list) {
    POSLL tmp = list;
    int size = 1;
    if(tmp == NULL) {
        return 0;
    }
    while(tmp->next != NULL) {
        tmp = tmp->next;
        size++;
    }
    return size;
}

void popUnknown(POSLL list, int id) {
    POSLL tmp = list, prev;

    if(tmp != NULL && tmp->id == id) {
        list = tmp->next;
        free(tmp);
        return;
    }

    while(tmp != NULL && tmp->id != id) {
        prev = tmp;
        tmp = tmp->next;
    }

    if(tmp == NULL) {
        return;
    }

    prev->next = tmp->next;
    free(tmp);
}


// only for debug
void printUnknown(POSLL list) {
    while(list != NULL) {
        printf("%d - %d %d\n", list->id, list->coords.posy, list->coords.posx);
        list = list->next;
    }
}


