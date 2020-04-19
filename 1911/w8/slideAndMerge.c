#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void slideAndMerge(int *nums);

int main(int argc, char* argv[]) {

	//freopen("c.txt", "r", stdin);
	
	int numbers[SIZE];//define int array size SIZE
	int i;

	i = 0;
	while (i < SIZE) {
		int number = getchar() - 48;//take char from stdin
		//and convert to int 48 = '0' (ASCII)
		numbers[i] = number;//puts integer in array
		i++;
	}

	i = 0;
	while (i < SIZE) {
		printf("%d ", numbers[i]);//prints the int array
		i++;
	}
	printf("\n");

	slideAndMerge(numbers);

	i = 0;
	while (i < SIZE) {
		printf("%d ", numbers[i]);//prints the int array
		i++;
	}
	printf("\n");
	return 0;
}

void slideone(int *a,int pos){
	int j;
	for (j=pos ; j<SIZE-1 ; j+=1){
		a[j]=a[j+1];
	}
	a[j]=0;
}
void slideAndMerge(int *nums) {
	// TODO
	int i,k=1;
	for (i=0 ; i<SIZE-k ; i+=1){//slide	
		if (nums[i]==0){
			slideone(nums,i);
			k++;
			i--;
		}
	}
	for (i=0 ; i<SIZE-k ; i+=1){//merge
		if (nums[i]==nums[i+1]){
			nums[i+1]=nums[i]*2;
			slideone(nums,i);
		}
	}
}