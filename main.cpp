#include <iostream>
#include "utils.h"
#include "floater.h"
#include "tests.h"

using namespace std;

int main() {

	bool repeat = true;
	floater f;

#if _DEBUG
	runTests();
#endif

	while (repeat) {
		f.getData();
		f.printNumber();		
		repeat = utils::userWantsTo("try again", 'y');
	}
	cout << "Bye!" << endl;
	
	return 0;
}