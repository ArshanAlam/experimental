/**
 * bitlib
 *
 * A library for doing bit-manipulations.
 */

#ifndef __BIT_LIB_H__
#define __BIT_LIB_H__

/**
 * repeatedRightShift
 *
 * Shift x by count bits to the right.
 */
int repeatedRightShift(int x, int count) {
  while(count-- > 0) {
    x >>= 1;
  }
  return x;
}

/**
 * repeatedLeftShift
 *
 * Shift x by count bits to the left.
 */
int repeatedLeftShift(int x, int count) {
  while(count-- > 0) {
    x <<= 1;
  }
  return x;
}

/**
 *  getBit
 *
 *  Get the bit at position i.
 */
bool getBit(int x, int i) {
  return ((x & (1 << (i-1))) > 0);
}

/**
 *  setBit
 *
 *  Set the bit at position i to a 1.
 */
int setBit(int x, int i) {
  return (x | (1 << (i-1)));
}

/**
 *  clearBit
 *
 *  Set the bit at position i to a 0.
 */
int clearBit(int x, int i) {
  return (x & (~(1 << (i-1))));
}

/**
 * clearBitsMSThroughI
 *
 * Clear all the bits from the most significant all the
 * way to bit I (inclusive).
 */
int clearBitsMSThroughI(int x, int i) {
  return (x & ((1 << (i-1)) - 1));
}

/**
 * clearBitsThroughI
 *
 * Clear all the bits from bit I to bit 0 (inclusive).
 */
int clearBitsThroughI(int x, int i) {
  return (x & (-1 << i));
}

/**
 * updateBit
 *
 * Set the given bit to the given value.
 */
int updateBit(int x, int i, bool bitIs1) {
  return (bitIs1)? setBit(x, i) : clearBit(x, i);
}
#endif
