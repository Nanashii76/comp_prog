#include <bits/stdc++.h>
using namespace std;

vector<char> commonChars(vector<string> &words) {

    unordered_map<char,int> unmap;
    unordered_map<char,int> unmapduplic;
    vector<char> ans;
    int n = words.size();
    for(int i = 0; i < n; ++i) {
        string aux = words[i];
        int m = words[i].length();
        for(int j = 0; j < m; ++j) {
            set<char> s;
            unmapduplic[aux[j]]++;
            if(not s.count(aux[j])) {
                unmap[aux[j]]++;
            }
        }
    }

    for(auto &it : unmap)
        if(it.second >= n)
            ans.emplace_back(it.first);

    for(auto &it : unmapduplic)
        if(it.second >= (2*n))
            ans.emplace_back(it.first);

    return ans;

}

int main(){

    vector<string> input = {"cool","lock","cook"};
    vector<char> res = commonChars(input);
    for(auto x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}