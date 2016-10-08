/**
 * Game of Threes C# Solution
 * 
 * Author: Peter Gagliardi
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace threes_csharp {
    class Divisibility {
        public static bool is_divisible_by(int x, int n) {
            return x % n == 0;
        }
    }

    class GameOfThrees {
        int read_number() {
            int val = Convert.ToInt32(Console.ReadLine());

            
            if (val <= 1) {
                throw new ArgumentException("Too small!");
            }
            return val;
        }

        int single_step(int num) {
            int new_num;
            int add_value;
            if (Divisibility.is_divisible_by(num, 3)) {
                new_num = num / 3;
                add_value = 0;
            } else if (Divisibility.is_divisible_by(num - 1, 3)) {
                new_num = (num - 1) / 3;
                add_value = -1;
            } else {
                new_num = (num + 1) / 3;
                add_value = 1;
            }

            Console.WriteLine(string.Format("{0} {1}", num, add_value));
            return new_num;
        }

        void play_game(int num) {
            while (num > 1)
                num = single_step(num);
            Console.WriteLine(1);
        }

        static void Main(string[] args) {
            GameOfThrees threes = new GameOfThrees();

            try {
                int val = threes.read_number();
                threes.play_game(threes.read_number());
            }
            catch (ArgumentException e) {
                Console.WriteLine(e.Message);
            }
            catch (FormatException) {
                Console.WriteLine("You must enter an integer > 2!");
            }
            catch (OverflowException) {
                Console.WriteLine("Too big!");
            }
        }
    }
}
