#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target){

    int rows = (int)matrix.size(), colums = matrix[0].size();
    int l = 0, r = (rows*colums) - 1;

    while(l <= r) {
        int mid = (l+r)/2;

        int row_index = mid/colums;
        int col_index = mid%colums;

        if(matrix[row_index][col_index] > target)
            r = mid-1;
        else if (matrix[row_index][col_index] < target)
            l = mid+1;
        else
            return true;

    }

    return false;

}