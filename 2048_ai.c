
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <math.h>
#include "./lib/helpers.h"
#include "./lib/ai.h"

int main() {
	int disp[LENGTH][WIDTH] = {{0}};
	int score = 0;
	int input;
	srand(time(0));

	input = getBestMove(disp, score);
	while(input != 'q'){
		switchMove(input, disp, &score);
		addValues(disp, &score);
		input = getBestMove(disp, score);
	}
}
