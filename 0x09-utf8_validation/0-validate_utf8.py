#!/usr/bin/python3
"""
    Contains function to check a given amount of
utf-8 bytes, and a function to check bytes
of a given array of binary utf-8 headers
(More on headers: https://dzone.com/articles/utf-8-in-http-headers)

functions ::

checkBytes()

and

validUTF8()
"""


def checkBytes(binaryData, bytesToCheck):
    """
    binaryData(Array) - array of bytes to check starting after
    the utf-8 header identifier
        >110XXXXX - 2 byte identifier
        >1110XXXX - 3 byte identifier
        >11110XXX - 4 byte identifier
    (More on headers: https://dzone.com/articles/utf-8-in-http-headers)
    function HAS to start after a given identifier so determine
    the identifier and pass the REST of the array

    Ex: 2 bytes to be checked
    Shouldnt be passed (here we have the idenfier passed in the data)
    ["110", "10"]
    Shouldbe passed (here we left the identifier out of the array passed
    to function in binaryData)
    ["10"]

    After you call the function with a specific identifier ommited,
    use the chart below to tell the function how many of the following
    bytes it needs to check

    Will check a given amount of utf-8 bytes (bytesToCheck)
    (bytesToCheck = 1 -- 2 byte check)
    (bytesToCheck = 2 -- 3 byte check)
    (bytesToCheck = 3 -- 4 byte check)
    (bytesToCheck = (...) -- (...) + 1 byte check)

    Returns false if following bytes are not valid
    """
    for data in range(0, bytesToCheck):
        if (binaryData[data][:2] != "10"):
            return (False)
    return (True)


def validUTF8(data):
    """
    Returns True if data passed is a valid UTF-8 encoding
        The utf-8 header identifier
            >110XXXXX - 2 byte identifier
            >1110XXXX - 3 byte identifier
            >11110XXX - 4 byte identifier
        (More on headers: https://dzone.com/articles/utf-8-in-http-headers)
    """

    """Converts to binary / gets first 5 digits (aka the header)"""
    binaryData = []

    for dataPoint in data:
        binaryDataPoint = ""
        for i in range(1, 33):
            if (dataPoint % 2 == 0):
                binaryDataPoint += "0"
            else:
                binaryDataPoint += "1"
            dataPoint = dataPoint // 2
        binaryData.append(binaryDataPoint[:8][::-1][:5])
        if dataPoint != 0:
            return (False)

    """Checks binary data"""
    i = 0
    while i < len(binaryData):
        if binaryData[i][0] == "0":  # Single byte check (does nothing)
            i += 1
            continue
        try:
            if binaryData[i][:3] == "110":  # Two byte check
                if (checkBytes(binaryData[i + 1:], 1) is False):
                    return (False)
                """
                    If byte is valid the following line will speed up
                the loop to pass the checked bytes
                """
                i += 1
            elif binaryData[i][:4] == "1110":  # Three byte check
                if (checkBytes(binaryData[i + 1:], 2) is False):
                    return (False)
                i += 2
            elif binaryData[i][:5] == "11110":  # Four byte check
                if (checkBytes(binaryData[i + 1:], 3) is False):
                    return (False)
                i += 3
            else:
                """ Will return false in event of incorrect utf-8 header"""
                return (False)
        except IndexError:
            """
                Covers if an array is passed which doesnt have the correct
                amount of utf-8 headers towards the end
            """
            return (False)
        i += 1

    return (True)
