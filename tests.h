#pragma once

#ifdef  _DEBUG

#include <iostream>
#include "floater.h"
using namespace std;

void runTestCase(double number, uint exbits, uint fbits, bool inclSignBit, string expected);
void runTests();
#endif 