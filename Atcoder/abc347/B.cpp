#include <bits/stdc++.h>
using namespace std;

int solve(string s){

    set<string> res;

    for(int i = 0; i <= (int)s.length(); ++i) {
        for(int j = 1; j <= (int)s.length()-i; ++j) {
            res.insert(s.substr(i,j));
        }
    }

    return res.size();
}

int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1; cin >> s1;
    int n = solve(s1);

    cout << n << endl;

}