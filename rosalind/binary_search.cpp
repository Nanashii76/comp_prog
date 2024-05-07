#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> values, int x){

    int l = 0;
    int r = values.size()-1;

    while(l <= r) {
        int mid = (l+r)/2;

        if(values[mid] == x)
            return mid;
        else if(x < values[mid])
            r = mid-1;
        else
            l = mid+1;
    }

    return -1;

}


int main() {

    int n,m; cin >> n >> m;
    vector<int> values(n);
    for(int i = 0; i < n; ++i)
        cin >> values[i];

    while(m--) {
        int aux; cin >> aux;
        cout << (binary_search(values,aux)!=-1?binary_search(values,aux)+1:-1) << " ";
    }
    cout << endl;
    return 0;

}