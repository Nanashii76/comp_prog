#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    if(floor(1.08*n) < 206)
        cout << "Yay!" << endl;
    else if(floor(1.08*n) == 206)
        cout << "so-so" << endl;
    else if (floor(1.08*n) > 206)
        cout << ":(" << endl;

    return 0;

}