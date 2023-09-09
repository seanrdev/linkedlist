#include <stddef.h>
#include "dll/node.h"

typedef struct LinkedList{
	struct Node *head;
	struct Node *tail;
	int elements;
}LinkedList;

int initialize(LinkedList *a){
	a->head = NULL;
	a->tail = NULL;
}

int add(Node *a, LinkedList *l){
	if(l->elements == 0){
		a->next = l->tail;
		a->prev = l->head;
		l->head->next = a;
		l->tail->prev = a;
		l->elements++;
	}
}

Node* getNode(int node_num, LinkedList *l){
	//
}
/*
0x0000000008001224 in add (a=0x80052a0, b=0x80052c0) at dll.c:14
14                      b->head->next = a;
*/
