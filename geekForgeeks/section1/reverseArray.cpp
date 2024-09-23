#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr) {
    int size = arr.size()-1;
    for(int i = 0; i < size; ++i) {
        int temp = arr[i];
        arr[i] = arr[size];
        arr[size] = temp;
        size--;
    }
}

int main() {

}