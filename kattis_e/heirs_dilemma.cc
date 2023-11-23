#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int lower_bound, upper_bound;
    cin >> lower_bound >> upper_bound;
    int count = 0;
    bool did_hit = false;
    for(int i=lower_bound; i<=upper_bound; i++){
        for(auto j: to_string(i)){
            if(i % (j-'0') > 0) {
                did_hit = true;
                break;
            }
        }
        if(!did_hit)count++;
        did_hit=false;
    }
    cout << count;
}