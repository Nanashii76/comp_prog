#include <bits/stdc++.h>
using namespace std;

int main(){
    double Sx, Sy, Gx, Gy;
    cin >> Sx >> Sy >> Gx >> Gy;

    double x = (Gy * Sx + Sy * Gx) / (Sy + Gy);
    cout << fixed << setprecision(10) << x << endl;
    return 0;
}
