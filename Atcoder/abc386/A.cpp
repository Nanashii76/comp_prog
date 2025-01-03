#include <bits/stdc++.h>
using namespace std;

int main() {

    unordered_map<int,int> unmap;
    for(int i = 0; i < 4; ++i) {
        int aux; cin >> aux;
        unmap[aux]++;
    }

    cout << (unmap.size() == 2 ? "Yes" : "No") << endl;

}