#include <iostream>
#include <vector>
#include <algorithm>


// Creating a template to sort the vector of pairs
// using the second int element
bool sortbysec(const std::pair<int,int> &a, const std::pair<int,int> &b) {
    return (a.second < b.second);
}

// function to count the max of activites that we can make
// Picking the first, after sorting te vector, to use as base
int findMax(std::vector<std::pair<int, int>> v) {

    std::sort(v.begin(),v.end(),sortbysec);
    
    int count = 1, temp = v[0].second;
    for(int i = 1; i < v.size(); ++i) {
        if(v[i].first >= temp && v[i].second > temp) {
            count++;
            temp = v[i].second;
        }
    }

    return count;

}

int main(){


    std::vector<std::pair<int, int>> act;
    int n, t;
    std::cin >> n;

    for(int i = 0; i < n; ++i) {

        std::cin >> t;
        for(int j = 0; j < t; ++j) {
            int s, e;
            std::cin >> s >> e;
            act.emplace_back(std::make_pair(s,e));
        }
            
        int count = findMax(act);
        std::cout << count << std::endl;

    }

}


