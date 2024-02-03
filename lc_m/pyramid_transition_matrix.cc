#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

bool findTop(string bottom, string next, int index, unordered_map<string, vector<char>>& map) {
    if(bottom.size() == 1) 
        return true;

    if(index == bottom.size()-1) 
        return findTop(next, "", 0, map);

    for(char c : map[bottom.substr(index, 2)]) {
        if(findTop(bottom, next+c, index+1, map))
            return true;
    }

    return false;
}

bool pyramidTransition(string bottom, vector<string>& allowed) {
    bool result = false;
    unordered_map<string, vector<char>> map;
    for(int i=0; i<allowed.size(); i++) {
        map[allowed[i].substr(0, 2)].push_back(allowed[i].back());
    }
    return findTop(bottom, "", 0, map);
}

int main() {
    string bottom = "BCD";
    vector<string> allowed{"BCC","CDE","CEA","FFF"};
    cout << pyramidTransition(bottom, allowed);
}