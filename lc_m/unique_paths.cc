#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Submission 1: Time limit exceeded
// int helper(int i, int j, int m, int n, vector<vector<int> > arr){
//     if(i == m && j == n){
//         return 1;   
//     }
//     else if(i == m){
//         return helper(i, j+1, m, n, arr);
//     }
//     else if(j == n){
//         return helper(i+1, j, m, n, arr);
//     }
//     else {
//         return helper(i+1, j, m, n, arr) + helper(i, j+1, m, n, arr);
//     }
// }

// int uniquePaths(int m, int n){
//     vector<vector<int> > arr(m, vector<int>(n, 0));
//     return helper(0, 0, m-1, n-1, arr);
// }



// int main(){
//     cout << uniquePaths(2, 3);
//     return 1;
// }

// Submission 2: Time limite exceeded
// int helper(int i, int j, int m, int n, vector<vector<int> > arr){
//     if(i == m || j == n){
//         return 1;   
//     }
//     // else if(i == m){
//     //     return helper(i, j+1, m, n, arr);
//     // }
//     // else if(j == n){
//     //     return helper(i+1, j, m, n, arr);
//     // }
//     else {
//         return helper(i+1, j, m, n, arr) + helper(i, j+1, m, n, arr);
//     }
// }

// int uniquePaths(int m, int n){
//     vector<vector<int> > arr(m, vector<int>(n, 0));
//     return helper(0, 0, m-1, n-1, arr);
// }



// int main(){
//     cout << uniquePaths(, );
//     return 0;
// }

/*
 *Submission 4 PASSING
 *Time complexity: O(m * n): nested for loop + assign each variable to 1 at the beginning
 *Space complexity: O(n)
*/
// int uniquePaths(int m, int n){
//     int arr[n];
//     for(int i=0; i<n; i++) arr[i] = 1;
//     for(int i=0; i<m-1; i++){
//         for(int j=n-2; j>=0; j--){
//             arr[j] += arr[j+1];
//         }
//     }
//     return arr[0];
// }


// int main(){
//     cout << uniquePaths(3, 7);
//     return 0;
// }

/*
 *Submission 5 PASSING
 *Time complexity: O(m * n): nested for loop + assign each variable to 1 at the beginning
 *Space complexity: O(n) 
 *Note: for some reason, fill_n is faster than using a for loop, even though they both have the same time complexity, O(n)
*/
int uniquePaths(int m, int n){
    int arr[n];
    fill_n(arr, n, 1);
    for(int i=0; i<m-1; i++){
        for(int j=n-2; j>=0; j--){
            arr[j] += arr[j+1];
        }
    }
    return arr[0];
}


int main(){
    cout << uniquePaths(3, 7);
    return 0;
}