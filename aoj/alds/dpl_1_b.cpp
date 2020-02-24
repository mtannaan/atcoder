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

int max_v(int ntmp, int wtmp, vector<vector<int>> &dp, const vector<int> &v, const vector<int> &w)
{
    if (ntmp < 0)
    {
        return 0;
    }
    if (dp.at(ntmp).at(wtmp) >= 0)
    {
        return dp.at(ntmp).at(wtmp);
    }

    int v_chosen;
    if (wtmp < w.at(ntmp))
    {
        v_chosen = 0;
    }
    else
    {
        v_chosen = max_v(ntmp - 1, wtmp - w.at(ntmp), dp, v, w) + v.at(ntmp);
    }
    int v_unchosen = max_v(ntmp - 1, wtmp, dp, v, w);

    int ret = max(v_chosen, v_unchosen);
    dp.at(ntmp).at(wtmp) = ret;
    return ret;
}

int main()
{
    int N;
    cin >> N;
    int W;
    cin >> W;
    vector<int> v(N), w(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v.at(i) >> w.at(i);
    }

    vector<vector<int>> dp(N, vector<int>(W + 1, -1));

    cout << max_v(N - 1, W, dp, v, w) << endl;

    return 0;
}