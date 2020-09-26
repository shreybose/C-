/* Copyright 2020
 *
 * This is a binary coverter calcutor, where a decimal number input by the user
 * will be converted to binary.
 *
 * First, we have to show the number of bits we want in then enter the decimal
 * number and lastly display in binary
 */

#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[]) {
  int bits_value, decimal_value, n, b = 0;
  cin >> bits_value >> decimal_value;

  if ( bits_value >= 1 && bits_value <= 31 ) {
    if ( decimal_value >= 0 && decimal_value <= 2147483647 ) {
      while ( decimal_value >= 0 && bits_value >= 1 ) {
        n = log2(decimal_value);
	cout << 1;
        b = pow(2, bits_value - 1);
        int c = b - pow(2, n);
        if ( c >= 0 ) {
          cout << 1;
//          decimal_value = decimal_value - n;
        } else if ( c < 0 ) {
          cout << 0;
        }
        --n;
        --bits_value;
      }
      cout << endl;
    } else {
      return 2;
    }

  } else {
    return 1;
  }
  return 0;
}

