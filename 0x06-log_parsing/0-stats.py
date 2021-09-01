#!/usr/bin/python3
""" Temp comment"""


from sys import stdin

def print_metrics(total_file_size, http_code_track):
    """ Temp comment"""
    # prints metrics every 10 lines
    print("File size: {}".format(total_file_size))
    for key, value in http_code_track.items():
        if (value != 0):
            print("{}: {}".format(key, value))

if __name__ == "__main__":
    """ Temp comment"""
    # will be used to determine if ten lines has been processed
    http_code_track = {"200": 0, "301": 0, "400": 0, "401": 0,
                    "403": 0, "404": 0, "405": 0, "500": 0}
    line_count = 0
    total_file_size = 0
    # loops through stdin given to program
    for line in stdin:
        if (line_count == 10):
            print_metrics(total_file_size, http_code_track)
            line_count = 0
        try:
            arguments = line.split(' ')
            http_code_track[arguments[7]] += 1
            total_file_size += int(arguments[8])
            line_count += 1
        except Exception:
            continue
