
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <math.h>
#include "./lib/helpers.h"

#define number_of_paths 100

char getBestMove(int[LENGTH][WIDTH], int);

int main() {
	int disp[LENGTH][WIDTH] = {{0}};
	int score = 0;
	int input;
	int prev_score = 0;

	srand(time(0));

	//display(disp);
	input = getBestMove(disp, score);

	while(input != 'q'){
		prev_score = score;
		switch(input){
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
			default:
				printf("Invalid Input!\n");
				break;
		}
		addValues(disp, &score);
		if(score == 0 && prev_score != 0) {
			printf("%d\n", prev_score);
		}
		input = getBestMove(disp, score);
		//clear(disp);
	}
}


// AI
char getBestMove(int disp[LENGTH][WIDTH], int score) {
	int scores[4][number_of_paths] = {{score}};
	int disp_test[LENGTH][WIDTH];
	int first_move_score;
	int test_score;
	int prev_score;
	int c;
	int run;
	memcpy(disp_test, disp, sizeof (int) * LENGTH * WIDTH);

	for (int m = 0; m < 4; m++) {
		first_move_score = score;
		switch(m){
			case 0:
				shiftLeft(disp_test, &first_move_score);
				break;
			case 1:
				shiftRight(disp_test, &first_move_score);
				break;
			case 2:
				shiftDown(disp_test, &first_move_score);
				break;
			case 3:
				shiftUp(disp_test, &first_move_score);
				break;
		}
		//printf("fm score: %d\n", first_move_score);
		addValues(disp_test, &first_move_score);
		if (first_move_score == 0) {
			scores[m][0] = 0;
		} else {
			for (int n = 0; n < number_of_paths; n++) {
				//printf("%d\n", n);
				memcpy(disp_test, disp, sizeof (int) * WIDTH * LENGTH);
				test_score = first_move_score;
				prev_score = 0;
				run = 0;
				while(run == 0 || test_score > 0) {
					if (run == 0)
						run = 1;
					prev_score = test_score;
					c = rand() % 4;
					switch(c){
						case 0:
							shiftLeft(disp_test, &test_score);
							break;
						case 1:
							shiftRight(disp_test, &test_score);
							break;
						case 2:
							shiftDown(disp_test, &test_score);
							break;
						case 3:
							shiftUp(disp_test, &test_score);
							break;
						default:
							printf("Invalid Input!\n");
							break;
					}
					addValues(disp_test, &test_score);
				}
				scores[m][n] = prev_score;
			}
		}
	}

	//calculate averages
	int avgs[4] = {0};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < number_of_paths; j++) {
			avgs[i] += scores[i][j];
		}
		avgs[i] = avgs[i] / 4;
	}
	//pick starting move with largest average
	int max = 0;
	int max_index = 0;
	for (int i = 0; i < 4; i++) {
		if (max < avgs[i]) {
			max = avgs[i];
			max_index = i;
		}
	}
	return max_index;
}
