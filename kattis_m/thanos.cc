
#include <iostream>
#include <math.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int main(){
    ll t, p, r, f;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> p >> r >> f;
        ld num = floor(log(f/p)/log(r));
        ll fixed_num = num < 0 ? 0 : (ll)(num + 1) ;
        cout << fixed_num << '\n';
    }
    return 0;
}







// #include <iostream>
// using namespace std;
// typedef long long ll;

// int main(){
//     ll t, p, r, f;
//     cin >> t;
//     ll count = 0;
//     for(int i=0; i<t; i++){
//         cin >> p >> r >> f;
//         count = 0;
//         while(p <= f){
//             p *= r;
//             count++;
//         }
//         cout << count << '\n';
//     }
//     return 0;
// }