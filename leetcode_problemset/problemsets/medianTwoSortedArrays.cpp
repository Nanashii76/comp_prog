#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {

    vector<int> sorted(nums1.size()+nums2.size());
    int i = 0, j = 0, k = 0;

    while (i < (int)nums1.size() and j < (int)nums2.size())
        if (nums1[i] <= nums2[j])
            sorted[k++] = nums1[i++];
        else
            sorted[k++] = nums2[j++];
    
    while(i < (int)nums1.size())
        sorted[k++] = nums1[i++];
     
    while(j < (int)nums2.size())
        sorted[k++] = nums2[j++];

    int size = sorted.size();
    double value = 0;
    if(size&1)
        value = sorted[size/2]; 
    else {
        value = (sorted[size/2] + sorted[(size/2)-1]) / 2.0;
    }

    return value;
    
}

int main(){

    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};

    cout << findMedianSortedArrays(nums1,nums2) << endl;
    return 0;

}