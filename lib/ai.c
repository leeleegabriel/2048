#include "ai.h"

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
		switchMove(m, disp_test, &first_move_score);
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
					switchMove(m, disp_test, &test_score);
					addValues(disp_test, &test_score);
				}
				scores[m][n] = prev_score;
			}
		}
	}
	//calculate averages
	double avgs[4] = {0};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < number_of_paths; j++) {
			avgs[i] += (double)scores[i][j];
		}
		avgs[i] = avgs[i] / 4.0;
	}
	//pick starting move with largest average
	float max = 0;
	int max_index = 0;
	for (int i = 0; i < 4; i++) {
		if (max < avgs[i]) {
			max = avgs[i];
			max_index = i;
		}
	}
	return max_index;
}

void switchMove(int m, int disp[LENGTH][WIDTH], int* score) {
	switch(m){
		case 0:
			shiftLeft(disp, score);
			break;
		case 1:
			shiftRight(disp, score);
			break;
		case 2:
			shiftDown(disp, score);
			break;
		case 3:
			shiftUp(disp, score);
			break;
	}
}