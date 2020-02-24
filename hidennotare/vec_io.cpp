
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void write_vec(const vector<T> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v.at(i);
        if (i < v.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

template <typename T>
void read_vec(vector<T> &v)
{
    for (T &elm : v)
    {
        cin >> elm;
    }
}
