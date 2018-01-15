/*
 * Zach Domke
 * Lab 5,CSCI 112
 * 3/2/16
 */
// allows for printf and scanf
#include <stdio.h>

// declare check method so main method can be at top
int check();

// declare bar array
int bar[12];

// recieves data and runs check method
int main(void){

	// prompts user to enter a bar code
	printf("Enter a bar code to check. Separate digits with a space >\n");

	// scans the ints entered and assigns them to the array
	for(int i = 0; i < 12; i++){
		scanf("%d", &bar[i]);
	}

	// prints out first line of output to confirm the code is correct
	printf("\nYou entered the code: ");
	for(int i = 0; i < 11; i++){
		printf("%d ", bar[i]);
	}
	printf("%d\n", bar[11]);

	// runs the check method to run the rest of the program
	check();

	return 0;
}

// checks if the barcode entered is valid or not
int check(void){

	// declares variables used in this method
	int sumO = 0;
	int sumE = 0;
	int sumF = 0;
	int val = 0;
	
	// step 1 adds all odd numbers together and multiplies by 3
	while(val < 12){
		sumO += bar[val];
		val += 2;
	}
	sumO = sumO * 3;
	printf("STEP 1: Sum of odds times 3 is %d\n", sumO);
	
	// step 2 adds all even numbers together
	val = 1;
	while(val < 11){
		sumE += bar[val];
		val += 2;
	}
	printf("STEP 2: Sum of the even digits is %d\n", sumE);
	
	// step 3 adds the two sums together
	sumF = sumO + sumE;
	printf("STEP 3: Total sum is %d\n", sumF);
	
	// step 4 finds the check digit using the modulus operator
	val = sumF % 10;
	if(val != 0){
		val = 10 - val;
	}
	printf("STEP 4: Calculated check digit is %d\n", val);
	
	// step 5 checks if the check digit is equal to the last digit
	if(val == bar[11]){
		printf("STEP 5: Check digit and last digit match\n");
		printf("Barcode is VALID.\n");
	}else{
		printf("STEP 5: Check digit and last digit do not match\n");
		printf("Barcode is INVALID.\n");
	}
	return 1;
}
