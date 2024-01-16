/*
I am confused as to why this problem has a 50% acceptance rate, the solution seems pretty intutitive to me. 
*/
#include <iostream>
#include <vector>
using namespace std;


int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int result = -1;
    int p1 = 0, p2 = 0;
    while(p1 < nums1.size() && p2 < nums2.size()) {
        if(nums1[p1] == nums2[p2]) 
            return nums1[p1];
        else if(nums1[p1] < nums2[p2])
            p1++;
        else
            p2++;
    }

    return -1;
}

int main() {
    //example 1
    // vector<int> nums1{1, 2, 3};
    // vector<int> nums2{2, 4};
    //example 2: two matching, return 2
    // vector<int> nums1{1, 2, 3, 6};
    // vector<int> nums2{2, 3, 4, 5};
    //case 3: no matching
    // vector<int> nums1{1, 2, 3, 6};
    // vector<int> nums2{7, 8, 9};
    //case 4: last numbers match
    vector<int> nums1{1, 4, 6, 8};
    vector<int> nums2{2, 3, 8};
    cout << getCommon(nums1, nums2);
}