// 最大公約数
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_B

// g++ -std=c++11 xxx.cpp && ./a.out

#include <iostream>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <vector>

using namespace std;

template <typename T>
void write_vec(const vector<T> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v.at(i);
        if (i < v.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

template <typename T>
void read_vec(vector<T> &v)
{
    for (T &elm : v)
    {
        cin >> elm;
    }
}

int gcd(int x, int y)
{
    if (x < y)
    {
        swap(x, y);
    }
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}

int main(void)
{
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y) << endl;

    return 0;
}