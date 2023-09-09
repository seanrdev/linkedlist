#include <stdio.h>
#include <stdlib.h>
#include "dll/node.h"
#include "dll/dll.h"

int main(){
	Node *test = (Node *) malloc(1 * sizeof(struct Node*));
	LinkedList *test1 = (LinkedList *) malloc(1 * sizeof(struct LinkedList*));
	test1->elements = 0; //initialize count to 0.
	initialize(test1);
	int data;
	add(test, test1);
	Node *test6 = (Node *) malloc(1 * sizeof(struct Node*));
	add(test6, test1);
	printf("Test end");
}
//test
