#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll,ll> getMinMax(vector<ll> arr) {

    int size = arr.size();
    pair<ll,ll> minMax;
    if(size == 1) {
        minMax.first = minMax.second = arr[0];
        return minMax;
    }
    minMax.first = LLONG_MAX;
    minMax.second = LLONG_MIN;

    for(int i = 0; i < size; ++i) {
        minMax.first = min(minMax.first,arr[i]);
        minMax.second = max(minMax.second,arr[i]);
    }

    return minMax;

}