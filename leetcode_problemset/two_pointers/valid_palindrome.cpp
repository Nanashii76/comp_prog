#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    
    string newS1;

    for(int i = 0; i < (int)s.length(); ++i)
        if(isalpha(s[i]) or isdigit(s[i]))
            newS1.push_back(tolower(s[i]));

    for(int i = 0; i < (int)newS1.length()/2; ++i) {
        if(newS1[i] != newS1[newS1.length()-i-1])
            return false;
    }

    return true;
}

int main() {

    string input; getline(cin,input);

    if(isPalindrome(input))
        cout << "Yes" << endl;
    else   
        cout << "No" << endl;

    return 0;
}