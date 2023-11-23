#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
    double n;
    cin >> n;
    cout << fixed << setprecision(0)<< round(n*(1000*(5280.0/4854.0)));
}