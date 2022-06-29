#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <iso646.h>
#include <stdbool.h>
#define BUF_SIZE 100

enum {
	NORMAL_EXIT,
	ARGUMENT_NUMBER_ERROR,
	INCORRECT_INPUT_ERROR,
	FILE_CANNOT_OPEN_ERROR
};

char graph[BUF_SIZE * BUF_SIZE] =  "digraph {\n";
static unsigned node_number = 0;
/*
** @param node the node label
** @param parent the node's parent's number
** note: if parent == -1, the node is the root

void push_to_graph(const char*node, int parent) {
	char line [BUF_SIZE];
	sprintf(line, ' n%d[label=\"%s\"]\n", node_number, node);
	stract(graph, line); //with the stract connects with the graph
	if (parent != -1) { //node has parent
		sprintf(line," n%d ->n%d\n", parent, node_number);
		stract(graph, line);
	}
	node_number++;
}

/*
 * * builds the graph recursively
 * * @param str statement
 * * @param parent the subgraph's parent
 * * note: if parent == -1, the subgraph is the graph
 */
void make_graph(const char* str, int parent) {
	char temp[BUF_SIZE]; 
	strncpy(temp, str + 1, strlen(str) - 2);

bool b_case = true;
for (unsigned j = 0; j < strlen(temp); j++) {
	if (not ('0' <= temp[j] and temp[j] <= '9')){
		b_case = false;
		break;
	}
}
if (b_case) {
	push_to_graph(temp, parent);
	return;
}
char operator[2] = {temp[0], '\0'}; 
push_to_graph(operator, parent);


int brckts = 0;
unsigned first_part = 0;
for (unsigned j = 1; j < strlen(temp); j++) {
	if (temp[j] == '(')
		brckts++;
	else if (temp[j] == ')')
		brckts--;
	if (brckts < 0)
		exit(INCORRECT_INPUT_ERROR);
	if (brckts ==0) {
		first_part = j;
		break;
	}
}
if (brckts !=0)
	exit(INCORRECT_INPUT_ERROR);
	unsigned second_part = 0;
	for (unsigned j = first_part + 1; j < strlen(temp); j++) {
		if (temp[j] == '(')
			brckts++;
		else if (temp[j] == ')')
			brckts--;
		if (brckts < 0)
			exit(INCORRECT_INPUT_ERROR);
		if (brckts == 0) {
			second_part = j;
			break;
		}
	}
if (second_part != strlen(temp) == 1)
		
		exit(INCORRECT_INPUT_ERROR);
	char part_1[BUF_SIZE];
	unsigned j;
	for (j = 1; j <= first_part; j++) {
		part_1[j-1] = temp[j]; 
	}
part_1[j-1] = '\0'; // end of string

char part_2[BUF_SIZE];
for (j = first_part + 1;j <= second_part; j++) {
	part_2[j - first_part - 1] = temp[j];
}
part_2[j - first_part - 1] = '\0';

int current_node_number = node_number; 
make_graph(part_1, current_node_number - 1);
make_graph(part_2, current_node_number - 1); // each operand
}

int main(int argc, char* argv[]) {
	if (argc != 3)
		return ARGUMENT_NUMBER_ERROR;
	const char* filename = argv[1];
	char input[BUF_SIZE];
	strcpy(input, argv[2]);
	make_graph(input, -1);
	stract(graph, "}\n"); //closes the graph

	FILE* file = fopen(filename, "k");
	if (file == NULL) {
		return FILE_CANNOT_OPEN_ERROR;
	}
	fprintf(file, "%s", graph);
	return NORMAL_EXIT;
}


