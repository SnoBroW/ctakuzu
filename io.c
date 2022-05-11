#include "takuzu.h"
#include "mat.h"
#include "util.h"
#include "grids.h"

#include <stdbool.h>

void displayGrid(GAME game, bool helper, char none) {
    printf("\n\n");
    if(helper) {
        printf("\\\t");
        for (int i = 0; i < game.size; ++i) {
            printf("%c  ", i + 'A');
        }
        printf("\n\n");
    }
    for (int i = 0; i < game.size; ++i) {
        if(helper) {
            printf("%d\t", i);
        }
        for (int j = 0; j < game.size; ++j) {
            printf("%c  ", game.grid[i][j].mask ? game.grid[i][j].content + '0' : none);
        }
        printf("\n");
    }
}


void inputCoordinates(COORDINATES * coords) {
    char * buf = malloc(8);

    printf("\n>\t");
    fgets(buf, 3, stdin);

    if(buf[0] <= 122 && buf[0] >= 97) {
        coords->posx = buf[0] - 'a';
    }
    else if(buf[0] <= 90 && buf[0] >= 65) {
        coords->posx = buf[0] - 'A';
    }
    else {
        coords->posx = -1;
    }

    if(buf[1] <= 57 && buf[1] >= 48 ) {
        coords->posy = buf[1] - '0';
    }
    else {
        coords->posy = -1;
    }

    // coords->posx = (int) buf[0] - 'A';
    // coords->posy = (int) buf[1] - '0';

    free(buf);
}


void inputContent(short * content) {
    printf("\n>\t");
    *content = (fgetc(stdin) - '0');
}


void proposition(GAME game) {



}

int inputSize() {

}


void multiChoiceMenu() {

}



void playGame(int size) {

    GAME game = createGame(size);
    COORDINATES coords;
    fillGridWithMatrix(&game, grid1);

    while(1) {

        // FAIRE SAISIE SECURISEE AVEC ISINGRID()
        // STP OUBLIE PAS

        displayGrid(game, true, '.');
        printf("\nPosition ?\nFormat: COLONNE/LIGNE");
        inputCoordinates(&coords);
        getchar();

        game.grid[coords.posy][coords.posx].mask = 1;

        printf("\nProposition?");
        inputContent(&(game.grid[coords.posy][coords.posx].content));
        getchar();
    }


    freeGame(&game);
}