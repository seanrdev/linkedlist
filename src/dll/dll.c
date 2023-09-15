#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "dll/node.h"
#include <stdbool.h>
#define NULL ((char *)0)

typedef struct LinkedList{
	struct Node *head;
	struct Node *tail;
	int size;
} linkedlist_t;


linkedlist_t *alloc_LinkedList(){
	linkedlist_t *ll = (linkedlist_t *) malloc(1 * sizeof(linkedlist_t));
	return ll;
}

void init_LinkedList(linkedlist_t *ll){
	ll->head = NULL;
	ll->tail = NULL;
	ll->size = 0;
}

void deinit_LinkedList(linkedlist_t *ll){
	ll->head = NULL;
	ll->tail = NULL;
	ll = NULL;
}

void free_LinkedList(linkedlist_t *ll){
	free(ll);
}

bool isempty_LinkedList(linkedlist_t *ll){
	if(ll->size < 1){
		return true;
	}
	return false;
}

ssize_t find_LinkedList(linkedlist_t *ll, element_t elem){
	/*
    if(l->size > node_num){
        return -1;
    }
    int index = 1;
    struct Node *traverse = l->head;
    while(index < node_num){
        traverse = traverse->next;
    }
    return traverse->element;
*/
	if(ll->size < 1){
		return -1; //Empty
	}//HERE
}

element_t *get_LinkedList(linkedlist_t *ll, size_t ndx){
	return 0;
}

ssize_t insert_LinkedList(linkedlist_t *ll, element_t elem){
	return -1;
}

element_t remove_LinkedList(linkedlist_t *ll, size_t ndx){
	return 0;
}

/*
int initialize(linkedlist_t *l){
	l->head = NULL;
	l->tail = NULL;
}
*/
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
