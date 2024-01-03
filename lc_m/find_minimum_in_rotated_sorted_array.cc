#include <iostream>
#include <vector>
using namespace std;
//Submission 1: Wrong Answer
// int findMinHelper(vector<int> nums, int pointer) {
//     if(pointer + 1 < nums.size() && nums[pointer+1] < nums[pointer]) {
//         pointer = nums.size() - pointer;
//         return findMinHelper(nums, pointer);
//     }
//     else if(pointer-1 >= 0 && nums[pointer-1] < nums[pointer]) {
//         pointer = pointer/2;
//         return findMinHelper(nums, pointer);
//     }
//     else {
//         return nums[pointer];
//     }
// }

// int findMin(vector<int>& nums) {
// //look at middle elemnt of arr
// //if elemnt to the left is smaller
//     //recurse to left
// //if elemnt to the right is smaller
//     //recuse to right
// //else
//     //you have found the smallest element
//     int pointer = nums.size()/2;
//     return findMinHelper(nums, pointer);
// }





int findMin(vector<int>& nums) {
    int result;
    int left = 0, right = nums.size()-1, middle = nums.size()/2;
    result = nums[middle];
    //6, 7, 1, 2  
    while(left+1 < right) {
        cout << nums[left] << " " << nums[middle] << " " << nums[right] << " " << result << '\n';
        if(nums[left] < nums[right]) return nums[left];


        if(nums[right] > nums[middle]) {
            right = middle;
            middle = (left + middle)/2;
        }
        else {
            left = middle;
            middle = (middle + right)/2;
        }

        result = min(result, nums[middle]);
    }

    return min(result, min(nums[left], nums[right]));
}

int main() {
    // vector<int> nums{3, 4, 5, 1, 2};
    // cout << findMin(nums);

    // vector<int> nums{4,5,6,7,0,1,2};
    // cout << findMin(nums);

    // vector<int> nums{11, 13, 15, 17};
    // cout << findMin(nums);

    // vector<int> nums{10};
    // cout << findMin(nums);

    // vector<int> nums{13, 11, 15, 17};
    // cout << findMin(nums);

    // vector<int> nums{1, 2};
    // cout << findMin(nums);

    // vector<int> nums{2,3,4,5,1};
    // cout << findMin(nums);

    // vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    // vector<int> nums{7, 1, 2, 3, 4, 5, 6};
    // vector<int> nums{6, 7, 1, 2, 3, 4, 5};
    // vector<int> nums{5, 6, 7, 1, 2, 3, 4};
    // vector<int> nums{3, 4, 5, 6, 7, 1, 2};
    // vector<int> nums{2, 3, 4, 5, 6, 7, 1};

    cout << findMin(nums);

}