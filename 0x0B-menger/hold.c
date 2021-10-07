#include "menger.h"

/**
 * menger - a function that draws a 2D Menger Sponge
 * @level: level is the level of the Menger Sponge to draw
*/
void menger(int level)
{
	int size = 0;
	int row = 0;
	int col = 0;
	int row_count = 1;
	int col_count = 1;
	int row_row_count = 1;
	int col_col_count = 1;

	if (level < 0)
	return;

	/*
	* Determines the size of the sponge
	* The size of a level N Menger sponge is calculated as follows: 3^N
	*/
	size = pow(3, level);

	for (row = 1; row <= size; row++)
	{
		for (col = 1; col <= size; col++)
		{
			if (row_row_count % 3 == 2 && col_col_count % 3 == 2)
				putchar(' ');
			else if (row_count % 3 == 2 && col_count % 3 == 2)
				putchar(' ');
			else if (row % 3 == 2  && col % 3 == 2)
			{
				putchar(' ');
			} else {
				printf("#");
			}
			if (col % 3 == 0)
				col_count++;
			if (col % 9 == 0)
				col_col_count++;
		}
		if (row % 3 == 0)
			row_count++;
		if (row % 9 == 0)
			row_row_count++;
		putchar('\n');
	}
}
