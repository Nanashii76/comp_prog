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


void substringsBit(std::string s1, int i) {

    int index = 0;
    while(i != 0) {
        int last_bit=i&1;
        if(last_bit)
            std::cout << s1[index];
        index++;
        i = 1>>1;
    }

    std::cout << std::endl;

}

void generateSubstring(std::string s1) {

    for(int i = 0; i < (1<<s1.length());++i)
        substringsBit(s1, i);
    return;

}




int main(){

    char s[100], output[100];

    std::cin >> s;
    findSubsets(s,output,0,0);

}



