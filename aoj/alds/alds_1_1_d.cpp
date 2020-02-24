// 最大の利益
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_D

// g++ -std=c++11 xxx.cpp && ./a.out

#include <iostream>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

template <typename T>
void read_vec(vector<T> &v)
{
    for (T &elm : v)
    {
        cin >> elm;
    }
}

int main(void)
{
    int n;
    cin >> n;

    vector<int> R(n);
    read_vec(R);

    int vmax = INT_MIN;
    int rmin = INT_MAX;
    for (int r : R)
    {
        vmax = max(vmax, r - rmin);
        rmin = min(rmin, r);
    }

    cout << vmax << endl;

    return 0;
}