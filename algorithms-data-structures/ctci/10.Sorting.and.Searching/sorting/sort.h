/**
 * A set of sorting functions to sort
 * an array of integers.
 */

#ifndef __SORT_H__
#define __SORT_H__

/**
 * Sort the n element array arr using bubble sort.
 *
 * O(n^2) average and worst case
 * O(1) space
 */
void bubbleSort(int * arr, int n) {
  bool sorted = false;
  while(!sorted) {
    sorted = true;
    for(int i = 0; i < n - 1; i++) {
      if(arr[i] > arr[i + 1]) {
        sorted = false;
        int temp = arr[i + 1];
        arr[i + 1] = arr[i];
        arr[i] = temp;
      }
    }
  }
}

/**
 * Sort the n element array arr using selection sort.
 *
 * O(n^2) average and worst case
 * O(1) space
 */
void selectionSort(int * arr, int n) {
  for(int i = 0; i < n; i++) {
    int min = arr[i];
    int index = i;
    for(int j = i + 1; j < n; j++) {
      if(arr[j] < min) {
        min = arr[j];
        index = j;
      }
    }
    arr[index] = arr[i];
    arr[i] = min;
  }
}


/**
 * Merge the two given arrays!
 */
int * merge(int * A, int lenA, int * B, int lenB) {
  int n = lenA + lenB;
  int * sorted = new int[n];
  int indexA = 0;
  int indexB = 0;
  int i = 0;
  while(i < n) {
    int min = 0;
    if((indexA < lenA) && (indexB < lenB)) {
      if (A[indexA] < B[indexB]) {
        min = A[indexA++];
      } else {
        min = B[indexB++];
      }
    } else if(indexA < lenA) {
      min = A[indexA++];
    } else {
      min = B[indexB++];
    }
    sorted[i++] = min;
  }

  return sorted;
}

/**
 * Sort the n element array arr using merge sort.
 *
 * O(nlogn) average and worst case
 * O(n) space
 */
void mergeSort(int * arr, int n) {
  // The single element array is sorted
  if(n <= 1) return;
  int leftSize = n / 2;
  int rightSize = n - leftSize;
  mergeSort(arr, leftSize);
  mergeSort(arr + leftSize, rightSize);
  
  int * result = merge(arr, leftSize, arr + leftSize, rightSize);
  for(int i = 0; i < n; i++) {
    arr[i] = result[i];
  }

  delete[] result;
}

/**
 * Partition the given array with respect to the element
 * at the given index.
 *
 * Return the new index of that element.
 */
int partition(int * arr, int n, int index) {
  int elem = arr[index];
  int pivotIndex = 0;
  arr[index] = arr[n - 1];
  arr[n - 1] = elem;
  
  for(int i = 0; i < n - 1; i++) {
    if (arr[i] < elem) {
      int tmp = arr[pivotIndex];
      arr[pivotIndex] = arr[i];
      arr[i] = tmp;
      pivotIndex++;
    }
  }

  arr[n - 1] = arr[pivotIndex];
  arr[pivotIndex] = elem;

  return pivotIndex;
}

/**
 * Sort the n element array arr using quick sort.
 *
 * O(nlogn) average case
 * O(n^2) worst case
 * O(logn) space
 */
void quickSort(int * arr, int n) {
  int index = partition(arr, n, n / 2);

  if (index > 0) {
    quickSort(arr, index);
  }

  if ((index + 1) < n) {
    quickSort(arr + index + 1, n - index - 1);
  }
}

/**
 * Search for element k in sorted array arr of size n.
 * Return the index of element k.
 *
 * If k is not found then -1 is returned.
 */
int binarySearch(int * arr, int n, int k) {
  int start = 0;
  int end = n - 1;

  while(start <= end) {
    int mid = (start + end) / 2;
    if (arr[mid] == k) return mid;
    else if (arr[mid] < k) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  // not found
  return -1;
}

/**
 * Search for element k in sorted array arr of size n.
 * Return the index of element k.
 *
 * If k is not found then -1 is returned.
 */
int binarySearchRecursive(int * arr, int n, int k) {
  // not found
  if(n <= 0) return -1;

  int mid = n / 2;
  if (arr[mid] == k) return mid;
  else if (arr[mid] < k) {
    int index = binarySearchRecursive(arr + mid + 1, n - mid - 1, k);
    if (index != -1) return mid + 1 + index;
    else return index;
  } else {
    return binarySearchRecursive(arr, mid, k);
  }
}


#endif
