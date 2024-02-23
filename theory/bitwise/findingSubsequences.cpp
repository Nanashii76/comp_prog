#include <iostream>
#include <cstring>

/*

    :Theory:
    Printing all subsequences of a string using bit-masking

    The subsequence numbers'ill be 2^n - 1
    so, we've to extract the binary number of each case
    them, match with your correspondence letter;


*/


void overLaynumber(std::string s, int n) {

    int index = 0;
    while (n != 0) {
        int last_bit = n&1;
        if(last_bit) {
            std::cout << s[index];
        }

        index++;
        n = n>>1;

    }

    std::cout << std::endl;

}

void subsequencesString(std::string s) {

    for(int i = 0; i < (1<<s.length()); ++i)
        overLaynumber(s,i);
    return;
}


int main(void) {

    std::string s;
    std::cin >> s;
    subsequencesString(s);

}