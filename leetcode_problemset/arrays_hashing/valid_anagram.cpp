/*
    To check if two string are anagrams, we've to methods to do this problem;
    
    1 -> sort all the string and compare each other, if they're equivalent, so
    they're anagrams

    2 -> using a hashmap to compare both strings

*/
#include <bits/stdc++.h>
using namespace std;

bool anagrams_sorting(string s1, string s2){

    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());

    return(s1 == s2 ? true : false);

}

bool anagrams_hash(string s1, string s2){


    if((int)s1.length() != (int)s2.length())
        return false;
    
    map<char,int> mapS1;
    map<char,int> mapS2;

    for(int i = 0; i < (int)s1.length(); ++i) {
        mapS1[s1[i]]++; mapS2[s2[i]]++;
    }

    return(mapS1 == mapS2 ? true : false);
    
}


int main(){

    string s,t; cin >> s >> t;

    cout << anagrams_sorting(s,t) << endl;
    cout << anagrams_hash(s,t) << endl;

    return 0;

}