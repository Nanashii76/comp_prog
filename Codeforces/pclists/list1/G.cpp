#include <bits/stdc++.h>
using namespace std;

bool dist_nums(int n) {

    set<int> nums;
    
    while(n) {
        int aux = n%10;
        if(nums.count(aux))
            return false;
        nums.insert(aux);
        n /= 10;
    }

    return true;

}

int main(){

    int n; cin >> n;
    n+=1;
    while(not dist_nums(n))
        n++;

    cout << n << endl;

    return 0;
}