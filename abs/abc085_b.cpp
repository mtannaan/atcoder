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
    int N;
    cin >> N;

    set<int> d;
    for (int i = 0; i < N; i++)
    {
        int di;
        cin >> di;
        d.insert(di);
    }

    cout << d.size() << endl;

    return 0;
}