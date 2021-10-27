#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * create_node - creates a new node for a AVL tree
 * @parent: the parent for the new node
 * @new_value: the new value that will be added to the new node
 * Return: returns a avl_t node with with given parent value and new values
 */
avl_t *create_node(avl_t *parent, int new_value)
{
	avl_t *new_node = NULL;

	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);

	new_node->parent = parent;
	new_node->n = new_value;
	return (new_node);
}

/**
 * create_AVL - creates an AVL tree recursively (only works for sorted array).
 * To properly start the recursive loop use this call.
 * create_AVL(NULL, [your array], 0, [max index of your array]);
 * @parent: (Changes) The parent node (the previously created node) to the new
 * node to be created in recrusive loop.
 * @array: (Constant) the given sorted array we are "splitting" into sub
 * arrays using start_index and end_index.
 * @start_index: (Changes) The beginning value of our "Sub Array" each call.
 * @end_index: (Changes) The ending value of our "Sub Array" each call.
 * Return: eventually will return the root node to a fully constructed
 * AVL Tree
 */

avl_t *create_AVL(avl_t *parent, int *array, int start_index, int end_index)
{
	/* The index of where the new value is located */
	/* Is located in the middle of the array always if array is sorted*/
	int new_value_idx;
	avl_t *new_node = NULL;

	/**
	 * This base case is here to determine when the array is to small
	 * to continue. As the array is split using recursions the start_index
	 * is increased by one and the end_index is decreased by on. This
	 * in turn will eventual result in start_index being freater than
	 * end_index. This is an invalid operation for the program since
	 * it results in a backwards traversal of a sort and an eventual
	 * infinit loop.
	 * Example:
	 * If our array is [1, 2, 3] our start_index is 1 and our end_index
	 * is 2. Now we split the array resulting in [1], and [3].
	 * For array = [1] it will call create_AVL again with start_index as
	 * 2 and end_index is  1. This is where our base case comes into effect.
	 * If the base case is not here then the next function call will
	 * become 1 and 2 again creating an infinit loop.
	 */
	if (end_index < start_index)
		return (NULL);

	new_value_idx = (start_index + end_index) / 2;
	new_node = create_node(parent, array[new_value_idx]);
	if (new_node == NULL)
		return (NULL);
	/*needs to increase by one to get skip over the found middle*/
	new_node->right = create_AVL(new_node, array, new_value_idx + 1, end_index);
	/*needs to decrease by one to get skip over the found middle*/
	new_node->left = create_AVL(new_node, array, start_index, new_value_idx - 1);

	return (new_node);
}

/**
 * sorted_array_to_avl - Creates and AVL tree from a sorted array
 * @array: The given array to transform into an AVL tree
 * @size: The total size of the given array (used to determine the max index)
 * Return: returns the root to the constructed AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	root = create_AVL(NULL, array, 0, size - 1);
	if (root == NULL)
		return (NULL);
	return (root);
}
