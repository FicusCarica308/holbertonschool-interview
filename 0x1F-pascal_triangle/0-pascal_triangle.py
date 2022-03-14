#!/usr/bin/python3
"""
A function that returns a list of lists of integers representing
the Pascal's triangle of n
"""


def pascal_triangle(n):
    """
    A function that returns a list of lists of integers representing
    the Pascal's triangle of n

    N is always gonna be an integer...
    Args:
        n (int): size of the pascal triangle
    """
    outerList = []

    if n <= 0:
        return []

    for outerIdx in range(0, n + 1):
        innerList = []
        for innerIdx in range(outerIdx):
            if (innerIdx == 0 or (innerIdx + 1) == outerIdx):
                innerList.append(1)
            else:
                innerList.append(outerList[outerIdx - 1][innerIdx - 1] +
                                 outerList[outerIdx - 1][innerIdx])
        outerList.append(innerList)
    return (outerList[1:])
