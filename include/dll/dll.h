#ifndef DLL_H
#define DLL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "node.h"

/**
 * Doubly-linked list
 * with pointers to head and tail nodes
 * and a count of elements
 */
typedef struct LinkedList{
  node_t *head;
  node_t *tail;
  size_t  elements;
} linkedlist_t;

/**
 * allocate memory for a LinkedList
 * @returns pointer to LinkedList
 */
linkedlist_t *alloc_LinkedList();

/**
 * initialize a LinkedList
 * @param ll pointer to LinkedList
 */
void           init_LinkedList(linkedlist_t *ll);

/**
 * remove all elements from a LinkedList,
 * then deinitialize it for security
 * @param ll pointer to LinkedList
 */
void         deinit_LinkedList(linkedlist_t *ll);

/**
 * frees memory for a LinkedList
 * @param ll pointer to LinkedList
 */
void           free_LinkedList(linkedlist_t *ll);

/**
 * @param ll pointer to LinkedList
 * @returns whether the LinkedList is empty
 */
bool        isempty_LinkedList(linkedlist_t *ll);

/**
 * @param ll pointer to LinkedList
 * @param elem element to find
 * @returns index of the element if found, -1 otherwise
 */
ssize_t        find_LinkedList(linkedlist_t *ll, element_t elem);

/**
 * @param ll pointer to LinkedList
 * @param ndx index to get
 * @returns element at the specified index
 */
element_t      *get_LinkedList(linkedlist_t *ll, size_t ndx);

/**
 * @param ll pointer to LinkedList
 * @param elem element to insert
 * @returns number of elements in the LinkedList if insertion was successful, -1 otherwise
 */
ssize_t      insert_LinkedList(linkedlist_t *ll, element_t elem);

/**
 * @param ll pointer to LinkedList
 * @param ndx index to remove
 * @returns element at the specified index
 */
element_t    remove_LinkedList(linkedlist_t *ll, size_t ndx);

// TODO don't let client code access Node
int add(struct Node *a, struct LinkedList *b);
struct Node* getNode(unsigned int node_num, struct LinkedList *l);

#ifdef __cplusplus
}
#endif

#endif

