#include <iostream>
using namespace std;

int main(){
    int megabytes, iterations;
    cin >> megabytes >> iterations;
    int total = megabytes;
    int current;
    for(int i = 0; i< iterations; i++ ){
        cin >> current;
        total -= current;
        total += megabytes;
    }
    cout << total;

}