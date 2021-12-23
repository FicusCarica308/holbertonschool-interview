#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
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

int strlgth(char *string)
{
	int strlgth = 0;

	for (; string[strlgth] != '\0'; strlgth++)
	;

	return (strlgth);
}

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

int main(int argc, char **argv)
{
	int *int_1 = NULL;
	int *int_2 = NULL;
	int *new_num = NULL;
	int hold_new_value;
	int i;
	int back_i = 0;
	int back_j = 0;
	int j;
	int hold_carry;
	int k;

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
			hold_new_value = int_1[i] * int_2[j] + new_num[back_i + back_j] + hold_carry;
			hold_carry = hold_new_value / 10;
			new_num[back_i + back_j] = hold_new_value % 10;
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
