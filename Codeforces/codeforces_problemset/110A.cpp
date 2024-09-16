#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int checkLuckyNumber(string n) {

    ull count = 0;

    for(ull i = 0; n[i] != '\0'; ++i) {
        if(n[i] == '7' || n[i] == '4')
            count++;
    }

    if(count == 7 || count == 4)
        return 1;
    else
        return 0;

}

int main(){

    string num; cin >> num;
    cout << (checkLuckyNumber(num) ? "YES" : "NO");

}