#include <iostream>
#include <unordered_map>

/*
    A dictionary is a translator from one type to another
                        (aplication of maps)
*/

std::unordered_map<char, int> dict;



int main(){

    // converting a session of chars to int; 
   dict['{'] = 1;
   dict['}'] = 2;
   dict['('] = 3;
   dict[')'] = 4;
   dict['['] = 5;
   dict[']'] = 6; 

    // we Can do the inverse operation, transforming each number
    // in a corresponding char

    for(std::unordered_map<char,int>::iterator it = dict.begin(); it != dict.end(); ++it)
        std::cout << "key: " << it->first << "\n" << "element: " << it->second << std::endl;

}