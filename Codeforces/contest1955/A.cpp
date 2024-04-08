#include <bits/stdc++.h>
using namespace std;

int solve(int n, int a, int b){

    if(n & 1) 
        return min(n*a,(((n/2)*b)+a));
    else
        return min(n*a,(n*b)/2);

}

int main(){

    int t; cin >> t;
    while(t--) {
        int n,a,b; cin >> n >> a >> b;
        cout << solve(n,a,b) << endl;
    }

    return 0;
}