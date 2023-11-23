/**
 * Given a set of non-negative integers and a value sum, the task is to check if there is a subset of the given set whose sum is equal to the given sum. 
*/

#include <iostream>
using namespace std;

//no answer
    // int n = 6;
    // int a[6] = {3, 34, 4, 12, 5, 2};
    // int S = 30;
/*
 * This is the bitwise operation version
*/
int main() {
//yes answer
int n = 6;
int a[6] = {3, 34, 4, 12, 5, 2}
int S = 9;
/**
 * This for loop represents all possible subsets of the set! 2^n
 * For example, in the first iteration, mask = 1 = 000001, which represents the subset [2];
 * When mask = 010101, its subset represents [34, 12, 2]
*/
for(int mask = 0; mask < (1 << n); mask++){
    long long sum_of_this_subset = 0;
    //this loop is going 0 - 5, but you should think of it like, 000001, 000010, 000100
    for(int i=0; i < n; i++){
        /**
         * This if statement is saying "if the value in position i of mask is a 1, append that element to the sum"
         * For example, if mask is 010101, the loop will go through each place value, and append 34, 12, and 2!
        */
        if((1<<i) & mask){
            sum_of_this_subset += a[i];
        }
    }
    //if a possible subset has been found terminate
    if(sum_of_this_subset == S){
        cout << "yes" << '\n';
        return 0;
    }
    
}
cout << "no" << '\n';
return 0;
}
/*
 * The time complexity of this program is O(2^n * n), and it makes sense when looking at each for loop
 * The first for loop goes through every subset, which is 2^n
 I* The second subset goes through the length of the list(which is n) for every subset
*/