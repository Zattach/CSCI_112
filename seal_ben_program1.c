/*
 * Ben Seal
 * Program 1,CSCI 112
 */

#include <stdio.h>
#include <math.h>

#define MAX_ARRAY_SIZE 50

//declares all of the functions so that they can be used anywhere
int populate_array( int array[] );
void print_array( int array[], int n );
void swap( int array[], int index1, int index2 );
void quicksort( int array[], int low, int high );
int partition( int array[], int low, int high );
int main(void);

int n = 0;
int index1 = 0;
int index2 = 0;
int low = 0;
int high = 0;
int set = 0;
int i = 0;

//main function that runs the main parts of the program and its function
int main(void){
	int array[MAX_ARRAY_SIZE];
	n = populate_array(array);		// add n = 
	printf("The initial array contains:\n");
	print_array(array, n);
	quicksort(array, 0, n - 1);		// replace n with n -1
	printf("The array is now sorted:\n");
	print_array(array, n);
	return 0;
}

//populates all the values of the array based on how many values are wanted by the user and also checks that they dont enter a out of bounds value
int populate_array(int array[]){
	printf("Enter the value of n > ");
	scanf("%d\n", &n);	// move \n from above down here
	if (n >= 0 && n <= MAX_ARRAY_SIZE){	// bring this to beginning of if else
		printf("Enter %d integers (positive, negative, or zero) >\n", n);	// delete space after >
		for(int i = 0; i < n; i++){
			scanf("%d", &set);
			array[i] = set;
		}
	}else if (n > MAX_ARRAY_SIZE){
		printf("%d exceeds the maximum array size. Please try again.\n\n", n);
		populate_array(array);
	}else if (n < 0){		// turn into if else statements
		printf("%d is less than zero. Please try again.\n\n", n);
		populate_array(array);
	}
	return n;
}

//prints out the array with all the values each on a new line with their respective sine
void print_array(int array[], int n){
	for(int k = 0; k < n; k++){			//replace i++ with k++
		printf("%+5d\n", array[k]);
	}
}

//swaps two values within the array
void swap(int array[], int index1, int index2){
	int temp = 0;
	temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

//the main sorting function 
void quicksort(int array[],int low, int high){
	int pivot = 0;
	if(low < high){
		pivot = partition(array,low,high);
		quicksort(array, low, pivot-1);
		quicksort(array, pivot+1, high);
	}
}

//gets the pivot values for the quicksort function so basically a sub function of quicksort
int partition(int array[], int low, int high){
	int pivot = array[high];
	i = low;
	for(int j = low; j < high; j++){
		if(array[j] <= pivot){
			swap(array, i, j);
			i = i + 1;
		}
	}
	swap(array, i, high);
	return i;
}

//Just a comment the grader wasnt working at the time of trying to fix the grading issues so I can really find out if it works 100% with all of the grader inputs however it works fine for the two user test inputs.
