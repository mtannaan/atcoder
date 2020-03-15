// 安定なソート
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/2/ALDS1_2_C

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

struct Card
{
    char suit;
    int value;

    bool operator==(const Card &other) const
    {
        return (suit == other.suit) && (value == other.value);
    }
};

void write_cards(vector<Card> &C)
{
    for (size_t i = 0; i < C.size(); i++)
    {
        cout << C.at(i).suit << C.at(i).value;
        if (i < C.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

void write_stable(vector<Card> &C, vector<Card> &C_orig)
{
    for (size_t i = 0; i < C.size() - 1; i++)
    {
        if (C.at(i).value == C.at(i + 1).value)
        {
            int j_orig, j_orig_1;
            for (int j = 0; j < C.size(); j++)
            {
                if (C.at(i) == C_orig.at(j))
                {
                    j_orig = j;
                }
                if (C.at(i + 1) == C_orig.at(j))
                {
                    j_orig_1 = j;
                }
            }
            if (j_orig_1 < j_orig)
            {
                cout << "Not stable" << endl;
                return;
            }
        }
    }
    cout << "Stable" << endl;
}

void bubble_sort(vector<Card> &C_orig)
{
    size_t N = C_orig.size();
    vector<Card> C = C_orig;
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j >= i + 1; j--)
        {
            if (C[j].value < C[j - 1].value)
            {
                swap(C[j], C[j - 1]);
            }
        }
    }
    write_cards(C);
    write_stable(C, C_orig);
}

void selection_sort(vector<Card> &C_orig)
{
    size_t N = C_orig.size();
    vector<Card> C = C_orig;

    for (int i = 0; i < N; i++)
    {
        int minj = i;
        for (int j = i; j < N; j++)
        {
            if (C[j].value < C[minj].value)
            {
                minj = j;
            }
        }
        swap(C[i], C[minj]);
    }
    write_cards(C);
    write_stable(C, C_orig);
}

int main(void)
{
    int N;
    cin >> N;

    vector<Card> C(N);
    for (Card &c : C)
    {
        cin >> c.suit;
        cin >> c.value;
    }

    bubble_sort(C);
    selection_sort(C);

    return 0;
}