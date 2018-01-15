/*
 * Zach Domke
 * Bonus Program,CSCI 112
 * 3/23/16
 */
// includes stdio.h to allow for printf and scanf
#include <stdio.h>

// includes string.h to allow for more ability in handling strings
#include <string.h>

// defines the max size of the word that can be used
#define MAX_SIZE 25

// defines the number of wrong guesses the used is allowed to make
#define MAX_WRONG_GUESSES 6

// initializes the check method which takes in a guess and checks if it is correct
int check(int len);

// initializes the out method which prints the output
int out(int gssLft, int crrct, char gss);

// initializes the string to be filled with the word to guess
char str1[MAX_SIZE];

// initializes the string to be filled with asterisks
char str2[MAX_SIZE];

int main(int argc, char *argv[]){
	int len = strlen(argv[1]);

// checks if user input meets length criteria
	if(len <= MAX_SIZE){
		strcpy(str1, argv[1]);
		strcpy(str2, str1);
		for(int i = 0; i < len; i++){
			str2[i] = '*';
		}

// continues with rest of program
		check(len);
	} else {

// returns error if word is too long
		printf("ERROR: Input argument is too long\n");
	}
	return 0;
}

int check(int len){
// creates counters to check guesses left, guesses made, when correct
	int gssLft = MAX_WRONG_GUESSES;
	int cntr1 = 0;
	int cntr2 = 0;
	while(cntr2 < len && gssLft > 0){

// prompts user to input a char as a guess
		char gss;
		printf("Guess a letter (%d attempts left) > ", gssLft);
		scanf(" %c", &gss);
		int crrct = 0;

// determines if guess is correct and displays correct letters
		for(int i = 0; i < len; i++){

// if they have already guessed the letter counter is set to -1
			if(str2[i] == gss){
				crrct = -1;

// when a guess is correct display changes from asterisk to char and counter increases
			} else if(str1[i] == gss){
				str2[i] = str1[i];
				crrct++;
				cntr2++;
			}
		}

// reduces the counter for guesses left if guess has already been made or is incorrect
		if(crrct == 0 || crrct == -1){
			gssLft--;
		}

// runs the out method to print output and adds to counter for guesses made
		out(gssLft, crrct, gss);
		cntr1++;
	}

// runs when the game is finished telling user if they won and guesses made
	printf("\nGame Over\n");
	if(gssLft == 0){
		printf("%d total guesses made.\nOut of guesses.\nYou lost.\n", cntr1);
	} else {
		printf("%d total guesses made.\nYou won!\n", cntr1);
	}
	return 0;
}

int out(int gssLft, int crrct, char gss){
// displays the hangman using ASCII characters
	switch(gssLft){
		case 0 : printf("\n___\n|\\o/\n| | \n|/ \\\n-----\n");
		break;
		case 1 : printf("\n___\n|\\o/\n| | \n|/  \n-----\n");
		break;
		case 2 : printf("\n___\n|\\o/\n| | \n|   \n-----\n");
		break;
		case 3 : printf("\n___\n|\\o/\n|   \n|   \n-----\n");
		break;
		case 4 : printf("\n___\n|\\o \n|   \n|   \n-----\n");
		break;
		case 5 : printf("\n___\n| o \n|   \n|   \n-----\n");
		break;
		case 6 : printf("\n___\n|   \n|   \n|   \n-----\n");
		break;
	}

// prints out word to guess with asterisks
	printf("%s \n", str2);

// prints how many letters they got correct with the guess
	switch(crrct){
		case -1 : printf("You already guessed %c!\n\n", gss);
		break;
		case 0 : printf("There are no %c's\n\n", gss);
		break;
		case 1 : printf("There is 1 %c\n\n", gss);
		break;
		default : printf("There are %d %c's\n\n", crrct, gss);
		break;
	}
	return 0;
}
