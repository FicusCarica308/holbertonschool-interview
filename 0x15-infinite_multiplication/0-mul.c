#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
void error()
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

	for(i = 0;  string[i] != '\0'; i++)
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
	int i;
	(void) new_num;

	if (argc != 3)
		error();
	int_1 = stoi(argv[1]);
	int_2 = stoi(argv[2]);
	new_num = malloc(sizeof(int) * strlgth(argv[1]) + strlgth(argv[2]));
	if (new_num == NULL)
		error();

	for (i = 0; i <= 1; i++)
	{
		printf("%d", int_1[i]);
	}
	printf("\n");
	free(int_1);
	free(int_2);
	free(new_num);
	return (0);
}
