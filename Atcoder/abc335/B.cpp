#include <bits/stdc++.h>
using namespace std;

int main(){

    int a,b,c,n;
    cin >> n;
    
    for(a = 0; a <= n; ++a)
        cout << 0 << " " << 0 << " " << a << endl;
    
    for(a = 0, b = 1; b <= n; ++a) {
        cout << 0 << " " << b << " " << a << endl;
        if(a+b >= n){
            b++;
            a=-1;
        }
    }

    for(a = 0, b = 0, c = 1; c <= n; ++a) {
        cout << c << " " << b << " " << a << endl;
        if(c+b>=n){
            c++;
            a=-1;
            b=0;
        }
        if(a+b+c>=n){
            b++;
            a=-1;
            }
        }

}