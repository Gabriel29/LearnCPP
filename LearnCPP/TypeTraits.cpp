#include "TypeTraits.h"

#include <iostream>

namespace LearnCPP {
	
	class MyClass { };

	// Type traits defines a compile-time template-based interface to query or modify the properties of types.
	// Also check: https://www.internalpointers.com/post/quick-primer-type-traits-modern-cpp

	TypeTraits::TypeTraits(std::string name) : TestCase(name) {

	}
	
	TypeTraits::~TypeTraits() { }

	void TypeTraits::exec() {
		std::cout << "std::is_class<MyClass> " << std::is_class<MyClass>::value << '\n';
		std::cout << "std::is_floating_point<MyClass> " << std::is_floating_point<MyClass>::value << '\n';
		std::cout << "std::is_floating_point<float> " << std::is_floating_point<float>::value << '\n';
		std::cout << "std::is_floating_point<int> " << std::is_floating_point<int>::value << '\n';

		std::cout << "std::is_same<std::conditional<true, int, double>::type, int>::value " 
			<< (std::is_same<std::conditional<true, int, double>::type, int>::value) << '\n';
	};
}
