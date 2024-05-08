#include <bits/stdc++.h>
using namespace std;


int main(){

    int n; cin >>n;
    while(n--) {
        int t; cin >> t;
        if(t%3) {
            if(t/3+2*((t/3)+1) == t)
                cout << t/3 << " " << t/3+1 << endl;
            else
                cout << t/3+1 << " " << t/3 << endl;    
        } else
            cout << t/3 << " " << t/3 << endl;
    }

    return 0;


}