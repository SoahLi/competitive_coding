#include <iostream>
#include <vector>
using namespace std;

//Time complexity: O(n * m)
//Space complexity: O(n * m)
// int uniquePaths(int m, int n) {
//     int unique[n][m];
//     for(int i=0; i<m; i++) {
//         unique[n-1][i] = 1;
//     }
//     for(int i=0; i<n; i++) {
//         unique[i][m-1] = 1;
//     }

//     for(int i=n-2; i>=0; i--) {
//         for(int j=m-2; j>=0; j--) {
//             unique[i][j] = unique[i+1][j] + unique[i][j+1];
//         }
//     }

//     return unique[0][0];
// }

int uniquePaths(long long m, unsigned long long n) {
    if(m == 1 || n == 1) return 1;
    
    int greater = max(m, n), lesser = min(m, n);
    vector<int> unique{0, 1, 0};
    vector<int> v;

    
    for(int i=0; i<greater-2; i++) {
        v.push_back(0);
        for(int j=0; j<unique.size()-1; j++) {
            v.push_back(unique[j] + unique[j+1]);
        }
        v.push_back(0);
        unique = v;
        v.clear();
    }

    
    for(int i=0; i<lesser; i++) {
       for(int j=0; j<unique.size()-1; j++) {
            v.push_back(unique[j] + unique[j+1]);
        }
        unique = v;
        v.clear();
    }
    return unique[0];
}


    



int main(){
    cout << uniquePaths(1, 1) << '\n';
    cout << uniquePaths(1, 2) << '\n';
    cout << uniquePaths(1, 3) << '\n';
    cout << uniquePaths(2, 2) << '\n';
    cout << uniquePaths(2, 3) << '\n';
    cout << uniquePaths(2, 4) << '\n';
    cout << uniquePaths(3, 3) << '\n';
    cout << uniquePaths(3, 4) << '\n';
    cout << uniquePaths(3, 5) << '\n';
    return 0;
}





















// // #include <iostream>
// // #include <vector>
// // using namespace std;

// // int uniquePaths(int m, int n) {
    
// // }
// // int main() {
    
// // }
