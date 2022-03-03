#!/usr/bin/python3
"""
Create a function def island_perimeter(grid): that returns the perimeter
of the island described in grid:

    grid is a list of list of integers:
        0 represents water
        1 represents land
        Each cell is square, with a side length of 1
        Cells are connected horizontally/vertically (not diagonally).
        grid is rectangular, with its width and height not exceeding 100
    The grid is completely surrounded by water
    There is only one island (or nothing).
    The island doesn’t have “lakes” (water inside that isn’t connected
    to the water surrounding the island).
"""


def island_perimeter(grid):
    """ Returns the perimeter of the island described in grid """
    rowSize = len(grid)
    columnSize = len(grid[0])
    surfaceArea = 0

    for row in range(rowSize):
        for column in range(columnSize):
            if (grid[row][column] == 1):
                if ((row - 1 < 0) or grid[row - 1][column] == 0):
                    surfaceArea += 1
                if ((row + 1 >= rowSize) or grid[row + 1][column] == 0):
                    surfaceArea += 1
                if ((column - 1) < 0 or grid[row][column - 1] == 0):
                    surfaceArea += 1
                if ((column + 1) >= columnSize or grid[row][column + 1] == 0):
                    surfaceArea += 1
    return (surfaceArea)
