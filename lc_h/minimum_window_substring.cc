#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include<vector>
using namespace std;




// string minWindow(string s, string t){
//     //loop through the string starting at each letter
//         //if all the letters are detected, compare to min
//     map<char, int> tIndexes;
//     int count = 0;
//     for(int i=0; i<t.length(); i++){
//         tIndexes[t[i]] = -5;
//     }
//     string min = s;
//     for(int i=0; i<s.length(); i++){
//         if(!(tIndexes.find(s[i]) == tIndexes.end())) {
//             cout << "found" << '\n';
//             cout << s[i] << '\n';
//             tIndexes[s[i]] = i;
//             count++;
//             //do I want to check before or after?
//             if(count >= t.length()){
//                 int distance = (tIndexes.rbegin()->second) - (tIndexes.begin()->second);
//                 cout <<(tIndexes.rbegin()->second) << '\n';
//                 cout << (tIndexes.begin()->second) << '\n';
//                 cout << distance << '\n';
//                 if(distance < min.length()) {
//                     min = s.substr((tIndexes.begin()->second), (tIndexes.rbegin()->second)+1);
//                     cout << min << '\n';
//                 }
//             }
//         }
//     }
//     return min;
// }

// int main(){
//     string s = "ADOBECODEBANC";
//     string t = "ABC";
//     cout << minWindow(s, t);
// }



//ONLINE ANSWER
// string minWindow(string s, string t) {
//     if(t == ""){
//         return "";
//     }

//     unordered_map<char , int> t_counter , window ;

//     for(auto x : t){
//         t_counter[x] = 1 + t_counter[x];
//     }

//     int have = 0 , need = t_counter.size() , ans_size = INT_MAX;
//     vector<int> ans;
//     int left = 0 ;

//     for(int right = 0 ; right < s.size() ; right++){
//         window[s[right]] = 1 + window[s[right]] ;

//         if(t_counter.find(s[right]) != t_counter.end() && window[s[right]] == t_counter[s[right]]){
//             cout << "found " << 
//             have++;
//         }

//         while(have == need){
//             if((right - left + 1) < ans_size){
//                 ans = {left , right} ;
//                 ans_size = right - left + 1 ;
//             }
            
//             window[s[left]] -= 1 ;
//             if(t_counter.find(s[left]) != t_counter.end() && window[s[left]] < t_counter[s[left]]){
//                 have--;
//             }
//             left++ ;
//         }  
//     }

//     return ans_size != INT_MAX ? s.substr(ans[0] , ans[1]-ans[0]+1) : "" ;
    
    
// }

// int main(){
//     cout << minWindow("ADOBECODEBANC", "ABC");
// }