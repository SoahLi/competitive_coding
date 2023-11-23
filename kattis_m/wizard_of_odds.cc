#include <iostream>
#include <math.h>
#include <string>

using namespace std;
typedef long long ll;

int main(){
    string n;
    int k;
    getline(cin, n);
    for(int i=0; i < n.length(); i++){
        if(n[i] == ' '){
            k = stoll(n.substr(i, n.length()));
            n = n.substr(0, i);
            cout << n << '\n';
            cout << k << '\n';
        }
    }
    ll first_half = 0;
    ll second_half = 0;
    if(n.length() > 14){
        first_half = stoll(n.substr(0, n.length()/2+1)) ;
        second_half = stoll(n.substr(n.length()/2, n.length()));
        if((log(first_half) + log(second_half)) < k){
            cout << "Your wish is granted!";
        }   else {
            cout << "You will become a flying monkey!";
        }
    }   else {
            ll number = stoll(n);
            if(log(number) < k){
                cout << "Your wish is granted!";
            }   else {
                cout << "You will become a flying monkey!";
            }
    }
}