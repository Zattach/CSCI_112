/*
 * Zach Domke
 * lab 9,CSCI 112
 * 4/18/16
 *
 */

// includes stdio.h, stdlib.h, and string.h libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defines maximum size of strings used
#define SIZE 25

// creates a structure element_t that is made of an int, a float, and strings
typedef struct{
	int aNum;
	char sym[4];
	char name[SIZE];
	float aWght;
	char state[7];
	char bond[SIZE];
	char year[9];
} element_t;

// initializes the methods used throughout the program
void search_element(element_t *e, int pos);
void print_element(element_t *e, int pos, FILE *output);

int main(int argc, char *argv[]){
// creates a null file variable and reads if any parameters are entered
	int strt = 1;
	FILE *output = NULL;
	if(argc < 2){
		printf("ERROR: Please provide at least one program argument.\n");
	} else {
// checks if first parameter is a symbol or a file name
		char * dot = strchr(argv[1], '.');
		if(dot){
			output = fopen(argv[1], "w");
			strt = 2;
		}

// creates an array of structs and searches for symbols entered
		element_t *elems = calloc((argc), sizeof(element_t));
		for(int i = strt; i < argc; i++){
			strcpy(elems[i].sym, argv[i]);
			search_element(elems, i);
		}
// prints the output to stdout or a file if entered
		for(int i = strt; i < argc; i++){
			print_element(elems, i, output);
		}
	}

	return 0;
}

void search_element(element_t *e, int pos){
// reads element_db.csv and creates a test variable
	FILE *input = fopen("element_db.csv", "r");
	element_t *test = calloc(1, sizeof(element_t));;
	char line[61] = {'\0'};
	char *ptr;
	if(input){
// saves a line to test then checks if it is the same symbol as was entered
		do{
			if(fgets(line, 60, input));
			ptr = strtok(line, ",");
			test[0].aNum = atoi(ptr);
			ptr = strtok(NULL, ",");
			strcpy(test[0].sym, ptr);
			ptr = strtok(NULL, ",");
			strcpy(test[0].name, ptr);
			ptr = strtok(NULL, ",");
			test[0].aWght = atof(ptr);
			ptr = strtok(NULL, ",");
			strcpy(test[0].state, ptr);
			ptr = strtok(NULL, ",");
			strcpy(test[0].bond, ptr);
			ptr = strtok(NULL, ",\n");
			strcpy(test[0].year, ptr);
		} while(strcmp(test[0].sym, e[pos].sym) != 0 && test[0].aNum < 118);
// saves the test struct if it matches
		if(strcmp(test[0].sym, e[pos].sym) == 0){
			e[pos].aNum = test[0].aNum;
			strcpy(e[pos].name, test[0].name);
			e[pos].aWght = test[0].aWght;
			strcpy(e[pos].state, test[0].state);
			strcpy(e[pos].bond, test[0].bond);
			strcpy(e[pos].year, test[0].year);
		} else {
// sets awght equal to -1 if the symbol entered does not match an element
			e[pos].aWght = -1;
		}
	}
}

void print_element(element_t *e, int pos, FILE *output){
// uses file entered or stdout depending on what is requested
	if(output == NULL){
		output = stdout;
	}
// prints a warning if the symbol entered does not match an element
	if(e[pos].aWght < 0){
		fprintf(output, "WARNING: No such element: %s\n", e[pos].sym);
	} else {
// prints out the element in the correct format if it exists
		fprintf(output, "---------------\n");
		fprintf(output, "| %d\t%.4f\n| %s\t%s\n| %s\n| %s\n| Found: %s\n",
			e[pos].aNum,
			e[pos].aWght,
			e[pos].sym,
			e[pos].name,
			e[pos].state,
			e[pos].bond,
			e[pos].year);
		fprintf(output, "---------------\n");
	}
}
