=begin
Disemvoweler Ruby Solution
Author: Peter Gagliardi
=end

#
# Take a string and divide it into two strings: one that contains only
# the vowels and another for consonants
#
def disemvowel sentence
    # Convert to lowercase and strip out spaces
    input = sentence.downcase.tr ' ', ''

    # Split the characters into [[vowels], [consonants]] and then convert
    # to two strings
    input.chars
        .partition {|x| "aeiou ".include? x}
        .map {|x| x.join ''}
end

# Test it out
puts "Time to remove some vowels:"
puts "Enter some words separated by spaces"
words = gets.chomp
vowels, consonants = disemvowel words
puts "Now without vowels: #{consonants}\nWe removed: #{vowels}"
