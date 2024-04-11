#include <bits/stdc++.h>
using namespace std;

int solve(vector<pair<int,int>> &points) {

    int xpos = 0,xneg = 0,ypos = 0,yneg = 0;

    for(int i = 0; i < (int)points.size(); ++i) {
        if(points[i].first > xpos)
            xpos = points[i].first;
        if(points[i].first < xneg)
            xneg = points[i].first;
        if(points[i].second > ypos)
            ypos = points[i].second;
        if(points[i].second < yneg)
            yneg = points[i].second;
    }

    return((2*xpos)+(2*ypos)+(2*fabs(xneg))+(2*fabs(yneg)));

}

int main(){

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int dist = 0; 
        vector<pair<int,int>> points;
        while(n--) {
            int xb,yb; cin >> xb >> yb;
            points.push_back(make_pair(xb,yb));
        }
        dist = solve(points);
        cout << dist << endl;
    }

    return 0;
}