/*
    Write a function that makesinput an array of distinct
    integers, and return the length of highest mountain

    A mountain is definied as adjacent integers that are strictly 
    increasing until they reach a peak, at which the become 
    stricly decreasing

    At least 3 number are required to form a mountain

    ex:
        10
      /   \      -----> This is a mountain
    5       3

*/
#include <iostream>
#include <vector>
#include <algorithm>


// my Implementation

int solve(std::vector<int> mountain) {

    int N = mountain.size();
    int peak = 0; // found the highest peak at the mountain
    for(int i = 1; i < N-2;) {

        // First, we've to find a peak
        if(mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1]) {
            
            int count = 1, j = i;
            
            // Finding the left size of the mountain
            while(j>= 1 && mountain[j]>mountain[j-1]) {
                j--;
                count++;
            }
            
            // finding the right size of the moutain
            while(i<=N-2 && mountain[i]>mountain[i+1]) {
                i++;
                count++;
            }

            peak = std::max(peak,count);

        } else
            i++;

    }

    return peak;

}

int main(){

    std::vector<int> nums = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    std::cout << solve(nums) << std::endl;

}


