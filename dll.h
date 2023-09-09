#ifndef DLL_H
#define DLL_H

typedef struct LinkedList{
        struct Node *head;
        struct Node *tail;
        int elements;
}LinkedList;


int add(Node *a, LinkedList *b);
Node* getNode(int node_num);


#endif
