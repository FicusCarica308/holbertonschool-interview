#!/usr/bin/python3
""" 0x19. Making Change - coding interview question """


def makeChange(coins, total):
    """
    Summary - Determines the fewest number of coins needed
        to meet a given amount total
    Return - Returns 0 if total is invalid and -1
        if the number cannot be met by any number of coins
    """
    coinCount = 0
    if (total <= 0):
        return (0)
    coins.sort(reverse=True)
    for i in range(len(coins)):
        while coins[i] <= total:
            total -= coins[i]
            coinCount += 1
    if (total != 0):
        return(-1)
    return (coinCount)
