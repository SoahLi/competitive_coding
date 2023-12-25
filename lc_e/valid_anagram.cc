#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

//Submission 1: PASSING
/*
 * Time Complexity: O(nlogn)
 * Space Complexity: O(1)
 * Completed in: 5 seconds
*/
// bool isAnagram(string s, string t){
//     sort(s.begin(), s.end());
//     sort(t.begin(), t.end());
//     return s == t;
// }

bool isAnagram(string s, string t){
    unordered_set<char> sCharacters;
    for(char character: s){
        sCharacters.insert(character);
    }

    for(char character: t){
        if(sCharacters.find(character) != sCharacters.end()){
            sCharacters.erase(character);
            for(char c: t){
                cout << t << '\n';
            }
        }
        else
            return false;
    }

    return sCharacters.empty();

}


int main(){
    string s1 = "anagram";
    string s2 = "nagaram";
    cout << isAnagram(s1, s2);
}