// LearnCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

#include "Menu.h"
#include "SimpleTest.h"
#include "SmartPointers.h"
#include "TypeTraits.h"
#include "StdLibrary.h"

using namespace LearnCPP;

void add_tests(Menu* menu) {
    menu->addTest(std::make_unique<SimpleTest>());
    menu->addTest(std::make_unique<SmartPointers>("SmartPointers"));
    menu->addTest(std::make_unique<TypeTraits>("TypeTraits"));
    menu->addTest(std::make_unique<StdLibrary>("StdLibrary"));
}

int main()
{
    int index;
    auto menu = Menu::getInstance();
    add_tests(menu);
    
    menu->showMenu();
    std::cout << "Menu option: ";
    std::cin >> index;

    menu->executeTests(index);

}
