#include <iostream>
using namespace std;


int main(){
    int m=0,a=0,b=0,c=0;
    cin>>m>>a>>b>>c;
    if((a+b+c) < (m*2)){
        cout << "possible";
    }   else {
        cout << "impossible";
    }
}