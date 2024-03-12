/*
    Given an array containing N integers, and an Number S
    denoting a target sum.

    Find all distinct integers that can add up to form target
    sum. The numbers in each triplet should be ordered in 
    ascending order, and triplet should be ordered too.
    Return empty array if no such triplet exist

*/
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> solve(std::vector<int> v, int sum){

    std::vector<std::vector<int>> ans;
    // sorting the given vector
    std::sort(v.begin(),v.end());    

    // Pick every v[i] number and solve a pair sum for remaining part
    for(int i = 0; i < (int)v.size()-2; ++i) {
        
        int j = i+1;
        int k = (int)v.size()-1;

        // Two pointer approach
        while(j < k) {
            int current_sum = v[i];
            if(current_sum+v[j]+v[k] == sum) {
                ans.push_back({current_sum,v[j],v[k]});
                j++;
                k--;
            } else if(current_sum+v[j]+v[k] > sum)
                k--;
            else
                j++;
        }
    }

    return ans;

}

int main(){

    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,15};
    int sum = 18;

    auto result = solve(arr,sum);

    for(auto rows : result) {
        for(auto elements : rows)
            std::cout << elements << " ";
        std::cout << std::endl;
    }


}


