using System;
using System.Linq;

namespace dotnet_test
{
    class ProgramC
    {
        static void Main(string[] args)
        {
            var nums =
                Console.ReadLine()
                .Split(' ')
                .Select(UInt64.Parse)
                .ToArray();
            UInt64 a = nums[0], b = nums[1], c = nums[2];



            UInt64 rhs_sqrt = c - a - b;
            UInt64 lhs = 4 * a * b;


            if (c < a + b || lhs >= rhs_sqrt * rhs_sqrt)
            {
                Console.WriteLine("No");
            }
            else
            {
                Console.WriteLine("Yes");
            }
        }
    }
}