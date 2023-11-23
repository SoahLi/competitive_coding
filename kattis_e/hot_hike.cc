#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    cin >> arr[0] >> arr[1] >> arr[2];
    int total = 0;
    int best = max(arr[0],arr[2]);
    int best_idx = 1;
    for(int i=1; i<n-2;i++){
        cin >> arr[i+2];
        total = max(arr[i], arr[i+2]);
        if(total < best){
            best = total;
            best_idx = i+1;
        }
    }
    cout << best_idx << " " << best;
}