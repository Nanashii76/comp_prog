#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve(int ax, int ay, int bx, int by, int cx, int cy) {

    int count = 1;
    if((ax < bx and ax < cx) or (ax > bx and ax > cx))
        count += min(fabs(ax-bx),fabs(ax-cx));
    if((ay < by and ay < cy) or (ay > by and ay > cy))
        count += min(fabs(ay-by),fabs(ay-cy));

    return count;
}

int main(){

    int t; cin >> t;
    while(t--) {
        int ax,ay,bx,by,cx,cy;
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        int count = solve(ax,ay,bx,by,cx,cy);
        cout << count << endl;
    }

    return 0;
}