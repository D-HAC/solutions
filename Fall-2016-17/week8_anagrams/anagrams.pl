use 5.18.2;
use strict;
use warnings;

sub reformat_phrase {
    # Handle arguments.
    # in Perl 6 you don't have to do this
    # weirdness
    my ($phrase) = @_;

    # make lowercase
    my $lower = lc $phrase;

    # Remove everything that's not an alphabetic character
    # s/pattern/replacement/ (substitute) means match a pattern via regex
    # on the string and replace with the replacement (in this case
    # empty string). the g (global) means match multiple times through the
    # the string
    $lower =~ s/[^a-z]//g;

    # Split the remaining characters into an array
    my @chars = split //, $lower;

    # sort the characters
    my @sorted = sort @chars;

    # join them all together as the return value
    join "", @sorted
}

# For every line in the input file or STDIN
while (<>) {
    # Regex match the input
    /"(.*)" \? "(.*)"/;
    # pull out the two groups
    my $a_str = $1;
    my $b_str = $2;

    # Reformat and sort the characters in each string
    my $a_sorted = reformat_phrase $a_str;
    my $b_sorted = reformat_phrase $b_str;

    # If the sorted characters match, we have an anagram!
    if ($a_sorted eq $b_sorted) {
        # qq (double quote) allows for double quotes without
        # escaping as well as string interpolation
        say qq("$a_str" is an anagram of "$b_str");
    }
    # If they don't match, there is not an anagram.
    else {
        say qq("$a_str" is NOT an anagram of "$b_str");
    }
}
