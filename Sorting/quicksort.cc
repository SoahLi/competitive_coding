/**
 * quick sort is a recursive algorithm that splits data
   into smaller sub-arrays and sorts them based on a pivot element
 * Time complexity: O(nlogn)
 * Space complexity: O(n)
*/

#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int* quickSort(int* arr, int start, int end);
int partition(int* arr, int start, int end);

int main() {
  int n = 5;
  // int arr[] = {-51, 10, 2, 5, 50};
  int arr[5];
  for(int m=0; m<10; m++){
    for(int i=0; i<n; i++){
      arr[i] = rand()%100+1;
    }
    quickSort(arr, 0, n-1);
    for(int j=0; j<n; j++){
      cout << arr[j] << " ";
    }
    cout << endl << endl;
  }
  // quickSort(arr, 0, n-1);
  // for(int i=0; i<n; i++){
  //   cout << arr[i] << " ";
  // }
}

int* quickSort(int* arr, int start, int end){
  //sort the array based on a pivot - partition
  // quickSort() on the left half
  // quickSort() on the right half
  //base case
  if(start < end){
    int pivotIndex = partition(arr, start, end);
    quickSort(arr, 0, pivotIndex-1);
    quickSort(arr, pivotIndex+1, end);
  }
  return arr;
}

int partition(int* arr, int start, int end){
  //choose a pivot element
  //sort the array based on the pivot
  //insert the pivot element into the correct position
  int pivotElement = arr[end];
  int j=start;
  for(int i=start; i<end; i++){
    if(arr[i] < pivotElement){
      swap(arr[i], arr[j]);
      j++;
    }
  }
  swap(arr[j], arr[end]);
  return j; 
}