// hhttps://atcoder.jp/contests/apg4b/tasks/APG4b_ca
// g++ -std=c++11 ex22.cpp && ./a.out
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <map>
#include <bitset>

using namespace std;

int get_keta(int n, int i_keta)
{
    int denom = 1;
    for (int i = 0; i < i_keta - 1; i++)
    {
        denom *= 10;
    }

    return (n / denom) % 10;
}

int get_sum_keta(int n)
{
    int sum = 0;
    for (int i = 1; i <= 5; i++)
    {
        sum += get_keta(n, i);
    }
    return sum;
}

int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    uint64_t summed = 0;

    for (int n = 1; n <= N; n++)
    {
        int sum_keta = get_sum_keta(n);
        if (A <= sum_keta && sum_keta <= B)
        {
            summed += n;
        }
    }

    cout << summed << endl;

    return 0;
}