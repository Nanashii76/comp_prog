#include <bits/stdc++.h>
using namespace std;

int main(){

    int sumA = 0, sumB = 0;
    for(int i = 0; i < 9; ++i) {
        int t; cin >> t;
        sumA += t;
    }

    for(int i = 0; i < 8; ++i) {
        int t; cin >> t;
        sumB += t;
    }

    if(sumA==sumB)
        cout << 1 << endl;
    else
        cout << abs(sumA-sumB)+1 << endl;
}