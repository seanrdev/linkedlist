#ifndef DLL_H
#define DLL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "node.h"

typedef struct LinkedList{
        struct Node *head;
        struct Node *tail;
        int elements;
}LinkedList;

int add(Node *a, LinkedList *b);
Node* getNode(int node_num);

#ifdef __cplusplus
}
#endif

#endif

