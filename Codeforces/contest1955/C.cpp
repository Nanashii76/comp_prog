#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void sub(string &n) {

    if(n[n.length()-1] == '0' and n[n.length()-2] == '0' and n.length() > 1) {        
        n.pop_back();
        n[n.length()-1] = '9';
        int i = n[n.length()-2] - '0';
        i -= 1;
        n[n.length()-2] = i+'0'; 
    } else if (n.length() == 1 and n[0] != '0') {
        int i = n[0]-'0';
        i -= 1;
        n[0] = i+'0';
    } else {
        n.pop_back();
    }
}


int solve(deque<ll> &ships, string k){

    int count = 0;

    for(ll i = 0; !k.empty(); ++i) {
        if(i & 1) {
            ships.back()--;
            sub(k);
            if(ships.back() == 0) {
                ships.pop_back();
                count++;
            }
        } else {
            ships.front()--;
            sub(k);
            if(ships.front() == 0) {
                ships.pop_front();
                count++;
            }
                
        }

        for(const auto& element : ships)
            cout << element << " ";
        cout << endl;

    }

    return count;

}


int main(){

    int t; cin >> t;
    while(t--) {

        int n;
        string k; cin >> n >> k;
        deque<ll> ships;
        for(int i = 0; i < n; ++i) {
            ll aux; cin >> aux;
            ships.push_back(aux);
        }

        cout << solve(ships,k) << endl;

    }

    return 0;

}
