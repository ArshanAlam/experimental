#include <bitlib.h>
#include <iostream>

using namespace std;

int main() {
  int x = 16;
  int i = 3;
  cout << repeatedRightShift(x, i) << endl;
  cout << repeatedLeftShift(x, i) << endl;
  cout << getBit(x, i) << endl;
  cout << getBit(x, 5) << endl;
  cout << setBit(x, i) << endl;
  cout << clearBit(x+6, i) << endl;
  cout << clearBitsMSThroughI(-1, i) << endl;
  cout << clearBitsThroughI(-1, i) << endl;
  cout << updateBit(x, i, true) << endl;
  cout << updateBit(x, 5, false) << endl;
  
  return 0;
}
