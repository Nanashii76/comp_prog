#include <iostream>
#include <vector>

// Implementing a merge sort
/*
    Mergesort is an algorithm to order determinates values
    folllowing a key rule

    the merge is a algorithn that divides and conquist

    1. divide in 2 vectors
    3. mersort the vector of the left and right
    3. merge the both vectors to result

*/

void merge(std::vector<int> &arr, int s, int e) {

    // mark variable to help during loops
    int i = s;
    int m = (s+e)/2;
    int j = m+1;

    // creating a temp vector to get the values from left and right
    std::vector<int> temp;

    while(i<=m and j<=e) {
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // copy remaining elements from first array
    for(; i <= m; ++i)
        temp.push_back(arr[i]);
    
    // copy remaining elements from second array
    for(; j<=e; ++j)
        temp.push_back(arr[j]);

    // copy back the elements from temp to original array
    int k = 0;
    for(int idx = s; idx <= e; ++idx)
        arr[idx] = temp[k++];

}

void mergesort(std::vector<int> &arr, int s, int e) {

    // base case
    if(s>=e)
        return;

    // recursion case
    // dividing the array in two parts
    int mid = (s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);

    // making the merge in both arrays
    return merge(arr,s,e);

}

int main(){

    std::vector<int> arr = {10,5,2,0,7,6,4};

    int s = 0;
    int e = arr.size()-1;
    mergesort(arr,s,e);

    for(int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;


}