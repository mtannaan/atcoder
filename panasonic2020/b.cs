using System;
using System.Linq;

namespace dotnet_test
{
    class ProgramB
    {
        static void Main(string[] args)
        {
            var hw =
                Console.ReadLine()
                .Split(' ')
                .Select(Int64.Parse)
                .ToArray();
            Int64 H = hw[0], W = hw[1];

            Int64 ret;
            if (H == 1 || W == 1)
            {
                ret = 1;
            }
            else if (W * H % 2 == 0)
            {
                ret = W * H / 2;
            }
            else
            {
                ret = (W * H + 1) / 2;
            }
            /*else
            {
                ret =
                ((W + 1) / 2) * ((H + 1) / 2)
                + (W / 2) * (H / 2);
            }
            */
            Console.WriteLine(ret);
        }
    }
}