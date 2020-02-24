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
    string s;

    cin >> s;

    int sum = 0;
    for (const char &c : s)
    {
        if (c == '1')
            sum += 1;
    }

    cout << sum << endl;

    return 0;
}