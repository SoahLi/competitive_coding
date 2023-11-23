#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
    double r, c;
    cin >> r >> c;
    //want the area of the crust over the area of cheese
    long double percentage = ((M_PI*(pow((r-c), 2))/(M_PI*(pow(r, 2)))))*100;
    cout << fixed << percentage;
}