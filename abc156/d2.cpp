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

int64_t modpow(const int64_t base, const int64_t expon, const int64_t mod)
{
    // 二分累乗法。O(log(expon))
    int64_t tmp_base = base;
    int64_t tmp_exp = expon;
    int64_t ret = 1;
    while (tmp_exp > 0)
    {
        if (tmp_exp % 2)
        {
            ret = (ret * tmp_base) % mod;
        }
        tmp_base = (tmp_base * tmp_base) % mod;
        tmp_exp /= 2;
    }
    return ret;
}

struct ExtGCDResult
{
    int64_t x;
    int64_t y;
    int64_t gcd;
};

ExtGCDResult ext_gcd(const int64_t a, const int64_t b)
{
    // a * x + b * y = gcd(a, b) を満たすx, yと、gcd(a, b)を求める
    // 下記を参考に拡張ユークリッドの互除法を用いる。
    // https://qiita.com/drken/items/b97ff231e43bce50199a#3-4-%E6%8B%A1%E5%BC%B5%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95%E3%81%AE%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E7%9A%84%E8%A8%98%E8%BF%B0
    // 理解のために可読性重視で書き直したので記事より遅いかも
    // ざっくりO(log(a))
    if (b == 0)
    {
        ExtGCDResult ret = {.x = 1, .y = 0, .gcd = a};
        return ret;
    }
    ExtGCDResult child_res = ext_gcd(b, a % b);
    ExtGCDResult ret = {
        .x = child_res.y,
        .y = child_res.x - (a / b) * child_res.y,
        .gcd = child_res.gcd};
    return ret;
}

int64_t modinv(const int64_t n, const int64_t mod)
{
    // find ret where
    //      n * ret = 1 (mod `mod`)
    // i.e. find ret and y where
    //      n * ret + mod * y = 1
    // nとmodは互いに素である前提

    ExtGCDResult gcdres = ext_gcd(n, mod);
    if (gcdres.gcd != 1)
    {
        cerr << "modinv: not coprime: " << n << ", " << mod << endl;
    }

    return gcdres.x + (gcdres.x < 0 ? mod : 0);
}

#define MODNCR_MAXN 510000
int64_t modncr(const int64_t n, const int64_t r, const int64_t mod)
{
    if (r >= MODNCR_MAXN)
    {
        cerr << "r (" << r << ") exceed MODNCR_MAXN" << endl;
    }

    static int64_t lastmod = -1;
    static vector<int64_t> fac(MODNCR_MAXN, -1), facinv(MODNCR_MAXN, -1), inv(MODNCR_MAXN, -1);
    if (mod != lastmod)
    {
        lastmod = mod;
        fac.at(0) = fac.at(1) = 1;
        facinv.at(0) = facinv.at(1) = 1;
        inv.at(1) = 1;
        for (int i = 2; i < MODNCR_MAXN; i++)
        {
            fac.at(i) = fac.at(i - 1) * i % mod;
            // https://drken1215.hatenablog.com/entry/2018/06/08/210000
            // mod = q * i + r, where q = mod // i and r = mod % i
            // q * i + r = 0  (mod `mod`)
            // q + r * inv[i] = 0  (mod `mod`)
            // inv[i] = -q * inv[r]
            //        = - (mod // i) * inv[mod % i]
            inv.at(i) = mod - inv.at(mod % i) * (mod / i) % mod;
            facinv.at(i) = facinv.at(i - 1) * inv.at(i) % mod;
        }
    }
    if (n < r || n < 0 || r < 0)
    {
        return 0;
    }
    int64_t ret;
    if (n < MODNCR_MAXN)
    {
        ret = fac.at(n) * facinv.at(r) % mod;
        ret = ret * facinv.at(n - r) % mod;
    }
    else
    {
        ret = 1;
        for (int64_t i = n; i >= n - r + 1; i--)
        {
            ret = ret * i % mod;
        }
        ret = ret * facinv.at(r) % mod;
    }

    return ret;
}

int main()
{
    int64_t n, a, b;
    cin >> n >> a >> b;

    const int64_t MOD = 1000000007;

    // n種類からの花束の種類の総数
    // (0, 1) の2通りをn本なので
    // (2 ** n) - 1
    // -1は0本の花束
    int64_t comb_all = modpow(2, n, MOD) - 1;

    // x本からなる花束の種類の総数
    // nCx = n! / x! / (n - x)!
    int64_t comb_a = modncr(n, a, MOD);
    int64_t comb_b = modncr(n, b, MOD);

    // 求める種類の総数
    int64_t ans = (comb_all - comb_a - comb_b) % MOD;
    cout << ans + (ans < 0 ? MOD : 0) << endl;

    return 0;
}