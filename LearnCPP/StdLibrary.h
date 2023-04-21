#pragma once

#include "TestCase.h"

namespace LearnCPP {

class StdLibrary : public TestCase {
public:
	StdLibrary(std::string name);
	~StdLibrary();
	void exec();

private:
	void TupleExamples();
};

}
