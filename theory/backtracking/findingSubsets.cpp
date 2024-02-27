#include <iostream>

void findSubsets(char *input, char *output, int i, int j) {

    //base case
    if(input[i] == '\0') {
        output[j] = '\0';
        if(output[0]=='\0')
            std::cout << "NULL";
        std::cout << output << std::endl;
        return;
    }

    //rec case
    //include the ith letter
    output[j] = input[i];
    findSubsets(input, output, i+1, j+1);

    //exclude the ith letter
    output[j] = '\0';
    findSubsets(input,output,i+1,j);

}




int main(){

    char s[100], output[100];

    std::cin >> s;
    findSubsets(s,output,0,0);

}



