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
    int N, P;
    cin >> N >> P;

    int ibuf = 0;  // 一番下のケタ

    int carry[N + 1];
    int ncarry = 0;
    int64_t ret = 0;
    for(int i=0; i<N; i++){
        char c;
        cin >> c;

        for(int icarry = 0; icarry < ncarry; icarry++){
            if(carry[icarry] < 0){
                continue;
            }
            int tmp = (carry[icarry] * 10 + c - '0');
            int iamari = tmp % P;
            if(iamari == 0){
                ret += 1;
                //*d*/ printf("i=%d icarry=%d ncarry=%d tmp=%d ret=%lld\n", i, icarry, ncarry, tmp, ret);
            }
            carry[icarry] = iamari;
        }

        int amari = (c - '0') % P;
        if(amari == 0){
            ret += 1;
            //*d*/ printf("amari0 ret=%lld\n", ret);
        }
        carry[ncarry] = amari;
        ncarry += 1;

        ibuf = (ibuf == 3) ? 0 : ibuf + 1;
    }
    
    cout << ret << endl;

    return 0;
}
