#include <iostream>

using namespace std;

bool is_divisible(int x, int n);

int main()
{
    int x;

    cout << "=== Game of Threes ===" << endl << endl;

    // Ask user to enter number
    cout << "Enter number: ";
    cin >> x;

    do
        {
          // If number is divisible by 3, divide it by 3
          if (is_divisible(x, 3))
                x = x / 3;

          // Otherwise
          else
            {
              // If (number + 1) is divisible by 3, divide it
              if(is_divisible(x + 1, 3))
                  x = (x + 1)/3;

              // Or if (number - 1) is divisible by 3, divide it
              if (is_divisible(x - 1, 3))
                  x = (x - 1)/3;

            }

          // Output number
          cout << x << endl;
        }

    // And keep doing this while number is not 1
    while(x != 1);


    return 0;
}

bool is_divisible(int x, int n)
    {
      if(x % n == 0)
        return true;
      else
        return false;
    }
