#include <iostream>
#include <cstring>
#include <string>


void subsets(char *input, char *output, int i, int j) {

    // base condition, when input reaches '\0'
    if(input[i] == '\0') {
        output[j] = '\0';
        std::cout << output << std::endl;
        return;
    }

    // recursions calls
    // when we gets a letter from input
    output[j] = input[i];
    subsets(input,output,i+1,j+1);

    // when we dont get a letter from input
    output[j] = '\0';
    subsets(input,output,i+1,j);

}


int main(void) {

    char input[1000], output[1000];
    std::cin.getline(input,1000);

    subsets(input,output,0,0);

}






