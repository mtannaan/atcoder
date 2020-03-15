#include <iostream>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

int main(void)
{

    uint64_t N, A, B;
    cin >> N >> A >> B;

    uint64_t AB = A + B;

    uint64_t wari = (N / AB) * A;

    uint64_t amari = N % AB;
    amari = min(amari, A);

    cout << wari + amari << endl;

    return 0;
}
