#include <iostream>
#include <iomanip>
#include <math.h>
typedef long long ll;
using namespace std;

int main(){
    ll area;
    cin >> area;
    long double length = sqrt(area);
    long double perimater = 4 * length;
    cout << setprecision(7) << perimater;
}