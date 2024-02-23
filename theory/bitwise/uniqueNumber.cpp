#include <iostream>


int uniqueNumber(int arr[], int size) {
    
    int ans = 0;
    for(int i = 0; i < size; ++i)
        ans = ans ^ arr[i];

    return ans;

}



int main(void){

    int n;
    std::cin >> n;
    int arr[n];


    for(int i = 0; i < n; ++i)
        std::cin >> arr[i];

    std::cout << uniqueNumber(arr,n) << std::endl;

}