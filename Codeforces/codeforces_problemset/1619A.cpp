#include <bits/stdc++.h>
using namespace std;

int checkSquareStr(string str) {

    string str1 = "", str2 = "";
    int size = str.length();
    for(int i = 0; i < size; ++i) {
        if(i < size/2)
            str1.push_back(str[i]);
        else
            str2.push_back(str[i]);
    }

    return str1 == str2;

}

int main() {

    int n; cin >> n;
    while(n--) {
        string str; cin >> str;
        cout << (checkSquareStr(str) ? "Yes" : "No") << endl;
    }

}