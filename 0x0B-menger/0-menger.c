#include "menger.h"
/**
 * test - a function that draws a 2D Menger Sponge
 * @row: row of parent caller
 * @col: col of parent caller
 * Return: void
 */
void test(int row, int col)
{
	while (row != 0 && col != 0)
	{
		if (col % 3 == 1 && row % 3 == 1)
		{
			printf(" ");
			return;
		}
		col = col / 3;
		row = row / 3;
	}
	printf("#");
}

/**
 * menger - a function that draws a 2D Menger Sponge
 * @level: level is the level of the Menger Sponge to draw
*/
void menger(int level)
{
	int size = 0;
	int row = 0;
	int col = 0;

	if (level < 0)
		return;

	/*
	* Determines the size of the sponge
	* The size of a level N Menger sponge is calculated as follows: 3^N
	*/
	size = pow(3, level);

	for (row = 0; row <= size - 1; row++)
	{
		for (col = 0; col <= size - 1; col++)
		{
			test(row, col);
		}
		putchar('\n');
	}
}
