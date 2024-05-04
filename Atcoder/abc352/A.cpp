#include <bits/stdc++.h>
using namespace std;


int main() {

    int n, x, y, z; cin >> n >> x >> y >> z;
    vector<int> values(n,0);
    while(x != y) {
        if(x <= y) {
            values[x] = 1;
            x++;
        
        }
        else {
            values[x] = 1;
            x--;
        }
    }

    cout << (values[z] ? "Yes" : "No") << endl;

    return 0;
}