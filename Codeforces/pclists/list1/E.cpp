#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    vector<int> contests;
    while(n--) {
        int aux; cin >> aux;
        contests.emplace_back(aux);
    }

    int count = 0;
    sort(contests.begin(),contests.end());
    for(int i = 0; i < (int)contests.size(); ++i) {
        auto it = find(contests.begin(),contests.end(), i+1);
        if(it != contests.end())
            count++;
    }

    cout << count << endl;

    return 0;

}