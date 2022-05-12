#include "takuzu.h"
#include "util.h"
#include "io.h"
#include "grids.h"
#include "game.h"

#define SIZE 8

int main(int argc, char * argv[]) {

    
    GAME game = createGame(SIZE);
    freeGrid(&game.grid, game.size);
    game.grid = createGridFromMatrix(SIZE, grid2);
    generateMask(game);

    playGame(game);
    freeGame(&game);

    return 0;
}