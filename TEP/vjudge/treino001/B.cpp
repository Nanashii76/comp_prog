#include <bits/stdc++.h>
using namespace std;


int main(){

    int n,x; cin >> n >> x;
    while(n--) {
        char ch; cin >> ch;
        if(x == 0 and ch == 'x') x = 0;
        else if(ch == 'o') x++;
        else
            x--;

        //cout << x << endl;
    }

    cout <<  x << endl;

    return 0;
}