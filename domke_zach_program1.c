/*
 * Zach Domke
 * Program 1,CSCI 112
 * 3/5/16
 */

// allows for scanf and printf functions to be called
#include <stdio.h>

// defines maximum and minimum array sizes to be called later in code
#define MAX_ARRAY_SIZE 50
#define MIN_ARRAY_SIZE 0

int popArr(int arr[]);				// Fill array with values from user.
int part(int arr[], int low, int high);		// Find the partition point.
void printArr(int arr[], int n);		// Print out the array values.
void swap(int arr[], int ind1, int ind2);	// Swap two array elements.
void quicksort(int arr[], int low, int high);	// Sorting algorithm.

// runs the functions to create, populate, and sort an array
int main(void){
	int arr[MAX_ARRAY_SIZE];
	int n;
	n = popArr(arr);
	printf("The initial array contains:\n");
	printArr(arr, n);
	quicksort(arr, 0, n - 1);
	printf("The array is now sorted:\n");
	printArr(arr, n);
	return 0;
}

// gets user input on how long of an array will be used and gets numbers to populate the array
int popArr(int arr[]){
	int n = 56;
	while(n > MAX_ARRAY_SIZE || n < MIN_ARRAY_SIZE){
		printf("Enter the value of n > ");
		scanf("%d", &n);
		if(n > MAX_ARRAY_SIZE){
			printf("%d exceeds the maximum array size. Please try again.\n\n", n);
		} else if(n < MIN_ARRAY_SIZE){
			printf("%d is less than zero. Please try again.\n\n", n);
		}
	}
	printf("Enter %d integers (positive, negative, or zero) >\n", n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	return n;
}

// partition function determines pivot point based two values given when called
int part(int arr[], int low, int high){
	int piv = arr[high];
	int i = low;
	for(int j = low; j < high; j++){
		if(arr[j] <= piv){
			swap(arr, i, j);
			i++;
		}
	}
	swap(arr, i, high);
	return i;
}

// print array function prints out the array as specified in the assignment
void printArr(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%+5d\n", arr[i]);
	}
}

// swap function swaps two values specified when called
void swap(int arr[], int ind1, int ind2){
	int temp = arr[ind1];
	arr[ind1] = arr[ind2];
	arr[ind2] = temp;
}

// quicksort function sorts the array
void quicksort(int arr[], int low, int high){
	if(low < high){
		int piv = part(arr, low, high);
		quicksort(arr, low, piv - 1);
		quicksort(arr, piv + 1, high);
	}
}
