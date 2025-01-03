#include <bits/stdc++.h>
using namespace std;

int main() {

    string s; cin >> s;
    int count = 0;
    for(int i = 0; i < (int)s.length(); ++i) {
        if(s[i] != '0') count++;
        else if(s[i] == '0' and s[i+1] == '0') {
            count++;
            i++;
        }
        else count++;
    }

    cout << count << endl;

}