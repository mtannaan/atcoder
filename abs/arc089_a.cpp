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

bool can_move(const tuple<int, int, int> &cur, const tuple<int, int, int> &next)
{
    int t0, t1, x0, x1, y0, y1;
    tie(t0, x0, y0) = cur;
    tie(t1, x1, y1) = next;

    int time = t1 - t0;
    int dist = abs(x0 - x1) + abs(y0 - y1);
    if (dist > time)
    {
        return false;
    }
    if ((dist - time) % 2)
    {
        return false;
    }
    return true;
}

int main()
{
    int N;
    cin >> N;

    tuple<int, int, int> cur = make_tuple(0, 0, 0);
    vector<tuple<int, int, int>> txys(N);
    for (tuple<int, int, int> &txy : txys)
    {
        int t, x, y;
        cin >> t >> x >> y;
        txy = make_tuple(t, x, y);
    }

    for (const tuple<int, int, int> &txy : txys)
    {
        if (can_move(cur, txy))
        {
            cur = txy;
        }
        else
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}