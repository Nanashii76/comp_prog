#include <bits/stdc++.h>
using namespace std;


vector<int> twoSum(vector<int>& numbers, int target) { 

    int i = 0, j = (int)numbers.size()-1;
    vector<int> res;
    while(i < j) {
        if(numbers[i]+numbers[j] > target)
            j--;
        else if(numbers[i]+numbers[j] < target)
            i++;
        else {
            res.push_back(i+1);
            res.push_back(j+1);
            return res;
        }
    }

    return res;

}