#include <bits/stdc++.h>
using namespace std;


int main(){

    int t; cin >> t;
    while(t--) {
        int bigger = 0, bigger2 = 0;
        vector<int> nums(4);
        for(int i = 0; i < 4; ++i) {
            cin >> nums[i];
            if(nums[i] >= bigger) {
                int aux = bigger;
                bigger = nums[i];
                bigger2 = aux;
            }

            if(nums[i] != bigger and nums[i] > bigger2)
                bigger2 = nums[i];
        }

        if((nums[0] == bigger and nums[1] == bigger2) or (nums[1] == bigger and nums[0] == bigger2) or (nums[2] == bigger and nums[3] == bigger2) or (nums[3] == bigger and nums[2] == bigger2))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;    
    }

    return 0;

}