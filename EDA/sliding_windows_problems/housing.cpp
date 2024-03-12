/*
    Along one sindeof a road there is a sequence of vacant
    plots of land. Each plot has a different area (non-zero).
    So, the areas from a sequence A[1], A[2], ... A[N].

    You want to buy K acres of alnd to build a house, you want
    to find all segments of contiguous plots (i.e., a subsection
    in the sequence) of whose sum is exaclty k.

    Sample input
    plots = [1 3 2 1 4 1 3 2 1 1 2]
    K = 8

    sample output
    2 5
    4 6
    5 9

*/
#include <iostream>
#include <vector>

void housing(int *arr, int n, int k) {

    int i, j, cout;
    i = j = cout = 0;

    while(j<n) {
        
        // expand to right
        cout += arr[j];
        j++;

        // remove elements from the left till cout > sum and i < j
        while(cout > k and i < j) {
            cout -= arr[i];
            i++;
        }

        // check if cout is equal to k
        if(cout==k) {
            // printing the window
            // j-1 because or current point j is pretendo to sum
            // the number in the next index
            std::cout << i << "-" << j-1 << std::endl;
        }


    }

    return;

}

void smallestHousing(int *arr, int n, int k) {

    int i, j, cout, small;
    i = j = cout = small = 0;
    std::pair<int,int> smallpair;

    while(j<n) {

        //expando to the right
        cout += arr[j];
        j++;

        // if the cout gets greater than k
        while(cout > k && i < j) {
            cout -= arr[i];
            i++;
        }

        // if we gets k
        if(cout==k) {
            int current = (j-1)-i+1;
            if (current < small || small == 0) {
                small = current;
                smallpair.first = i;
                smallpair.second = j-1;
            }
        }

    }

    std::cout << smallpair.first << "-" << smallpair.second << std::endl;

}



int main(void) {

    int plots[] = {1,3,2,1,4,1,3,2,1,1};
    int n = sizeof(plots)/sizeof(int);
    int k = 8;

    housing(plots,n,k);
    std::cout << "Small window: ";
    smallestHousing(plots,n,k);

}







