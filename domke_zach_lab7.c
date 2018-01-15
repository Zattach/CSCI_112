/*
 * Zach Domke
 * Lab 7,CSCI 112
 * 4/7/16
 *
 */
// includes packages to allow for input and output, string handling, and strtol()
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// defines the maximum amount of elements and maximum size of name and desc.
#define SIZE 80
#define MAX_ELEMENTS 20

// defines the type element_t as a structure
typedef struct{
	int aNum;
	char name[SIZE];
	char sym[3];
	char class[SIZE];
	float aWeight;
	int electrons[7];
} element_t;

// initializes functions used using the prototypes
void scan_element(element_t *e, int j);
void print_element(element_t *e, int j); 

int main(int argc, char *argv[]){
	int N;
	int smalln = 130;
	char smallstr[SIZE];
	int largen = 0;
	char largestr[SIZE];
// checks if a number was entered when running the program
	if(argc != 2){
		printf("ERROR: You must provide exactly one argument to this program.\n");
	} else {
// converts and saves argc(string) to N(int) and checks if N meets criteria
		N = (int) strtol(argv[1], NULL, 10);
		if(N <= 0 || N > MAX_ELEMENTS){
			printf("ERROR: You must provide an integer greater than 0 and less than or equal to %d.\n", MAX_ELEMENTS);
		} else {
// creates an array of element_t called elems
			element_t *elems = malloc(N * sizeof *elems);
// runs scan method and determines the elements with the largest and smallest atomic numbers
			for(int i = 0; i < N; i++){
				scan_element(elems, i);
				if(elems[i].aNum > largen){
					largen = elems[i].aNum;
					strcpy(largestr, elems[i].name);
				}
				if(elems[i].aNum < smalln){
					smalln = elems[i].aNum;
					strcpy(smallstr, elems[i].name);
				}
			}
// prints total elements and elements with largest and smallest atomic numbers
			printf("%d total elements.\n", N);
			printf("%s had the smallest atomic number.\n", smallstr);
			printf("%s had the largest atomic number.\n", largestr);
// prints out all elements in required format
			for(int j = 0; j < N; j++){
				print_element(elems, j);
			}
		}
	}
	return 0;
}

void scan_element(element_t *e, int k){
// scans input and saves to the element_t
	scanf("%d %s %s %s %f %d %d %d %d %d %d %d",
		&e[k].aNum,
		e[k].name,
		e[k].sym,
		e[k].class,
		&e[k].aWeight,
		&e[k].electrons[0],
        &e[k].electrons[1],
        &e[k].electrons[2],
        &e[k].electrons[3],
        &e[k].electrons[4],
        &e[k].electrons[5],
        &e[k].electrons[6]);
}

void print_element(element_t *e, int l){
// prints elements in required format
	printf("---------------\n");
	printf("| %d\t%.4f\n| %s\t%s\n|",
		e[l].aNum,
		e[l].aWeight,
		e[l].sym,
		e[l].name);
	for(int n = 0; n < 7; n++){
		if(e[l].electrons[n] != 0){
			printf(" %d", e[l].electrons[n]);
		} else {
			n = 7;
		}
	}
    printf("\n---------------\n");
}
