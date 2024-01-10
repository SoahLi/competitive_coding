#include <iostream>
#include <string>
using namespace std;

vector<string> divideString(string s, int k, char fill) {
    vector<string> result;
    string current = "";
    int i=0, size=s.size();

    while(i < size) {
        if(current.size() == k) {
            result.push_back(current);
            current = "";
        }
        current += s[i];
        i++;
    }
    

    if(current.size() > 0) {
        // while(current.size() != k) {
        //     current.push_back(fill);
        // }
        for(int j=current.size(); j<k; j++){
            current += fill;
        }
        result.push_back(current);
    }

    return result;
}

int main() {
    // string s = "abcdefghi";
    // int k = 3;
    // char fill = 'x';

    string s = "abcdefghij";
    int k = 3;
    char fill = 'x';
    vector<string> answer = divideString(s, k, fill);
    for(string group : answer){
        cout << group << " ";
    }
}