#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; scanf("%d %d", &n, &k);
    while(n--) {
        int aux; scanf("%d", &aux);
        if(aux%k == 0)
            cout << aux/k << " ";
    }

    cout << endl;

    return 0;
    
}