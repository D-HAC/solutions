# Challenges for the week of October 5th, 2016
# Source: https://d-hac.github.io/puzzle/game-of-threes
# Author: Gray (surrsurus) gdm44@drexel.edu
# Ommitted challenges: Tick Tock problem

######  1st Challenge
# Functions to Add to Your Code Library
#
# bool is_divisible_by(int x, int n);
#
# This method returns true if x is divisible by n, and false otherwise. Assume x >= 0 and n > 0.
#
# Examples:
#
# is_divisible_by(4, 2) #=> True
# is_divisible_by(3, 2) #=> False
# is_divisible_by(6, 4) #=> False
# is_divisible_by(6, 2) #=> True

# My solution:
is_divisible_by = lambda x, y: True if x % y == 0 else False

# print(is_divisible_by(4, 2))
# print(is_divisible_by(5, 2))

######  1st Mini-project:
# Stripes - write a console program that displays stripes.
# Every Nth line, print a line of different characters. Examples:
#
# N=2
# ============================
# ----------------------------
# ============================
# ----------------------------
# ============================
# ----------------------------

# My solution:
make_lines = lambda n: [(lambda x: '='*10 if x % n == 0 else '-'*10 )(x) for x in range(n*3+1)]

# for line in make_lines(5): print(line)

######  1st Puzzle: Game of Threes
# Description: https://www.reddit.com/r/dailyprogrammer/comments/3r7wxz/20151102_challenge_239_easy_a_game_of_threes/

# My solution:
# Works, but you only see the end output, which is always 1
game_of_threes = lambda n: n if n == 1 else game_of_threes((n + (0, -1, 1)[int(n % 3)]) / 3)

# print(game_of_threes(100))

######  2nd Puzle: Fizzbuzz
# You should know what the fizzbuzz problem is.

# My solution:
fizzbuzz = lambda *_: print([(lambda x: 'fizzbuzz' if x%3 == 0 and x%5 == 0 else 'fizz' if x%3 == 0 else 'buzz' if x%5 == 0 else str(x))(x) for x in range(1, 100)])

# fizzbuzz()
