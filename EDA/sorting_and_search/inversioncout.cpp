#include <iostream>
#include <vector>
/*
    Given an array containing integers, you need to count the
    total number of inversions.
    Inversion: Two elements a[i] and a[j] form an inversion
    if a[i]>a[j] and i < j;
*/

// Brute force approach (O(n^2))
int mySolution(std::vector<int> &arr) {

    int i, j, cout;
    i = cout = 0;

    while (i < (int)arr.size()-1) {
        j = i+1;
        while(j <= (int)arr.size()-1) {
            if(arr[i]>arr[j])
                cout++;
            j++;
        }
        i++;
    }

    return cout;

}

// Implementation with mergesort (O(nlog n))
int merge(std::vector<int> &arr, int s, int e){

    int i = s;
    int m = (s+e)/2;
    int j = m+1;

    std::vector<int> tmp;
    int cout = 0;

    while(i<=m and j<=e) {
        if(arr[i] < arr[j]) {
            tmp.push_back(arr[i]);
            i++;
        } else {
            cout += (m-i+1);
            tmp.push_back(arr[j]);
            j++;
        }
    }

    // completing the fill from the first array
    for(; i<=m; ++i)
        tmp.push_back(arr[i]);
    
    // completing the fill from the second array
    for(; j<=e; ++j)
        tmp.push_back(arr[j]);

    // passing the tmp array to the original
    int k = 0;
    for(int idx = s; idx <=e; ++idx)
        arr[idx] = tmp[k++];

    return cout;

}

int inversion_cout(std::vector<int> &arr, int s, int e){

    // base case
    if(s>=e)
        return 0;
    
    // recursions call
    int m = (s+e)/2;
    int c1 = inversion_cout(arr,s,m);
    int c2 = inversion_cout(arr,m+1,e);
    int c3 = merge(arr,s,e);

    return c1+c2+c3;

}


int main(void) {

    std::vector<int> arr = {0,5,2,3,1};
    std::cout << mySolution(arr) << std::endl;
    std::cout << inversion_cout(arr,0,arr.size()-1) << std::endl;


}

