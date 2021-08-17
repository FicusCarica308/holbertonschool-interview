#include "sandpiles.h"


/**
* unstable_check - checks if a given sandpile is unstable
* @grid: 
* Return: returns 1 if stable and 0 if unstable
*/
int unstable_check(int grid[3][3], unsigned int grid_size)
{
	unsigned int row = 0;
	unsigned int column = 0;

	for (row = 0; row <= grid_size; row++)
		for (column = 0; column <= grid_size; column++)
			if (grid[row][column] > 3)
			{
                return (0);
			}
	return (1);
}

static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
* sandpiles_sum - a function that computes the sum of two sandpiles
* @grid1: Description
* @grid2: Description
* Return: Description
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	unsigned int grid_size = 2;
	unsigned int check_unstable = 0;
	unsigned int row = 0;
	unsigned int column = 0;
	int grid_hold[3][3];
 
	/* add operations */
	for (row = 0; row <= grid_size; row++)
		for (column = 0; column <= grid_size; column++)
			grid1[row][column] = grid1[row][column] + grid2[row][column];
	if (unstable_check(grid1, grid_size) == 0)
		{
			printf("=\n");
			print_grid(grid1);
		}

	while (1)
	{
		for (row = 0; row <= grid_size; row++)
			for (column = 0; column <= grid_size; column++)
				grid_hold[column][row] = grid1[column][row];
		check_unstable = 0;
		for (row = 0; row <= grid_size; row++)
			for (column = 0; column <= grid_size; column++)
				if (grid_hold[row][column] > 3)
				{
					grid1[row][column] -= 4;
					if (row != 0)
						grid1[row - 1][column] += 1;
					if (row != 2)
						grid1[row + 1][column] += 1;
					if (column != 0)
						grid1[row][column - 1] += 1;
					if (column != 2)
						grid1[row][column + 1] += 1;
					check_unstable = 1;
				}
		if (check_unstable == 0)
			return;
		else
		{
			if (unstable_check(grid1, grid_size) == 0)
			{
				printf("=\n");
				print_grid(grid1);
			}
		}
	}

	return;
}
