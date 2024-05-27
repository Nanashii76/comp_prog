#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    unordered_map<int,bool> unmap;
    while(n--) {
        int a,b; cin >> a >> b;
        if(a==1) unmap[b]=1;
        if(a==2) cout << (unmap[b]?"Sim":"Nao") << endl;
    }

    return 0;
}