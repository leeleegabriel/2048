
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <math.h>
#include "./lib/helpers.h"

int main() {
	int disp[LENGTH][WIDTH] = {{0}};
	int score = 0;
	char input;

	srand(time(0));

	clear(disp);
	printf("Use WASD as arrows to shift, q to quit : ) \n\n");
	display(disp);
	getInput(&input);
	clear(disp);

	while(input != 'q'){
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
		printf("Score: %d\n", score);
		display(disp);
		getInput(&input);
		clear(disp);
	}
}
