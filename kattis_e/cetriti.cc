#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int> n;
    int c;
    for(int i=0; i<3; i++){
        cin >> c;
        n.push_back(c);
    }
    int difference1, difference2;
    unordered_map<int ,int> test;
    sort(n.begin(), n.end());
    difference1 = n[2] - n[1];
    difference2 = n[1] - n[0];
    if(difference1 == difference2) {
        cout << n[2] + difference1;
    }
    else if(difference1 < difference2) {
        cout << n[0]+difference1;
    }
    else {
        cout << n[1]+difference2;
    }
}

