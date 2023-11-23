#include <iostream>
using namespace std;

int main(){
    int sweet, sour;
    while(cin >> sweet >> sour){
        if(sweet==0 && sour==0){
            break;
        }
        if((sweet + sour) == 13){
            cout << "Never speak again." <<'\n';
            continue; 
        }   else if(sweet > sour) {
            cout << "To the convention." << '\n';
            continue;
        }   else if(sweet < sour) {
            cout << "Left beehind." << '\n';
            continue;
        }   else if(sour == sweet){
            cout << "Undecided." << '\n';
            continue;
        }

    }
    return 0;
}
