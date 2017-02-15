#!/usr/bin/env python
# Turtle graphics examples
# Author: Peter Gagliardi

import turtle

# Create our turtle
t = turtle.Turtle()

# Draw a cool pattern by drawing straight lines then making sharp
# angled turns
for i in range(9):
    # Move 300 pixels forward
    t.forward(300)
    # Turn to the right 200 degrees
    t.right(200)

# This keeps the turtle window open at the end of the program
turtle.mainloop()
