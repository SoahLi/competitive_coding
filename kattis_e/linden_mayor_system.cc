#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    int num_rules, iterations;
    string current_rule, root;
    cin >> num_rules >> iterations;

    unordered_map<char, string> rules;
    for(int i = 0; i < num_rules; i++) {
        char c;
        cin >> c;
        cin.ignore(4);
        string s;
        cin >> s;
        rules[c] = s;
    }
    cin >> root;
    string result;
    for(int i =0; i<iterations; i++){
        for(auto j : root){
            //if there is a rule for current character
            if(rules.count(j) > 0) {
                result += rules[j];
            }
            //if there is not a rule for current character
            else {
                result += j;
            }

        }
        root = result;
        result = "";
    }
    cout << root;
}