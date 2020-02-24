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

struct Dice
{
    int top;
    int bottom;
    int n;
    int s;
    int w;
    int e;

    Dice(int top_, int s_, int e_, int w_, int n_, int bottom_)
    {
        top = top_;
        s = s_;
        e = e_;
        w = w_;
        n = n_;
        bottom = bottom_;
    }

    void move(char &direction)
    {
        if (direction == 'N')
        {
            roll(top, n, bottom, s);
        }
        else if (direction == 'S')
        {
            roll(top, s, bottom, n);
        }
        else if (direction == 'W')
        {
            roll(top, w, bottom, e);
        }
        else if (direction == 'E')
        {
            roll(top, e, bottom, w);
        }
    }

    void roll(int &a, int &b, int &c, int &d)
    {
        int tmp = a;
        a = d;
        d = c;
        c = b;
        b = tmp;
    }
};

int main()
{
    vector<double> x(6);

    read_vector(x, 6);

    Dice dice = Dice(x[0], x[1], x[2], x[3], x[4], x[5]);

    string moves;
    cin >> moves;

    for (int i = 0; i < moves.length(); i++)
    {
        dice.move(moves.at(i));
    }

    cout << dice.top << endl;

    return 0;
}
