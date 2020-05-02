#pragma once

#include <string>

typedef unsigned int uint;
typedef unsigned int ulong;

class floater {
	double __number;
	uint __numberOfExponentBits;
	uint __numberOfFractionBits;
	bool __includeSignBit;
	std::string __signBit;
	std::string __fractionBits;
	std::string __exponentBits;
	std::string __getExponentBits(uint, int);
	std::string __getFractionBits(uint, double);
	double __adjustNumber(double, int&);
	void __printBits(const char* signBit, std::string& exponentBits, std::string& fractionBits);
public:
	floater() :
		__number(0),
		__numberOfExponentBits(0),
		__numberOfFractionBits(0),
		__includeSignBit(false) {};
	void getData(void);
	void printNumber(void);
};
