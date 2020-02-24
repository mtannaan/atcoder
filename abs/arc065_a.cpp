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
    string s;
    cin >> s;

    bool er_flag = false;
    bool r_flag = false;
    int cur = 0;
    while (cur < s.size())
    {
        int n_remaining = s.size() - cur;
        if (
            n_remaining >= 5 &&
            s.substr(cur, 5) == "dream")
        {
            er_flag = true;
            r_flag = false;
            cur += 5;
        }
        else if (
            n_remaining >= 5 &&
            s.substr(cur, 5) == "erase")
        {
            er_flag = false;
            r_flag = true;
            cur += 5;
        }
        else if (
            er_flag &&
            n_remaining >= 2 &&
            s.substr(cur, 2) == "er")
        {
            er_flag = false;
            r_flag = false;
            cur += 2;
        }
        else if (
            r_flag &&
            n_remaining >= 1 &&
            s.substr(cur, 1) == "r")
        {
            er_flag = false;
            r_flag = false;
            cur += 1;
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}