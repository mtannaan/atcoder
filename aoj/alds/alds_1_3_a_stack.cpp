// スタック
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/3/ALDS1_3_A

// g++ -std=c++11 xxx.cpp && ./a.out

#include <iostream>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

int main(void)
{
    stack<int> S;
    string line;
    getline(cin, line);

    size_t cur = 0;
    while (cur < line.size())
    {
        if (line.at(cur) == '+')
        {
            int b = S.top();
            S.pop();
            int a = S.top();
            S.pop();
            S.push(a + b);
            cur += 2;
        }
        else if (line.at(cur) == '-')
        {
            int b = S.top();
            S.pop();
            int a = S.top();
            S.pop();
            S.push(a - b);
            cur += 2;
        }
        else if (line.at(cur) == '*')
        {
            int b = S.top();
            S.pop();
            int a = S.top();
            S.pop();
            S.push(a * b);
            cur += 2;
        }
        else
        {
            size_t sep_pos;
            int a = stoi(line.substr(cur), &sep_pos);
            S.push(a);
            cur += sep_pos + 1;
        }
    }

    cout << S.top() << endl;

    return 0;
}