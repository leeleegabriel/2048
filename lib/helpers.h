#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <math.h>
#define LENGTH 5
#define WIDTH 5

void getInput(char*);
void clear(int[LENGTH][WIDTH]);
void display(int[LENGTH][WIDTH]);
void shiftLeft(int[LENGTH][WIDTH], int*);
void shiftRight(int[LENGTH][WIDTH], int*);
void shiftUp(int[LENGTH][WIDTH], int*);
void shiftDown(int[LENGTH][WIDTH], int*);
void addValues(int[LENGTH][WIDTH], int*);
char getBestMove(int[LENGTH][WIDTH], int);
