#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

string base_repr(ull N, int base) {

    if(N == 0) return "0";
    string res = "";
    while (N) {
        res += char('0' + N % base);
        N /= base;
    }
    reverse(res.begin(),res.end());
    return res;

}

int charToDigit(int ch) {
    return ch-'0';
}


int main(){

    ull n; cin >> n;
    n--;
    string ans = base_repr(n,5);

    for(int i = 0; i < (int)ans.length(); ++i) {
        cout << charToDigit(ans[i])*2;
    }
    cout << endl;

    return 0;

}