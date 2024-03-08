#include <iostream>
#include <vector>
#include <algorithm>

// In this problem you've a table with activities
// We've to chose the maximum number of activties that we can do
// the input is a time of (START and END) of this activity


// The first option of solution is to read first the end and them
// the start time, and them sort

// The second option is read normally and sort passing a custom 
// template to sort in ascending order using the end time

bool sortBySecond(const std::pair<int,int> &a, const std::pair<int,int> &b){
    return a.second < b.second;
}

int maxActivities(std::vector<std::pair<int,int>> act){

    std::sort(act.begin(),act.end(),sortBySecond);

    std::vector<std::pair<int,int>> ans;
    ans.emplace_back(std::make_pair(act[0].first,act[0].second));
    int count = 1, tmp = act[0].second;

    for(int i = 1; i < (int) act.size(); ++i) {
        if(act[i].first >= tmp) {
            count++;
            tmp = act[i].second;
            ans.emplace_back(std::make_pair(act[i].first,act[i].second));
        }
    }

    for(const auto &values : ans) {
        std::cout << values.first << "->" << values.second << " "; 
    }
    std::cout << std::endl;

    return count;

}


int main(void) {

    int t; // number of activities 
    std::cin >> t;

    std::vector<std::pair<int,int>> act;
 
    for(int i = 0; i < t; ++i) {
        int s,e;
        std::cin >> s >> e; // reading the satart and end of each act
        act.emplace_back(std::make_pair(s,e));
    }

    std::cout << "Max num of act: " << maxActivities(act) << std::endl;


}


