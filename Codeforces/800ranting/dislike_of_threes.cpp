#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3+10;
vector<int> sequence(MAX);

void init_seq() {

    int aux = 1;
    for(int i = 0; i < MAX; ++i) {
        while(aux%3==0 or (aux%10)==3) 
            aux++;
        sequence[i] = aux;
        aux++;
    }

}

int main(){

    init_seq();
    int t; cin >> t;
    while(t--) {
        int a; cin >> a;
        cout << sequence[a-1] << endl;
    }

    return 0;

}

