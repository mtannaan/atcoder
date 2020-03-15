// Areas on the Cross-Section Diagram
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/3/ALDS1_3_D

// g++ -std=c++11 xxx.cpp && ./a.out

#include <iostream>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>

using namespace std;

struct Pool
{
    int start = -1;
    int end = -1;
    int area_d = -1;
};

void print_pool(Pool *pool, bool newline = true)
{
    if (pool)
    {
        printf(" %d->%d (%d) ", pool->start, pool->end, pool->area_d);
    }
    else
    {
        printf(" (null) ");
    }

    if (newline)
    {
        cout << endl;
    }
}

int main(void)
{
    string buf;
    cin >> buf;

    int lv = 0;
    int highest_start = -1;

    Pool *cur_pool = nullptr;
    stack<Pool *> cand_pools, pools;
    int total_area = 0;

    for (size_t i = 0; i < buf.size(); i++)
    {
        char &c = buf.at(i);
        std::cout << i << " " << c << endl;
        printf("cur pool (start):");
        print_pool(cur_pool);

        if (c == '\\')
        {
            if (cur_pool)
            {
                cand_pools.push(cur_pool);
                printf("pushed cand_pools:");
                print_pool(cur_pool);
            }
            cur_pool = new Pool();
            cur_pool->start = i;
            cur_pool->area_d = 1;
            cur_pool->end = -1;
            lv -= 1;
            puts("built new pool");
        }
        else if (c == '_')
        {
            cur_pool->area_d += 2;
        }
        else
        {
            lv += 1;
            if (cur_pool)
            {
                cur_pool->end = i + 1;
                cur_pool->area_d += 1;
                printf("area_d %d (+1)\n", cur_pool->area_d);

                // より低いpoolをmerge
                if (!pools.empty())
                {
                    Pool *last = pools.top();
                    printf("last pool:");
                    print_pool(last);
                    if (cur_pool->start < last->start)
                    {
                        cur_pool->area_d += last->area_d;
                        pools.pop();
                        total_area -= last->area_d / 2;
                        delete last;
                        printf("merged: ");
                    }
                }
                pools.push(cur_pool);
                printf("pushed pool:");
                print_pool(cur_pool);
                total_area += cur_pool->area_d / 2;
            }

            if (!cand_pools.empty())
            {
                Pool *next_cur_pool = cand_pools.top();
                cand_pools.pop();
                if (cur_pool)
                {
                    next_cur_pool->area_d += (cur_pool->end - cur_pool->start) * 2;
                    printf("tobikoe (+%d)\n", (cur_pool->end - cur_pool->start) * 2);
                }
                cur_pool = next_cur_pool;
            }
            else
            {
                cur_pool = nullptr;
                puts("deleted cur_pool");
            }
        }
        printf("cur pool (end):");
        print_pool(cur_pool);
    }

    cout << total_area << endl;
    cout << pools.size();
    while (!pools.empty())
    {
        cout << " ";
        Pool *pool = pools.top();
        cout << pool->area_d / 2;
        pools.pop();
    }
    cout << endl;

    return 0;
}