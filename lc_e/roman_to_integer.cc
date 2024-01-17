#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> map;
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;
    int prev = map[s[1]], current = 0, count = 0;
    for(int i=0; i<s.size(); i++) {
        cout << map[s[i]] << '\n';
        cout << map[s[i+1]] << '\n';
        cout << endl;
        if(map[s[i]] < map[s[i+1]]) {
            current -= map[s[i]];
        }
        else{
            current += map[s[i]];
            count += current;
            current = 0;
        }
    }

    return count;
}

int main() {
    // string s = "III";
    // string s = "LVIII";
    // string s = "MCMXCIV";
    string s = "MMMDCCCLXXXVIII";
    cout << romanToInt(s);
}