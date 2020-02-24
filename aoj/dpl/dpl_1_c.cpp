// ナップザック問題
// https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_C

// g++ -std=c++11 xxx.cpp && ./a.out

#include <iostream>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <vector>

using namespace std;

vector<int> w(100), v(100);
int n;

int vmax(int W)
{
    static vector<int> memos(10001, -1);
    if (W <= 0)
    {
        return 0;
    }

    int &memo = memos.at(W);
    if (memo >= 0)
    {
        return memo;
    }
    int ret = -1;
    for (int i = 0; i < n; i++)
    {
        if (w.at(i) <= W)
        {
            ret = max(ret, v.at(i) + vmax(W - w.at(i)));
        }
    }
    ret = max(ret, vmax(W - 1));
    memo = ret;
    return memo;
}

int main(void)
{
    int W;
    cin >> n >> W;
    for (int i = 0; i < n; i++)
    {
        cin >> v.at(i) >> w.at(i);
    }

    cout << vmax(W) << endl;

    return 0;
}