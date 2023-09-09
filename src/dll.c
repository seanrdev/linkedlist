#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
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

void add(Node *a, LinkedList *l){
	if(l->elements == 0){
		l->head = a;
		a->prev = NULL;
		a->next = NULL; //redundant
		l->elements++;
	}else if(l->elements == 1){
		l->tail = a;
		a->next = NULL;
		a->prev = l->head;
		l->elements++;
	} else {
		//Place on tail end and expand.
	 	Node *temp;
		temp = l->tail;
		l->tail = a;
		a->prev = l->tail;
		a->next = NULL;
		a = l->tail;
	}
}

Node* getNode(unsigned int node_num, LinkedList *l){
	if(l->elements > node_num){
		return NULL;
	}
	int index = 1;
	Node *traverse = l->head;
	while(index < node_num){
		traverse = traverse->next;
	}
	return traverse->digit;
}


