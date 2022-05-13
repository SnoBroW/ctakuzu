#include "takuzu.h"
#include "util.h"

#include <stdbool.h>
#include <string.h>


void displayGrid(GAME game, bool helper, char none) {
    printf("\n");
    if(helper) {
        printf("\\\t");
        for (int i = 0; i < game.size; ++i) {
            printf("%c  ", i + 'A');
        }
        printf("\n\n");
    }
    for (int i = 0; i < game.size; ++i) {
        if(helper) {
            printf("%d\t", i);
        }
        for (int j = 0; j < game.size; ++j) {
            printf("%c  ", game.grid[i][j].mask ? game.grid[i][j].content + '0' : none);
        }
        printf("\n");
    }
}

void printLives(short lives) {
    printf("\nVies: ");
    for (int i = 0; i < lives; ++i)
    {
        printf("❤ ");
    }
    printf("\n");
}

void inputCoordinates(COORDINATES * coords) {
    char * buf = malloc(8);
    bool valid = true;

    printf("\n>\t");
    fgets(buf, 8, stdin);

    strtok(buf, "\n");
    strtok(buf, " ");

    if(strlen(buf) < 2) {
        valid = false;
    }

    if(valid) {
        if(buf[0] <= 122 && buf[0] >= 97) {
            coords->posx = buf[0] - 'a';
        }
        else if(buf[0] <= 90 && buf[0] >= 65) {
            coords->posx = buf[0] - 'A';
        }
        else {
            coords->posx = -1;
        }

        if(buf[1] <= 57 && buf[1] >= 48 ) {
            coords->posy = buf[1] - '0';
        }
        else {
            coords->posy = -1;
        }
    }
    else {
        coords->posx = -1;
        coords->posy = -1;
    }
    free(buf);
}

short inputContent() {
    
    int input;
    printf("\n>\t");
    input = (fgetc(stdin) - '0') % 2;
    getchar();
    // un peu débile mais ça marche
    return (short) input;
}


int multiChoiceMenu(char * elements[], int size) {
    int choice;
    printf("%s\n\n", elements[0]);

    for (int i = 1; i < size; ++i) {
        printf("[%d] -\t%s\n", i, elements[i]);
    }

    printf("\n>\t");
    choice = (fgetc(stdin) - '0');
    fflush(stdin); // pas censé marcher mais ça marche
    if((choice < size) && (choice > 0)) {
        return choice;
    }
    else {
        return -1;
    }

}

int inputSize() {
    char * elements[] = {"Choisissez la taille:", "4x4", "8x8", "16x16"};
    switch(multiChoiceMenu(elements, 4)) {
        case -1:
            printf("Erreur taille invalide, 4x4 séléctionnée par défaut\n");
            return -1;
        case 1:
            return 4;
        case 2:
            return 8;
        case 3:
            return 16;
        default:
            return -1;
    }
}

void mainMenu() {

}


void printBanner() {
    // j'étais obligé c'est trop cool
    printf(" _______ _______ _______ _     _ _     _ ______ _     _\n"
           " |          |    |_____| |____/  |     |  ____/ |     |\n"
           " |_____     |    |     | |    \\_ |_____| /_____ |_____|\n");
    printf("########################################################\n\n");
}

