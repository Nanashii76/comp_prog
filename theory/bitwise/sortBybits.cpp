#include <bits/stdc++.h>
using namespace std;

int countBits(int n) {

    int count = 0;
    while(n != 0) {
        count += (n&1);
        n = n<<1;
    }

    return count;

}


vector<int> sortBybits(vector<int> arr) {

    int i, j;
    bool swapped;
    for (i = 0; i < arr.size() - 1; i++) {
        swapped = false;
        for (j = 0; j < arr.size() - i - 1; j++) {
            if (countBits(arr[j]) > countBits(arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;

        return arr;
    }
}

int main(void) {

    vector<int> v = {0,1,2,3,4,5,6,7,8};
    vector<int> v2(sortBybits(v));

    for(auto x : v2)
        cout << x;

}