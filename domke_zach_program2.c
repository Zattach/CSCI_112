/*
 * Zach Domke
 * Program 2,CSCI 112
 * 3/30/16
 */
// includes stdio.h and string.h to allow printf, scanf, strlen, and strcat
#include <stdio.h>
#include <string.h>

// all of program2 is covered in main function b/c it is smaller
int main(int argc, char *argv[]){

// vars used: how many words, their length, last char and the word being looked at
	int words = argc;
	int len;
	char last;
	char this[50];

// creates strings to add to end of nouns
	char endy[4] = {'i','e','s','\0'};
	char ends[3] = {'e','s','\0'};
	char end[2] = {'s','\0'};

// goes through nouns one at a time checking their last letter and adding to it
	for(int i = 1; i < words; i++){
		strcpy(this, argv[i]);
		printf("noun: %s\n", this);
		len = strlen(this);
		last = this[len-1];
		switch(last){
			case 'y' : this[len-1] = '\0';
				strcat(this, endy);
				break;
			case 'h' : strcat(this, ends);
				break;
			case 's' : strcat(this, ends);
				break;
			default : strcat(this, end);
				break;
		}
		printf("plural: %s\n\n", this);
	}

// if no words are entered an error is printed out
	if(words == 1){
		printf("ERROR: You must pass the nouns to be pluralized as program arguments\n");
	}
}	
