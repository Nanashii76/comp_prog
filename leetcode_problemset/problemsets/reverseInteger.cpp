#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int reverse(int x) {
    ll ans = 0;
    while (x)
    {
        ans = (ans * 10) + (x % 10);
        x /= 10;
    }

    if (ans > INT_MAX or ans < INT_MIN)
        return 0;
    return ans;
}

int main() {
    int value;
    cin >> value;
    cout << reverse(value) << endl;

    return 0;
}