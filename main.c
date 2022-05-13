#include "takuzu.h"
#include "util.h"
#include "io.h"
#include "grids.h"
#include "game.h"

#define SIZE 4

int main(int argc, char * argv[]) {

    printBanner();
    GAME game = createGame(inputSize());
    
/*    freeGrid(&game.grid, game.size);
    game.grid = createGridFromMatrix(SIZE, grid1);*/
    
    generateMask(game);
    playGame(game);
    freeGame(&game);




    return 0;
}