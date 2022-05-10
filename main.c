#include "mat.h"
#include "takuzu.h"
#include "util.h"
#include "io.h"
#include "grids.h"

#define SIZE 4

int main(int argc, char * argv[]) {

    GAME game = createGame(SIZE);

    fillGridWithMatrix(&game, grid1);

    displayGrid(game, true, '.');

    COORDINATES coords = inputCoordinates();

    CASE piss = getCaseByPos(game, coords.posx, coords.posy);

    printCase(piss);

    freeGame(&game);

    return 0;
}