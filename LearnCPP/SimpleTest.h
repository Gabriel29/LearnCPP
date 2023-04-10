#pragma once

#include <vector>
#include "TestCase.h"

namespace LearnCPP {

class SimpleTest : public TestCase {
public:
	SimpleTest();
	SimpleTest(std::string name);
	~SimpleTest();

	void exec();

private:
	std::vector<int> numbers;
};

}

