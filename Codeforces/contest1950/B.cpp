#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            if ((i / 2 + j / 2) % 2 == 0) {
                cout << '#';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int n;
        cin >> n; 
        solve(n);
    }

    return 0;
}