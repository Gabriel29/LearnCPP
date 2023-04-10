#include "StdLibrary.h"

#include <iostream>
#include <tuple>

namespace LearnCPP {

StdLibrary::StdLibrary(std::string name) : TestCase(name) {

}

StdLibrary::~StdLibrary() {

}

void StdLibrary::exec() {
	std::cout << "Running StdLibrary test!\n";

	auto myTuple = std::make_tuple(51, "abc", true);

	std::string myStr;
	std::tie(std::ignore, myStr, std::ignore) = myTuple;
	std::cout << myStr << '\n';

	std::cout << std::get<0>(myTuple) << '\n';
	std::cout << std::get<1>(myTuple) << '\n';
	std::cout << std::get<2>(myTuple) << '\n';
}

}
