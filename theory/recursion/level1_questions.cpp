#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

/*
    Question 1:

    Give an integer N, print all the number before N
    until 1;

    input: 5

    output: 5 4 3 2 1
*/
void print_until_n(int n) {

    // base case
    if(n == 1) {
        std::cout << 1 << std::endl;
        return;
    }

    // recursion call
    std::cout << n << " ";
    print_until_n(n-1);

}


/*
    Question 2:

    Print all the number between [1,N];

    input: 5

    output: 1 2 3 4 5
*/
void print_at_n(int n) {

    // base case
    if(n == 1) {
        std::cout << 1 << " ";
        return;
    }

    // recursion call
    print_at_n(n-1);
    std::cout << n << " ";

}

/*
    Question 3:

    Factorial of a number N;
*/
int factorial(int n) {

    // base case
    if(n==1)
        return 1;

    // recursion case
    return n*factorial(n-1);

}

/*
    Question 4:

    Sum of the digit between [N,1];


*/
int sum_between_n(int n) {

    // base case
    if(n == 1)
        return 1;
    
    // recursion call
    return n+sum_between_n(n-1);

}

/*
    Question 5:

    sum of digits of N

*/
int sum_of_digits(int n) {

    // base case
    if (n/10 == 0)
        return n;
    
    // recursion call
    return n%10+sum_of_digits(n/10); 

}

/*
    Question 6:

    Products of digits of N;
*/
int products_of_n(int n) {

    // base case
    if(n/10 == 0)
        return n;

    // recursion call
    return n%10*products_of_n(n/10);

}

/*
    Question 7:

    reverse a number N;
*/
void reverse(int n) {

    // base case
    if(n/10 == 0) {
        std::cout << n;
        return;
    }

    std::cout << n%10;
    reverse(n/10);

}

/*
    Question 8:

    Check if N is a palindrome
*/
bool palindrome(std::string n) {

    std::string n2;
    for(int i = n.length(), b = 0; i >= 0; --i, ++b)
        n2[b] = n[i];

    if(n2 == n)
        return true;
    else 
        return false; 

}






int main(){

    std::cout << "Question 01" << std::endl;
    print_until_n(5);
    std::cout << std::endl;
// ----------------------------------------------------
    std::cout << "Question 02" << std::endl;
    print_at_n(5);
    std::cout << std::endl;
    std::cout << std::endl;
// ----------------------------------------------------
    std::cout << "Question 03" << std::endl;
    std::cout << factorial(5) << std::endl;
    std::cout << std::endl;
// ----------------------------------------------------
    std::cout << "Question 04" << std::endl;
    std::cout << sum_between_n(10) << std::endl;
    std::cout << std::endl;
// ----------------------------------------------------
    std::cout << "Question 05" << std::endl;
    std::cout << sum_of_digits(123) << std::endl;
    std::cout << std::endl;
// ----------------------------------------------------
    std::cout << "Question 06" << std::endl;
    std::cout << products_of_n(222) << std::endl;
    std::cout << std::endl;
// ----------------------------------------------------
    std::cout << "Question 07" << std::endl;
    reverse(345);
    std::cout << std::endl;
    std::cout << std::endl;
// ----------------------------------------------------
    std::cout << "Question 08" << std::endl;
    if(palindrome("123321"))
        std::cout << "Is a palindrome" << std::endl;
    else
        std::cout << "Isn't a palindrome" << std::endl;
    std::cout << std::endl;
// ----------------------------------------------------
    std::cout << "Question 09" << std::endl;

    std::cout << std::endl;
// ----------------------------------------------------
    std::cout << "Question 10" << std::endl;

    std::cout << std::endl;
// ----------------------------------------------------
    std::cout << "Question 11" << std::endl;

    std::cout << std::endl;
// ----------------------------------------------------


}







