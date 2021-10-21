#!/usr/bin/python3
"""[summary]
"""
from sys import argv


if __name__ == "__main__":
    """Checks"""
    if (len(argv) != 2):
        print("Usage: nqueens N")
        exit(1)
    try:
        N = int(argv[1])
    except:
        print("N must be a number")
        exit(1)
    if (N < 4):
        print("N must be at least 4")
        exit(1)
    
    """Solution"""
    