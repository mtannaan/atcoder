// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

template <typename T>
void read_vector(vector<T> &vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
}

int main()
{
    vector<int> x(6);

    read_vector(x, 6);

    int right_dict[6][4] = {
        {2, 3, 5, 4},
        {6, 3, 1, 4},
        {1, 2, 6, 5},
        {1, 5, 6, 2},
        {1, 3, 6, 4},
        {2, 4, 5, 3},
    };

    int n_questions;
    cin >> n_questions;

    for (int i_q = 0; i_q < n_questions; i_q++)
    {
        int top, front;
        cin >> top >> front;

        std::vector<int>::iterator it_top = std::find(x.begin(), x.end(), top);
        int i0_top = std::distance(x.begin(), it_top);
        std::vector<int>::iterator it_front = std::find(x.begin(), x.end(), front);
        int i0_front = std::distance(x.begin(), it_front);

        int *loop = right_dict[i0_top];
        int i1_right = 999;
        for (int iright = 0; iright < 4; iright++)
        {
            if (loop[iright] == i0_front + 1)
            {
                i1_right = loop[(iright + 1) % 4];
                break;
            }
        }

        cout << x.at(i1_right - 1) << endl;
    }
    return 0;
}
