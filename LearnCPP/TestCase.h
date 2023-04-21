#pragma once

#include <string>
#include <typeinfo>

/* Abstract class that defines a Test Case */
class TestCase {
protected:
	TestCase() = default;
	TestCase(std::string name) : _name(name) { }
	
	void init_test_name() { _name = get_class_name(); }

public:
	virtual void exec() = 0;
	const std::string& get_name() { return _name; }
	
	const char* get_full_class_name() const { return typeid(*this).name(); }
	const char* get_class_name() const {
		auto full_name = get_full_class_name();
		if (auto ptr = strrchr(full_name, ':'))
			return ptr + 1;
		return full_name;
	}

protected:
	std::string _name;
};