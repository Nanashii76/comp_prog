#include <bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int> encoded, int first) {

    vector<int> v;
    v.resize(static_cast<int>(encoded.size()+1));
    v[0]=first;

    for(int i = 1; i < static_cast<int>(encoded.size()+1); ++i) {
        v[i] = encoded[i-1]^v[i-1];
    }

    return v;
    
}

int main(void) {

    vector<int> ans = {1,2,3};
    for(auto x : decode(ans,1))
        cout << x;

}