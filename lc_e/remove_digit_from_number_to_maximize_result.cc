#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string removeDigit(string number, char digit) {
    vector<string> nums;
    string temp = number;

    for(int i=0; i<number.size(); i++) {
        if(number[i] == digit) {
            temp = number;
            temp.erase(temp.begin()+i);
            nums.push_back(temp);
        }
    }
        
    sort(nums.begin(), nums.end());

    return nums.back();
}   

int main() {
    // string number = "1231";
    // char digit = '1';
    // string number = "551";
    // char digit = '5';
    string number = "123";
    char digit = '3';
    cout << removeDigit(number, digit);
}