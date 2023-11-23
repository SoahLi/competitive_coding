#include <iostream>
using namespace std;

int main(){
    int g[4];
    int e[4];
    cin >> g[0] >> g[1] >> g[2] >> g[3];
    cin.ignore();
    cin >> e[0] >> e[1] >> e[2] >> e[3];
    int sum1=0, sum2=0;
    for(int i =0; i<4; i++){
        sum1+=g[i];
        sum2+=e[i];
    }
    if(sum1 > sum2) cout << "Gunnar";
    else if(sum2 > sum1) cout << "Emma";
    else cout << "Tie";
}