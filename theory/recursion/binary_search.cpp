#include <iostream>
#include <vector>


int binary_search(int *v, int l, int r, int x) {

    int m = (l+r)/2;

    // base cases
    if(v[m] == x)
        return m;

    if(l > r)
        return -1;

    // recursion call
    if(v[m] < x )
        return binary_search(v,m+1,r,x);
    else
        return binary_search(v,l,m-1,x);

}


int main(){

    int vet[] = {0,1,2,3,4,5,6,7,8,9};
    int n = 10;
    int v = binary_search(vet,0,n-1,8);

    if(v != -1)
        std::cout << "found at index: " << v << std::endl;
    else
        std::cout << "not found" << std::endl;

}

