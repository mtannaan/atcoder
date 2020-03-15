// バブルソート
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/2/ALDS1_2_A

// g++ -std=c++11 xxx.cpp && ./a.out

#include <iostream>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <vector>

using namespace std;

template <typename T>
void read_vec(vector<T> &v)
{
    for (T &elm : v)
    {
        cin >> elm;
    }
}

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
int main(void)
{
    int N;
    cin >> N;

    vector<int> A(N);
    read_vec(A);

    bool flag = true; // 逆の隣接要素が存在する
    int n_swaps = 0;
    while (flag)
    {
        flag = false;
        for (int j = N - 1; j >= 1; j--)
        {
            if (A.at(j) < A.at(j - 1))
            {
                swap(A.at(j), A.at(j - 1));
                flag = 1;
                n_swaps += 1;
            }
        }
    }

    write_vec(A);
    cout << n_swaps << endl;

    return 0;
}