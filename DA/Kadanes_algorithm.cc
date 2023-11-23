/**
 * Kadane's Algorithm is a dynamic programming algorithm used to find the maximum 
 * subarray sum in a given array of numbers. It efficiently solves this problem in
 *  linear time complexity, making it an efficient solution for handling large 
 * datasets. The algorithm works by maintaining two variables, one to keep track 
 * of the maximum subarray sum ending at the current element, and another to keep 
 * track of the maximum subarray sum overall. By iterating through the array and 
 * updating these variables, Kadane's Algorithm identifies the contiguous subarray 
 * with the highest sum.
 * Time complexity: O(n)
*/

#include <iostream>
#include <algorithm>
using namespace std;
int n[8] = {-1,2,4,-3,5,2,-5,2};
int l = 8;

int maximum_subarray_sum(int len, int arr[]){
    int best=0, sum=0;
    for(int i=0; i< len; i++){
        cout << "iteration " << i << '\n';
        cout << "current number is " << arr[i] << '\n';
        cout << "overall sum with current number is " << sum+arr[i] << '\n';
        cout << "best is " << best << '\n';
        sum = max(arr[i], sum+arr[i]); 
        best = max(sum, best);
        cout << "after comparison, sum is now " << sum << " and best is now " << best << '\n';
    }
    return best;
}


int main(){
    cout << maximum_subarray_sum(l, n);
}
