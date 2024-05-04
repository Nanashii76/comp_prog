#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool templateSort(pair<ll,ll> a, pair<ll,ll> b) {
    return a.first > b.first;
}

int main(){

    int n; cin >> n;
    vector<pair<ll,ll>> heights(n+1);
    while(n--) {
        ll a, b; cin >> a >> b;
        heights.emplace_back(make_pair(a,b));
    }

    sort(heights.begin(),heights.end(),templateSort);
    int count = heights[0].second;
    
    for(int i = 1; i < (int)heights.size(); ++i) {
        heights[i].first += heights[i-1].first;
        heights[i].second += heights[i-1].first;

        if(heights[i].second >= count)
            count = heights[i].second;

    }

    cout << count << endl;
    return 0;

}