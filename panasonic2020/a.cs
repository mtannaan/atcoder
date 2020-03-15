using System;

namespace dotnet_test
{
    class ProgramA
    {
        static void Main(string[] args)
        {
            int[] nums = new int[] {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
            int K =
            int.Parse(Console.ReadLine());
            
            Console.WriteLine(nums[K - 1]);
        }
    }
}
