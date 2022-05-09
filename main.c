#include "mat.h"
#include "takuzu.h"
#include "util.h"
#include "grids.h"

#define SIZE 8

int main(int argc, char * argv[]) {

    GAME game = createGame(SIZE);

    fillGridWithMatrix(&game, grid2);
    printf("\n%d", isValid(game, 4, 5, 1));
    printGrid(game, 0);

    freeGame(&game);

    return 0;
}