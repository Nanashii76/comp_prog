#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int tmp = n;
    vector<int> notOrd;
    
    while(tmp--) {
        int x; 
        cin >> x;
        notOrd.emplace_back(x);
    }

    int op = 0;
    vector<pair<int,int>> res;

    for(int i = 0; i < notOrd.size(); ++i) { 

        if(notOrd[i] != i+1) {
            ++op;
            auto it = find(notOrd.begin(), notOrd.end(), i+1);
            int index = distance(notOrd.begin(), it);
            int tmp = notOrd[i];
            notOrd[i] = notOrd[index];
            notOrd[index] = tmp;
            res.emplace_back(make_pair(notOrd[i], notOrd[index]));
        }

    }

    cout << op << endl;
    for(const auto& elements : res)
        cout << elements.first << " " << elements.second << endl;
    
}
