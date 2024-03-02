#include <bits/stdc++.h>
using namespace std;

typedef unsigned long ul;

bool isPalindrome(string num) {

    string num2(num.rbegin(),num.rend());

    if(num2 == num)
        return true;
    else
        return false;
}

int main(){

    string num;
    cin >> num;

    ul tmp;

    while(isPalindrome(num) != 0) {
        tmp = stoul(num);
        tmp -= 1;
        num = to_string(tmp);
    }

    cout << tmp << endl;

}