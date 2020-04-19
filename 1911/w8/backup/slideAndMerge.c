#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void slideAndMerge(int *nums);

int main(int argc, char* argv[]) {
	int numbers[SIZE];
	int i;

	i = 0;
	while (i < SIZE) {
		int number = getchar() - 48;
		numbers[i] = number;
		i++;
	}

	i = 0;
	while (i < SIZE) {
		printf("%d ", numbers[i]);
		i++;
	}
	printf("\n");

	slideAndMerge(numbers);

	i = 0;
	while (i < SIZE) {
		printf("%d ", numbers[i]);
		i++;
	}
	printf("\n");

	return 0;
}

void slideAndMerge(int *nums) {
	// TODO
}