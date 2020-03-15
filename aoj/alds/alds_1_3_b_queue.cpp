// キュー
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/3/ALDS1_3_B

// g++ -std=c++11 xxx.cpp && ./a.out

#include <iostream>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct Process
{
    char name[10];
    int time;
};

int main(void)
{
    int n, q;
    cin >> n >> q;

    queue<Process> Q;

    for (int i = 0; i < n; i++)
    {
        Process p;
        cin >> p.name >> p.time;
        Q.push(p);
    }

    int64_t now = 0;
    while (!Q.empty())
    {
        Process p = Q.front();
        Q.pop();
        if (p.time <= q)
        {
            now += p.time;
            cout << p.name << " " << now << endl;
        }
        else
        {
            now += q;
            p.time -= q;
            Q.push(p);
        }
    }

    return 0;
}