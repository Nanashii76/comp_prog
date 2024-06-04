#include <bits/stdc++.h>
using namespace std;

/*
    find the values of x and y thats

    A * x + B * y = gcd(A,B)

    where A and B are inputs

*/
int gcd(int a, int b) {
    return b==0?a:gcd(b,a%b);
}

pair<int,int> extendedGCD(int a, int b) {

    // base case
    if(b==0) {
        // returning the values of x and y
        return {1,0};
    }

    pair<int,int> result = extendedGCD(b,a%b);
    int smallX = result.first;
    int smallY = result.second;

    int x = smallY;
    int y = smallX - floor(a/b)*smallY;

    return {x,y};

}


int main(){

    int a,b; cin >> a >> b;
    // a x + b y = gcd(a,b);
    pair<int,int> ans = extendedGCD(a,b);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}

