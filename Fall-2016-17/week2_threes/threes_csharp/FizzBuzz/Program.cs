using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FizzBuzz {
    class Divisibility {
        public static bool is_divisible_by(int x, int n) {
            return x % n == 0;
        }
    }

    class FizzBuzz {

        public void fizzbuzz(int n) {
            //Do this for the numbers from 1 to n
            for (int i = 1; i <= n; i++) {
                //This is the text of the current line
                string output = "";

                //Check if we found cases for "Fizz", "Buzz"
                //or "FizzBuzz" and update the string
                if (Divisibility.is_divisible_by(i, 3))
                    output += "Fizz";
                if (Divisibility.is_divisible_by(i, 5))
                    output += "Buzz";
                
                //If output is not "Fizz" and/or "Buzz"
                //just set the string to the current number
                if (output == "")
                    output += i;

                //Finally, print the current value
                Console.WriteLine(output);
            }
        }

        static void Main(string[] args) {
            var fizz = new FizzBuzz();
            fizz.fizzbuzz(20);
        }
    }
}
