/*
 * Zach Domke
 * Lab 8,CSCI 112
 * 4/12/16
 *
 */

// imports stdio.h and stdlib.h to allow for scan, print, calloc and free
#include <stdio.h>
#include <stdlib.h>

// defines the maximum length of strings
#define NAME_SIZE 25

// creates structure student that involoves sid, name, grades and gpa
typedef struct{
	int sid;
	char nameL[NAME_SIZE];
	char nameF[NAME_SIZE];
	float *grade;
	float gpa;
} student;

// initializes the methods used in the program
void scan_student(student *s, int pos, int numG);
void solve(student *s, int pos, int numG);
void print_student(student *s, int pos, int numG);
void release(student *s, int numS);

int main(void){
// creates, scans, and returns number of students and grades
	int numS, numG;
	scanf("%d", &numS);
	scanf("%d", &numG);
	printf("Number of students: %d\n", numS);
	printf("Number of grades (each): %d\n", numG);

// creates array of students and scans then prints them
	student *stu = (student *)calloc(numS, sizeof(student));
	for(int i = 0; i < numS; i++){
		scan_student(stu, i, numG);
		solve(stu, i, numG);
	}
	for(int i = 0; i < numS; i++){
		print_student(stu, i, numG);
	}

// frees the students and grades to prevent memory leak
	release(stu, numS);

	return 0;
}

void scan_student(student *s, int pos, int numG){
// scans the data given and saves it to appropriate student
	scanf("%d %s %s",
		&s[pos].sid,
		s[pos].nameL,
		s[pos].nameF);

// creates and fills an array of grades
	s[pos].grade = (float *)calloc(numG, sizeof(float));
	for(int i = 0; i < numG; i++){
		float var;
		scanf(" %f", &var);
		s[pos].grade[i] = var;
	}
}

void solve(student *s, int pos, int numG){
// finds the average of the grades given to the program
	float var = 0;
	for(int i = 0; i < numG; i++){
		var += *(s[pos].grade + i);
	}
	s[pos].gpa = var / numG;
}

void print_student(student *s, int pos, int numG){
// prints out data other than grades for each student
	printf("ID: %d, Name: %s %s, GPA: %.2f\n", 
		s[pos].sid,
		s[pos].nameF,
		s[pos].nameL,
		s[pos].gpa);

// prints each grade systematically
	printf("Grades:");
	for(int i = 0; i < numG; i++){
		printf(" %.1f", *(s[pos].grade + i));
	}
	printf("\n");
}

void release(student *s, int numS){
// frees students and grades to prevent memory leak	
	for(int i = 0; i < numS; i++){
		free(s[i].grade);
		s[i].grade = NULL;
	}
	free(s);
	s = NULL;
}
