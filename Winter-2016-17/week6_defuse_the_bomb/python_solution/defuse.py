from __future__ import print_function


class Color:
    WHITE = 1
    BLACK = 2
    RED = 3
    GREEN = 4
    ORANGE = 5
    PURPLE = 6

    @classmethod
    def from_str(cls, s):
        s = s.strip().upper()
        if not hasattr(cls, s):
            raise RuntimeError("Unknown color '{}'".format(s))
        else:
            return getattr(cls, s)


def free_rule(wire):
    """
    Bomb is still intact after cutting a wire. Meant to act as the rule for the
    first wire to cut.
    """
    return True


def white_wire_rule(wire):
    return wire != Color.WHITE and wire != Color.BLACK


def red_wire_rule(wire):
    return wire == Color.GREEN


def black_wire_rule(wire):
    return wire not in {Color.WHITE, Color.GREEN, Color.ORANGE}


def orange_wire_rule(wire):
    return wire == Color.RED or wire == Color.BLACK


def green_wire_rule(wire):
    return wire == Color.ORANGE or wire == Color.WHITE


def purple_wire_rule(wire):
    return wire not in {Color.PURPLE, Color.GREEN, Color.ORANGE, Color.WHITE}


NEXT_RULE = {
    Color.WHITE: white_wire_rule,
    Color.BLACK: black_wire_rule,
    Color.RED: red_wire_rule,
    Color.GREEN: green_wire_rule,
    Color.ORANGE: orange_wire_rule,
    Color.PURPLE: purple_wire_rule,
}


def defuse(rule, wire):
    """
    Takes a rfunction representing what the next wire can be and the next wire.

    Args:
        rule (function): This function takes the wire as an input and returns a
            bool representing if the momb has not blown up yet.
        wire (int): The color of the next wire to cut.

    Returns:
        (None, function): The next rule to follow, or None to indicate the bomb
            blew up.
    """
    bomb_intact = rule(wire)
    if bomb_intact:
        return NEXT_RULE[wire]
    else:
        return None


def wire_stream_handler(wire_stream):
    """
    Accepts a stream/iterator of wires and runs defuse on it.

    Args:
        wire_stream (Iterator[int])

    Returns:
        bool: True if the bomb is intact. False otherwise.
    """
    rule = free_rule
    while rule:
        try:
            wire = next(wire_stream)
        except StopIteration:
            # No more wires means successfully defused bomb.
            return True
        else:
            rule = defuse(rule, wire)
    return False


def wire_str_stream_handler(wire_str_stream):
    """
    Wrapper for wire_stream_handler, but accepts a stream of strings to be
    converted to Colors.
    """
    return wire_stream_handler(iter(map(Color.from_str, wire_str_stream)))


def main():
    import sys

    if wire_str_stream_handler(sys.stdin):
        print("BOMB DEFUSED")
    else:
        print("BOOM")

    return 0


if __name__ == "__main__":
    main()

