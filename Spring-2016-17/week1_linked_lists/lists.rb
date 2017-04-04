class List
    # Needed to allow fields to be public
    attr_accessor :value, :next_node

    # Constructor
    def initialize value=nil, next_node=nil
        @value = value
        @next_node = next_node
    end

    # String representation
    def to_s
        if @next_node.nil?
            "#{@value} -> NIL"
        else
            "#{@value} -> #{@next_node}"
        end
    end
end

# Take a string like "5->4->3->2->NULL" and create
# a List
def parse_list list_str
    list = nil
    list_str.split("->").reverse.each do |x|
        unless x == 'NULL'
            list = List.new x.to_i, list
        end
    end
    list
end

# Display the elements of a list, one per line
def display_list list
    if list.nil?
        puts "(empty)"
    else
        curr = list
        until curr.nil?
            puts curr.value
            curr = curr.next_node
        end
    end
end

# Construct a list in reverse
def reverse_list list
    new_list = nil
    old_list = list
    until old_list.nil?
        new_list = List.new old_list.value, new_list
        old_list = old_list.next_node
    end
    new_list
end

# Main routine
def main
    puts "Enter a list like 5->4->3->2->NULL"
    print "> "
    l = parse_list gets.strip
    puts "Elements:"
    display_list l
    puts "Reversed:"
    puts reverse_list l
end

# Call main()
main
