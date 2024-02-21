#include <iostream>

int main(){

    int x, y;
    int max = 0;
    std::cin >> x >> y;

    for(int i = x; i <= y; ++i) {
        for(int j = x; j <= y; ++j) {
            int currentMax = (i^j);
            if(currentMax > max)
                max = currentMax;
        }
    }

    std::cout << max << std::endl;

}