// 1490 - D. Permutation Transformation

#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> unmap;

void getRootSubArray(int l, int r, vector<int> vals, int depth) {

    if(l > r) return;

    int maxVal = l;
    for(int i = l; i <= r; ++i)
        if(vals[i] > vals[maxVal]) maxVal = i; 

    unmap[vals[maxVal]] = depth;

    getRootSubArray(l, maxVal - 1, vals, depth+1);
    getRootSubArray(maxVal + 1, r, vals, depth+1);

}


int main(){

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> vals(n);
        for(int i = 0; i < n; ++i)
            cin >> vals[i];

        getRootSubArray(0, n - 1, vals, 0);
        for(int i = 0; i < n; ++i)
            cout << unmap[vals[i]] << " ";
        cout << endl;

        unmap.clear();
    }

    return EXIT_SUCCESS;

}