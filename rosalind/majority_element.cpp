#include <bits/stdc++.h>
using namespace std;


int main() {

    int n, m; cin >> n >> m;
    while(n--) {
        unordered_map<int,int> unmap;
        for(int i = 0; i < m; ++i) {
            int aux; cin >> aux;
            unmap[aux]++;
        }

        bool has = false;
        for(auto element : unmap)
            if(element.second > m/2) {
                cout << element.first << " ";
                has=true;
            }
                
        if(not has)
            cout << "-1" << " ";
    }
    cout << endl;
    return 0;

}