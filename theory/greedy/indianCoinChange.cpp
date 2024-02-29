/*

    Problem: Suposse you want to make a change of some
    Indian Rupees using minimum number of coins / notes

    Denominatios = [1,2,5,10,20,50,100,500,2000]


    Input
    273

    Output
    100+100+50+20+2+1

*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> denomination = {1,2,5,10,20,50,100,500,2000};


void findMin(int n) {

    std::vector<int> ans;

    for(int i = denomination.size()-1; i >= 0; --i) {

        while(n >= denomination[i]) {
            n -= denomination[i];
            ans.push_back(denomination[i]);
        }
    }


    for(auto x: ans)
        std::cout << x << " ";
    std::cout << std::endl;

}


int main(){

    int n;
    std::cin >> n;

    findMin(n);


}







