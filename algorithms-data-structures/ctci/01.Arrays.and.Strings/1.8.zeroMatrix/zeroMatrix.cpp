/**
 * Arshan Alam
 *
 * Cracking the Coding Interview 6th Edition
 *
 * Problem 1.8 Zero Matrix
 *
 * Write an algorithm such that if an element in an MxN matrix is zero,
 * its entire row and column are set to zero.
 *
 */

#include <iostream>


/**
 * Zero the rows and columns that contain a zero entry.
 */
void zeroMatrix(unsigned  M, unsigned N, int ** matrix) {
  bool * isZeroRow = new bool[M];
  bool * isZeroCol = new bool[N];
  for (unsigned i = 0; i < M; i++) {
    isZeroRow[i] = false;
  }
  for (unsigned j = 0; j < N; j++) {
    isZeroCol[j] = false;
  }

  for (unsigned i = 0; i < M; i++) {
    for (unsigned j = 0; j < N; j++) {
      if(matrix[i][j] == 0) {
        isZeroRow[i] = true;
        isZeroCol[j] = true;
        break;
      }
    }
  }

  for (unsigned i = 0; i < M; i++) {
    if(isZeroRow[i] == true) {
      for (unsigned j = 0; j < N; j++) {
        matrix[i][j] = 0;
      }
    }
  }

  for (unsigned j = 0; j < N; j++) {
    if(isZeroCol[j] == true) {
      for (unsigned i = 0; i < M; i++) {
        matrix[i][j] = 0;
      }
    }
  }

  delete [] isZeroRow;
  delete [] isZeroCol;
}

int main() {
  int ** matrix;
  unsigned M, N;

  /**
   * Read the matrix input
   */
  std::cin >> M >> N;
  matrix = new int * [M];
  for (unsigned i = 0; i < M; i++) {
    matrix[i] = new int[N];
    for (unsigned j = 0; j < N; j++) {
      std::cin >> matrix[i][j];
    }
  }

  /**
   * Zero the matrix and print the result
   */

   zeroMatrix(M, N, matrix);
   for (unsigned i = 0; i < M; i++) {
     for (unsigned j = 0; j < N; j++) {
       std::cout << matrix[i][j] << " ";
     }
       std::cout << std::endl;
   }

  /**
   * Apply clean-up
   */
  for (unsigned i = 0; i < M; i++) {
    delete [] matrix[i];
  }
  delete [] matrix;
  return 0;
}
