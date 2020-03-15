#include <iostream>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

struct Tree
{
    Tree *parent;
};

Tree *get_root(Tree *tree)
{
    if (!(tree->parent))
    {
        return tree;
    }
    else
    {
        return get_root(tree->parent);
    }
}

int main(void)
{

    int N, M, K;
    cin >> N >> M >> K;

    vector<set<int>> friends(N, set<int>());
    vector<Tree *> roots(N, nullptr);

    Tree *t;
    for (int m = 0; m < M; m++)
    {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        if (b < a)
        {
            swap(a, b);
        }
        friends.at(a).insert(b);

        t = new Tree();
        t->parent = nullptr;
        if (roots.at(a))
        {
            get_root(roots.at(a))->parent = t;
        }
        if (roots.at(b))
        {
            Tree *rb = get_root(roots.at(b));
            if (rb != t)
            {
                rb->parent = t;
            }
        }
        roots.at(a) = t;
        roots.at(b) = t;
    }

    vector<set<int>> blocks(N, set<int>());
    for (int k = 0; k < K; k++)
    {
        int c, d;
        cin >> c >> d;
        c -= 1;
        d -= 1;
        if (d < c)
        {
            swap(c, d);
        }
        blocks.at(c).insert(d);
    }

    // cout << "nclusters " << clusters.size() << endl;
    // puts("cdump--------");
    /*
    for(auto &c : clusters){
        for(auto &i : c){
            cout << i << " ";
        }
    }
    cout << endl;
    */

    vector<int> ncands(N, 0);
    for (int i = 0; i < N; i++)
    {
        Tree *ri = get_root(roots.at(i));
        for (int j = i + 1; j < N; j++)
        {
            //cout << "check " << i << " " << j << endl;
            if (friends.at(i).count(j) || blocks.at(i).count(j))
            {
                //puts("friend or block");
                continue;
            }
            if (!roots.at(i) || !roots.at(j))
            {
                continue;
            }

            //printf("finding root: %d, %d\n", i, j);
            //printf("%p, %p\n", roots.at(i), roots.at(j));
            Tree *rj = get_root(roots.at(j));
            if (ri == rj)
            {
                ncands.at(i) += 1;
                ncands.at(j) += 1;
            }
        }
    }

    bool first = true;
    for (auto &n : ncands)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            cout << " ";
        }
        cout << n;
    }
    cout << endl;

    return 0;
}
