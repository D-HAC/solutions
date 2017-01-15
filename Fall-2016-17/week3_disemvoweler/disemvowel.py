#!/usr/bin/env python3
"""
Disemvoweler: Python 3 Solution
Author: Peter Gagliardi
"""

def disemvowel(sentence):
    vowels = ""
    consonants = ""
    for c in sentence.lower():
        if c in "aeiou":
            vowels += c
        elif c == ' ':
            continue
        else:
            consonants += c
    return vowels, consonants

if __name__ == "__main__":
    words = input('Enter some words: ')
    vowels, consonants = disemvowel(words)
    print("After the operation: {}".format(consonants))
    print("Removed vowels: {}".format(vowels))
