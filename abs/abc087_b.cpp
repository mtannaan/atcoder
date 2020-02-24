// hhttps://atcoder.jp/contests/apg4b/tasks/APG4b_ca
// g++ -std=c++11 ex22.cpp && ./a.out
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <map>
#include <bitset>

using namespace std;

int main()
{
    int A, B, C, X;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> X;

    int count = 0;
    for (int a = 0; a <= A; a++)
    {
        for (int b = 0; b <= B; b++)
        {
            for (int c = 0; c <= C; c++)
            {
                count += (500 * a + 100 * b + 50 * c == X);
            }
        }
    }

    cout << count << endl;

    return 0;
}