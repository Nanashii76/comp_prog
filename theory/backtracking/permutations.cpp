#include <iostream>
#include <cstring>
#include <string>

void swap(char *a, char *b) {
    char tmp = *a;
    *a=*b;
    *b=tmp;
}

/*

    Given a string s, find all permutations of the string
    

*/

void permutationsString(char *n1, int l, int r) {

    int i;
    if(l == r)
        std::cout << n1 << std::endl;
    
    for(i = l; i <= r; ++i) {
        swap((n1+l), (n1+i));
        permutationsString(n1, l+1, r);
        swap((n1+l),(n1+i));
    }

}

int main(){

    char str[100];
    std::cin >> str;
    int n = strlen(str);

    permutationsString(str, 0 , n-1);


}



