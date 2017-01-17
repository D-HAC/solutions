#!/usr/bin/env python
# Golldilocks Python 3 Solution
# Author: Peter Gagliardi
import sys

def parse_line(line):
    """
    Parse a single line in the format
    '<weight:int> <heat:int>'
    """
    weight, heat = line.split(' ')
    return int(weight), int(heat)

def feasible_seat(weight, heat, min_weight, max_heat):
    """
    Return True if the seat can support Goldilocks'
    weight and the porridge is not too hot. This is used
    as a filter
    """
    return weight >= min_weight and heat <= max_heat

def heuristic(weight, heat, min_weight, max_heat):
    """
    Return the weight above the min_weight and
    the heat below the max heat. This function needs to
    be minimized
    """
    return (weight - min_weight) + (max_heat - heat)

if __name__ == '__main__':
    # Get Golldilocks' weight and heat limit
    min_weight, max_heat = parse_line(input().strip())

    # Skip the '--' line
    input()

    # read in the seat descriptions
    seats = [parse_line(line) for line in sys.stdin]

    # Calculate heuristics for seats that meet Goldilocks'
    # minimum requirements. Also include the seat number
    seat_heuristics = [
        (i + 1, heuristic(weight, heat, min_weight, max_heat))
        for i, (weight, heat) in enumerate(seats)
        if feasible_seat(weight, heat, min_weight, max_heat)]

    try:
        seat_num, _ = min(seat_heuristics, key=lambda x: x[1])
        print(seat_num)
    except ValueError:
        print("Try the next house.")
