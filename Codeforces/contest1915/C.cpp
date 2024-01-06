#include <bits/stdc++.h>
using namespace std;

int main(void) {

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        long long soma = 0;
        int a, aux;
        cin >> a;
        for (int j = 0; j < a; ++j) {
            cin >> aux;
            soma += aux;
        }

        if (abs(sqrt(soma)-(int)(sqrt(soma))) > 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

}