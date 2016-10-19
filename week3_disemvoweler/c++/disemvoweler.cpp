#include <string>
#include <iostream>
#include <tuple>

using namespace std;

string rmCharFromStr(string inp, char ch);
tuple<string, string> disemvowel(string inp); 

int main(int argc, char* argv[])
{
    string tmp;
    string input = "Hello World!";
    tmp = rmCharFromStr(input, 'o');
    cout << "The removed text is: " << tmp << endl;
    input = "Hard coded messages are cool!";
    tuple<string, string> results;
    results = disemvowel(input);
    cout << "The message was: " << input << endl; 
    cout << "The vowels removed were: " << get<0>(results) << endl;
    cout << "The removed value was: " << get<1>(results) << endl;
}

string rmCharFromStr(string inp, char ch)
{
    string res;

    for(int i=0; i < inp.length(); i++)
    {
        char tmp = inp[i];
        if(tmp != ch)
        {
            res.append(1, tmp);
        }
    }

    return res;
}

tuple<string, string> disemvowel(string inp) 
{
    string res;
    string vowels;

    for(int i=0; i < inp.length(); i++)
    {
        char tmp = inp[i];
        switch(tmp)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowels.append(1,tmp);
                break;
            default:
                res.append(1,tmp);
                break;
        }
    }

    return make_tuple(res, vowels);
}
