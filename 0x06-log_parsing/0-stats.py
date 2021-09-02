#!/usr/bin/python3
""" Temp comment"""


from sys import stdin


def print_metrics(metrics):
    """ Temp comment"""
    # prints metrics every 10 lines
    for key, value in metrics.items():
        if (key == 'total_size'):
            print("File size: {}".format(value))
        elif (value != 0):
            print("{}: {}".format(key, value))

if __name__ == "__main__":
    """ Temp comment"""
    # will be used to determine if ten lines has been processed
    metrics = {"total_size": 0, "200": 0, "301": 0, "400": 0, "401": 0,
                "403": 0, "404": 0, "405": 0, "500": 0}
    line_count = 0
    # loops through stdin given to program
    try:
        for line in stdin:
            try:
                arguments = line.split()
                metrics[arguments[-2]] += 1
                metrics['total_size'] += int(arguments[-1])
                line_count += 1
            except:
                continue
            if (line_count == 10):
                print_metrics(metrics)
                line_count = 0
    except:
        pass
    finally:
        print_metrics(metrics)
