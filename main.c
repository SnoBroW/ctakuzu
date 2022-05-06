#include "mat.h"
#include "takuzu.h"
#include "util.h"

#define SIZE 4

int main(int argc, char * argv[]) {

    GAME game = createGame(SIZE);

    printf("\n%d", isValid(game, 3, 2, 1));

    freeGame(&game);

    return 0;
}