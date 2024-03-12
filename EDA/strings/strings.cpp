#include <iostream>
#include <string>
#include <vector>

int main(){

    // std::string s;
    // getline(std::cin,s);

    // std::cout << s << std::endl;

    // for(char ch : s)
    //     std::cout << ch << ",";

    // std::cout << std::endl;

    // int n = 5;
    // std::vector<std::string> arr;

    // while(n--) {
    //     std::string tmp;
    //     getline(std::cin,tmp);
    //     arr.push_back(tmp);
    // }

    // for(auto names : arr)
    //     std::cout << names << " ";

    // std::cout << std::endl;


    // Find Function
    std::string paragraph = "We are learning about STL strings. STL string class is quite powerfull";

    std::string word;
    getline(std::cin,word);

    int index = paragraph.find(word);
    if(index == -1)
        std::cout << "Not found" << std::endl;
    else
        std::cout << word << std::endl;

    // Finding more than 1 occurency of a string
    for(int i = 1; index != -1; ++i) {
        std::cout << i <<" occ at: " << index << std::endl;
        index = paragraph.find(word,index+1);
    }


}