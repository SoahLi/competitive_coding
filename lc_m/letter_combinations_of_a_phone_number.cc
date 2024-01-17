#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
std::unordered_map<int, std::string> letters{{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};


void helper(string current, int pos, string& digits, vector<string>& ans) {
    if(pos == digits.size()){
        ans.push_back(current);
        return;
    }
    else {
        for(char i : letters[digits[pos]-'0']) {
            current.push_back(i);
            helper(current, pos+1, digits, ans);
            current.pop_back();
        }
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    helper("", 0, digits, ans);
    return ans;
}


int main() {
    string digits = "234";
    vector<string> result = letterCombinations(digits);
    cout << result.size() << '\n';
    for(string combination : result) {
        cout << combination << " ";
    }
}