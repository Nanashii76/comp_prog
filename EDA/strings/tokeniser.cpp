/*
    Creating my own function to get tokens from a string
*/
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>

char *mystrtok(char *str, char delim) {

    static char *input = NULL;
    if(str!=NULL)
        input = str;
    if(input == NULL)
        return NULL;

    char *token = new char[strlen(input)+1];
    int i = 0;

    for(; input[i]!='\0';++i) {
        if(input[i]!=delim)
            token[i]=input[i];
        else {
        token[i] = NULL;
        input = input+i+1;
        }
    } 

    // out of the loop
    token[i] = '\0';

    // resete the input as NULL
    input = NULL;
    return token;

}