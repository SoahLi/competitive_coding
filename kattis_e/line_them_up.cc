#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
if
int main(){
    int n;
    cin >> n;
    cin.ignore();
    vector<string> names;
    string c;
    for(int i=0; i<n; i++){
        getline(cin, c);
        names.push_back(c);
    }
    if(is_sorted(names.begin(), names.end())) cout << "INCREASING";
    else{
        reverse(names.begin(), names.end());
        if(is_sorted(names.begin(), names.end())) cout << "DECREASING";
        else cout << "NEITHER";
    }
}

