#include <iostream>

//Reverse an array
void reverseArray(int *v, int size) {

    int tmp, a = 0;
    for(int i = size-1; i>=size/2; --i) {
        tmp = v[i];
        v[i] = v[a];
        v[a] = tmp;
        a++;
    }

}

int main(){

    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int n = 10;
    reverseArray(arr, n);

}









