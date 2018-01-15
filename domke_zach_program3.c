/*
 * Zach Domke
 * Program 3,CSCI 112
 * 4/24/16
 *
 */

// inports many c libraries to allow for more functionality in the program
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// creates structure for nodes that contains a value and points to last node
typedef struct node{
	double num;
	struct node *prev;
} node_t;

// creates structure for stack that storing top node and size of stack
typedef struct{
	struct node *top;
	int size;
} stack_t;

// initializes the methods used in the program
node_t * new_node(double val);
void push(stack_t *s, node_t *n);
node_t * pop(stack_t *s);
void print_stack(stack_t *s);

// reads through the line entered and performs calculations as requested
int main(void){
	// initializes the variables used and allocates memory for nodes and stack
	node_t *node1 = malloc(sizeof(node_t));
	node_t *node2 = malloc(sizeof(node_t));
	stack_t *stack = malloc(sizeof(stack_t));
	char *ptr;
	char line[51];
	double result;

	// populates the line string with the entered line and starts reading it
	fgets(line, 50, stdin);
	ptr = strtok(line, " \n");

	// saves the first value (always a number) to the first node
	result = atof(ptr);
	node1 = new_node(result);
	push(stack, node1);
	print_stack(stack);

	// runs through the line reading in numbers and symbolss
	while((ptr = strtok(NULL, " \n"))){
	
	// determines if char is number or action and saves numbers
		if(isdigit(*ptr) || (strncmp(ptr, ".", 1) == 0)){
			result = atof(ptr);
			node1 = new_node(result);
			push(stack, node1);
			print_stack(stack);
		} else {

	// determines if enough values have been entered to run actions
			int N = 2;
			if(strncmp(ptr, "sqrt", 4) == 0){
				N = 1;
			}
			if(stack[0].size < N){
				printf("ERROR: The user has not provided enough input values");
			} else {

	// saves first number to be used
				node1 = pop(stack);
				double temp1 = node1[0].num;
	// performs addition if requested by the user
				if(strncmp(ptr, "+", 1) == 0){
					node2 = pop(stack);
					double temp2 = node2[0].num;
					result = temp2 + temp1;
					node1 = new_node(result);
					push(stack, node1);
					printf("add\n");
				} else if(strncmp(ptr, "-", 1) == 0){
	// performs subtraction if requested by the user
					node2 = pop(stack);
					double temp2 = node2[0].num;
					result = temp2 - temp1;
					node1 = new_node(result);
					push(stack, node1);
					printf("subtract\n");
				} else if(strncmp(ptr, "*", 1) == 0){
	// performs multiplication if requested by the user
					node2 = pop(stack);
					double temp2 = node2[0].num;
					result = temp2 * temp1;
					node1 = new_node(result);
					push(stack, node1);
					printf("multiply\n");
				} else if(strncmp(ptr, "/", 1) == 0){
	// performs division if requested by the user
					node2 = pop(stack);
					double temp2 = node2[0].num;
					result = temp2 / temp1;
					node1 = new_node(result);
					push(stack, node1);
					printf("divide\n");
				} else if(strncmp(ptr, "%", 1) == 0){
	// performs modulus if requested by the user
					node2 = pop(stack);
					double temp2 = node2[0].num;
					int int1 = (int) temp1;
					int int2 = (int) temp2;
					result = int2 % int1;
					node1 = new_node(result);
					push(stack, node1);
					printf("modulus\n");
				} else if(strncmp(ptr, "pow", 3) == 0){
	// performs powers if requested by the user
					node2 = pop(stack);
					double temp2 = node2[0].num;
					result = pow(temp2, temp1);
					node1 = new_node(result);
					push(stack, node1);
					printf("raise to power\n");
				} else if(strncmp(ptr, "sqrt", 4) == 0){
	// performs square root if requested by the user
					result = sqrt(temp1);
					node1 = new_node(result);
					push(stack, node1);
					printf("square root\n");
				} else {
	// shows when something else is entered
					printf("Unavailable option please try again\n");
				}

	// prints out the stack to show what is currently in the stack
				print_stack(stack);
			}
		}
	}

	// prints out the result or tells if there were too many values entered
	if(stack[0].size == 1){
		node1 = pop(stack);
		result = node1[0].num;
		printf("Result: %lf\n", result);
	} else {
		printf("ERROR: stack size is: %d\n", stack[0].size);
	}

	return 0;
}

// creates a new node and stores a value in it, returns the node created
node_t * new_node(double val){
	node_t *temp = malloc(sizeof(node_t));
	temp[0].num = val;
	temp[0].prev = NULL;
	return temp;
}

// adds a node to the top of the stack
void push(stack_t *s, node_t *n){
	n[0].prev = s[0].top;
	s[0].top = n;
	s[0].size++;
}

// pops the top node off of the stack
node_t * pop(stack_t *s){
	if(s[0].top == NULL){
		return NULL;
	} else {
		node_t *temp = malloc(sizeof(node_t));
		temp = s[0].top;
		s[0].top = temp[0].prev;
		s[0].size--;
		return temp;
	}
}

// prints out the entire stack from top to bottom
void print_stack(stack_t *s){
	node_t *temp = malloc(sizeof *temp);
	temp = s[0].top;
	for(int i = s[0].size; i > 0; i--){
		printf("%lf\n", temp[0].num);
		temp = temp[0].prev;
	}
	printf("\n");
}
