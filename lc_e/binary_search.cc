#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
  
  int p1 = 0;
  int p2 = (nums.size()-1)/2;
  int p3 = nums.size()-1;
  if(nums[p1] == target) return p1;
  if(nums[p2] == target) return p2;
  if(nums[p3] == target) return p3;
  
  while(p1 < p3) {
    if(nums[p2] == target)
      return p2;
    else if(nums[p2] > target)
      p3 = p2;
    else
      p1 = p2;

     p2 = (p1 + p3)/2;
  }

  return -1;
}

int main() {
  vector<int> nums{-1,0,3,5,9,12};
  vector<int> nums{2, 5}
  {0, 1}
  // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
  // int target = 2; 
  int target = 9;
  cout << search(nums, target);
}
