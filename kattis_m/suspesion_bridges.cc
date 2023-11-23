#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int d, s;
    cin >> d >> s;
    double a = exp(-(log(2)+ log(s)));
    cout << a << '\n';
    cout << "1" << '\n';
    double length = 2*a * sinh(d/(2*a));
    cout << "2 " << '\n';
    cout << length;
}