// hhttps://atcoder.jp/contests/apg4b/tasks/APG4b_ca
// g++ -std=c++11 ex22.cpp && ./a.out
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <cstdio>
#include <cmath>
#include <climits>

using namespace std;
#include <cstdint>
#include <iostream>

using namespace std;

// MOD (素数)
const int64_t MOD = 1000000007; // 10^9 + 7

struct Modint
{
    int64_t value;

    Modint(uint64_t value_ = 0)
    {
        value = value_ % MOD;
        value += value < 0 ? MOD : 0;
    }

    Modint operator-() const
    {
        return Modint(-value);
    }

    Modint &operator+=(const Modint n)
    {
        value += n.value;
        if (value >= MOD)
        {
            value -= MOD;
        }
        return *this;
    }
    Modint &operator-=(const Modint n)
    {
        value = value - n.value + MOD;
        if (value >= MOD)
        {
            value -= MOD;
        }
        return *this;
    }
    Modint &operator*=(const Modint n)
    {
        value = value * n.value % MOD;
        return *this;
    }
    Modint &operator/=(const Modint n)
    {
        *this *= n.inv();
        return *this;
    }

    Modint operator+(const Modint n) const
    {
        Modint ret(*this);
        ret += n;
        return ret;
    }
    Modint operator-(const Modint n) const
    {
        Modint ret(*this);
        ret -= n;
        return ret;
    }
    Modint operator*(const Modint n) const
    {
        Modint ret(*this);
        ret *= n;
        return ret;
    }
    Modint operator/(const Modint n) const
    {
        Modint ret(*this);
        ret /= n;
        return ret;
    }

    // mod MODにおける逆元を返す
    Modint inv() const
    {
        // 1 = inv(a) * a  (mod MOD) をみたすinv(a)を求める
        // フェルマーの小定理：
        //  1 = a ** (MOD - 1)  (mod MOD)
        //      (MOD: 素数, aとMODは互いに素)
        //  --> 1 = (a ** (MOD - 2)) * a  (mod MOD)
        //  --> inv(a) = a ** (MOD - 2)
        return this->pow(MOD - 2);
    }

    // expon乗した値を返す
    Modint pow(const int64_t expon) const
    {
        if (expon == 0)
        {
            return Modint(1);
        }
        Modint ret = this->pow(expon / 2);
        ret *= ret;
        if (expon % 2)
        {
            ret *= (*this);
        }
        return ret;
    }

    // 2項係数 (this, r) を返す
    // O(r)
    Modint comb(const int64_t r) const
    {
        Modint numer(1), denom(1);
        for (int64_t i = 0; i < r; i++)
        {
            numer *= value - i;
            denom *= i + 1;
        }
        return numer / denom;
    }
};

std::ostream &operator<<(std::ostream &stream, const Modint &modint)
{
    return stream << modint.value;
}

int main()
{
    int64_t n, a, b;
    cin >> n >> a >> b;

    // n種類からの花束の種類の総数
    // (0, 1) の2通りをn本なので
    // (2 ** n) - 1
    // -1は0本の花束
    Modint comb_all = Modint(2).pow(n) - 1;

    // x本からなる花束の種類の総数
    // nCx = n! / x! / (n - x)!

    // 求める種類の総数
    Modint ans = comb_all - Modint(n).comb(a) - Modint(n).comb(b);
    cout << ans << endl;

    return 0;
}