import re
import sys

RULES = [
    'W[^WB]',
    'RG',
    'B[^WGO]',
    'G[OW]',
    'P[^PGOW]',
    'O[RB]',
]
REGEXES = [re.compile(r) for r in RULES]

def defuses_bomb(seq):
    # Iterate over all the characters except the last
    # and check for sequences that would set off the bomb
    for i in range(len(seq) - 1):
        # Check each pattern and make sure at least one
        # matches the beginning of seq[i:]
        for regex in REGEXES:
            # We found a match, we're good
            if regex.match(seq, pos=i):
                break
        else:
            # No match found
            return False
    else:
        # If we survived this long, the bomb is defused!
        return True

if __name__ == '__main__':
    seq = ''.join(
        line[0].upper() 
        for line in sys.stdin
        if line.rstrip())
    if defuses_bomb(seq):
        print("BOMB DEFUSED")
    else:
        print("BOOM")
        