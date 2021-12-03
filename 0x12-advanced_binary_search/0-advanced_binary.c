#include "search_algos.h"
/**
 * 
 * 
 */
int find_index(int *array, int start_index, int end_index, int value)
{
	/* start_index, end_index */
	int middle;
	int i;

	if (end_index > start_index)
	{
		printf("Searching in array:");
		for (i = start_index; i <= end_index; i++)
		{
			printf("%d", array[i]);
			if (i != end_index)
			printf(", ");
		}
		printf("\n");
		middle = start_index + (end_index - start_index) / 2;
		if (array[middle] == value && array[middle - 1] != value)
			return (middle);
		if (array[middle] >= value)
			return (find_index(array, start_index, middle, value));
		if (array[middle] <= value)
			return (find_index(array, middle + 1, end_index, value));
	}
	return (-1);
}

/**
 * 
 * 
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (find_index(array, 0, size - 1, value));
}