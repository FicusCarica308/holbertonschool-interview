#!/usr/bin/python3
"""_summary_
    maria alwasy goes first
"""


def isPrime(n):
    for i in range(2, int(n / 2) + 1):
        if (n % i) == 0:
            break
    else:
        return (n)  # is prime


def isWinner(x, nums):
    """ : """
    maria_wins = 0
    ben_wins = 0

    for round in range(0, x):
        if (round < len(nums)):
            round_nums = list(filter(isPrime, range(1, nums[round] + 1)))
            if (len(round_nums) % 2 == 0):
                maria_wins += 1
            else:
                ben_wins += 1
    if (maria_wins > ben_wins):
        return ('Maria')
    return ('Ben')
