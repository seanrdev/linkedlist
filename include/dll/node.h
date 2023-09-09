#ifndef NODE_H
#define NODE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Node{
        struct Node *next;
        struct Node *prev;
        int digit;
}Node;

#ifdef __cplusplus
}
#endif

#endif

