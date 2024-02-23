#include <iostream>
#include <string>
#include <algorithm>

char digitToChar(int n) {
    return n + '0';
}

int charToDigit(char n) {
    return n - '0';
}


std::string addNumbers(std::string n1, std::string n2) {

    // N2 has to be the larger
    if (n1.length() > n2.length())
        std::swap(n1,n2);
    
    // Result
    std::string result = "";

    // Reversing Numbers
    std::reverse(n1.begin(),n1.end());
    std::reverse(n2.begin(),n2.end());

    // Add digt upto a n1.lenght()
    int carry = 0;

    for(int i = 0; i < n1.length(); ++i) {
        int d1 = charToDigit(n1[i]);
        int d2 = charToDigit(n2[i]);
        int sum = d1+d2+carry;
        carry = sum/10;

        result.push_back(digitToChar(sum%10));

    }

    for(int i = n1.length(); i < n2.length(); ++i) {
        int d2 = charToDigit(n2[i]);
        int sum = d2 + carry;
        carry = sum/10;

        result.push_back(digitToChar(sum%10));

    }

    // If has a carry
    if(carry)
        result.push_back('1');

    std::reverse(result.begin(),result.end());

    return result;

}


int main(void) {

    // Reading the bit integers as a string
    std::string s1,s2;
    std::cin >> s1 >> s2;

    std::cout << addNumbers(s1,s2) << std::endl;

}






