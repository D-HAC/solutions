#!/usr/bin/env ruby
#
# Degree Conversions - Ruby Solution
#
# To Run: `ruby degrees.rb` or `./degrees.rb`
#

# Functions to convert degrees <-> radians ======
# Note: Parentheses are optional in Ruby
def degrees_to_radians degrees
    # The :: operator is much like the scope
    # resolution operator in C++
    degrees * Math::PI / 180.0
end

def radians_to_degrees radians
    # Also note how in Ruby the last line of a
    # function is the value the function returns.
    # the 'return' keyword is optional in this case.
    radians * 180.0 / Math::PI
end

# Functions to convert fahrenheit <-> celsius <-> kelvins ========

def fahrenheit_to_celsius f
    5.0 / 9.0 * (f - 32.0)
end

def celsius_to_fahrenheit c
    9.0 / 5.0 * c + 32.0
end

def celsius_to_kelvin c
    c + 273.15
end

def kelvin_to_celsius k
    k - 273.15
end

# Programming Puzzle Functions

def read_input
    # gets -- reads a line of input
    # strip -- removes whitespace from beginning
    #   and end of the string
    input_line = gets.strip
    output_line = gets.strip

    # Return the values as an array
    [input_line, output_line]
end

def parse_input_line line
    # Split the lines into three parts. value needs to
    # be a float (decimal number).
    #
    # [0...-2] means slice the text from the start (position 0)
    #   to 2 from the right (exclusive).
    # Example: "hello"[0...-2] = "hel"
    #
    # .to_f turns a string (text) into a float (decimal)
    value = line[0...-2].to_f
    # Select the last two characters. Double dot means include
    # index -1 where triple dot would mean exclude -1
    units = line[-2..-1]

    # We want to return the value and the units
    [value, units]
end

def convert value, units
    # Check the value of units and return one
    # of the following results. This is like
    # a switch statement in other languages but
    # a little nicer
    case units
    when "rd"
        # Parentheses are optional!
        radians_to_degrees value
    when "dr"
        degrees_to_radians value
    when "fc"
        fahrenheit_to_celsius value
    when "cf"
        celsius_to_fahrenheit value
    when "ck"
        celsius_to_kelvin value
    when "kc"
        kelvin_to_celsius value
    when "fk"
        # You can compose functions in programming!
        celsius_to_kelvin(fahrenheit_to_celsius(value))
    when "kf"
        # If you have to nest function calls, keep the
        # parentheses
        celsius_to_fahrenheit(kelvin_to_celsius(value))
    # The user typed something that isn't a valid conversion
    else
        # We can't convert this, so let's raise an error
        # and let someone else handle it.
        raise "No candidate for conversion"
    end
end

def process_line line
    # Reformat the input line
    value, units = parse_input_line line
    # Calculate the result
    result = convert value, units
    # Get the result's units (last character in the units string)
    result_units = units[-1]

    # Print the value rounded to two decimal places
    # and the result units
    puts "#{result.round(2)}#{result_units}"
end

# Main script
# Read the two lines of input. Note that we are
# implicitly calling the read_input function just by
# writing its name!
input_lines = read_input

# Loop over the input lines
# this is like `for line in input_lines` in Python
input_lines.each do |line|
    # This is like a try/catch block
    # in other languages
    begin
        process_line line
    rescue => error
        # If an error happens, print the error message
        puts error
    end
end
