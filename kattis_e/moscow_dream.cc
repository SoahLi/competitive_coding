#include <iostream>
using namespace std;

int main(){
    int a=0,b=0,c=0, n=0;
    cin >> a >> b >> c >> n;
    if((a > 0 && b > 0 && c > 0 && n>=3 && (a+b+c >= n))){
        cout << "YES";
    }   else {
        cout << "NO";
    }
}