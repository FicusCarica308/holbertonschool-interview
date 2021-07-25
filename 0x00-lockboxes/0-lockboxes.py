#!/usr/bin/python3
"""
File contents:
    def canUnlockAll(boxes):
        > function that unlocks all locked boxes from a given list
"""


def canUnlockAll(boxes):
    """ Function that unlocks a list of locked boxes"""
    keys = [0]
    for key in keys:
        for box in boxes[key]:
            if box not in keys:
                keys.append(box)
    if len(keys) != len(boxes):
        return False
    return True
