#Game of threes using command-line args
import sys

def divide(x):
	print str(x)+"/3"
	x = x/3
	return x

def add(x):
	print str(x)+" + 1"
	x = x+1
	return x
	
def subtract(x):
	print str(x)+" - 1"
	x = x-1
	return x


x = int(sys.argv[1])
print x

while x > 1:
	if x%3 == 0:
		x = divide(x)
	elif (x+1)%3 == 0:
		x = add(x)
	elif (x-1)%3 == 0:
		x = subtract(x)

print x