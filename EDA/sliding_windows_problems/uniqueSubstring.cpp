/*
    Given a string, write a function to find the lasrgest
    substring with unique characters (no duplicates)

    input
    prateekbhaiya
    aabcb

    output
    ekhbhaiy
    abc
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>

std::string unique_substring(std::string str) {

    int i, j, cout;
    i = j = cout = 0;

    int max_window = 0;
    int start_window = -1;

    std::unordered_map<char,int> map;

    while(j < (int)str.length()) {

        // current character
        char ch = str[j];

        // if it is inside hashmap and index >=  start of the
        // current window (i);
        if(map.count(ch) and map[ch]>=i) {
            // starting new window
            i = map[ch]+1;
            cout=j-i; // updated remaining windows len exlucing current char
        }

        // update the last occurrency
        map[ch] = j;
        cout++;
        j++;

        //update max_window_len every step
        if(cout > max_window) {
            max_window = cout;
            start_window = i;
        }


    }

    return str.substr(start_window,max_window);

}

int main(void) {

    std::string input;
    std::cin >> input;

    std::cout << unique_substring(input) << std::endl;


}



