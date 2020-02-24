// 連鎖行列積
// https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_B

// g++ -std=c++11 xxx.cpp && ./a.out

#include <iostream>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <vector>

using namespace std;

// (r1, c1) * (r2, c2) のスカラー乗算回数はr1 * c1 * c2
// 結果は (r1, c2)

// 例: 各行列の(r, c)が
// (3, 4), (4, 2), (2, 5)

// (3, 4) * (4, 2) を先に計算した場合
// 乗算回数 = 3*4*2 + 3*2*5 = 54

// (4, 2), (2, 5) を先に計算した場合
// 乗算回数 = 4*2*5 + 3*4*5 = 100

// 連鎖の右端に (5, 7) をつなげた場合
// (3, 4) (^1) (4, 2) (^2) (2, 5) (^3) (5, 7)
// --
// ^1, ^2, ^3 の順に計算: 44 + 2*5*7 = 114
// 2, 1, 3の順: 100 + 2*5*7 = 170 (<- 明らかに計算不要。メモ化可能)
// 1, 3, 2: 24 + 70 + 3*2*7 = 136
// 3, 1, 2: 136 (1つ上と同じ。まとめて計算可能)
// 2, 3, 1: 4*2*5 + 4*5*7 + 3*4*7 = 264
// 3, 2, 1: 2*5*7 + 4*2*7 + 3*4*7 = 210

vector<int> r(100), c(100);

int minn(int posl, int posr)
{
    static vector<vector<int>> memos(100, vector<int>(100, -1));
    int &memo = memos.at(posl).at(posr);
    if (memo >= 0)
    {
        return memo;
    }
    else if (posl == posr)
    {
        memo = 0;
    }
    else if (posl + 1 == posr)
    {
        memo = r.at(posl) * c.at(posl) * c.at(posr);
    }
    else
    {
        int ret = INT_MAX;
        for (int i = posl; i < posr; i++)
        {
            int tmp = minn(posl, i) + r.at(posl) * c.at(i) * c.at(posr) + minn(i + 1, posr);
            ret = min(ret, tmp);
        }
        memo = ret;
    }

    return memo;
}

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> r.at(i) >> c.at(i);
    }

    cout << minn(0, n - 1) << endl;

    return 0;
}