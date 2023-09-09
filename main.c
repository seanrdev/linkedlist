#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "dll.h"

int main(){
	Node *test = (Node *) malloc(1 * sizeof(struct Node*));
	LinkedList *test1 = (LinkedList *) malloc(1 * sizeof(struct LinkedList*));
	test1->elements = 0; //initialize count to 0.
	initialize(test1);
	int data;
	add(test, test1);
}
//test
