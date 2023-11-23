#include <iostream>
#include <unordered_map>
#include <math.h>
using namespace std;

int main(){
    unordered_map<int, int> companies;
    int num_companies=0, requests=0;
    cin >> num_companies >> requests;
    for(int i=0; i<num_companies; i++){
        cin >> companies[i+1];
    }   
    int request_type, x, y;
    for(int i=0; i<requests; i++){
        cin >> request_type;
        if(request_type == 1){
            cin >> x;
            cin >> companies[x];
        }
        else if(request_type == 2){
            cin >> x;
            cin >> y;
            cout << abs(companies[y] - companies[x]) << '\n';
        }
    }
}