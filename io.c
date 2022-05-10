#include "takuzu.h"
#include "mat.h"
#include "util.h"

#include <stdbool.h>

void displayGrid(GAME game, bool helper, char none) {
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


COORDINATES inputCoordinates() {
    char * buf = malloc(2);

    COORDINATES coords;

    printf("\n>\t");
    getchar(); // juste pour être sur
    fgets(buf, 2, stdin);

    if(buf[0] <= 122 && buf[0] >= 97) {
        coords.posx = buf[0] - 97;
    }
    else if(buf[0] <= 90 && buf[0] >= 65) {
        coords.posx = buf[0] - 65;
    }
    else {
        coords.posx = -1;
    }

    if(buf[1] <= 57 && buf[1] >= 48 ) {
        coords.posy = buf[0] - 48;
    }
    else {
        coords.posy = -1;
    }

    free(buf);
    return coords;
}