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
    int dist;
};

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
        u.dist = -1;
    }

    G.at(0).dist = 0;

    queue<int> Q;
    Q.push(1);

    while (!Q.empty())
    {
        int id = Q.front();
        Q.pop();

        Vertex &u = G.at(id - 1);

        int cand_dist = u.dist + 1;
        for (int i : u.neigh)
        {
            Vertex &v = G.at(i - 1);
            if (v.dist == -1 || v.dist > cand_dist)
            {
                v.dist = cand_dist;
                Q.push(i);
            }
        }
    }

    for (Vertex &u : G)
    {
        printf("%d %d\n", u.id, u.dist);
    }

    return 0;
}