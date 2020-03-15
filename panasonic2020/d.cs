using System;

namespace dotnet_test
{
    class ProgramD
    {
        static string Alphas = "abcdefghij";

        static void Fun(ref char[] buf, int len, int imax, int N){
            for(int i=0; i<=imax + 1; i++){
                buf[len] = Alphas[i];
                int nextlen = len + 1;
                if(nextlen == N){
                    Console.WriteLine(buf, 0, N);
                }else{
                    Fun(ref buf, nextlen, Math.Max(imax, i), N);
                }
            }
        }

        static void Main(string[] args)
        {
           int N = int.Parse(Console.ReadLine());
           char[] buf = new char[N];
           Fun(ref buf, 0, -1, N);
        }
    }
}