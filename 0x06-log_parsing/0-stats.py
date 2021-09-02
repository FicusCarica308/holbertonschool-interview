#!/usr/bin/python3
""" Temp comment"""
from sys import stdin


def print_metrics(metrics, total_size):
    """ Temp comment"""
    # prints metrics every 10 lines
    codes = [200, 301, 400, 401,
             403, 404, 405, 500]
    print("File size: {}".format(total_size))
    for code in codes:
        if (metrics[int(code)] > 0):
            print("{}: {}".format(int(code), metrics[int(code)]))


# will be used to determine if ten lines has been processed
metrics = {200: 0, 301: 0, 400: 0, 401: 0,
           403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0
total_size = 0
# loops through stdin given to program
try:
    for line in stdin:
        try:
            arguments = line.split()
            status_code = int(arguments[-2])
            metrics[status_code] += 1
            total_size += int(arguments[-1])
            line_count += 1
        except Exception:
            continue
        if (line_count == 10):
            print_metrics(metrics, total_size)
            line_count = 0
except Exception:
    pass
finally:
    print_metrics(metrics, total_size)
