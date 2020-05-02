#include <iostream>
#include "utils.h"
#include "floater.h"

using namespace std;

int main() {

	bool repeat = true;
	floater f;

	while (repeat) {
		f.getData();
		f.printNumber();		
		repeat = utils::userWantsTo("try again", 'y');
	}
	cout << "Bye!" << endl;
	
	return 0;
}
