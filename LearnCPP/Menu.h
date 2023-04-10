#pragma once

#include <string>
#include <vector>
#include <memory>

#include "TestCase.h"
	
namespace LearnCPP {

/* Menu */
class Menu {
private:
	Menu();

public:
	Menu(const Menu& obj) = delete;

	void showMenu();
	std::string readEntry();
	void executeTests(unsigned int index);
	void addTest(std::unique_ptr<TestCase> t);

	static Menu* getInstance();

private:
	std::string menu;
	std::vector <std::unique_ptr<TestCase>> test_cases;

	static Menu* _singleton;
};

}