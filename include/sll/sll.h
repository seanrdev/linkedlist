#ifndef SLL_H
#define SLL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "node.h"

/**
 * Singly-linked list
 * with pointers to head and tail nodes
 * and a count of elements
 */
typedef struct SLinkedList{
  sll_node_t *head;
  size_t      size;
} slinkedlist_t;

/**
 * allocate memory for a LinkedList
 * @returns pointer to LinkedList
 */
slinkedlist_t *alloc_SLinkedList();

/**
 * initialize a LinkedList
 * @param ll pointer to LinkedList
 */
void           init_SLinkedList(slinkedlist_t *ll);

/**
 * remove all elements from a LinkedList,
 * then deinitialize it for security
 * @param ll pointer to LinkedList
 */
void         deinit_SLinkedList(slinkedlist_t *ll);

/**
 * frees memory for a LinkedList
 * @param ll pointer to LinkedList
 */
void           free_SLinkedList(slinkedlist_t *ll);

/**
 * @param ll pointer to LinkedList
 * @returns whether the LinkedList is empty
 */
bool        isempty_SLinkedList(slinkedlist_t *ll);

/**
 * @param ll pointer to LinkedList
 * @param elem element to find
 * @returns index of the element if found, -1 otherwise
 */
ssize_t        find_SLinkedList(slinkedlist_t *ll, sll_element_t elem);

/**
 * @param ll pointer to LinkedList
 * @param ndx index to get
 * @returns element at the specified index
 */
sll_element_t  *get_SLinkedList(slinkedlist_t *ll, size_t ndx);

/**
 * @param ll pointer to LinkedList
 * @param elem element to insert
 * @returns number of elements in the LinkedList if insertion was successful, -1 otherwise
 */
ssize_t      insert_SLinkedList(slinkedlist_t *ll, sll_element_t elem);

/**
 * @param ll pointer to LinkedList
 * @param ndx index to remove
 * @returns element at the specified index
 */
sll_element_t remove_SLinkedList(slinkedlist_t *ll, size_t ndx);

// TODO don't let client code access Node
//int add(struct SLLNode *a, struct SLinkedList *b);
//struct SLLNode* getSLLNode(unsigned int node_num, struct SLinkedList *l);

#ifdef __cplusplus
}
#endif

#endif

