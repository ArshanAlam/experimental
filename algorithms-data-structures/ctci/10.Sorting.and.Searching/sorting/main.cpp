/**
 * Sort Example
 */

#include <sort.h>
#include <iostream>
using namespace std;

#define N 10
#define K 15

int main() {
  int * arr = new int[N];

  arr[0] = 1;
  arr[1] = 15;
  arr[2] = 2;
  arr[3] = 6;
  arr[4] = 3;
  arr[5] = 7;
  arr[6] = 4;
  arr[7] = 0;
  arr[8] = 9;
  arr[9] = 8;

  // bubbleSort(arr, N);
  // selectionSort(arr, N);
  // mergeSort(arr, N);
  quickSort(arr, N);

  for(int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  
  cout << "Element " << K << " at index " << binarySearch(arr, N, K) << endl;
  cout << "Element " << K * K << " at index " << binarySearch(arr, N, K * K) << endl;

  cout << "Recursive Element " << K << " at index " << binarySearchRecursive(arr, N, K) << endl;
  cout << "Recursive Element " << K * K << " at index " << binarySearchRecursive(arr, N, K * K) << endl;

  delete[] arr;
  return 0;
}
