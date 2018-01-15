/*
 * Zach Domke
 * Lab 4,CSCI 112
 * 2/24/16
 */
#include <stdio.h>
#include <math.h>

// declarevariables used throughout project
float val;
int var;

// declare userMenu method
int userMenu();

// declare equation methods
void equation1(float * result);
void equation2(float * result);
void equation3(float * result);
void equation4(float * result);

// delare get methods
float getPositionInitial();
float getPositionFinal();
float getVelocityInitial();
float getVelocityFinal();
float getTime();
float getAcceleration();

int main(void){
	printf("Welcome to the MOTION EQUATION CALCULATOR\n\n");
	int choice;
	// do while loop to run calculator until QUIT is chosen
	do{
		// gets user input on which equation to use
		choice = userMenu();
		float result;
		switch(choice){
			case 1:
				// runs equation 1 with the result pointer
				equation1(&result);
				break;
			case 2:
				// runs equation 2 with the result pointer
				equation2(&result);
				break;
			case 3:
				// runs equation 3 with the result pointer
				equation3(&result);
				break;
			case 4:
				// runs equation 3 with the result pointer
				equation4(&result);
				break;
			case 5:
				// thanks the user when the QUIT command is chosen
				printf("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye.\n");
				return 0;
				break;
			default:
				// tells the user when an invalid option is chosen
				printf("Invalid Option. Please try again.\n\n");
				break;
		}
		// prints the result when a valid option is chosen
		if(0 < choice && choice < 5){
			printf("Your result is %.4f.\n\n", result);
		}
	} while (choice != 5);
	return 0;
}

// gets initial position
float getPositionInitial(void){
	printf("\tEnter initial position > ");
	scanf("%f", &val);
	return val;
}

// gets final position
float getPositionFinal(void){
	printf("\tEnter final position > ");
	scanf("%f", &val);
	return val;
}

// gets initial velocity
float getVelocityInitial(void){
	printf("\tEnter initial velocity > ");
	scanf("%f", &val);
	return val;
}

// gets final velocity
float getVelocityFinal(void){
	printf("\tEnter final velocity > ");
	scanf("%f", &val);
	return val;
}

// gets acceleration
float getAcceleration(void){
	printf("\tEnter acceleration > ");
	scanf("%f", &val);
	return val;
}

// gets time
float getTime(void){
	printf("\tEnter time > ");
	scanf("%f", &val);
	return val;
}

// solves for final velocity using the first equation
void equation1(float * result){
	float v0 = getVelocityInitial();
	float a = getAcceleration();
	float t = getTime();
	float vf = (v0 + (a * t));
	*result = vf;
}

// solves for final position using the second equation
void equation2(float * result){
	float x0 = getPositionInitial();
	float v0 = getVelocityInitial();
	float t = getTime();
	float a = getAcceleration();
	float xf = (x0 + (v0 * t) + (.5 * a * (pow(t,2))));
	*result = xf;
}

// solves for final velocity using the third equation
void equation3(float * result){
	float v0 = getVelocityInitial();
	float a = getAcceleration();
	float xf = getPositionFinal();
	float x0 = getPositionInitial();
	float vf = sqrt(pow(v0,2) + (2 * a * (xf - x0)));
	*result = vf;
}

// solves for final position using the fourth equation
void equation4(float * result){
	float x0 = getPositionInitial();
	float vf = getVelocityFinal();
	float v0 = getVelocityInitial();
	float t = getTime();
	float xf = (x0 + (.5 * (vf + v0) * t));
	*result = xf;
}

// prompts user to choose an equation or to quit the calculator
int userMenu(){
	printf("Choose a motion equation 1-4 or choose 5 to QUIT > ");
	scanf("%d", &var);
	return var;
}
