#include <bits/stdc++.h>
using namespace std;


int main(){

    string s, t; cin >> s >> t;
    for(int i = 0, j = 0; s[i] != '\0';++j) {
        if(s[i] == t[j]) {
            cout << j+1 << " ";
            i++;
        }
    }

    cout << endl;
    return 0;

}