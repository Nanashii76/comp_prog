#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    vector<string> names;
    while(n--) {
        string aux; cin >> aux;
        names.emplace_back(aux);
    }

    vector<string> names_sorted = names;
    sort(names_sorted.begin(),names_sorted.end());
    for(int i = 0; i < (int)names.size();++i) {
        auto it = find(names_sorted.begin(),names_sorted.end(), names[i]);
        cout << it - names_sorted.begin() << " ";

    }
    cout << endl;

    return 0;
}