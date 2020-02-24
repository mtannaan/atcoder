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

struct Vertex
{
    int id;
    vector<int> neigh;
    int d;
    int f;
    bool visited;
};

void dfs(int u, vector<Vertex> &G, int &t)
{
    Vertex &v = G.at(u - 1);
    v.visited = true;
    v.d = t;
    t += 1;
    for (int v_i : v.neigh)
    {
        if (G.at(v_i - 1).visited)
        {
            continue;
        }
        dfs(v_i, G, t);
        t += 1;
    }
    v.f = t;
}

int main()
{
    int n;
    cin >> n;

    vector<Vertex> G(n);
    for (Vertex &u : G)
    {
        cin >> u.id;
        int k;
        cin >> k;
        u.neigh = vector<int>(k);
        for (int &vi : u.neigh)
        {
            cin >> vi;
        }
        u.visited = false;
    }

    int t = 1;
    for (int i = 1; i <= n; i++)
    {
        if (G.at(i - 1).visited)
            continue;
        dfs(i, G, t);
        t += 1;
    }

    for (Vertex &u : G)
    {
        printf("%d %d %d\n", u.id, u.d, u.f);
    }

    return 0;
}