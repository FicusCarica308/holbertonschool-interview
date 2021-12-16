#include "binary_trees.h"

int tree_size(heap_t *root)
{
	if (root == NULL)
		return (0);
	else
		return (tree_size(root->left) + 1 + tree_size(root->right));
}

void path_to_last_node(int tree_size, long int return_values[])
{
	long int binary_path = 0, iteration = 1, remainder;

	while (tree_size != 0)
	{
		remainder = tree_size % 2;
		binary_path = binary_path + remainder * iteration;
		iteration = iteration * 10;
		tree_size = tree_size / 2;
	}
	return_values[0] = binary_path;
	return_values[1] = iteration / 100;
}

/**
* heap_extract - a function that extracts the root node of a Max Binary Heap
* @root: is a double pointer to the root node of the heap
* Return: returns 0 on failure or the ->n value of the node extracted
*/
int heap_extract(heap_t **root)
{
	long int node_path_info[2], node_path, node_start_point;
	heap_t *temp_head = *root;
	(void) temp_head;

	if (root == NULL)
		return (0);
	
	/* Init all variables*/
	path_to_last_node(tree_size(*root), node_path_info);
	node_path = node_path_info[0];
	node_start_point = node_path_info[1];

	printf("path = %ld ------ starting_point = %ld\n", node_path, node_start_point);

	while (node_start_point > 1)
	{
		node_path = node_path / 10;
		if ((node_path / node_start_point) == 0)
		{
			temp_head = temp_head->left;
			printf("ran1");
		}
		else if ((node_path / node_start_point) == 1)
		{
			temp_head = temp_head->right;
			printf("ran2");
		}
		node_start_point = node_start_point / 10;
	}

	printf("Found node = %d", temp_head->n);

	/* 
	Find node to delete
	save the value of that node
	Free the node
	
	Move the root down to the bottom
	once the root has reached the bottom swap the values with the saved value from delete node
	*/

	return (0);
}
