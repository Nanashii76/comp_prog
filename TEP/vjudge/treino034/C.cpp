#include <bits/stdc++.h>
using namespace std;

int nChoosek( int n, int k ) {
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main(){

    int n, m, count = 0; cin >> n;
    m = n;
    set<int> s;
    while(n--) {
        int aux; cin >> aux;
        if(s.count(aux))
            count++;
        s.insert(aux);
    }

    int i = nChoosek(m,2);
    cout << i << " " << count << endl;
    cout << i-count << endl;
    return 0;



}