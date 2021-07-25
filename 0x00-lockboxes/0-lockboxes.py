#!/usr/bin/python3
"""
File contents:
    def canUnlockAll(boxes):
        > function that unlocks all locked boxes from a given list
"""


def canUnlockAll(boxes):
    """ Function that unlocks a list of locked boxes"""
    if boxes is None or len(boxes) == 0:
        return False
    keys = [0]
    for key in keys:
        for box_key in boxes[key]:
            if box_key not in keys and box_key < len(boxes):
                keys.append(box_key)
    if len(keys) != len(boxes):
        return False
    return True
