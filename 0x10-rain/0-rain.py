#!/usr/bin/python3
""" Summary """


def rain(walls):
    """ Summary """
    spaces_between = 0
    prev_wall = 0
    total_water = 0

    for wall in walls:
        if (wall != 0 and prev_wall == 0):
            prev_wall = wall
            continue
        if (wall != 0):
            if (wall < prev_wall):
                lost_space = prev_wall - wall
                total_water += (prev_wall - lost_space) * spaces_between
                spaces_between = 0
                prev_wall = wall
            if (wall > prev_wall):
                lost_space = (prev_wall - wall) * -1
                total_water += (wall - lost_space) * spaces_between
                spaces_between = 0
                prev_wall = wall
        else:
            if (prev_wall != 0):
                spaces_between += 1
    return total_water
