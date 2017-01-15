#!/usr/bin/env python3
"""
Degrees Puzzle -- Python Solution

Author: Peter Gagliardi

To run: `python3 degrees.py` or `./degrees.py`
"""
# I'm a connoseiur of pi. my slices are imported.
import math

# Functions for converting between degrees <-> radians
def degrees_to_radians(degrees):
    return degrees * math.pi / 180.0

def radians_to_degrees(radians):
    return radians * 180.0 / math.pi

# Functions for converting °F <-> °C <-> K

def fahrenheit_to_celsius(f):
    return 5.0 / 9.0 * (f - 32.0)

def celsius_to_fahrenheit(c):
    return 9.0 / 5.0 * c + 32.0

def celsius_to_kelvin(c):
    return c + 273.15

def kelvin_to_celsius(k):
    return k - 273.15

# Programming challenge solution ========

def read_input():
    """
    Read input from the command line
    input -- read a line of input
    strip -- remove whitespace from beginning
        and end of string.
    """
    input_line = input().strip()
    output_line = input().strip()

    # Return the values as an array
    return input_line, output_line

def parse_input_line(line):
    # Python allows multiple variable assignment!
    # line[:-2] means slice from beginning of string up to
    # but not including the 2nd character from the right
    # line[-2:] means slice from the 2nd to last character to
    # the end
    value, units = float(line[:-2]), line[-2:]
    return value, units

def convert(value, units):
    if units == "rd":
        return radians_to_degrees(value)
    elif units == "dr":
        return degrees_to_radians(value)
    elif units == "fc":
        return fahrenheit_to_celsius(value)
    elif units == "cf":
        return celsius_to_fahrenheit(value)
    elif units == "ck":
        return celsius_to_kelvin(value)
    elif units == "kc":
        return kelvin_to_celsius(value)
    elif units == "kf":
        return celsius_to_fahrenheit(kelvin_to_celsius(value))
    elif units == "fk":
        return celsius_to_kelvin(fahrenheit_to_celsius(value))
    else:
        raise ValueError("No candidate for conversion")

def process_line(line):
    """
    handle a single line of input
    """
    # Reformat the input line
    value, units = parse_input_line(line)
    # Calculate the result
    result = convert(value, units)
    # Get the result's units (last character in the units string)
    result_units = units[-1]

    # Print the value rounded to two decimal places
    # and the result units
    print("{:.02f}{}".format(result, result_units))

# This is a common Python idiom for
# making sure this code only runs when run as a script
# and not when imported as a library
if __name__ == "__main__":
    # Read the two lines of input.
    input_lines = read_input()

    # Loop over both lines
    for line in input_lines:
        try:
            process_line(line)
        # If something goes wrong, print the error
        # message and keep going.
        except ValueError as e:
            print(e)
