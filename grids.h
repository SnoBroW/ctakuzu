#ifndef PROJET_C_L1_GRIDS_H
#define PROJET_C_L1_GRIDS_H

 short grid1[4][4] = {
        {1,0,0,1},
        {1,0,1,0},
        {0,1,1,0},
        {0,1,0,1}
};



short grid2[8][8] = {
        {1,0,1,1,0,1,0,0},
        {1,0,1,0,1,0,0,1},
        {0,1,0,1,1,0,1,0},
        {0,1,0,1,0,1,1,0},
        {1,0,1,0,0,1,0,1},
        {0,1,0,0,1,0,1,1},
        {0,0,1,1,0,1,1,0},
        {1,1,0,0,1,0,0,1}
};


short grid3[16][16] = {
            {1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0},
            {1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
            {0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
            {1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1},
            {1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0},
            {0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1},
            {0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1},
            {1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0},
            {1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1},
            {0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1},
            {1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1},
            {1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0},
            {0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
            {0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0}
};



// Seulement utilisée pour le debug
short unknownGrid[4][4] = {
        {-1,-1,-1,-1},
        {-1,-1,-1,-1},
        {-1,-1,-1,-1},
        {-1,-1,-1,-1}
};



#endif //PROJET_C_L1_GRIDS_H
