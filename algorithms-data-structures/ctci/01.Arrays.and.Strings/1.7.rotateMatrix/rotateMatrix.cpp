/**
 * Arshan Alam
 *
 * Cracking the Coding Interview 6th Edition
 *
 * Problem 1.7 Rotate Matrix
 *
 * Given an image represented by an NxN matrix, where each pixel
 * in the image is 4 bytes, write a method to rotate the image by
 * 90 degrees. Can you do this in place?
 *
 */

#include <iostream>


/**
 *  Rotate the given matrix by 90 degrees.
 *
 *  Assume we are rotating the images 90 degrees counterclockwise.
 *    |> Similar to pi/2 on a unit circle
 */
void rotate90(unsigned N, int ** matrix) {
  for (unsigned i = 0; i < N-i; i++) {
    for (unsigned j = i; j < N-i-1; j++) {
      int temp = matrix[i][j];
      matrix[i][j]          = matrix[j][N-i-1];
      matrix[j][N-i-1]      = matrix[N-i-1][N-j-1];
      matrix[N-i-1][N-j-1]  = matrix[N-j-1][i];
      matrix[N-j-1][i]      = temp;
    }
  }
}

int main() {
  int ** matrix;
  unsigned N;
  std::cin >> N;
  matrix = new int * [N];

  /**
   * Read the matrix input
   */
  for (unsigned i = 0; i < N; i++) {
    matrix[i] = new int[N];
    for (unsigned j = 0; j < N; j++) {
      std::cin >> matrix[i][j];
    }
  }

  // rotate the matrix
  rotate90(N, matrix);

  /**
   * Print the rotated matrix
   */
  for (unsigned i = 0; i < N; i++) {
    for (unsigned j = 0; j < N; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }

  for (unsigned i = 0; i < N; i++) {
    delete [] matrix[i];
  }
  delete [] matrix;

  return 0;
}
