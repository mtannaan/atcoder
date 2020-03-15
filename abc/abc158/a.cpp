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

    char S1, S2, S3;
    cin >> S1 >> S2 >> S3;

    bool res = ((S1 != S2) || (S2 != S3) || (S3 != S1));
    cout << (res ? "Yes" : "No") << endl;

    return 0;
}
