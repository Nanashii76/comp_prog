#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k) {

    vector<int> res;
    unordered_map<int, int> map;

    for(int i = 0; i < (int)nums.size(); ++i) 
        map[nums[i]]++;

    vector<list<int>> count((int)nums.size()+1);
    for(const auto& elements : map) 
        count[elements.second].push_back(elements.first);
    
    for(int j = (int)count.size()-1; k != 0; --j) {
        while(!count[j].empty()) {
            res.push_back(count[j].front());
            count[j].pop_front();
            k--;
        }
    }


    return res;

}

int main(){


    vector<int> nums = {1,1,2,2,3};
    vector<int> ans = topKFrequent(nums,2);

    for(const auto& element : ans)
        cout << element << " "; 
    cout << endl;

    return 0;

}