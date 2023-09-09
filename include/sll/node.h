#ifndef SLL_NODE_H
#define SLL_NODE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * type of element contained within a Node
 */
typedef int sll_element_t;

/**
 * Doubly-linked list node
 */
typedef struct SLLNode{
  struct SLLNode *next;
  sll_element_t   element;
} sll_node_t;

/**
 * allocate memory for a Node
 * @returns pointer to Node
 */
sll_node_t *alloc_SLLNode();

/**
 * initialize a Node
 * @param node Node to initialize
 * @param next Node after parameter node
 * @param prev Node before parameter node
 * @param element value at parameter node
 */
void   init_SLLNode(sll_node_t *node, sll_node_t *next, sll_node_t *prev, sll_element_t element);

/**
 * deinitialize a Node for security
 * @param node pointer to Node
 */
void deinit_SLLNode(sll_node_t *node);

/**
 * free memory for a Node
 * @param node pointer to Node
 */
void   free_SLLNode(sll_node_t *node);

/**
 * link to nodes
 * @param node Node to set next
 * @param next Node to set prev
 */
void setnext_SLLNode(sll_node_t *node, sll_node_t *next);

/**
 * link to nodes
 * @param node Node to set prev
 * @param prev Node to set next
 */
void setprev_SLLNode(sll_node_t *node, sll_node_t *prev);

#ifdef __cplusplus
}
#endif

#endif

