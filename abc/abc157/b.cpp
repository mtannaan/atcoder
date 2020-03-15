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

    int A[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> A[i][j];
        }
    }

    int N;
    cin >> N;

    set<int> B;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        B.insert(tmp);
    }

    // yoko
    for (int i = 0; i < 3; i++)
    {
        bool flag = true;
        for (int j = 0; j < 3; j++)
        {
            if (B.count(A[i][j]) == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            puts("Yes");
            return 0;
        }
    }

    // tate
    for (int i = 0; i < 3; i++)
    {
        bool flag = true;
        for (int j = 0; j < 3; j++)
        {
            if (B.count(A[j][i]) == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            puts("Yes");
            return 0;
        }
    }

    // naname1
    bool flag = true;
    for (int i = 0; i < 3; i++)
    {
        if (B.count(A[i][i]) == 0)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        puts("Yes");
        return 0;
    }

    // naname2
    flag = true;
    for (int i = 0; i < 3; i++)
    {
        if (B.count(A[i][2 - i]) == 0)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        puts("Yes");
        return 0;
    }

    puts("No");
    return 0;
}
