#include <bits/stdc++.h>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void solve(vector<pair<int,int>> p){

    double dist = 0;
    int id = 0;

    for(int i = 0; i < (int)p.size(); ++i) {
        id = 0;
        dist = 0;
        for(int j = 0; j < (int)p.size(); ++j) {
            
            if(i == j)
                continue;

            double newDist = 0; 
            newDist = distance(p[i].first, p[i].second, p[j].first, p[j].second);
            if(newDist > dist) {
                dist = newDist;
                id = j+1;
            }
        }
        cout << id << endl;
    }

}

int main(){

    int n; cin >> n;
    vector<pair<int,int>> points;
    for(int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        points.push_back(make_pair(a,b));
    }

    solve(points);

}