#include <bits/stdc++.h>
using namespace std;


int main(){

    int n; cin >> n;
    while(n--) {
        int t; cin >> t;
        int countEven = 0, countOdd = 0;
        for(int i = 0; i < 2*t; i++) {
            int num; cin >> num;
            if(num&1)
                countOdd++;
            else
                countEven++;
        }
        cout << (countEven==countOdd?"Yes":"No") << endl;
    }

    return 0;
}