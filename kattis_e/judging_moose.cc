#include <iostream>
using namespace std;

int main(){
    int left=0, right=0;
    cin >> left >> right;
    if((left == 0) && (right == 0)){
        cout << "Not a moose";
        return 0;
    }
    if (right == left){
        cout << "Even " << right*2;
        return 0;
    }   else {
        if(left > right){
            cout << "Odd " << left*2;
            return 0;
        }   else {
            cout << "Odd " << right*2;
            return 0;
        }
    }
}