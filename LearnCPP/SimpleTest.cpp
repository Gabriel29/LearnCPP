#include <iostream>

#include "SimpleTest.h"

namespace LearnCPP {

SimpleTest::SimpleTest() {
	init_test_name();
}

SimpleTest::SimpleTest(std::string name) : TestCase(name) {
	for (int i = 0; i < 10; i++) {
		numbers.push_back(i);
	}
}

SimpleTest::~SimpleTest() {
}

void SimpleTest::exec() {
	for (int i = 0; i < numbers.size(); i++) {
		std::cout << i << " ";
	}
} 

}