#include <bits/stdc++.h>
using namespace std;

int squaredReverseSum(vector<int> vec) {

    int size = vec.size() - 1, sum;
    sum = vec[size]*vec[size];
    bool sub = true;
    for(int i = size-1; i >= 0; --i) {
        if(sub) {
            sum -= (vec[i] * vec[i]);
            sub = false;
        } else {
            sum += (vec[i] * vec[i]);
            sub = true;
        }
    }

    return sum;
}

int main(){

    int t, n; 
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> vec(n);
        for(int i = 0; i < n; ++i) 
            cin >> vec[i];
        int ans = squaredReverseSum(vec);
        cout << ans << endl;
    }

}