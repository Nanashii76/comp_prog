#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

    int n, t; cin >> n >> t;
    vector<int> locale(n);
    for(int i = 0; i < n-1; ++i)
        cin >> locale[i];    

    int cur = 1;
    do{
        cur += locale[cur-1];
        if(cur == t) {
            cout << "YES" << endl;
            return 0;
        }
    } while(cur < n);

    cout << "NO" << endl;
    return 0;
}