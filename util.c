#include "util.h"

void initRand() {
    time_t t;
    srand(time(&t));
}

int getRandom() {
    return rand() % 2;
}