#include "mat.h"
#include "takuzu.h"
#include "util.h"
#include "io.h"
#include "grids.h"

#define SIZE 16

int main(int argc, char * argv[]) {

    GAME game = createGame(SIZE);

    // fillGridWithMatrix(&game, grid2);

    displayGrid(game, true, '.');

    inputCoordinates();

    freeGame(&game);

    return 0;
}