#!/usr/bin/python3
"""[summary]
"""
from sys import argv

def populate_board(size):
    board = []
    board_row = []
    for i in range(0, size):
        board_row.append(i + 1)
    for j in range(0, size):
        board.append(board_row)
    return board

def get_attacks(board, row, column):
    vert = []
    right_diag = []
    left_diag = []

    # gets vertical attack pattern for position
    for i in range(len(board)):
        vert.append(board[i][column])
    total = 0
    for i in range(1, len(board)):
        if (column + i < len(board)):
            right_diag.append(board[i][column + i])
    for i in range(len(board), 0, -1):
        if (column - i > -1):
            left_diag.append(board[i][column - i])
    return vert, right_diag, left_diag
        
    # gets diagnal attack pattern for position
def validate_position():
    pass


def place_queen(size, board):
    pass
    


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
    
    board = populate_board(N)
    print(get_attacks(board, 0, 0))
    print(board)