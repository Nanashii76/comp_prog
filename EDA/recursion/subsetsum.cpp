#include <iostream>
#include <string>
#include <algorithm>

/*
    Without loop: given a set of non-negative integers, and
    a value sum, determine if there is a subset of the given
    set with sum equal to given sum.

    input
    arr=[10,12,15,6,19,20];
    sum=16;

    output
    Yes
*/

bool sumExist(int *arr, int sum, int i, int j) {

    // base condition
    if(arr[i]+arr[j] == sum)
        return true;

    if(arr[i]+arr[j] > sum)
        return sumExist(arr,sum,i,j-1);
    else
        return sumExist(arr,sum,i+1,j);

    return false;

}


int main(){

    int arr[] = {10,12,15,6,19,20};
    int sum = 16;
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // first we've to sort the array
    std::sort(arr,arr+n);

    if(sumExist(arr,sum,0,n-1))
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

}

