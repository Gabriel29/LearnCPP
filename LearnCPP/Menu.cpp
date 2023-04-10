#include <iostream>

#include "Menu.h"

namespace LearnCPP {

std::ostream& operator << (std::ostream& os, const std::vector< std::unique_ptr<TestCase>>& v)
{
	for (typename std::vector< std::unique_ptr<TestCase>>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		os << std::distance(v.begin(), it) << ". " << it->get()->get_name() << "\n";
	}
	
	os << v.size() << ". All Tests\n";
	os << "-1. Quit\n";

	return os;
}

Menu* Menu::_singleton;

Menu::Menu() {
}

void Menu::showMenu() {
	std::cout << test_cases;
}

std::string Menu::readEntry() {
	return std::string();
}

void Menu::addTest(std::unique_ptr<TestCase> t) {
	test_cases.push_back(std::move(t));
}

void Menu::executeTests(unsigned int index) {
	// Quit without executing tests
	if (index == -1) return;
	
	// Execute all tests
	if (index == test_cases.size()) {
		for (int i = 0; i < test_cases.size(); i++)
			test_cases[i]->exec();
	}

	else if (index >= 0 && index <= test_cases.size())
		test_cases[index]->exec();

	else std::cout << "Index out of range\n";
}

Menu* Menu::getInstance() {
	if (_singleton == NULL) {
		_singleton = new Menu();
	}

	return _singleton;
}

}