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
    if n <= 0:
        return []
