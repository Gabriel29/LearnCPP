#include <iostream>
#include "SmartPointers.h"

namespace LearnCPP {

struct A {
	std::string getName() { return "A"; }
};

SmartPointers::SmartPointers(std::string name) : TestCase(name) {

}

SmartPointers::~SmartPointers() {

}

void SmartPointers::exec() {
	shared_ptr<A> a(new A());
	std::cout << a->getName() << "\n";

	shared_ptr<A> ua(new A());
	std::cout << ua->getName() << "\n";
}

}