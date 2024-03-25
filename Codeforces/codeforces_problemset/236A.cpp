#include <bits/stdc++.h>


int main(void) {

    std::set<char> set;
    std::string s; std::cin >> s;
   
    for(int i = 0; i < (int)s.length(); ++i)
        set.emplace(s[i]);
    
    if((int)set.size()&1)
        std::cout << "IGNORE HIM!" << std::endl;
    else
        std::cout << "CHAT WITH HER!" << std::endl;

}

