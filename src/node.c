//#include <stddef.h>
#include <stdlib.h>
#include "dll/node.h"

node_t *alloc_Node() {
  return (node_t *)malloc(sizeof(node_t));
}

void   free_Node(node_t *node) {
  free(node);
}

void   init_Node(node_t *node, node_t *next, node_t *prev, element_t element) {
  node->next    = next;
  node->prev    = prev;
  node->element = element;
}

void deinit_Node(node_t *node) {
  node->next    = NULL;
  node->prev    = NULL;
  node->element = 0;
}

void setnext_Node(node_t *node, node_t *next) {
  node->next = next;
  next->prev = node;
}

void setprev_Node(node_t *node, node_t *prev) {
  node->prev = prev;
  prev->next = node;
}

