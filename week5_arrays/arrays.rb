#!/usr/bin/env ruby
def one2two index, cols
    # return [row, col]
    return [index / cols, index % cols]
end

def two2one row, col, cols
    return row * cols + col
end

# New empty array of length n
# initialized to 0s
def empty_1d_arr n
    Array.new(n, 0)
end

# New 2D array with dimensions rows x cols
# initialized to 0s
def empty_2d_arr rows, cols
    Array.new(rows) {empty_1d_arr cols}
end

def arr1to2 arr, cols
    # We have the number of columns, let's get the rows
    rows = arr.length / cols
    arr2d = empty_2d_arr rows, cols
    
    arr.each_with_index do |x, i|
        r, c = one2two i, cols
        arr2d[r][c] = x
    end
    arr2d
end

def arr2to1 arr, cols
    rows = arr.length
    output = empty_1d_arr rows * cols
    arr.each_with_index do |row, r|
        row.each_with_index do |val, c|
            i = two2one r, c, cols
            output[i] = val
        end
    end
    output
end

def puts_arr arr
    arr.each do |row|
        puts row.inspect
    end
end

arr = (0...12).to_a
two_d = arr1to2 arr, 4
puts_arr two_d

puts "---"

one_d = arr2to1 two_d, 4
puts one_d.inspect

