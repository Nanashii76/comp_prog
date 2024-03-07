#include <iostream>
#include <vector>

// If we want to find to numbers that the sum of them is equal
// to a determinate K, we can use two point technique

int two_points(std::vector<int> &v, int key) {

    int low = 0, high = (int) v.size()-1;
    
    while(low < high) {
        int sum = v[low]+v[high];

        if(sum == key)
            break;
        else if (sum < key)
            low++;
        else
            high--;

    }

    if(v[low]+v[high] == key && low != high) 
        std::cout << "found at positions: " << low << " and " << high << std::endl;
    else
        std::cout << key << " cannot be obtained" << std::endl;
    
    return 0;

}



int main(){

    std::vector<int> nums = {1,2,3,3,4,5,7,9,10};
    int key = 6;

    two_points(nums,key);

}


