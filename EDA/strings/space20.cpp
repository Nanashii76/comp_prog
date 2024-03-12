/*
    Given an string, write a function to replace all spaces
    in a string with "%20".
*/
#include <iostream>
#include <cstring>
#include <vector>

void replace_space(char *str) {

    int spaces = 0;
    for(int i = 0; str[i] != '\0'; ++i) 
        if(str[i] == ' ')
            spaces++;

    int idx = strlen(str) + 2*spaces;
    str[idx] = '\0';

    for(int i = (int)strlen(str)-1; i>=0; --i) {
        if(str[i]==' ') {
            str[idx-1] = '0';
            str[idx-2] = '2';
            str[idx-3] = '%';
            idx-=3;
        } else {
            str[idx-1] = str[i];
            idx--; 
        }
    }

}

int main(){

    char input[1000];
    std::cin.getline(input,1000);

    replace_space(input);
    std::cout << input << std::endl;


}




