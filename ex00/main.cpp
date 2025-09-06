#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
	std::vector<int> vec = {1, 2, 3, 4, 5};
	std::list<int> lst = {10, 20, 30, 40, 50};

	try {
		std::cout << "Found in vector: " << *easyfind(vec, 3) << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Not found in vector: " << e.what() << std::endl;
	}

	try {
		std::cout << "Found in list: " << *easyfind(lst, 25) << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Not found in list: " << e.what() << std::endl;
	}

	return (0);
}