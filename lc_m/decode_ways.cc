#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Submission 1 Time Limit Exceeded
// int helper(int currentIndex, int stringLength, string &s){
//     if(currentIndex == stringLength) return 1;
//     else if(stringLength - currentIndex >= 2){
//         if(stoi(s.substr(currentIndex, 2)) >= 10 && stoi(s.substr(currentIndex, 2)) <= 26){
//             if(stoi(s.substr(currentIndex,1)) > 0 && stoi(s.substr(currentIndex, 1)) <= 26) {
//                 cout << "returning double" << '\n';
//                 return helper(currentIndex+1, stringLength, s) + helper(currentIndex+2, stringLength, s);
//             }
//             else {
//                 cout << " return single in double" << '\n';
//                 return helper(currentIndex+2, stringLength,s);
//             }
//         }
//         else if(stoi(s.substr(currentIndex,1)) > 0 && stoi(s.substr(currentIndex, 1)) <= 26) {
//             return helper(currentIndex+1, stringLength, s);
//         }
//         else return 0;
        
//     }
//     else if(stringLength - currentIndex >= 1) {
//         if(stoi(s.substr(currentIndex,1)) > 0 && stoi(s.substr(currentIndex, 1)) <= 26) {
//             return helper(currentIndex+1, stringLength, s);
//         }
//         else return 0;
//     } 
//     else return 0;
// }


// int numDecodings(string s){
//     return helper(0, s.length(), s);    
// }



// int main() {
//     // string encodedNumber = "11106";
//     // string encodedNumber = "12";
//     // string encodedNumber = "226";
//     // string encodedNumber = "06";
//     cout << numDecodings(encodedNumber);
// }

//Submission 2 Time Limit Exceeded
// int helper(int currentIndex, int stringLength, string &s){
//     if(currentIndex > stringLength) return 0;
//     else if(currentIndex == stringLength) return 1;
//     else{
//         if(stoi(s.substr(currentIndex,1)) > 0 && stoi(s.substr(currentIndex, 1)) <= 26){ 
//             if(stoi(s.substr(currentIndex, 2)) >= 10 && stoi(s.substr(currentIndex, 2)) <= 26)
//                 return helper(currentIndex+1, stringLength, s) + helper(currentIndex+2, stringLength, s);
//             else return helper(currentIndex+1, stringLength, s);
//         }
//         else return 0;
//     }
// }


// int numDecodings(string s){
//     return helper(0, s.length(), s);    
// }



// int main() {
//     string encodedNumber = "11106";
//     // string encodedNumber = "12";
//     // string encodedNumber = "226";
//     // string encodedNumber = "06";
//     cout << numDecodings(encodedNumber);
// }

// //Submission 3 PASSING
// /*
//  * Time complexity: Unknown
//  * Space complexity: O(n)
// */
// int helper(int currentIndex, int stringLength, string &s, vector<int> &mem){
//     if(mem[currentIndex] > -1) return mem[currentIndex];
//     if(currentIndex > stringLength) return 0;
//     else if(currentIndex == stringLength) return 1;
//     else{
//         if(stoi(s.substr(currentIndex,1)) > 0 && stoi(s.substr(currentIndex, 1)) <= 26){ 
//             if(stoi(s.substr(currentIndex, 2)) >= 10 && stoi(s.substr(currentIndex, 2)) <= 26)
//                 return mem[currentIndex] = helper(currentIndex+1, stringLength, s, mem) + helper(currentIndex+2, stringLength, s, mem);
//             else return mem[currentIndex] = helper(currentIndex+1, stringLength, s, mem);
//         }
//         else return mem[currentIndex] = 0;
//     }
// }


// int numDecodings(string s){
//     vector<int> mem(s.length()+1, -1);
//     mem[s.length()] = 1;
//     return helper(0, s.length(), s, mem);    
// }

// int main() {
//     // string encodedNumber = "11106";
//     // string encodedNumber = "12";
//     // string encodedNumber = "226";
//     // string encodedNumber = "06";
//     string encodedNumber = "111101";
//     cout << numDecodings(encodedNumber);
// }

//Submission 4 PASSING
/*
 * Time complexity: O(n)
 - Processes each indecy once
 *Space Complexity: O(n)
*/
int helper(int currentIndex, int stringLength, string &s, vector<int> &mem){
    cout << "Current Index is " << currentIndex << '\n';
    for(int i=0; i<mem.size(); i++){
        cout << mem[i] << " ";
    }
    cout << '\n';
    if(mem[currentIndex] > -1) return mem[currentIndex];
    if(currentIndex > stringLength) return 0;
    else{
        if(stoi(s.substr(currentIndex,1)) > 0 && stoi(s.substr(currentIndex, 1)) <= 26){ 
            mem[currentIndex] = helper(currentIndex+1, stringLength, s, mem);
            if(stoi(s.substr(currentIndex, 2)) >= 10 && stoi(s.substr(currentIndex, 2)) <= 26)
                return mem[currentIndex] += helper(currentIndex+2, stringLength, s, mem);
            else return mem[currentIndex] = helper(currentIndex+1, stringLength, s, mem);
        }
        else return mem[currentIndex] = 0;
    }
}


int numDecodings(string s){
    vector<int> mem(s.length()+1, -1);
    mem[s.length()] = 1;
    return helper(0, s.length(), s, mem);    
}

int main() {
    // string encodedNumber = "11106";
    // string encodedNumber = "12";
    // string encodedNumber = "226";
    // string encodedNumber = "06";
    string encodedNumber = "111101";
    cout << numDecodings(encodedNumber);
}