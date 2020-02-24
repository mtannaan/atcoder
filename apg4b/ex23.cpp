// hhttps://atcoder.jp/contests/apg4b/tasks/APG4b_ca
// g++ -std=c++11 ex22.cpp && ./a.out
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    map<int, int> counts;
    for (int i = 0; i < N; i++)
    {
        int A_i;
        cin >> A_i;
        if (counts.count(A_i))
        {
            counts.at(A_i)++;
        }
        else
        {
            counts[A_i] = 1;
        }
    }

    pair<int, int> max_elm = pair<int, int>(-1, -1);
    for (const pair<int, int> &this_elm : counts)
    {
        if (max_elm.second < this_elm.second)
        {
            max_elm = this_elm;
        }
    }

    cout << max_elm.first << " " << max_elm.second << endl;

    return 0;
}