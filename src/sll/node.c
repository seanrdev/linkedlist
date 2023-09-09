//#include <stddef.h>
#include <stdlib.h>
#include "sll/node.h"

sll_node_t *alloc_SLLNode() {
  return (sll_node_t *)malloc(sizeof(sll_node_t));
}

void   free_SLLNode(sll_node_t *node) {
  free(node);
}

void   init_SLLNode(sll_node_t *node, sll_node_t *next, sll_node_t *prev, sll_element_t element) {
  node->next    = next;
  if(prev != NULL)
    prev->next  = node;
  node->element = element;
}

void deinit_SLLNode(sll_node_t *node) {
  node->next    = NULL;
  node->element = 0;
}

void setnext_SLLNode(sll_node_t *node, sll_node_t *next) {
  node->next = next;
}

void setprev_SLLNode(sll_node_t *node, sll_node_t *prev) {
  prev->next = node;
}

