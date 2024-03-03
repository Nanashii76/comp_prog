#include <iostream>
#include <string>



/*
    Question 1:

    skip a caracter in string

    intput: baccad, a
    output: bccd

*/
void jump_char(char *input, char *output, char a, int i, int j) {

    if(input[i] == '\0') {
        output[j] = '\0';
        return;
    }

    if(input[i] == a) 
        jump_char(input,output,a,i+1,j);
    else {
        output[j] = input[i];
        jump_char(input,output,a,i+1,j+1);
    }
        
}


int main(){

    char input[100], output[100];
    char a;
    std::cin >> input >> a;
    jump_char(input,output,a,0,0);

    std::cout << output << std::endl;


}


