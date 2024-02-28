#include <iostream>
#include <string>

void generateBrackets(std::string output, int n, int open, int close, int i) {

    // base case
    if(i==2*n) {
        std::cout << output << std::endl;
        return;
    }

    // open
    if(open<n) {
        generateBrackets(output + '(',n,open+1,close,i+1);
    }

    //closing
    if(close<open) {
        generateBrackets(output + ')',n,open,close+1,i+1);
    }


}



int main(){

    std::string output;
    int n;
    std::cin >> n;

    generateBrackets(output, n, 0,0,0);

}






