#include <iostream>
using namespace std;

//Submission 1: Time limit exceeded
// int helper(int currentStair, int n){
//     //base case
//     if(currentStair == n){
//         return 0;
//     }
//     else if(currentStair+1 == n){
//         return 1;
//     }
//     else if(currentStair+2 == n){
//         return 2;
//     }
//     else {
//         return helper(currentStair+1, n) + helper(currentStair+2, n);
//     }
// }
// int climbStairs(int n){
//     return helper(0, n);
// }

// int main(){
//     cout << climbStairs(2);

// }

// int helper(int currentStair, int n){
//     //base case
//     if(currentStair == n){
//         return 0;
//     }
//     else if(currentStair+1 == n){
//         return 1;
//     }
//     else if(currentStair+2 == n){
//         return 2;
//     }
//     else {
//         return helper(currentStair+1, n) + helper(currentStair+2, n);
//     }
// }
// int climbStairs(int n){
//     return helper(0, n);
// }

//Submission 2 PASSING
/*
 * Time complexity: O(n)
 * Space complexity: O(1)
*/
// int climbStairs(int n){
//     int result = 1;
//     int previous = 0;
//     for(int i=1; i<=n; i++){
//         int temp = result;
//         result += previous;
//         previous = temp;
//     }
//     return result;
// }

// int main(){
//     cout << climbStairs(4);

// }


//Submission 3 PASSING
/*
 * Time complexity: O(n)
 * Space complexity: O(1)
*/
int climbStairs(int n){
    int result = 1;
    int previous = 0;
    int temp = result;
    for(int i=1; i<=n; i++){
        temp = previous;
        result += previous;
        previous = temp;
    }
    return result;
}

int main(){
    cout << climbStairs(4);

}