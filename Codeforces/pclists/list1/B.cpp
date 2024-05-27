#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    vector<int> values;
    while(n--) {
        int aux; cin >> aux;
        values.emplace_back(aux);
    }

    n = values.size();
    int count = 0, maxValue = *max_element(values.begin(),values.end());
    for(int i = 0; i < n; ++i) 
        count += abs(maxValue-values[i]);

    cout << count << endl;

    return 0;
}