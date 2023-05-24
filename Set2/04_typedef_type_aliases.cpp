#include <iostream>
#include <vector>

//typedef std::vector<std::pair<std::string, int>> pairlist_t;

//typedef std::string text_t;
// typedef int number_t;

// however, using is preferred as it is more useful for templates
using text_t = std::string;
using number_t = int;

int main4(){

	//pairlist_t pairlist;

	text_t firstname = "Bobby";
	number_t age = 21;

	std::cout << firstname << std::endl;
	std::cout << age << std::endl;

	return 0;
}
