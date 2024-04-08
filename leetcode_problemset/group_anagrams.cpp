#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    
    vector<vector<string>> res;
    unordered_map<string, vector<string>> map;

    for (const string &str : strs) {
        string sorted_str = str;
        sort(sorted_str.begin(), sorted_str.end());
        map[sorted_str].push_back(str);
    }

    for (const auto &pair : map) {
        res.push_back(pair.second);
    }

    return res;
}

int main(){


    vector<string> str = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> out = groupAnagrams(str);

    for(const auto& rows : out) {
        for(const auto& colums : rows)
            cout << colums << " ";
        cout << endl;
    }
        
    return 0;
}