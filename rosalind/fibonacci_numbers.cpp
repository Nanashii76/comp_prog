#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
vector<int> values(MAX,-1);

int fib(int n) {

    if(n < 2) {
        values[n] = n;
        return values[n];
    }

    if(values[n] != -1)
        return values[n];

    return values[n] = fib(n-1) + fib(n-2);

}

int main(){

    int n; cin >> n;
    cout << fib(n) << endl;

    return 0;
}