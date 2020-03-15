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
#include <cstdio>

using namespace std;

int main()
{
    int N, R;
    cin >> N;
    cin >> R;

    // int internal;
    // R = (N >= 10) ? internal : internal - 100 * (10 - N);

    if (N >= 10)
    {
        cout << R << endl;
    }
    else
    {
        cout << R + 100 * (10 - N) << endl;
    }

    return 0;
}