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
    int N;
    cin >> N;

    vector<int> A(N);

    for (int &Ai : A)
    {
        cin >> Ai;
    }

    int count = 0;
    while (1)
    {
        for (int &Ai : A)
        {
            if (Ai % 2 == 0)
            {
                Ai /= 2;
            }
            else
            {
                cout << count << endl;
                return 0;
            }
        }
        count += 1;
    }

    return 0;
}