/*
 *  Zach Domke
 *  Program 0,CSCI 112
 *  2/6/16
 */
#include <stdio.h>

// get_n method gets an input
int get_n(void){
    int N = -1;
    do {
	printf("Enter an odd number less than or equal to 9 and greater than 0 > ");
	scanf("%d", &N);
	// if statement to determine if input is less than 1
	if (N < 1){
	    printf("You have entered a number less than 1. Please try again.\n\n");
	// else if statement to determine if input is greater than 9
	} else if (N > 9){
	    printf("You have entered a number greater than 9. Please try again.\n\n");
	// else if statement to determine if input is an even number
	} else if (N == 2 || N == 4 || N == 6 || N == 8){
	    printf("You have entered an even number. Please try again.\n\n");
	}
    // reruns loop if any if statement is met
    } while (N == 2 || N == 4 || N == 6 || N == 8 || N > 9 || N < 1);
    printf("\n");
    return N;
}

// diamondtop method prints the top half of the diamond using 3 for loops
int diamondtop(int m){
    int end = 1;
    int i = 1;
    int tmax = m + 1;
    // nested for loops are used here in order to work in 2D
    for (end = 1; end < tmax; end += 2){
	// for loop to print correct spacing
	for (i = m - end; i > 0; i -= 1){
	    printf(" ");
	}
	// for loop to print correct number
	for (i = 1; i < end; i += 1){
	    printf("%d ", i);
	}
	printf("%d\n", end);
    }
    return 0;
}

// diamondbot method prints the bottom half of the diamond using 3 for loops
int diamondbot(int m){
    int end = m - 2;
    int i = 1;
    // nested for loops are used here in order to work in 2D
    for (end = m - 2; end > 0; end -= 2){
	// for loop used to print the correct spacing
	for (i = 0; i < m - end; i += 1){
	    printf(" ");
	}
	// for loop used to print the correct number
	for (i = 1; i < end; i += 1){
	    printf("%d ", i);
	}
	printf("%d\n", end);
    }
    return 0;
}

// main method runs the 3 methods stated previously
int main(void){
    int N = get_n();
    diamondtop(N);
    diamondbot(N);
    return 0;
}
