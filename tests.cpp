#include <iostream>
#include "floater.h"
#include "tests.h"
using namespace std;

void runTestCase(double number, uint exbits, uint fbits, bool inclSignBit, string expected) {
	floater f(number, exbits, fbits, inclSignBit);
	auto p = f.printNumber();
	if (expected != p) {
		cout << "error!" << endl;
		cout << "expected: " << expected << endl;
		cout << "actual:   " << p << endl;
	}
	else
		cout << "pass" << endl;
}

void runTests() {
	runTestCase(4.25, 8, 23, 1, "01000000100010000000000000000000");
	runTestCase(4.25234234, 8, 23, 1, "01000000100010000001001100110000");
	runTestCase(-4.25234234, 8, 23, 1, "11000000100010000001001100110000");
	runTestCase(423.25, 8, 23, 1, "01000011110100111010000000000000");
	runTestCase(423.25234234, 8, 23, 1, "01000011110100111010000001001101");
	runTestCase(-423.25234234, 8, 23, 1, "11000011110100111010000001001101");
	runTestCase(0, 8, 23, 1, "00000000000000000000000000000000");
	runTestCase(0.999999, 8, 23, 1, "00111111011111111111111111101111");
	runTestCase(-0.999999, 8, 23, 1, "10111111011111111111111111101111");
	runTestCase(-0.999999, 8, 23, 1, "10111111011111111111111111101111");
	runTestCase(0.00000000000001, 8, 23, 1, "00101000001101000010010011011100");
	runTestCase(0.0000000000000000000001, 8, 23, 1, "00011010111100011100100100000001");
	runTestCase(-0.00000000000001, 8, 23, 1, "10101000001101000010010011011100");
	runTestCase(-0.0000000000000000000001, 8, 23, 1, "10011010111100011100100100000001");
	runTestCase(0, 4, 4, 1, "000000000");
	runTestCase(0.5, 4, 4, 1, "001100000");
	runTestCase(0.25, 4, 4, 1, "001010000");
	runTestCase(0.125, 4, 4, 1, "001000000");
	runTestCase(0.0625, 4, 4, 1, "000110000");
	runTestCase(-0, 4, 4, 1, "000000000");
	runTestCase(-0.5, 4, 4, 1, "101100000");
	runTestCase(-0.25, 4, 4, 1, "101010000");
	runTestCase(-0.125, 4, 4, 1, "101000000");
	runTestCase(-0.0625, 4, 4, 1, "100110000");
}