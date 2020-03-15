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

    int A, B;
    cin >> A >> B;

    int xmin = int(ceil(max(A / 0.08, B / 0.1)));
    double xmax = min((A + 1) / 0.08, (B + 1) / 0.1);

    int ret;
    if(xmin < xmax){
        ret = xmin;
    }else{
        ret = -1;
    }

    cout << ret << endl;

    return 0;
}
