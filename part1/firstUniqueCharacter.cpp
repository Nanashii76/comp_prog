#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {

    for(auto i : s)
        if(count(s.begin(),s.end(),i) == 1)
            return s.find(i);
    
    return -1;

}

int main() {

    string str; cin >> str;
    cout << firstUniqChar(str) << endl;
    return 0;
    
}