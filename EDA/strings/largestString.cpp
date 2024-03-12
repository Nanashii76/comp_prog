/*
    Write a C++ program to find the largest word in a given string.
    Example:
    Sample Input: C++ is a general-purpose programming language.
    Sample Output: programming

*/
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>


std::vector<std::string> words(std::string s1) {

    std::vector<std::string> ans;
    std::stringstream ss(s1);
    std::string token;
    while(getline(ss,token,' ')) {
        ans.push_back(token);
    }

    return ans;

}


std::string bigString(std::vector<std::string> vec) {

    std::string bigger = "";
    int comp = 0;
    for(int i = 0; i < (int)vec.size(); ++i) {
        int n = vec[i].length();
        if(n > comp) {
            bigger = vec[i];
            comp = (int)vec[i].length();
        }
    }

    return bigger;

}


int main(){
    
    std::string p;
    getline(std::cin, p);

    std::vector<std::string> res = words(p);
    std::cout << bigString(res) << std::endl;

}




