// hhttps://atcoder.jp/contests/apg4b/tasks/APG4b_ca
// g++ -std=c++11 ex22.cpp && ./a.out
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <map>
#include <bitset>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;

    priority_queue<int> a;

    for (int i = 0; i < N; i++)
    {
        int ai;
        cin >> ai;
        a.push(ai);
    }

    vector<int> ab = {0, 0};
    bool a_or_b = false;

    while (!a.empty())
    {
        int a_max = a.top();
        ab.at((int)a_or_b) += a_max;
        a.pop();
        a_or_b = !a_or_b;
    }

    cout << ab.at(0) - ab.at(1) << endl;

    return 0;
}