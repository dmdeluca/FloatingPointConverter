#pragma once

namespace utils {
	template <typename T>
	void cinValidated(T& dest);

	template <typename T, typename S>
	T get(const S named, bool bePolite = true);

	template <typename S>
	bool userWantsTo(const S verbText, char affirmative = 'y');

	template <typename T>
	void cinValidated(T& dest) {
		while (true) {
			std::cin >> dest;
			if (!std::cin.fail())
				break;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
	}

	template <typename T, typename S>
	T get(const S named, bool bePolite) {
		T data;
		std::cout << "enter " << named << ": ";
		cinValidated(data);
		if (bePolite)
			std::cout << "thanks!" << std::endl;
		return data;
	}

	template <typename S>
	bool userWantsTo(const S verbText, char affirmative) {
		bool userAffirms;
		char response;
		std::cout << "want to " << verbText << "? (" << affirmative << "/n): ";
		cinValidated(response);
		userAffirms = response == affirmative;
		std::cout << "OK, we are " << (userAffirms ? "" : "not ") << "going to " << verbText << ". Hope that's OK." << std::endl;
		return userAffirms;
	}


}

