
#ifndef _NODE_H_
#define _NODE_H_


typedef void* data_type;


typedef struct Node
{
    data_type value;
    struct Node *prev;
    struct Node *next;
} Node;

/**
 * @brief Creates a new Node struct
 * 
 * @param value
 * The value to be stored in the node
 * @param prev
 * Pointer to the previous node
 * @param next
 * Pointer to the next node
 * 
 * @return Node*
 * Pointer to the node created
*/
Node *node_construct(data_type value, Node *prev, Node *next);

/**
 * @brief Destroys a Node struct
 * 
 * @param n
 * Pointer to the node to be destroyed
 * @param free_func
 * Pointer to the function that frees the memory allocated for the value stored in the node
*/
void node_destroy(Node *n, void (*free_func)(data_type));

/**
 * @brief Prints the value stored in a node in a debug format
 * 
 * @param n
 * Pointer to the node to be printed
 * @param print_fn
 * Pointer to the function that prints the value stored in the node
*/
void node_print_debug(Node *n, void (*print_fn)(data_type));

/**
 * @brief Prints the value stored in a node
 * 
 * @param n
 * Pointer to the node to be printed
 * @param print_fn
 * Pointer to the function that prints the value stored in the node
*/
void node_print(Node *n, void (*print_fn)(data_type));


#endif