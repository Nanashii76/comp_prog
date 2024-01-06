## Data Struct and STL Containers in c++

## Using array like a classic data structure in c++

#include <iostream>
using namespace std;


// In this case we're passing the array by reference

 ->  a copy is being created and appointing to the original 

void updateArray(int arr[], int index, int value) {
    arr[i] = value;
}

int main() {

    int arr[5] = {1,2,3,4,5}; // you dont need to put the size if you've inicialized the list

    int arr[] = {1,2,3,4,5};


    int n = sizeof(arr)/sizeof(int); // getting the size of array

    /* 
    
        sizeof(arr) in main function is different in others function, because
        int main function the arr is an object, and in others function is just
        a pointer passes by reference

        so the sizeof(arr) in others function will have the sizeof 8 bytes
        while in main whill have sizeof(int)*qtd; 

    */

}

## Array STL

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

//Update and array
 -> If we want to change a value of the array stl, we've to pass by reference
    Because in that case, all the calling create objects, in main and in others
    functions

void update(array<int,n> &arr, int index, int value){
    arr[i] = value;
}

void printArray(const array<int,n> &arr) {
    for(int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
}


int main(){

    array<int,6> arr = {10,2,3,43,5,61}; // now we can use methods for this object

    //Sort
    sort(arr.begin(),arr.end());

    //Fill <encher com algum valor>
    array<int,10> zeros;
    zeros.fill(0);

    //For each loop
    for(int x : arr)
        cout << x << " ";

}



