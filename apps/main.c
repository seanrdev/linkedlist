#include <stdio.h>
#include <stdlib.h>
#include "dll/node.h"
#include "dll/dll.h"

int main(){
	Node *test = (Node *) malloc(1 * sizeof(struct Node*));
	test->digit = 23;
	LinkedList *test1 = (LinkedList *) malloc(1 * sizeof(struct LinkedList*));
	test1->elements = 0; //initialize count to 0.
	initialize(test1);
	int data;
	add(test, test1);
	Node *test6 = (Node *) malloc(1 * sizeof(struct Node*));
	test6->digit = 45;
	add(test6, test1);
	printf("Node 1 has %d and 2 has %d", test1->head->digit, test1->tail->digit);

	LinkedList *large = (LinkedList *) malloc(1 * sizeof(struct LinkedList*));
	//Node (*tester) [100] = (Node *) malloc(1 * sizeof(struct Node*));
	Node (*tester) [100] = (Node *) malloc(1 * sizeof(struct Node*));

	for(int i = 0; i < 100; i++){
		tester[i]->digit = i*3;
		add(tester[1], large);
	}
	printf("complete");
}
//test
