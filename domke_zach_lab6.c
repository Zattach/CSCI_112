/*
 * Zach Domke
 * Lab 6,CSCI 112
 * 3/30/16
 */
// includes libraryies to allow for printf, fgets, strlen, strtol, and isalnum
#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// defines the maximum size of a sentence that can be taken in
#define SIZE 80

// initializes the other function used in this program
int run(void);

// takes in how many times to run and how many words are used to call program
int main(int argc, char *argv[]){
	int N;

// checks if a number is entered for how many times to run
	if(argc != 2){
		printf("ERROR: Please provide an integer greater than or equal to 0\n");
	} else {

// checks if number entered is positive and runs N times if it is
		N = (int) strtol(argv[1], NULL, 10);
		if(N < 0){	
			printf("ERROR: Please provide an integer greater than or equal to 0\n");
		} else {
			for(int i = 0; i < N; i++){
				run();
			}
		}
	}
	return 0;
}

// runs through asking for a sentence and printing it's reverse
int run(void){

// initializes variables used in this function
	char str[SIZE];
	char newstr[SIZE] = {'\0'};
	char word[SIZE] = {'\0'};
	int len;
	int temp = 0;
	int var = 0;

// gets the sentence to reverse and saves it to str
	if(fgets(str, SIZE, stdin)){
	}
	len = strlen(str) - 1;

// reverses the sentence by starting at end of sentence and adding each word to the newstr
	for(int j = len; j >=0; j--){
		if(isalnum(str[j])){
			word[temp] = str[j];
			temp++;
		} else {

// if there is a space it adds the word to newstr and if there is an apostraphe it adds that to the word
			if(str[j] == ' '){
				for(int k = temp - 1; k >= 0; k--){
					newstr[var] = word[k];
					var++;
				}
				newstr[var] = str[j];
				var++;
				temp = 0;
			} else if(str[j] == '\''){
				word[temp] = str[j];
				temp++;
			}
		}
	}

// adds the first word to the end of the newstr since it didn't have a space
	for(int i = temp - 1; i >= 0; i--){
		newstr[var] = word[i];
		var++;
	}

// resets var and temp values and prints out reversed sentence
	temp = 0;
	var = 0;
	printf("%s\n", newstr);
	return 0;
}
