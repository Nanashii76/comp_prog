#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string S) {
    
    int size = S.length();
    for(int i = 0, j = size-1; i < (size/2); ++i, --j) {
        if(S[i] != S[j])
            return 0;
    }

    return 1;
}