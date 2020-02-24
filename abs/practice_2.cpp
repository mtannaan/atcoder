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
    int a, b;
    string s;

    cin >> a;
    cin >> b;

    if (a * b % 2)
    {
        cout << "Odd" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
    return 0;
}