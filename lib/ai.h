#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <math.h>
#include "config.h"
#include "helpers.h"

char getBestMove(int[LENGTH][WIDTH], int);
void switchMove(int, int[LENGTH][WIDTH], int*);