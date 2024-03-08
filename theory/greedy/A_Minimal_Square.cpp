#include <iostream>
#include <vector>

// mathmatical proof
// to find the minimum square, we've to find the max approach
// to width and height
int findMin(int a, int b) {
    int side = std::min(std::max(a*2,b), std::max(a,2*b));
    return side*side;
}


int main(){

    int n;
    std::cin >> n; // number of test cases

    for(int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::cout << findMin(a,b) << std::endl;
    }

}




