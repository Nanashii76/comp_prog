#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n,vector<int>(m,0));
    int r = 0, c = 0;

    for (int i = 0; i < n; ++i) {
        bool hasColum = true;
        for (int j = 0; j < m; ++j) {
            char aux; cin >> aux;
            mat[i][j] = aux-'0';
            if (mat[i][j]) {
                r = max(r, j+1);
                if(hasColum) {
                    hasColum = false;
                    c++;
                } 
            }
        }
    }

    cout << r << "x" << c << endl;
    return 0;
}
