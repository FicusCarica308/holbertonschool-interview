#include "slide_line.h"
/**
* shift_index - shifts two index's directly from slide_line
* @line: The line we are shifting the index of
* @slow_index: An iteratoring value representing the outer for loop
* @fast_index: An iteratoring value representing the inner for loop
*/
void shift_index(int *line, int slow_index, int fast_index)
{
	if (line[fast_index] == line[slow_index])
	{
		line[fast_index] = line[slow_index] * 2;
		line[slow_index] = line[fast_index];
		line[fast_index] = 0;
	}
}

/**
* slide_line - emulates single line 2048
* @line: a line passed to the function to be slid and merged
* @size: The size of the given line
* @direction: What direction the user is telling the program to move to
* Return: returns 1 upon success, or 0 upon failure
*/
int slide_line(int *line, size_t size, int direction)
{
	int slow_index = 0, fast_index = 0, iterator = 0, index_max = size - 1;

	if (direction == SLIDE_RIGHT)
		/*start at the end of the given line*/
		for (slow_index = index_max; slow_index >= 0; slow_index--)
		{
			for (fast_index = slow_index - 1; fast_index >= 0; fast_index--)
			{
				if (line[fast_index] != line[slow_index] && line[fast_index] != 0)
					break;
				shift_index(line, slow_index, fast_index);
			}
			for (iterator = slow_index; iterator != index_max; iterator++)
				if (line[iterator + 1] == 0)
				{
					line[iterator + 1] = line[iterator];
					line[iterator] = 0;
				}
		}
	else if (direction == SLIDE_LEFT)
		/*starts at the beginning of the given line*/
		for (slow_index = 0; slow_index <= index_max; slow_index++)
		{
			for (fast_index = slow_index + 1; fast_index <= index_max; fast_index++)
			{
				if (line[fast_index] != line[slow_index] && line[fast_index] != 0)
					break;
				shift_index(line, slow_index, fast_index);
			}
			for (iterator = slow_index; iterator != 0; iterator--)
				if (line[iterator - 1] == 0)
				{
					line[iterator - 1] = line[iterator];
					line[iterator] = 0;
				}
		}
	else
		return (0);
	return (1);
}
