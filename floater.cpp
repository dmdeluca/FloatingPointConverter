#include <iostream>
#include "floater.h"
#include "utils.h"

using namespace std;

void floater::getData()
{
	__number = utils::get<double>("decimal number");
	__includeSignBit = utils::userWantsTo("include sign bit");
	__numberOfExponentBits = utils::get<uint>("number of exponent bits");
	__numberOfFractionBits = utils::get<uint>("number of fraction bits");
}

void floater::printNumber()
{
	auto signBit = !__includeSignBit ? "" : (__number >= 0 ? "0" : "1");

	int exponent;
	auto adjustedNumber = __adjustNumber(__number, exponent);
	auto fractionBits = __getFractionBits(__numberOfFractionBits, adjustedNumber);
	auto exponentBits = __getExponentBits(__numberOfExponentBits, exponent);

	__printBits(signBit, exponentBits, fractionBits);

	return;
}

void floater::__printBits(const char* signBit, std::string& exponentBits, std::string& fractionBits)
{
	cout << signBit << "  " << exponentBits << "  " << fractionBits << endl;

	cout << "^+ ^ex";

	for (size_t i = 0; i < exponentBits.length() - 1; i++)
		cout << " ";

	cout << "^fr" << endl;
}


string floater::__getExponentBits(uint nEx, int exponent) {
	string exponentBits = "";
	auto bias = (uint)pow(2, nEx - 1) - 1;
	ulong expValue = (exponent + (int)bias);
	long bitMask = 1 << (nEx - 1);
	while (exponentBits.length() < nEx) {
		exponentBits += expValue & bitMask ? "1" : "0";
		expValue <<= 1;
	}
	return exponentBits;
}

string floater::__getFractionBits(uint nFr, double adjustedNumber) {
	string fractionBits = "";
	auto roundedNumber = round(adjustedNumber * pow(2, nFr)) / pow(2, nFr);
	bool roundUp = roundedNumber > adjustedNumber;
	while (fractionBits.length() < nFr) {
		adjustedNumber = (adjustedNumber >= 1 ? adjustedNumber - 1 : adjustedNumber) * 2;
		fractionBits += adjustedNumber > 1 ? "1" : "0";
	}
	if (roundUp) {
		for (int i = fractionBits.length() - 1; i > 0; i--) {
			if (fractionBits[i] == '0') {
				fractionBits[i] = '1';
				break;
			}
			fractionBits[i] = '0';
		}
	}
	return fractionBits;
}

double floater::__adjustNumber(double number, int& exponent) {
	exponent = 0;
	double adjustedNumber = number;
	while (adjustedNumber >= 2) {
		adjustedNumber /= 2;
		exponent += 1;
	}
	while (adjustedNumber < 1) {
		adjustedNumber *= 2;
		exponent -= 1;
	}
	return adjustedNumber;
}