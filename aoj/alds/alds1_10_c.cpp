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

int main()
{
    int q;
    cin >> q;
    for (int iq = 0; iq < q; iq++)
    {
        string a, b;
        cin >> a;
        cin >> b;
        int dp[a.size()][b.size()];
        int a_matched[a.size()][b.size()];
        bool b_matched[a.size()][b.size()];
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                int tmpa = (i > 0) ? dp[i - 1][j] : 0;
                int tmpb = (j > 0) ? dp[i][j - 1] : 0;
                int bef = (i > 0 && j > 0) ? dp[i - 1][j - 1] : 0;
                int tmpc = (a.at(i) == b.at(j)) ? bef + 1 : 0;
                dp[i][j] = max(max(tmpa, tmpb), tmpc);
            }
        }

        cout << dp[a.size() - 1][b.size() - 1] << endl;
    }

    return 0;
}