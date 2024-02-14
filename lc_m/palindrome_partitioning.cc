#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
I literally have the right answer I just can't figure out how to code it
*/
// bool isValidPalindrome(string pal) {
//     int n= pal.size();
//     string s1 = pal.substr(0, n/2);
//     string s2 = pal.substr(n/2, n/2);
//     if(s1 == s2)
//         return true;
//     else
//         return false;
// }

// void helper(string s, vector<string> current, vector<vector<string>>& result) {
//     if(s.size() == 0) {
//         result.push_back(current);
//         return;
//     }
    

//     string comp;
//     for(int i=s.size(); i>=0; i--) {

//         comp = s.substr(0, i);
//         cout << s.size() << '\n';
//         cout << comp << '\n';
//         if(isValidPalindrome(comp)) {
//             cout << "recursing" << '\n';
//             current.push_back(comp);
//             helper(comp.substr(i-1), current, result);
//             current.pop_back();
//         }
//     }
// }

// vector<vector<string>> partition(string s) {
//     vector<vector<string>> result;
//     vector<string> current;
//     helper(s, current, result);
//     return result;
// }

// class Solution {
// public:
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> res;
//         vector<string> path;
//         helper(0, s, path, res);
//         return res;
//     }

//     void helper(int index, string s, vector<string> path, vector<vector<string>>& result) {
//         if(index >= s.size()) {
//             result.push_back(path);
//             return;
//         }

//         for(int i=index; i<s.size(); i++) {
//             if(isPalindrome(s, index, i)) {
//                 path.push_back(s.substr(index, i-index+1));
//                 helper(i+1, s, path, result);
//                 path.pop_back();
//             }
//         }
//     }


//     bool isPalindrome(string s, int start, int end){
//         while(start <= end){
//             if(s[start++] != s[end--]) return false;
//         }
//         return true;
//     }

// };
























































bool isPalindrome(const std::string& str) {
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return str == reversed;
}

void helper(int i, string& s, vector<string> current, vector<vector<string> >& result) {
    if(i >= s.size()) {
        result.push_back(current);
        return;
    }

    string str;
    for(int j=1; j<=(s.size()-i); j++) {

        str = s.substr(i, j);
        if(isPalindrome(str)) {

            current.push_back(str);
            helper(i+j, s, current, result);
            current.pop_back();            

        }
    }

}

vector<vector<string> > partition(string s) {
    vector<vector<string> > result;
    vector<string> current;
    string str;
    for(int i=0; i<s.size(); i++) {
        str = s.substr(0, i+1);
        if(isPalindrome(str)) {
            current.clear();
            current.push_back(str);
            helper(i+1, s, current, result);
        }
    }

    return result;
}


int main() {
    string str = "abbab";
    vector<vector<string> > ans = partition(str);
    for(vector<string> a : ans) {
        for(string part : a) {
            cout << part << " ";
        }
        cout << endl;
    }

}
