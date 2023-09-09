#ifndef NODE_H
#define NODE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * type of element contained within a Node
 */
typedef int element_t;

/**
 * Doubly-linked list node
 */
typedef struct Node{
        struct Node *next;
        struct Node *prev;
        element_t    element;
} node_t;

/**
 * allocate memory for a Node
 * @returns pointer to Node
 */
node_t *alloc_Node();

/**
 * initialize a Node
 * @param node Node to initialize
 * @param next Node after parameter node
 * @param prev Node before parameter node
 * @param element value at parameter node
 */
void   init_Node(node_t *node, node_t *next, node_t *prev, element_t element);

/**
 * deinitialize a Node for security
 * @param node pointer to Node
 */
void deinit_Node(node_t *node);

/**
 * free memory for a Node
 * @param node pointer to Node
 */
void   free_Node(node_t *node);

/**
 * link to nodes
 * @param node Node to set next
 * @param next Node to set prev
 */
void setnext_Node(node_t *node, node_t *next);

/**
 * link to nodes
 * @param node Node to set prev
 * @param prev Node to set next
 */
void setprev_Node(node_t *node, node_t *prev);

#ifdef __cplusplus
}
#endif

#endif

