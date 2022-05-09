#include "mat.h"
#include "takuzu.h"
#include "util.h"
#include "io.h"
#include "grids.h"

#define SIZE 4

int main(int argc, char * argv[]) {

    GAME game = createGame(SIZE);

    fillGridWithMatrix(&game, grid2);
    // printf("\n%d", isValid(game, 4, 5, 1));

    displayGrid(game);

    freeGame(&game);

    return 0;
}