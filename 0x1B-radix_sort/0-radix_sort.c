#include "sort.h"
#include <stdio.h>
/**
 * find_largest_pos - finds the largest position the program will need to loop
 * @array: the array we are using to determine the largest postion
 * @size: the size of the array
 * Return: returns the max position
*/
int find_largest_pos(int *array, size_t size)
{
size_t i = 0;
int max = 0;
int pos = 10;

for (i = 0; i < size; i++)
{
	if (array[i] > max)
		max = array[i];
}

while (max != 0)
{
	max = max / 10;
	pos = pos * 10;
}
return (pos / 10);
}

/**
 * get_last_digit - Determines the last digit in a number from a given position
 * @digit: The digit to be processed
 * @pos: The position at which we want to get the number from
 * Return: returns the single digit
 */
int get_last_digit(int digit, int pos)
{
	pos = pos * 10;

	if (digit < pos / 10)
		return (0);

	digit = digit % pos;

	if (digit < 10 && pos >= 100)
		return (0);

	while (digit >= 10)
	{
		pos = pos / 10;
		digit = digit - (digit % pos);
		digit = digit / 10;
	}

	return (digit);
}

/**
 *radix_sort - performs a radix sort operation on a given array
 *@array: The array to be sorted
 *@size: The size of the array to be sorted
 *Return: returns nothing
 */
void radix_sort(int *array, size_t size)
{
	int *sorted_list = NULL;
	int i = 0;
	int max_sig_digit = 0, curr_sig_digit = 1;
	size_t sorted_index = 0;
	size_t original_index = 0;
	(void)array;

	if (size < 2 || array == NULL)
		return;
	sorted_list = (int *)malloc(sizeof(int) * size);
	max_sig_digit = find_largest_pos(array, size);
	if (sorted_list == NULL)
		return;

	while (curr_sig_digit < max_sig_digit)
	{
		for (sorted_index = 0; sorted_index < size; sorted_index++)
		{
			for (i = 0; i < 10; i++)
			{
				for (original_index = 0; original_index < size; original_index++)
					/* if (array[original_index] % significant_digit == i) */
					if (get_last_digit(array[original_index], curr_sig_digit) == i)
					{
						sorted_list[sorted_index] = array[original_index];
						sorted_index++;
					}
			}
		}
		print_array(sorted_list, size);
		for (original_index = 0; original_index < size; original_index++)
			array[original_index] = sorted_list[original_index];
		if (curr_sig_digit == 1)
			curr_sig_digit = 10;
		else
			curr_sig_digit = curr_sig_digit * 10;
	}

	free(sorted_list);
}
