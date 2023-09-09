#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "dll/node.h"

typedef struct LinkedList{
	struct Node *head;
	struct Node *tail;
	int size;
} linkedlist_t;

int initialize(linkedlist_t *l){
	l->head = NULL;
	l->tail = NULL;
}

void add(node_t *a, linkedlist_t *l){
	if(l->size == 0){
		l->head = a;
		a->prev = NULL;
		a->next = NULL; //redundant
		l->size++;
	}else if(l->size == 1){
		l->tail = a;
		a->next = NULL;
		a->prev = l->head;
		l->size++;
	} else {
		//Place on tail end and expand.
	 	node_t *temp;
		temp = l->tail;
		l->tail = a;
		a->prev = l->tail;
		a->next = NULL;
		a = l->tail;
	}
}

int getNode(unsigned int node_num, linkedlist_t *l){
	if(l->size > node_num){
		return -1;
	}
	int index = 1;
	struct Node *traverse = l->head;
	while(index < node_num){
		traverse = traverse->next;
	}
	return traverse->element;
}

//return -1 if an issue with removing the Node
int removeNode(unsigned int node_num, linkedlist_t *l){
	if(l->size > node_num){
		return -1;
	}
	int index = 1;
	node_t *traverse = l->head;
	while(index < node_num){
		traverse = traverse->next;
	}
	//Here is where the node should be removed.
	//At least that's how it works in my brain.
	traverse->next->prev = traverse->prev;
	traverse->prev->next = traverse->next;
	free(traverse);
	l->size--;
}
