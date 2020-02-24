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
#include <cmath>
#include <climits>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> X(N);
    for (int &xi : X)
    {
        cin >> xi;
    }

    int minsum = INT_MAX;
    for (int p = 1; p <= 100; p++)
    {
        int sum = 0;
        for (int xi : X)
        {
            sum += (xi - p) * (xi - p);
        }
        minsum = min(sum, minsum);
    }

    cout << minsum << endl;

    return 0;
}