#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>

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
typedef struct binary_tree_s avl_t;

/* Prototypes */
void binary_tree_print(const binary_tree_t *);
int find_height(const binary_tree_t *node);
void process_node(const binary_tree_t *node,
				  int *bts_flag,
				  int left_or_right,
				  const binary_tree_t *head);
void binary_is_bst(const binary_tree_t *node,
				   int *bts_flag,
				   int left_or_right,
				   const binary_tree_t *head);
int binary_tree_is_avl(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(const binary_tree_t *parent, int value);

#endif
