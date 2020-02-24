// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

template <typename T>
void read_vector(vector<T> &vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
}

template <typename T>
void print_vector(vector<T> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i == vec.size() - 1)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }
}

int perm_n[6] = {4, 0, 2, 3, 5, 1};
int perm_e[6] = {2, 1, 5, 0, 4, 3};

void roll(const vector<int> &orig, vector<int> &rolled, const int perm[6])
{
    for (int i = 0; i < 6; i++)
    {
        rolled[i] = orig[perm[i]];
    }
}

int is_identical_w_given_top(const vector<int> &d1, const vector<int> &d2)
{
    if ((d1[0] != d2[0]) || (d1[5] != d2[5]))
    {
        return 0;
    }
    if (
        ((d1[1] == d2[1]) && (d1[2] == d2[2]) && (d1[4] == d2[4]) && (d1[3] == d2[3])) ||
        ((d1[1] == d2[2]) && (d1[2] == d2[4]) && (d1[4] == d2[3]) && (d1[3] == d2[1])) ||
        ((d1[1] == d2[4]) && (d1[2] == d2[3]) && (d1[4] == d2[1]) && (d1[3] == d2[2])) ||
        ((d1[1] == d2[3]) && (d1[2] == d2[1]) && (d1[4] == d2[2]) && (d1[3] == d2[4])))
    {
        return 1;
    }
    return 0;
}

int is_identical(const vector<int> &d1, const vector<int> &orig_d2)
{
    vector<int> tmp(6);
    vector<int> d2(6);
    d2 = orig_d2;
    for (int i = 0; i < 4; i++)
    {
        tmp = d2;
        roll(tmp, d2, perm_n);
        if (is_identical_w_given_top(d1, d2))
        {
            return 1;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        tmp = d2;
        roll(tmp, d2, perm_e);
        if (is_identical_w_given_top(d1, d2))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;

    vector<
        vector<int>

        >
        ds(n);

    for (int i = 0; i < n; i++)
    {
        ds[i] = vector<int>(6);
        read_vector(ds[i], 6);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (is_identical(ds[i], ds[j]))
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}
