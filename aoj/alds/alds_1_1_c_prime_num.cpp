// 素数
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C

// g++ -std=c++11 xxx.cpp && ./a.out

#include <iostream>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int n_prime = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 2)
        {
            n_prime += 1;
            continue;
        }
        if (x == 1 || x % 2 == 0)
            continue;
        bool is_prime = true;
        for (int p = 3; p <= sqrt(x); p += 2)
        {
            if (x % p == 0)
            {
                is_prime = false;
            }
        }
        n_prime += is_prime;
    }

    cout << n_prime << endl;

    return 0;
}