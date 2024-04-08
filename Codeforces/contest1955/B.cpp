#include <bits/stdc++.h>
using namespace std;

bool solve(vector<vector<int>> &matrix, int c, int d){

    for(int i = 0; i < (int)matrix.size()-1; ++i) {
        for(int j = 0; j < (int)matrix[i].size()-1; ++j) {
            if( (matrix[i][j] != matrix[i+1][j] + c) and (matrix[i][j]+d != matrix[i][j+1] + d) )
                return false;
        }
    }

    return true;

}


int main(){

    int t; cin >> t;
    while (t--) {

        int n,c,d; cin >> n >> c >> d;
        vector<vector<int>> matrix(n, vector<int>(n));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j)
                cin >> matrix[i][j];
        }

        for(const auto& rows : matrix) {
            for(const auto& colums : rows)
                cout << colums << " ";
            cout << endl;
        }

        if(solve(matrix,c,d))
            cout << "Yes\n";
        else
            cout << "No\n";

    }

    return 0;

}