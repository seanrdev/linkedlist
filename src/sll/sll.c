#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "sll/sll.h"
#include "sll/node.h"

slinkedlist_t *alloc_SLinkedList() {
  return (slinkedlist_t *)malloc(sizeof(slinkedlist_t));
}

/*int*/void    init_SLinkedList(slinkedlist_t *ll) {
  //if(__builtin_expect(ll == NULL, false)) return -1;
  assert(ll != NULL);
  ll->head = NULL;
  ll->size =    0;
  //return 0;
}

void         deinit_SLinkedList(slinkedlist_t *ll) {
  while(! isempty_SLinkedList(ll)) remove_SLinkedList(ll, 0);
  init_SlinkedList(ll);
}

/*int*/void    free_SLinkedList(slinkedlist_t *ll) {
  //if(__builtin_expect(ll->head != NULL, false)) return -1;
  //if(__builtin_expect(ll->size !=    0, false)) return -1;
  assert(ll->head == NULL);
  assert(ll->size ==    0);
  free(ll);
  //return 0;
}

bool        isempty_SLinkedList(slinkedlist_t *ll) {
  assert((ll->head == NULL) == (ll->size == 0));
  return ll->size == 0;
}

ssize_t        find_SLinkedList(slinkedlist_t *ll, sll_element_t elem) {
  assert(ll != NULL);
  sll_node_t *node;
  size_t         i;
  for(node = ll->head, i = 0; node != NULL && __builtin_expect(i <= SSIZE_MAX, true); node = node->next, i++)
    if(node->element == elem) return (ssize_t)i;
  return -1;
}

sll_element_t  *get_SLinkedList(slinkedlist_t *ll, size_t ndx) {
  assert(ll != NULL);
  sll_node_t *node;
  size_t         i;
  for(node = ll->head, i = 0; node != NULL && __builtin_expect(i <= SSIZE_MAX, true); node = node->next, i++)
    if(i == ndx) return &(node->element);
  return NULL;
}

ssize_t      insert_SLinkedList(slinkedlist_t *ll, sll_element_t elem) {
  assert(ll != NULL);
  sll_node_t *node = alloc_SLLNode();
  if(__builtin_expect(node == NULL, false)) return -1;
  init_SLLNode(node, ll->head, NULL, elem);
  ll->head = node;
  ll->size++;
  return ll->size;
}

sll_element_t remove_SLinkedList(slinkedlist_t *ll, size_t ndx) {
  assert(ll != NULL);
  sll_node_t   *node, *prev;
  size_t           i;
  sll_element_t elem;
  for(node = ll->head, prev = NULL, i = 0; node != NULL && __builtin_expect(i <= SSIZE_MAX, true); prev = node, node = node->next, i++) {
    if(i != ndx) continue;
    setnext_SLLNode(prev, node->next);
    elem = node->element;
    ll->size--;
    deinit_SLLNode(node);
    free_SLLNode(node);
    return elem;
  }
  return -1; // TODO
}

