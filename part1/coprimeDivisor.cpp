#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {return b==0?a:gcd(b,a%b);}

int solve(int a, int b){
    
    int value = 1, x = 0;
    while(value < max(a,b)) {
        if(a%value == 0 and gcd(value,b)==1)
            x = value;
        value++;
    }
    
    return x;
}

int main(){

    int a,b; cin >> a >> b;
    cout << solve(a,b) << endl;

    return 0;
}