#include <bits/stdc++.h>
using namespace std;

int main() {

    int k; cin >> k;
    string s1, s2; cin >> s1 >> s2;
    
    string diff;
    if((int)s2.length() > (int)s1.length()) {
        diff = s1;
        s1 = s2;
    } else {
        diff = s2;
    }
        
    unordered_map<char,int> unmap;
    for(int i = 0; i < (int)s1.length(); ++i)
        unmap[s1[i]]++;

    int count = 0;
    for(int i = 0; i < (int)diff.length(); ++i) 
        if(unmap[diff[i]] == 0)
            count++;

    cout << (count > k ? "No" : "Yes") << endl;

}