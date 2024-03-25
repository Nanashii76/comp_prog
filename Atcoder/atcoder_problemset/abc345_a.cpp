#include <bits/stdc++.h>

int main(void) {

    std::string s; std::cin >> s;
    std::unordered_map<char, int> unmap;

    for(int i = 0; i < (int)s.length(); ++i)
        unmap[s[i]]++;

    if(s[0] == '<' and s[s.length()-1] == '>') {
        if(unmap['<'] > 1 || unmap['>'] > 1) {
            std::cout << "No" << std::endl;
        } else
            std::cout << "Yes" << std::endl;
    } else
        std::cout << "No" << std::endl;

}

