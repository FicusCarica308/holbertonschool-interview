#include "search_algos.h"
/**
 * 
 * 
 */
int find_index(int *array, int start, int end, int size, int value)
{
	int i = 0;
	int result;
	int new_size = 0;

	if (array[end] < value || array[start] > value)
	{
		return (-1);
	}
	printf("Searching in array:");
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i != end)
			printf(", ");
	}
	printf("\n");

	if (size % 2 != 0)
		new_size = (size / 2) + 1;
	else
		new_size = (size / 2);

	result = find_index(array, start, new_size - 1, new_size, value); // left
	result = find_index(array, start + new_size, end, new_size, value); // right

	return (result);
}

/**
 * 
 * 
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	/* whenever the number is not found inside the array return -1 */

	/* search left most first */
	/* search right most next */

	return (find_index(array, 0, size - 1, size, value));
}