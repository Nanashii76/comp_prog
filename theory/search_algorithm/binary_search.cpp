#include <iostream>

int binary_search(int arr[], int l, int r, int x) {

    while(l <= r) {
        int mid = (l+r)/2;

        if(arr[mid] < x) 
            l=mid+1;
        else if(arr[mid] > x)
            r=mid-1;
        else
            return mid;

    }

    return EXIT_FAILURE;

}

int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    if(binary_search(arr,0,n-1,6) != EXIT_FAILURE)
        std::cout << "Element found at position: " << binary_search(arr,0,n-1,6) << std::endl;
    else
        std::cout << "Not-Found" << std::endl;


}










