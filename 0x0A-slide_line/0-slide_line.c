#include "slide_line.h"
/**
* 
*
*/
void shift_index(int *line, int i, int k)
{
	if (line[k] == line[i])
	{
		line[k] = line[i] * 2;
		line[i] = line[k];
		line[k] = 0;
	}
}

/**
*
*
*/
int slide_line(int *line, size_t size, int direction)
{
	int i = 0, k = 0, j = 0, index_max = size - 1;

	if (direction == SLIDE_RIGHT)
	{
		for (i = index_max; i >= 0; i--)
		{
			for (k = i - 1; k >= 0; k--)
			{
				if (line[k] != line[i] && line[k] != 0)
					break;
				shift_index(line, i, k);
			}
			for (j = i; j != index_max; j++)
				if (line[j + 1] == 0)
				{
					line[j + 1] = line[j];
					line[j] = 0;
				}
		}
		return (1);
	}
	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i <= index_max; i++)
		{
			for (k = i + 1; k <= index_max; k++)
			{
				if (line[k] != line[i] && line[k] != 0)
					break;
				shift_index(line, i, k);
			}
			for (j = i; j != 0; j--)
				if (line[j - 1] == 0)
				{
					line[j - 1] = line[j];
					line[j] = 0;
				}
		}
		return (1);
	}
	return (0);
}
