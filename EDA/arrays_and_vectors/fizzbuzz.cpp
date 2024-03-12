#include <iostream>
#include<vector>
#include<string>

std::vector<std::string> fizzbuzz(int n){
    
    std::vector<std::string> result;
    
    for(int i = 1; i <= n; ++i) {
        
        if(i%3==0 && i%5!=0)
            result.push_back("Fizz");
        else if(i%3!=0 && i%5==0)
            result.push_back("Buzz");
        else if(i%3==0 && i%5==0 && i != 0)
            result.push_back("FizzBuzz");
        else
            result.push_back(std::to_string(i));
    }
    
    return result;
    
}


int main(){

    std::vector<std::string> ans = fizzbuzz(17);

    for(auto element : ans)
        std::cout << element << " ";
    std::cout << std::endl;


}