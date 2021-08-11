#!/usr/bin/python3
""" Minimum operations """


def minOperations(n):
    """
    minOperations - finds the minimum amount of operations it will take to
        make n number of H's in a text file
    args:
        @n(type: int) - number we want to make
    description:
        uses prime factorization to determine how many operations it will
        take in order for program to get n number of H's;
    """
    total_ops = 0
    i = 2  # represents number of operations for a copy and paste
    """
        loop ends when the number i is equal to n (when we reach the largest
    prime number for that n) and doesnt run when the starting
    prime number is less than n
    """
    while i * i <= n:
        if n % i:  # checks if number is divisible by prime numer stating at 2
            i += 1  # if num isnt divisible it skips to the next prime number
        else:
            """when divisble code divides the remaining value of n by
            the prime number determined"""
            n //= i  # uses floor division to prevent float values
            total_ops += i
    if n > 1:
        total_ops += n  # adds last prime factor after loop ends
    return total_ops
