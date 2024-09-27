#include <bits/stdc++.h>
using namespace std;

void update(int a[], int n, int update[], int k) {

    for(int i = 0; i < n; ++i)
        a[i] = 0;

    for(int i = 0; i < k; ++i)
        a[update[i] - 1]++;
    
    for(int i = 1; i < n; ++i)
        a[i] += a[i-1];

}

