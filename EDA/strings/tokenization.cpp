/*
    Tokenization a string denotes splitting a string with 
    respect to some delimiter(s).


    input
    "Today is sunny day"

    output
    "Today","is","sunny","day"
*/
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>

int main(){


    // 1. Using stringstream class
    std::string input;
    getline(std::cin,input);

    // Create a string stream object
    std::stringstream ss(input);

    // >> and << operators
    std::string token;
    std::vector<std::string> tokens;
    while(getline(ss,token,' ')) {
        tokens.push_back(token);
    }

    // printing the resul
    for(auto string : tokens)
        std::cout << "'" << string << "'" << ",";
    
    std::cout << std::endl;



    // 2. Using strtok -> from cstring
    char string[1000];
    std::cin.getline(string,1000);


    // strtok()
    // Internally maintains the state of the string passed in the last
    // fuction
    char *tok = strtok(string," ");

    while(tok!=NULL) {
        std::cout << tok << std::endl;
        tok = strtok(NULL," ");
    }


}