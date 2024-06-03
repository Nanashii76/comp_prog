#include <bits/stdc++.h>
using namespace std;


void solve(vector<int> &vec) {

    int cont = 0, l = 0, sum = 0;
    int ans = 360;

    while(cont < (int)vec.size()) {
        sum += vec[cont];
        while(sum >= 180) {
            ans = min(ans,2*abs(sum-180));
            sum -= vec[l];
            l++;
        }
        ans = min(ans,2*abs(sum-180));
        cont++;
    }

    cout << ans << endl;

}


/* Minhas outras 2 soluções
void solve(vector<int> &vec) {

    if(!((int)vec.size()&1)) {
        cout << 0 << endl;
        return;
    }

    if((int)vec.size() == 1) {
        cout << vec[0] << endl;
        return;
    }

    int max = *max_element(vec.begin(),vec.end());
    int count = 0;
    for(int i = 0; i < (int)vec.size(); ++i)
        count += min(vec[i],vec[i+1]);
    
    cout << abs(count-max) << endl;

}

void solve(vector<int> &vec) {

    unordered_map<int,int> pizza;
    for(const auto& x : vec)
        pizza[x]++;
    
    for(int i = 0; i < (int)vec.size(); ++i) {
        if(pizza.count(180-vec[i])) {
            pizza.erase(vec[i]);
            pizza.erase(180-vec[i]);
        }
    }

    if(pizza.size() == 0) {
        cout << 0 << endl;
        return;
    } else {
        sort(vec.begin(),vec.end());
        int sum = 0;
        for(int i = 0; i < (int)vec.size()/2; ++i)
            sum += vec[i];
        
        cout << abs(sum-vec[vec.size()-1]) << endl;
        return;
    }

}
*/

int main(){

    int n; cin >> n;
    vector<int> sizes;
    while(n--) {
        int t; cin >> t;
        sizes.emplace_back(t);
    }

    solve(sizes);

    return 0;
}