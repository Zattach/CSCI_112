/*
 * Zach Domke
 * Lab 3,CSCI 112
 * 2/17/16
 */

// imports stdio.h and math.h to allow for scanf and sin(), cos(), tan()
#include <stdio.h>
#include <math.h>

// defines the values of PI and LOOP_LIMIT as 3.14 and 90 respectively
#define PI 3.14159
#define LOOP_LIMIT 90

// creates variables using enumerator command
typedef enum{
	Sine,
	Cosine,
	Tangent,
	Quit
} menu_t;

// initializes methods used in the program
int input();
int math(int trig);
int main();

// initializes enumerator variable used in the program
menu_t MENU = Sine;

// initializes variables used in the program
double deg;
double rad;
double answ;

int input(void){
	do{
		// prompts user for an input that would meet the criteria
		printf("Please choose an option: (0) Sine (1) Cosine (2) Tangent (3) QUIT\n");
		printf("Enter your choice > ");
		scanf("%u", &MENU);

		// checks input and runs the math method
		switch(MENU){
			case Sine: math(0);
			break;
			case Cosine: math(1);
			break;
			case Tangent: math(2);
			break;
			case Quit: break;
			default: printf("%u is an invalid option. Please try again.\n", MENU);
			break;
		}

	// ends while loop when QUIT option is chosen
	} while (MENU != Quit);
	printf("You chose QUIT. Thank you, come again!\n");
	return MENU;
}

int math(int trig){
	// increases value in degrees by 15 between 0 and 90
	for(deg = 0; deg <= LOOP_LIMIT; deg += 15){

		// converts degrees to radians
		rad = PI * (deg/180);

		// runs sine method when sine is chosen
		if(trig == 0){
			answ = sin(rad);
			printf("\tsin(%.f) = %.4f\n", deg, answ);

		// runs cosine method when cosine is chosen
		}else if(trig == 1){
			answ = cos(rad);
			printf("\tcos(%.f) = %.4f\n", deg, answ);

		// runs tangent method when tangent is chosen
		}else if(trig == 2){

			// checks for tan of 90 and replaces with undefined
			if(deg == LOOP_LIMIT){
				printf("\ttan(%.f) is UNDEFINED\n", deg);
			}else{
				answ = tan(rad);
				printf("\ttan(%.f) = %.4f\n", deg, answ);
			}

		// returns error if something went wrong
		}else{
			printf("Something broke\n");
		}
	}
	return 0;
}

// runs other methods
int main(void){
	input();
}
