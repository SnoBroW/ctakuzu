#include "takuzu.h"
#include "util.h"
#include "io.h"

#include <stdbool.h>
#include <string.h>

void playGame(GAME game) {

    COORDINATES coords;
    bool valid, filled;
    int cptFilled = 0;
    short proposition, lives = 3;
    int size = game.size;

    while(!(!lives || filled)) {

        valid = true;

        printLives(lives);
        displayGrid(game, true, '.');
        printf("\nPosition ?\nFormat: COLONNE/LIGNE");
        inputCoordinates(&coords);

        if(coords.posx == -1 || coords.posy == -1) {
            valid = false;
        }

        if(valid && !isInGrid(game.size, coords.posx, coords.posy)) {
            valid = false;
        }

        if(valid && game.grid[coords.posy][coords.posx].mask != 0) {
            valid = false;
        }

        if(valid) {
            printf("\nProposition ?");
            proposition = inputContent();
            if(isValidMove(game, coords.posy, coords.posx, proposition)) {
                if(proposition == game.grid[coords.posy][coords.posx].content) {
                game.grid[coords.posy][coords.posx].content = proposition;
                game.grid[coords.posy][coords.posx].mask = 1;
                }
                else {
                    printf("\n\nCoup incorrect !\n");
                }
            }
            else {
                printf("\n\nCoup invalide !\n");
                lives--;
            }
        }
        else {
            printf("\nErreur, position invalide.\n");
        }

        cptFilled = 0;

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if(game.grid[i][j].mask == 1) {
                    cptFilled++;
                }
            }
        }

        filled = (cptFilled == size * size) ? true : false;

    }

    if(filled) {
        printf("\nVous avez gagné !\n\n");
    }
    else if(lives == 0) {
        printf("\nVous n'avez plus de vies\nPerdu !\n\n");
    }
    else {
        printf("\nCela n'est pas censé se produire veuillez contacter l'administration\n\n");
    }
}

void solveGrid(GAME game) {
    POSLL list = initUnknownList(game);
    COORDINATES random;

    bool solved = false;

    while(!solved) {

        random = drawRandomPosition(list, rand() % getUnknownListSize(list));

        if(isValidGrid(game.grid, game.size) && getUnknownListSize(list) == 0) {
            solved = true;
        }
    }


}