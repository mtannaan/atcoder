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

    int N, M, K;
    cin >> N >> M >> K;

    vector<set<int>>friends(N, set<int>());
    vector<set<int>> clusters;

    for (int m = 0; m < M; m++)
    {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        if(b < a){
            swap(a, b);
        }
        friends.at(a).insert(b);

        int64_t ca = -1, cb = -1;
        for (size_t i = 0; i < clusters.size(); i++)
        {
            set<int> &c = clusters.at(i);
            if (ca < 0 && c.count(a))
            {
                ca = i;
            }
            if (cb < 0 && c.count(b))
            {
                cb = i;
            }
            if (ca >= 0 && cb >= 0)
                break;
        }
        if (ca < 0 && cb < 0)
        {
            set<int> newc = {a, b};
            clusters.push_back(newc);
            // cout << "pushed " << a << " " << b << endl;
        }
        else if (ca < 0)
        {
            clusters.at(cb).insert(a);
            // cout << "added " << a << endl;
        }
        else if (cb < 0)
        {
            clusters.at(ca).insert(b);
            // cout << "added " << b << endl;
        }
        else if (ca != cb)
        {
            for (int ib : clusters.at(cb))
            {
                clusters.at(ca).insert(ib);
            }
            clusters.erase(clusters.begin() + cb);
        }
    }

    vector<set<int>>blocks(N, set<int>());
    for (int k = 0; k < K; k++){
        int c, d;
        cin >> c >> d;
        c -= 1;
        d -= 1;
        if(d < c){
            swap(c, d);
        }
        blocks.at(c).insert(d);
    }

    // cout << "nclusters " << clusters.size() << endl;
    // puts("cdump--------");
    /*
    for(auto &c : clusters){
        for(auto &i : c){
            cout << i << " ";
        }
    }
    cout << endl;
    */

    vector<int>ncands(N, 0);
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            //cout << "check " << i << " " << j << endl;
            if(friends.at(i).count(j) || blocks.at(i).count(j)){
                //puts("friend or block");
                continue;
            }
            for (auto &c : clusters)
            {
                if(c.count(i) && c.count(j)){
                    ncands.at(i) += 1;
                    ncands.at(j) += 1;
                    break;
                }
            }
        }
    }

    bool first = true;
    for(auto &n : ncands){
        if(first){
            first = false;
        }else{
            cout << " ";
        }
        cout << n;
    }
    cout << endl;

    return 0;
}
