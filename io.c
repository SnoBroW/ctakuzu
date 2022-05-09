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
            printf("%c  ", game.grid[i][j].content ^ game.grid[i][j].mask ? game.grid[i][j].content + '0' : none);
        }
        printf("\n");
    }
}


COORDINATES inputCoordinates() {
    char * buf = malloc(2);


    printf("\n>\t");
    getchar(); // juste pour être sur
    fgets(buf, 2, stdin);
}