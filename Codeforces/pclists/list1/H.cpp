#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,x,y; cin >> n >> x >> y;
    pair<int,int> gast_dist = {INT_MAX,-1};
    for(int i = 0; i < n; ++i) {
        int distx,disty,value; cin >> distx >> disty >> value;
        if((abs(distx-x)+abs(disty-y))*2+(value) < gast_dist.first)
            gast_dist = {(abs(distx-x)+abs(disty-y))*2+(value), i+1}; 
    }

    cout << gast_dist.first << " " << gast_dist.second << endl;
    return 0;
}