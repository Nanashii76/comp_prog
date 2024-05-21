#include <bits/stdc++.h>
using namespace std;

pair<int,int> check_substring(string comp, int k) {

    int size = comp.length();
    unordered_map<char,int> rep;
    for(int i = k; i < size; ++i) {
        rep[comp[i]]++;
        if(rep[comp[i]] >= 2)
            return {k,i};
    }

    return {k,size};

}

int lengthOfLongestSubstring(string s) {

    int ini = 0, size = s.length(), fin = 0;
    for(int i = 0; i < size; ++i) {
        pair<int,int> new_fin = check_substring(s,i);
        if((new_fin.second - new_fin.first) > (fin-ini)) {
            fin = new_fin.second;
            ini = new_fin.first;
        }
        //cout << ini << " " << fin << endl;
    }

    return fin-ini;
}


// int main(){

//     string s = "abcabcbb";
//     int maxSub = lengthOfLongestSubstring(s);
//     cout << maxSub << endl;

//     return 0;
// }