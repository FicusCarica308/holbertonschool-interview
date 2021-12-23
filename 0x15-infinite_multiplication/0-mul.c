#include "holberton.h"
#include <stdlib.h>

/**
* error - prints error and exists program with status 98
*/
void error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * strlgth - finds the length of a string
 * @string: The string we are measuring
 * Return: returns the computed length
*/
int strlgth(char *string)
{
	int strlgth = 0;

	for (; string[strlgth] != '\0'; strlgth++)
	;

	return (strlgth);
}

/**
 * stoi - converts a given string into a integer array
 * @string: the string we are converting
 * Return: returns the array representation of the string
 */
int *stoi(char *string)
{
	int i = 0;
	int hold;
	int *large_num = NULL;
	(void) hold;

	large_num = malloc(sizeof(int) * strlgth(string));
	if (large_num == NULL)
		error();

	for (i = 0;  string[i] != '\0'; i++)
	{
		if ((int)string[i] > 58 || (int)string[i] < 48)
			error();
		large_num[i] = string[i] - '0';
	}
	return (large_num);
}

/**
 * main - Entry point
 * @argv: command line arguments
 * @argc: command line argument count
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	int *int_1 = NULL, *int_2 = NULL, *new_num = NULL;
	int hold_new, hold_carry;
	int i, j, k;
	int back_i = 0, back_j;

	if (argc != 3)
		error();
	int_1 = stoi(argv[1]);
	int_2 = stoi(argv[2]);
	new_num = malloc(sizeof(int *) * (strlgth(argv[1]) + strlgth(argv[2])));
	if (new_num == NULL)
		error();

	for (i = strlgth(argv[1]) - 1; i >= 0; i--, back_i++)
	{
		hold_carry = 0;
		back_j = 0;
		for (j = strlgth(argv[2]) - 1; j >= 0; j--, back_j++)
		{
			hold_new = int_1[i] * int_2[j] + new_num[back_i + back_j] + hold_carry;
			hold_carry = hold_new / 10;
			new_num[back_i + back_j] = hold_new % 10;
			back_j++;
		}
		if (hold_carry > 0)
			new_num[back_i + back_j] += hold_carry;
		back_i++;
	}

	for (k = strlgth(argv[1]) + strlgth(argv[2]) - 1; k >= 0; k--)
		_putchar(new_num[k] + '0');
	free(int_1);
	free(int_2);
	free(new_num);
	return (0);
}
