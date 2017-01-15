function is_palindrome(Str)

ComparedStr = Str;

Str(~ismember(Str,['A' : 'Z' 'a' : 'z'])) = ''; %removes all members of the string that are not letters A-Z or a-z

StrLength = length(Str);
NewStr='';

n=0;

while n<StrLength
    NewStr = strcat(NewStr,Str(StrLength-n));
    n=n+1;
end

StrComparison = strcmpi(Str,NewStr);

if StrComparison == 1
    fprintf('This is a great achievement. %s is a palindrome.\n',ComparedStr) 
    else
    fprintf('We offer our sincere condolences. %s is not palindrome.\n',ComparedStr) 
end
end