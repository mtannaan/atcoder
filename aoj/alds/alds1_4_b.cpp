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

bool my_bs(int t, const vector<int> &S, int imin, int imax)
{
    // printf("t=%d imin=%d imax=%d\n", t, imin, imax);

    if (imin > imax)
    {
        return false;
    }

    int imid = (imax + imin) / 2;
    int smid = S.at(imid);
    if (t == smid)
    {
        //printf("hit %d\n", t);
        return true;
    }
    else if (t > smid)
    {
        return my_bs(t, S, imid + 1, imax);
    }
    else
    {
        return my_bs(t, S, imin, imid - 1);
    }
}

int main()
{
    int n, q;
    cin >> n;
    vector<int> S(n);
    for (int &s_i : S)
    {
        cin >> s_i;
    }

    cin >> q;
    vector<int> T(q);
    for (int &t_i : T)
    {
        cin >> t_i;
    }

    int count = 0;
    for (int t_i : T)
    {
        count += my_bs(t_i, S, 0, S.size());
    }

    cout << count << endl;

    return 0;
}