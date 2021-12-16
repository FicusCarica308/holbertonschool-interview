#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

/* Prototypes */
size_t left_and_right(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
int tree_size(heap_t *root);
void get_last_node_path(unsigned long int n, int *binary, int current_index);
void binary_tree_print(const binary_tree_t *);
int heap_extract(heap_t **root);
int free_last_node(heap_t *root);

#endif
