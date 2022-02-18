#include "sort.h"

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

	while (digit >= 10)
	{
		pos = pos / 10;
		digit = digit - (digit % pos);
		digit = digit / 10;
	}
	return (digit);
}

/**
 * find_last_digits - Places the last digits of the iteration into a list
 * @array: The array of integers we are finding the last digits of
 * @pos: The position at which we want to get the number from on each number
 * @size: The size of the array
 * Return: Returns the array of single digits
 */
int *find_last_digits(int *array, int pos, size_t size)
{
	size_t i = 0;
	int *last_digits = malloc(sizeof(int) * size);

	if (last_digits == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		last_digits[i] = get_last_digit(array[i], pos);
	return (last_digits);
}

/**
 * count_sort - performs a count_sort operation on a given array
 * @digit_array: An array of single digits found using the original_array
 * @pos: The position at which we want to get the number from on each number
 * @size: The size of the array
 * @original_array: This is the array we are gonna modify to be sorted
 * Return: Returns the new sorted array
 */
void count_sort(int *digit_array, int *original_array, int pos, size_t size)
{
	int *count_array = malloc(sizeof(int) * 9);
	int sorted_array[size + 1];
	size_t i = 0;
	int k = 0;

	if (count_array == NULL || sorted_array == NULL)
		return;
	for (i = 0; i < size; i++)
		count_array[digit_array[i]] += 1;
	for (i = 1; i < 10; i++)
		count_array[i] += count_array[i - 1];
	for (i = 9; i > 0; i--)
		count_array[i] = count_array[i - 1];
	count_array[0] = 0;
	for (i = 0; i < size; i++)
		for (k = 0; k < 10; k++)
		{
			if (get_last_digit(original_array[i], pos) == k)
			{
				sorted_array[count_array[k]] = original_array[i];
				count_array[k] += 1;
			}
		}
	for (i = 0; i < size; i++)
		original_array[i] = sorted_array[i];
	free(count_array);
}

/**
 *radix_sort - performs a radix sort operation on a given array
 *@array: The array to be sorted
 *@size: The size of the array to be sorted
 *Return: returns nothing
 */
void radix_sort(int *array, size_t size)
{
	int *last_digits = NULL;
	int curr_pos = 1;
	int max_pos = 0;

	if (size < 2)
		return;

	max_pos = find_largest_pos(array, size);

	while (curr_pos < max_pos)
	{
		last_digits = find_last_digits(array, curr_pos, size);
		count_sort(last_digits, array, curr_pos, size);
		print_array(array, size);
		if (curr_pos == 1)
			curr_pos = 10;
		else
			curr_pos = curr_pos * 10;
		free(last_digits);
	}
}
