// シェルソート
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/2/ALDS1_2_D

// g++ -std=c++11 xxx.cpp && ./a.out

// ひとまずGの要素を2^kで試してみてACしたが、
// https://en.wikipedia.org/wiki/Shellsort#Gap_sequences
// によると良い例ではない様子。
// とにかく1が入っていれば最後は通常の挿入ソートになり正答が得られるが、
// (3^k - 1) / 2など、（経験的に？) 速くなる選び方がある

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

int cnt;

void insertionSort(vector<int> &A, int n, int g)
{
    for (int i = g; i < n; i++)
    {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v)
        {
            A[j + g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j + g] = v;
    }
}

int main(void)
{
    int N;
    cin >> N;

    vector<int> A(N);
    read_vec(A);

    cnt = 0;
    int m = log2(N) + 1;
    vector<int> G(m);
    for (int i = 0; i < m; i++)
    {
        G.at(i) = 1 << (m - i - 1);
    }

    for (int i = 0; i < m; i++)
    {
        insertionSort(A, N, G[i]);
    }

    cout << m << endl;
    write_vec(G);
    cout << cnt << endl;
    for (int &a : A)
    {
        cout << a << endl;
    }

    return 0;
}