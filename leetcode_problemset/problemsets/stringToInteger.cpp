#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {

    int ans = 0, size = s.length();

    // checking if is readable
    for(int i = 0; i < size; ++i)
        if(isalpha(s[i]) and isalpha(s[i+1]))
            return 0;

    for(int i = 0; i < size; ++i)
        if(isdigit(s[i]))
            ans = ans*10+(s[i]-'0');
    
    return s[0]==-1?-ans:ans;
}