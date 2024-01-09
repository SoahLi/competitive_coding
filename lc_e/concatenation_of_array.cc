#include <iostream>
#include <vector>
using namespace std;

vector<int> getConcatenation(vector<int>& nums) {
    nums.insert(nums.end(), nums.begin(), nums.end());
    return nums;
}

int main() {
    vector<int> nums{1, 2, 3};
    vector<int> result = getConcatenation(nums);
    for(int num: result) {
        cout << num << " ";
    }
}