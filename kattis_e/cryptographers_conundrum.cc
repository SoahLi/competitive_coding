//cryptographers_conundrum.cc
#include <iostream>
#include<string>
#include <map>
using namespace std;

int main(){
    string s;
    cin >> s;
    int total = 0;
    for(int i=0; i<s.length(); i++){
        if(i%3==0 && s[i] == 'R') total += 1;
        else if(i%2 == 0 && s[i] == 'E') total += 1;
        else if(s[i] == 'P') total += 1;
    }
    cout << s.length() - total;
}