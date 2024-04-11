#include <bits/stdc++.h>
using namespace std;

int main(){

    int x; cin >> x;
    int total = x, i = 1;
    while(total%360 != 0) {
        i++;
        total+=x;
    }
    cout << i << endl;
}