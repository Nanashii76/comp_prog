#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>

std::string unique_string(std::string str) {

    int i, j, cout;
    i = j = cout = 0;

    int start_window = -1;
    int max_windows = 0;

    std::unordered_map<char,int> ocurrency;

    while (j < (int)str.length()){
        // current char
        char ch = str[j];

        // find a ocurrency of repettion
        if(ocurrency.count(ch) && ocurrency[ch]>=i) {
            i=ocurrency[ch]+1;
            cout = j-i; // j-i because we exclude the nex ocurrency of j
        }

        // Creating the case of ocurrency in hashmap
        ocurrency[ch] = j;
        j++;
        cout++;

        if(cout > max_windows) {
            max_windows = cout;
            start_window = i;
        }
    }

    return str.substr(start_window,max_windows);

}



int main(void) {

    std::string input;
    getline(std::cin,input);

    std::cout << unique_string(input) << std::endl;

}

