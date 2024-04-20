#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, op; cin >> n >> op;
    vector<int> dentes(n+1,1);

    for(int i = 0; i < op; ++i) {
        int x; cin >> x;
        if(dentes[x] == 1) {
            dentes[x] = 0;
            --n;
        } else {
            dentes[x] = 1;
            ++n;
        }
    }

    cout << n << endl;

}
