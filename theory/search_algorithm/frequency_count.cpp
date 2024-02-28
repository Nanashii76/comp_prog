#include <iostream>
#include <vector>

// The most otimized solution
/*

We've to program 2 functions
    -> lower bound
    -> upper bound

    to get the first occurency of the number and the last, the
    answer'll be (Lo-Fo+1)

*/

int lower_bound(std::vector<int> arr, int key) {

    int l = 0;
    int r = arr.size() - 1;

    int ans = -1;
    while( l <= r) {

        int mid = (l+r)/2;

        if(arr[mid]==key) {
            ans = mid;
            r = mid - 1;
        } else if (arr[mid] > key)
            r=mid-1;
        else
            l=mid+1;

    }

    return ans;


}

int upper_bound(std::vector<int> arr, int key) {

    int l = 0;
    int r = arr.size() - 1;

    int ans = -1;
    while( l <= r) {

        int mid = (l+r)/2;

        if(arr[mid]==key) {
            ans = mid;
            l = mid + 1;
        } else if (arr[mid] > key)
            r=mid-1;
        else
            l=mid+1;

    }

    return ans;


}

int main(){

    std::vector<int> arr = {0,1,1,1,1,2,2,2,3,4,4,5,10};
    std::cout << (upper_bound(arr,1)-lower_bound(arr,1))+1 << std::endl;

}


//My solution
/*


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

    return -1;

}



int main(){

    int arr[] = {0,1,1,1,1,2,2,2,3,4,4,5,10};
    int size = 12;

    int id = binary_search(arr,0,size-1,2);
    int i = id;
    int count = 0;

    if(id != -1) {
        while(arr[i] == arr[id]) {
            count++;
            i++;
        }
    }

    std::cout << count << std::endl;


}
*/











