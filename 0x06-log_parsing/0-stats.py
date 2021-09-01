#!/usr/bin/python3
""" Temp comment"""

from sys import stdin
from ipaddress import ip_address
from datetime import datetime
import re
from signal import signal, SIGINT


def print_metrics(total_file_size, http_code_track):
    """ Temp comment"""
    # prints metrics every 10 lines
    print('File size:', total_file_size)
    for key, value in http_code_track.items():
        print("{}:{}".format(key, value))


def handler(signal_recieved, frame):
    """ Temp comment"""
    total_file_size = 3000
    http_code_track = {}
    print_metrics(total_file_size, http_code_track)


def check_arguments(arguments):
    """ Temp comment"""
    ip_rgx1 = "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)"
    ip_rgx2 = "(\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)){3}"
    date_format = "[%Y-%m-%d_%X.%f]"
    request_str1 = '"GET_/projects/260_HTTP/1.1"'
    request_str2 = "GET_/projects/260_HTTP/1.1"
    http_codes = ["200", "301", "400", "401",
                  "403", "404", "405", "500"]

    if re.search(ip_rgx1 + ip_rgx2, arguments[0]) is None:
        print('IP')
        return None

    if arguments[1] != '-':
        return None

    try:
        datetime.strptime(arguments[2], date_format)
        int(arguments[5])
    except (ValueError, TypeError):
        return None

    if arguments[3] != request_str1:
        if arguments[3] != request_str2:
            return None

    if arguments[4] not in http_codes:
        return None

    size_and_code = {'http_code': arguments[4], 'file_size': int(arguments[5])}
    return size_and_code


def get_arguments(line):
    """ Temp comment"""
    new_line = str()
    space_count = 0
    for char in line:
        if char == ' ' and space_count in [2, 4, 5]:
            new_line += '_'
            space_count += 1
        elif char == ' ':
            new_line = new_line + char
            space_count += 1
        elif char != '\n':
            new_line = new_line + char
    return new_line.split(' ')


if __name__ == "__main__":
    """ Temp comment"""
    # will be used to determine if ten lines has been processed
    http_code_track = {"200": 0, "301": 0, "400": 0, "401": 0,
                       "403": 0, "404": 0, "405": 0, "500": 0}
    line_count = 0
    total_file_size = 0

    signal(SIGINT, handler)

    # loops through stdin given to program
    for line in stdin:
        if (line_count == 10):
            print_metrics(total_file_size, http_code_track)
            line_count = 0
        arguments = get_arguments(line)
        size_and_code = check_arguments(arguments)
        if size_and_code is None:
            line_count += 1
            continue
        http_code_track[size_and_code['http_code']] += 1
        total_file_size += size_and_code['file_size']
        line_count += 1
