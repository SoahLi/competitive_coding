#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

//first attempt
/*int main(){
    int iterations;
    cin >> iterations;
    if(iterations == 1) {
        cout << 1;
        return 0;
    }
    long double total=0;
    long double denominator;
    for(int i=0; i<=iterations; i++){
        denominator=1;
        for(int j=0; j<i; j++){
            denominator *= j+1;
        }
        total += (1/denominator);
    }
    cout << fixed << setprecision(15) << total;
}*/

//second attempt

int main(){
    int n;
    cin >> n;
    long double t=1, f=1;
    for(int i=1; i<=n; i++){
        f *= i;
        t += 1.0/f;
    }
    //does this number have to be 15?
    cout << fixed << setprecision(15)  << t;
}