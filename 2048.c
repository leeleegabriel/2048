

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <math.h>

#define LENGTH 5
#define WIDTH 5
#define MOVES 5


void getInput(char*);
void reset(int[LENGTH][WIDTH]);
void clear(int[LENGTH][WIDTH]);
void display(int[LENGTH][WIDTH]);
void shiftLeft(int[LENGTH][WIDTH], int*);
void shiftRight(int[LENGTH][WIDTH], int*);
void shiftUp(int[LENGTH][WIDTH], int*);
void shiftDown(int[LENGTH][WIDTH], int*);
void addValues(int[LENGTH][WIDTH], int*);
char getBesttMove(int[LENGTH][WIDTH], int*);
char getNextMove(int[LENGTH][WIDTH]);

//void generateMoves();



int main() {
    int disp[LENGTH][WIDTH];
    int score = 0;
    char input;
    char test;
    int seed = time(0);

    srand(seed);

    reset(disp);
    clear(disp);
    printf("Use WASD as arrows to shift, q to quit : ) \n\n");
    display(disp);
    getInput(&input);
    clear(disp);

    while(input != 'q'){
        test = getBestMove(disp, &seed);
        srand(seed);
        printf("Best Move: %c\n", test);
        switch(input){
            case 'a':
                shiftLeft(disp, &score);
                break;
            case 'd':
                shiftRight(disp, &score);
                break;
            case 'w':
                shiftUp(disp, &score);
                break;
            case 's':
                shiftDown(disp, &score);
                break;
            default:
                printf("Invalid Input!\n");
                break;
        }
        addValues(disp, &score);
        display(disp);
        getInput(&input);
        clear(disp);
    }
}

void shiftLeft(int disp[LENGTH][WIDTH], int* score) {
    int c;
    int l;
    for (int y = 0; y < LENGTH; y++){
        //merge all pairs
        c = 0;
        l = -1;
        while(c < WIDTH) {
            if (disp[y][c] != 0) {
                if (l == -1 || disp[y][c] != disp[y][l]) {
                    l = c; 
                } else {
                    disp[y][l] = disp[y][l]*2;
                    *score = disp[y][l];
                    disp[y][c] = 0; 
                    l = -1;
                }
            }
            c++;
        }
        // move all non zeros left
        c = 0;
        for (int x = 0; x < WIDTH; x++){
            if (disp[y][x] != 0)
                disp[y][c++] = disp[y][x];
        }
        while (c < WIDTH) {
            disp[y][c++] = 0;
        }       
    }
}

void shiftRight(int disp[LENGTH][WIDTH], int* score) {
    int c;
    int r;
    for (int y = 0; y < LENGTH; y++){
        //merge all pairs
        c = WIDTH - 1;
        r = -1;
        while(c >= 0) {
            if (disp[y][c] != 0) {
                if (r == -1 || disp[y][c] != disp[y][r]) {
                    r = c; 
                } else {
                    disp[y][r] = disp[y][r]*2;
                    *score = disp[y][r];
                    disp[y][c] = 0; 
                    r = -1;
                }
            }
            c--;
        }
        // move all non zeros right
        c = WIDTH-1;
        for (int x = WIDTH - 1; x >= 0; x--){
            if (disp[y][x] != 0)
                disp[y][c--] = disp[y][x];
        }
        while (c >= 0) {
            disp[y][c--] = 0;
        }       
    }
}

void shiftUp(int disp[LENGTH][WIDTH], int* score) {
    int c;
    int u;
    for (int x = 0; x < WIDTH; x++){
        //merge all pairs
        c = 0;
        u = -1;
        while(c < LENGTH) {
            if (disp[c][x] != 0) {
                if (u == -1 || disp[c][x] != disp[u][x]) {
                    u = c; 
                } else {
                    disp[u][x] = disp[u][x]*2;
                    *score += disp[u][x];                   
                    disp[c][x] = 0; 
                    u = -1;
                }
            }
            c++;
        }
        // move all non zeros down
        c = 0;
        for (int y = 0; y < LENGTH; y++){
            if (disp[y][x] != 0)
                disp[c++][x] = disp[y][x];
        }
        while (c < LENGTH) {
            disp[c++][x] = 0;
        }       
    }
}

void shiftDown(int disp[LENGTH][WIDTH], int* score) {
    int c;
    int d;
    for (int x = 0; x < WIDTH; x++){
        //merge all pairs
        c = LENGTH - 1;
        d = -1;
        while(c >= 0) {
            if (disp[c][x] != 0) {
                if (d == -1 || disp[c][x] != disp[d][x]) {
                    d = c; 
                } else {
                    disp[d][x] = disp[d][x]*2;
                    *score += disp[d][x];
                    disp[c][x] = 0; 
                    d = -1;
                }
            }
            c--;
        }
        // move all non zeros down
        c = LENGTH;
        for (int y = LENGTH; y >= 0; y--){
            if (disp[y][x] != 0)
                disp[c--][x] = disp[y][x];
        }
        while (c >= 0) {
            disp[c--][x] = 0;
        }       
    }
}

// char getBest(int disp[LENGTH][WIDTH], int* seed) {
//     int disp_test[LENGTH][WIDTH];
//     memcpy(disp_test, disp, sizeof (int) * WIDTH * LENGTH);

//     srand(*seed);
//     for (int i; i < 500; i++) {

//     }



// }

// AI
char getNextMove(int disp[LENGTH][WIDTH]) {
    int max = 0;
    int max_index = 0;// -1
    int score = 0;

    for (int i = 0; i < 4; i++) {
        switch(i){
            case 0:
                shiftLeft(disp, &score);
                break;
            case 1:
                shiftRight(disp, &score);
                break;
            case 2:
                shiftUp(disp, &score);
                break;
            case 3:
                shiftDown(disp, &score);
                break;
        }
        if (score > max) {
            max = score;
            max_index = i;
        } 
        score = 0;
    }

    char best[4] = {'a', 'd', 'w', 's'};
    return best[max_index];
}


// DISPLAY 

void clear(int disp[LENGTH][WIDTH]){
    printf("\e[1;1H\e[2J");
}

void reset(int disp[LENGTH][WIDTH]) {
    for (int y = 0; y < LENGTH; y++){
        for (int x = 0; x < WIDTH; x++){
            disp[y][x] = 0;
        }   
    }
}


void display(int disp[LENGTH][WIDTH]) {
    for (int y = 0; y < LENGTH; y++){
        for (int x = 0; x < WIDTH; x++){
            printf("%4d", disp[y][x]);
        }
        for (int x = 0; x < WIDTH/2; x++){
            printf("\n");   
        }
    }
}

void addValues(int disp[LENGTH][WIDTH], int* score) { 
    int* zeroes[LENGTH*WIDTH] = {0}; // array of addresses of display where the value is 0
    int c = 0;
    memset(zeroes, -1, sizeof zeroes);
    for(int y = 0; y < LENGTH; y++){
        for(int x = 0; x < WIDTH; x++){
            if (disp[y][x] == 0) {
                zeroes[c] = &disp[y][x];
                c++;
            }
        }
    }
    if (c == 0) {
        //check if there is a possible move if none, lose
        printf("You Lose! Finale Score: %d\n", *score);
        reset(disp);
    } else {
        *zeroes[rand() % c] = (rand() % (2) + 1) * 2;
        printf("Score: %d\n", *score);
    }

}

void getInput(char* ptr) {
    printf("Enter a value: ");
    scanf(" %c", ptr);
    fflush(stdin);
}


