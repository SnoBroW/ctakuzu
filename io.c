#include "takuzu.h"
#include "mat.h"
#include "util.h"

void displayGrid(GAME game) {
    for (int i = 0; i < game.size; ++i) {
        for (int j = 0; j < game.size; ++j) {
            printf("%c ", game.grid[i][j].content ^ game.grid[i][j].mask ? game.grid[i][j].content + '0' : '_');
        }
        printf("\n");
    }
}


COORDINATES inputCoordinates() {

}