#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define DIV_COUNT 3200

int LOOPS;
int flip(int div[], int count, int hits);

int main(void){
	int recure = 50000;
	int mean = 0;
	int div[DIV_COUNT];
	
	for (int i = 0; i < recure; i++){
		int hits = 0;
		LOOPS = 0;
		
		for (int k = 0; k < DIV_COUNT; k++)
			div[k] = 1;
		
		int result = flip(div, (DIV_COUNT*.01), hits);

		mean = mean + result;
	}
	printf("looped through %d times with an average of %d seconds\n", recure, ((mean/recure)/10));
	return 0;
}

int flip(int div[], int count, int hits){
	
	for (int j = 0; j < count; j++){
		int x = rand() % (DIV_COUNT - 1);
		if (div[x] == 1){
			hits++;
			div[x] = 0;
		}
	}
	
	if (hits > (.99 * DIV_COUNT))
		return LOOPS;
	else 
		LOOPS++;
		
	flip(div, count, hits);
}
