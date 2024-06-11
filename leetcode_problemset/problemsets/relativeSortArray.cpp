#include <bits/stdc++.h>
using namespace std;

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    vector<int> sorted;
    int n = arr1.size(), m = arr2.size();
    sort(arr1.begin(), arr1.end());
    for(int i = 0, j = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(arr1[j] == arr2[i]) {
                sorted.emplace_back(arr1[j]);
                arr1[j] = -1;
            }
        }
    }

    for(int i = 0; i < n; ++i)
        if(arr1[i] != -1)
            sorted.emplace_back(arr1[i]);

    return sorted;
}