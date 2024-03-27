#include <bits/stdc++.h>

void solve(std::string s) {

    int max = 1, count = 1;
    for(int i = 0; i < (int)s.length(); ++i) {
        
        if(count > max)
            max = count;

        if(s[i] == s[i+1])
            count++;
        else
            count = 1;
        
    }

    std::cout << max << std::endl;

}

int main(void) {

    std::string s; getline(std::cin,s);
    solve(s);

}