#!/usr/bin/python3
"""
"""


def canUnlockAll(boxes):
    """ Function that unlocks a list of locked boxes"""
    keys = [0]
    for contents in boxes:
        for key in contents:
            if key not in keys:
                keys.append(key)
    print(keys)
    if len(keys) != len(boxes):
        return False
    return True
