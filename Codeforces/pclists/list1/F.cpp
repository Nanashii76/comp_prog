#include <bits/stdc++.h>
using namespace std;

int count_digits(int n) {
    int count = 0;
    while(n) {
        count += (n%10);
        n /= 10;
    }

    return count;
}


int main(){

    int n, a, b; cin >> n >> a >> b;
    vector<int> nums(n);
    int count = 0;
    iota(nums.begin(),nums.end(),1);

    for(auto i : nums) 
        if(count_digits(i) >= a and count_digits(i) <= b)
            count += i;

    cout << count << endl;
    return 0;
}