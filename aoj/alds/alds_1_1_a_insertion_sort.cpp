// 挿入ソート
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_A

// g++ -std=c++11 xxx.cpp && ./a.out

#include <iostream>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <vector>

using namespace std;

template <typename T>
void print_vec(const vector<T> &v)
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
    for (int &a : A)
    {
        cin >> a;
    }

    print_vec(A);

    for (int i = 1; i < N; i++)
    {
        int v = A.at(i);
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (A.at(j) <= v)
            {
                break;
            }
            A.at(j + 1) = A.at(j);
        }
        A.at(j + 1) = v;
        print_vec(A);
    }

    return 0;
}