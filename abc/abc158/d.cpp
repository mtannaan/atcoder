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

    string S;
    getline(cin, S);

    int64_t Q;
    cin >> Q;

    bool rev = false;
    char cfront[200001], cback[200001];
    int64_t lfront=0, lback=0;
    for(int64_t i=0; i<Q; i++){
        int64_t T;
        cin >> T;
        if(T == 1){
            rev = !rev;
            continue;
        }
        int64_t F;
        char C;
        cin >> F;
        cin >> C;
        if(F == 1 && !rev){
            cfront[lfront] = C;
            lfront += 1;
        }else if(F == 1){
            cback[lback] = C;
            lback += 1;
        }else if(F==2 && !rev){
            cback[lback] = C;
            lback += 1;
        }else{
            cfront[lfront] = C;
            lfront += 1;
        }
    }

    if(!rev){
        for(int64_t i=lfront - 1; i>=0; i--){
            printf("%c", cfront[i]);
        }
        cout << S;
        for(int64_t i=0; i<lback; i++){
            printf("%c", cback[i]);
        }
    }else{
        for(int64_t i=lback - 1; i>=0; i--){
            printf("%c", cback[i]);
        }
        size_t slen = S.size();
        const char *sc = S.c_str();
        for(int64_t i=slen - 1; i>=0; i--){
            printf("%c", *(sc + i));
        }
        for(int64_t i=0; i<lfront; i++){
            printf("%c", cfront[i]);
        }
    }

    cout << endl;

    return 0;
}
