/*
Write a C++ program to change every letter in a given string with the letter following it in the alphabet (i.e. a becomes b, p becomes q, z becomes a).
Example:
Sample Input: w3resource
Sample Output: x3sftpvsdf

*/
#include <iostream>
#include <vector>
#include <string>

std::string changeLetter(std::string s) {

    int char_code; // variable stogin ascii values

    for(int i = 0; i < (int)s.length(); ++i) {

        char_code = int(s[i]);

        // checking if the element is z, to change to a
        if(char_code == 122)
            s[i] = char(97);
        else if(char_code == 90) // checking if it Z, to change to A
            s[i] = char(65);
        else
            s[i] = char(char_code+1);

    }

    return s;

}


int main(){

    std::string s1;
    getline(std::cin,s1);

    std::cout << "Word before: " << s1 << std::endl;
    std::cout << "Word after: " <<changeLetter(s1) << std::endl;


}

