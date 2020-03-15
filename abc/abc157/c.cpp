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

    int N, M;
    cin >> N >> M;

    int s[M], c[M];
    for (int i = 0; i < M; i++)
    {
        cin >> s[i] >> c[i];
    }

    for (int i = 0; i < 1000; i++)
    {
        if (int(log10(i)) == N - 1 || (N == 1 && i == 0))
        {
            for (int m = 0; m < M; m++)
            {
                // 右からsrightけた目。0始まり
                int sright = N - s[m];
                int keta = (i / int(pow(10, sright))) % 10;
                if (keta != c[m])
                {
                    goto endloop;
                }
            }
            cout << i << endl;
            return 0;
        }

    endloop:
        continue;
    }

    puts("-1");
    return 0;
}
