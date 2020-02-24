// hhttps://atcoder.jp/contests/apg4b/tasks/APG4b_ca
// g++ -std=c++11 ex22.cpp && ./a.out
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare_2nd(const pair<int, int> a, const pair<int, int> b)
{
    return (a.second < b.second);
}

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> int_pairs(N);
    for (pair<int, int> &this_pair : int_pairs)
    {
        int a, b;
        cin >> a >> b;
        this_pair = pair<int, int>(a, b);
    }

    sort(int_pairs.begin(), int_pairs.end(), compare_2nd);

    for (pair<int, int> &this_pair : int_pairs)
    {
        cout << this_pair.first << " " << this_pair.second << endl;
    }

    return 0;
}