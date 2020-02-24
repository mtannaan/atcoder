// hhttps://atcoder.jp/contests/apg4b/tasks/APG4b_ca
// g++ -std=c++11 ex22.cpp && ./a.out
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <queue>

using namespace std;

int main()
{
    int N, Y;
    cin >> N;
    cin >> Y;

    for (int n_10000 = 0; n_10000 <= Y / 10000; n_10000++)
    {
        int y_rest = Y - 10000 * n_10000;
        for (int n_5000 = 0; n_5000 <= y_rest / 5000; n_5000++)
        {
            int n_1000 = N - n_10000 - n_5000;
            if (y_rest - 5000 * n_5000 == 1000 * n_1000)
            {
                cout << n_10000 << " " << n_5000 << " " << n_1000 << endl;
                return 0;
            }
        }
    }

    cout << "-1 -1 -1" << endl;

    return 0;
}