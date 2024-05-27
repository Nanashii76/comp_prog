#include <bits/stdc++.h>
using namespace std;

int main(){

    string s1,s2; cin >> s1 >> s2;
    unordered_map<char,char> dic;
    for(int i = 0; i < (int) s1.length(); ++i)
        dic[s1[i]]=s2[i];
    
    int n; cin >> n;
    while(n--) {
        string str, res = ""; cin >> str;
        for(int i = 0; i < (int) str.length(); ++i) {
            
            char let = str[i];
            if(isdigit(let))
                res += let;
            if(isupper(let))
                res += toupper(dic[tolower(let)]);
            else
                res += dic[let];
        }
        for(auto i : res)
            if(isdigit(i) or isalpha(i))    
                cout << i;
            cout << endl;
    }
    return 0;
}