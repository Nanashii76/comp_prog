#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &arr, int x) {

    int l = 0, r = arr.size() - 1, target = -1;
    while(l <= r) {
        int mid = l+r/2;
        if(arr[mid] == x) {
            target = mid;
            r = mid-1;
            arr[mid] = 0;
        } else if (arr[mid] > x) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    return target;
}

int upper_bound(vector<int> &arr, int x) {
    
    int l = 0, r = arr.size() - 1, target = -1;
    while(l <= r) {
        int mid = l+r/2;
        if(arr[mid] == x) {
            target = mid;
            l = mid+1;
            arr[mid] = 0;
        } else if (arr[mid] > x) {
            r = mid - 1;
        } else {
            l = mid+1;
        }
    }

    return target;
}

void frequencyCount(vector<int>& arr, int N, int P) {

    int size = arr.size() - 1;
    sort(arr.begin(),arr.end());
    for(int i = 0; i < size; ++i) {
        if(arr[i] == 0)
            continue;

        int val = arr[i];
        int f = lower_bound(arr, val);
        int l = upper_bound(arr, val);
        l = l-f+1;
        arr[val-1] = l;
    }
}