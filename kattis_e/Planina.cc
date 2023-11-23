#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;

int main(){
    ll iter, base;
    cin >> iter;
    base = pow(2, iter) + 1;
    cout << base*base;
}
