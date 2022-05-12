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

    while(!(filled || !lives)) {
        
        valid = true;

        // FAIRE SAISIE SECURISEE AVEC ISINGRID()
        // STP OUBLIE PAS

        printLives(lives);
        displayGrid(game, true, '.');
        printf("\nPosition ?\nFormat: COLONNE/LIGNE");
        inputCoordinates(&coords);

        if(coords.posx == -1 || coords.posy == -1) {
            valid = false;
        }

        if(!(game.grid[coords.posy][coords.posx].mask == 0)) {
            valid = false;
        }

        if(valid) {
            printf("\nProposition ?");
            proposition = inputContent();
            if(proposition == game.grid[coords.posy][coords.posx].content) {
                game.grid[coords.posy][coords.posx].content = proposition;
                game.grid[coords.posy][coords.posx].mask = 1;
            }
            else {
                printf("\n\nNon!\n");
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
        printf("\nVous avez gagné!\n\n");
    }
    else if(lives == 0) {
        printf("\nVous n'avez plus de vies\nDommage!\n\n");
    }
    else {
        printf("\nCela n'est pas censé se produire veuillez contacter l'administration\n\n");
    }
}