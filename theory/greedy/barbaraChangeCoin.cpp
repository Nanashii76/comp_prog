#include <iostream>
#include <vector>

// notes (ordered) that barbara have to change with client 
std::vector<int> coins = {1, 2, 5, 10};


void findMin(int n) {

    std::vector<int> ans;

    for(int i = coins.size()-1; i >= 0; --i) {

        while(n >= coins[i]) {
            n -= coins[i];
            ans.push_back(coins[i]);
        }

    }

    for(const auto value : ans) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

}



int main(){

    int n;
    std::cin >> n;

    findMin(n);

}

