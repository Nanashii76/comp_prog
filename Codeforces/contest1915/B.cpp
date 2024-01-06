#include <bits/stdc++.h>
using namespace std;

char solve(vector<char> l){

    for(auto i : l)
        if(count(l.begin(), l.end(), i) == 2)
            return i;

    return '0';

}


int main(){

    int n;
    char aux;
    cin >> n;

    for(int i = 0; i < n; ++i) {

        vector<char> letters;
        letters.reserve(9);

        for(int j = 0; j < letters.capacity(); ++j) {
            cin >> aux;
            letters.emplace_back(aux);
        }
        cout << solve(letters) << endl;
        //letters.clear();
    }

}