#include <bits/stdc++.h>
using namespace std;

int main(){

    string s; cin >> s;
    string s2 = s.substr(3,6);

    int n = stoi(s2);
    if(n >= 350 or n == 316 or n <= 0)
        return cout << "No" << endl,0;
    else
        return cout << "Yes" << endl,0;
}