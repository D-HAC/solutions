"""
Roman Numerals Convversion Library
Author: Peter Gagliardi
"""

# Table of roman numerals and their values. Note that I include
# the subtraction rules for my greedy algorithm.
TO_ROMAN_TABLE = [
    (1000, 'M'),
    (900, 'CM'),
    (500, 'D'),
    (400, 'CD'),
    (100, 'C'),
    (90, 'XC'),
    (50, 'L'),
    (40, 'XL'),
    (10, 'X'),
    (9, 'IX'),
    (5, 'V'),
    (4, 'IV'),
    (1, 'I')
]

def dec2roman(dec):
    """
    Convert a decimal to roman numerals
    """
    output = ""
    for val, roman_digit in TO_ROMAN_TABLE:
        while dec >= val:
            dec -= val
            output += roman_digit
    return output

ROMAN_DEC_MAP = {
    'M': 1000,
    'D': 500,
    'C': 100,
    'L': 50,
    'X': 10,
    'V': 5,
    'I': 1
}

def roman2dec(roman):
    """
    Convert roman numerals to decimal recursively
    """
    if len(roman) == 0:
        return 0
    if len(roman) == 1:
        return ROMAN_DEC_MAP[roman]

    # look at the first two characters
    first = ROMAN_DEC_MAP[roman[0]]
    second = ROMAN_DEC_MAP[roman[1]]

    # If the first is less than the second, we have a subtraction rule.
    # add second - first to the total
    if first < second:
        return second - first + roman2dec(roman[2:])

    # Otherwise, just add the first character to the total and
    # examine the rest of the string
    return first + roman2dec(roman[1:])

if __name__ == "__main__":
    print(dec2roman(7))
    print(dec2roman(1404))
    print(dec2roman(2017))

    print(roman2dec("VII"))
    print(roman2dec("MCDIV"))
    print(roman2dec("MMXVII"))
