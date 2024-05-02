#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    while(n--) {
        int a,b; cin >> a >> b;
        string a1, a2; cin >> a1 >> a2;

        int ans = 0;

        for(int i = 0, j = 0; i < (int)a2.length(); ++i) {
            if(a2[i] == a1[j]) {
                ans++;
                j++;
            }
        }

        cout << ans << endl;
    }
}