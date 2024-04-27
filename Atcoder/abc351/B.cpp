#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    vector<vector<char>> A(n), B(n);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) {
            char x; cin >> x;
            A[i].emplace_back(x);
        }

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) {
            char x; cin >> x;
            B[i].emplace_back(x);
        }


    pair<int,int> res = {-1,-1};
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(A[i][j] != B[i][j]) {
                res = {i+1,j+1};
                break;
            }
                
    cout << res.first << " " << res.second << endl;
    return 0;

}