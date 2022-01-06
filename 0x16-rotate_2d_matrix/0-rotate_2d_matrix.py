#!/usr/bin/python3
""" Rotates a NxN matrix 90 degrees """


def rotate_2d_matrix(matrix):
    """ Rotates a NxN matrix 90 degrees """
    size = len(matrix[0])
    transpose = list(map(list, zip(*matrix)))
    for row in range(size):
        for column in range(size - 1, -1, -1):
            matrix[row][abs(column - (size - 1))] = transpose[row][column]
