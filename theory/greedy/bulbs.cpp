#include <iostream>
#include <vector>

int bulbs(std::vector<int> &values) {

    int cost = 0;

    for(int i = 0; i < (int)values.size(); ++i) {
        if(cost % 2 == 0)
            values[i] = values[i];
        else
            values[i] = ~values[i];
        
        if(values[i] % 2 == 1)
            continue;
        else
            cost++;
    }
    return cost;
    
}

int main(){

    std::vector<int> values = {0,0,1,0,1,0};
    std::cout << bulbs(values) << std::endl;

}








