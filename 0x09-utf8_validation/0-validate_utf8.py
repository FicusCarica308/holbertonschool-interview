#!/usr/bin/python3
"""Temp"""

def checkBytes(binaryData, bytesToCheck):
    for data in range(0, bytesToCheck):
        if (binaryData[data][:2] != "10"):
            return (False)
    return (True)



def validUTF8(data):
    """ Returns True if data passed is a valid UTF-8 encoding """
    
    
    """Convert to binary"""
    binaryData = []
    
    for dataPoint in data:
        binaryDataPoint = ""
        binarySub = 128
        if dataPoint > 255:
            return (False)
        for i in range(1, 6):
            if dataPoint - binarySub >= 0:
                dataPoint -= binarySub
                binaryDataPoint += "1"
            else:
                binaryDataPoint += "0"
            binarySub /= 2
        binaryData.append(binaryDataPoint)

    """Checks binary data"""
    i = 0
    while i < len(binaryData):
        if binaryData[i][0] == "0":
            i += 1
            continue
        try:
            if binaryData[i][:3] == "110":
                if (checkBytes(binaryData[i + 1:], 1) == False):
                    return (False)
                i += 1
            elif binaryData[i][:4] == "1110":
                if (checkBytes(binaryData[i + 1:], 2) == False):
                    return (False)
                i += 2
            elif binaryData[i][:5] == "11110":
                if (checkBytes(binaryData[i + 1:], 3) == False):
                    return (False)
                i += 3
            else:
                return (False)
        except IndexError:
            return (False)
        i += 1

    return (True)
