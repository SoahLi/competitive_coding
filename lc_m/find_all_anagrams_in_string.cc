#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// bool isAnagram(int i, std::unordered_multiset<char>& chars, string &s) {
//   if (chars.empty())
//     return true;

//   std::unordered_multiset<char>::iterator it;

//   it = chars.find(s[i]);
//   if(it == chars.end()) {
//     return false;
//   }
//   else chars.erase(it);

//   return isAnagram(++i, chars, s);
// }

// vector<int> findAnagrams(string s, string p) {
//   vector<int> result;

//   std::unordered_multiset<char> chars;
//   for (char l : p) {
//     chars.insert(l);
//   }
//   std::unordered_multiset<char> copy = chars;

//   for (int i = 0; i < s.size(); i++) {
//     if (isAnagram(i, chars, s)) {
//       result.push_back(i);
//     }
//     chars = copy;
//   }

//   return result;
// }
vector<int> findAnagrams(string s, string p) {
  if (p.size() > s.size())
    return vector<int>();

  vector<int> result;
  sort(p.begin(), p.end());
  int i = 0, n = p.size();
  string comp = s.substr(0, n);
  sort(comp.begin(), comp.end());
  if(comp == p) result.push_back(0);
  i++;
  int it;

  while (i < s.size() - n + 1) {
    it = comp.find(s[i-1]);
    comp.erase(it);
    comp.push_back(s[i]);
    sort(comp.begin(), comp.end());
    
    if (comp == p) {
      result.push_back(i);
    }

    i++;
  }

  return result;
}
int main() {
  string s = "cbaebabacd";
  string p = "abc";
  vector<int> result = findAnagrams(s, p);
  for (int r : result) {
    cout << r << " ";
  }
}
