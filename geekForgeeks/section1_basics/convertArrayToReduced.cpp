#include <bits/stdc++.h>
using namespace std;

void convert(int arr[], int n) {

    int arr2[n+1];
    for(int i = 0; i < n; ++i)
        arr2[i] = arr[i];
    
    sort(arr2, arr2+n);

    unordered_map<int,int> unmap;
    for(int i = 0; i < n; ++i)
        unmap[arr2[i]] = i;

    for(int i = 0; i < n; ++i)
        arr[i] = unmap[arr[i]];

}