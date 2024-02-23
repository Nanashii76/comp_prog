#include <iostream>
#include <vector>

/*

    1. XOR of two unique numbers > 0 (Atleast 1 set bit)
    2. A bit is set when it is present in exaclty one of two numbers
    3. Create a subsequence with numbers that have the same bit set
    4. the subsequence will have just one unique number 2n+1
    5. the other subsequence will have the second unique number


*/

void uniqueTwoNumbers(std::vector<int> arr) {

    // XOR of all the numbers
    int ans = 0;
    for(int i = 0; i < static_cast<int>(arr.size()); ++i)
        ans = ans^arr[i];

    // Finding the first position of "ans" that is 1
    int pos = 0;
    int temp = ans;
    while((temp&1) == 0) {
        pos++;
        temp = (temp>>1);
    }

    // Filter out the number from the array wich have set bit in the same position
    int setA = 0;
    int setB = 0;
    int mask = (1<<pos);    

    for(int i = 0; i < static_cast<int>(arr.size()); ++i) {
        if((arr[i]&mask) > 0)
            setA = setA^arr[i];
        else
            setB = setB^arr[i];
    }

    std::cout << setA << " " << setB << std::endl;

}

int main(void) {

    std::vector<int> arr = {1,3,5,4,3,1,5,7}; // {4,7}
    uniqueTwoNumbers(arr);

}