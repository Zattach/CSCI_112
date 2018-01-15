/*
 * Zach Domke
 * Lab 1, CSCI 112
 * 1/26/16
 */
#include <stdio.h>

double valuen = 0;
double valuen1 = 0;
double valuen2 = 0;

int main(void){
	/* set variables using get_input */
	valuen2 = get_input(valuen2);
	valuen1 = get_input(valuen1);
	
	/* run get_next and print_result */
	get_next();
	print_result();
}

get_input(double value){
	/* get and set variables valuen1 and valuen2 */
	printf("Enter a value > ");
	scanf("%lf", &value);
	return value;
}

get_next(void){
	/* use a for loop to solve for desired variable */
	int i = 3;
	for(i=3; i<6; i++){
	valuen = (valuen2 / 2) + (3 * valuen1);
	valuen2 = valuen1;
	valuen1 = valuen;
	}
}

print_result(void){
	/* prints the final result */
	printf("The result is %.2f \n", valuen);
}
