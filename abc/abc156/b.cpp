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

using namespace std;

int main()
{
    int N, K;
    cin >> N;
    cin >> K;

    double ell = log(N) / log(K);
    cout << int(ell) + 1 << endl;

    return 0;
}