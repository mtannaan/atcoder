using System;
using System.Linq;

namespace dotnet_test
{
    class Program
    {
        char MergeChar(char a, char b){
            if(a == '?'){
                return b;
            }else if(b == '?'){
                return a;
            }else if (a == b){
                return a;
            }else{
                return (char)0;
            }
        }

        static string Comp(string left, string right){
            for(int ofs = 0; ofs < left.Length; ofs++){
                bool matched = true;
                for(int i=0; i + ofs < left.Length && i < right.Length; i++){
                    left[i + ofs]
                }
                if(matched)
            }
            return left + right;
        }
        static void Main(string[] args)
        {
            string
            a = Console.ReadLine(),
            b = Console.ReadLine(),
            c = Console.ReadLine();


        }
    }
}