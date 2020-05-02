#include <iostream>
#include "utils.h"

template <typename T>
void __cinWrapper(T& dest) {
	while (true) {
		std::cin >> dest;
		if (!std::cin.fail())
			break;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
}

template <typename T, typename S>
T __get(const S named, bool bePolite) {
	T data;
	std::cout << "enter " << named << ": ";
	__cinWrapper(data);
	if (bePolite)
		std::cout << "thanks!" << std::endl;
	return data;
}

template <typename S>
bool __userWantsTo(S verbText, char affirmative) {
	bool yes;
	char response;
	std::cout << "want to " << verbText << "? (" << affirmative << "/n): ";
	__cinWrapper(response);
	yes = response == affirmative;
	std::cout << "OK, we are " << (yes ? "" : "not ") << "going to " << verbText << ". Hope that's OK." << std::endl;
	return yes;
}

