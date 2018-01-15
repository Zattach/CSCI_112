/*
 * Zach Domke
 * Lab 2,CSCI 112
 * 2/1/16
 */
#include <stdio.h>
#include <math.h>
#include <float.h>

double lowest = 0;
double highest = 0;
double sum = 0;
double sum_squares = 0;
double range = 0;
double average = 0;
double std_dev = 0;

/* get n method prompts user to enter a value for N */
int get_n(void){
    int N = -1;
    do {
	printf("Enter a value for N that is >= 0: ");
	scanf("%d", &N);
	if (N < 0){
	    printf("Invalid value for N\n");
	}
    } while (N < 0);
    return N;
}

/* get input method prompts user to enter a number for variable 'current' */
double get_input(void){
    double var = 0;
    printf("Enter a number: ");
    scanf("%lf", &var);
    return var;
}

/* print results method prints all values that have been used */
int print_results(void){
    printf("The Highest is: %.3f\n", highest);
    printf("The Lowest is: %.3f\n", lowest);
    printf("The Average is: %.3f\n", average);
    printf("The Range is: %.3f\n", range);
    printf("The Standard Deviation is: %.3f\n", std_dev);
    return 0;
}

/* main method runs get n method then runs a for loop N times */
int main(void){
    int N = get_n();
    int i = 0;
    lowest = DBL_MAX, highest = DBL_MIN;

/* the for loop runs get input for a 'current' variable and checks if the number is the highest or lowest number in the sequence */
    for(i=0; i<N; i++){
	double current = get_input();
	if (current < lowest){
	    lowest = current;
	}
	if (current > highest){
	    highest = current;
	}
	sum = sum + current;
	sum_squares = sum_squares + pow(current, 2.0);
    }

/* main method calculates average and standard deviation of the sequence */
    if (N == 0){
	lowest = 0;
	average = 0;
	std_dev = 0;
    } else {
	average = sum / N;
	std_dev = sqrt( (sum_squares / N) - pow(average, 2.0));
    }
    range = highest - lowest;
    print_results();

    return 0;
}
