#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;


//Idea 1: pointers
// vector<int> twoOutOfThree(vector<int>& nums1, vector<int> nums2, vector<int> nums3) {
//     sort(nums1.begin(), nums1.end());
//     sort(nums2.begin(), nums2.end());
//     sort(nums3.begin(), nums3.end());
//     unordered_set<int> result; 

//     int p1 = 0, p2 = 0, p3 = 0;

//     while(true) {
//         if(p1 < nums1.size()){
//             if(compare(n1[p1], n2[p2], n3[p3])) {
//                 result.insert(n1[p1]);
//             }
//         }
//     }
//     int n = max(nums1.size(), max(nums2.size(), nums3.size()));
//     int n1 = nums1[0], n2 = nums2[0], n3 = nums3[0];
//     for(int i=0; i<n ; i++) {
//         if(n1 == n2 || n1 == n3){
//             result.insert(n1);
//         }
//         else if(n2 == n3) {
//             result.insert(n3);
//         }

//     }
// }

// vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
//     unordered_map<int, int> elementFrequency;
//     unordered_set<int> unique;
//     for(int num : nums1) {
//         unique.insert(num);
//     }
//     for(int num : unique) {
//         elementFrequency[num]++;
//     }
//     unique.clear();
//     for(int num : nums2) {
//         unique.insert(num);
//     }
//     for(int num : unique) {
//         elementFrequency[num]++;
//     }
//     unique.clear();
//     for(int num : nums3) {
//         unique.insert(num);
//     }
//     for(int num : unique) {
//         elementFrequency[num]++;
//     }

//     vector<int> result;
//     for(auto& node : elementFrequency) {
//         if(node.second > 1) result.push_back(node.first);
//     }

//     return result;
// }

// vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
//     unordered_map<int, unordered_set<string>> elementFrequency;
//     for(int num : nums1) {
//         elementFrequency[num].insert("n1");
//     }
//     for(int num : nums2) {
//         elementFrequency[num].insert("n2");
//     }
//     for(int num : nums3) {
//         elementFrequency[num].insert("n3");
//     }

//     vector<int> result;
//     for(auto& node : elementFrequency) {
//         if(node.second.size() > 1) result.push_back(node.first);
//     }

//     return result;
// }

vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    sort(nums3.begin(), nums3.end());
    unordered_map<int, int> elementFrequency;
    int prev = INT_MIN;
    for(int num : nums1) {
        if(prev != num) elementFrequency[num]++;
        prev = num;
    }
    prev = INT_MIN;
    for(int num : nums2) {
        if(prev != num) elementFrequency[num]++;
        prev = num;
    }
    prev = INT_MIN;
    for(int num : nums3) {
        if(prev != num) elementFrequency[num]++;
        prev = num;
    }

    vector<int> result;
    for(auto& node : elementFrequency) {
        if(node.second > 1) result.push_back(node.first);
    }

    return result;
}

int main() {
    vector<int> nums1{1,1,3,2};
    vector<int> nums2{2, 3};
    vector<int> nums3{3};
    vector<int> result = twoOutOfThree(nums1, nums2, nums3);
    for(int num : result) {
        cout << num << " ";
    }
}