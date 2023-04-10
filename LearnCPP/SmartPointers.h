#pragma once

#include "TestCase.h"

namespace LearnCPP {

template<typename T>
class unique_ptr {
public:
	unique_ptr() : m_Object(0) { }
	unique_ptr(T* ptr) : m_Object(ptr) { }

	~unique_ptr() {
		delete m_Object;
	}

	T& operator*() {
		return *m_Object;
	}

	T* operator->() {
		return m_Object;
	}

	unique_ptr(const unique_ptr<T>& obj) = delete;
	unique_ptr<T>& operator= (const unique_ptr<T>& obj) = delete;

private:
	T* m_Object{ nullptr };
};

template<typename T>
class shared_ptr {
private:
	class ReferenceCounter {
		friend class shared_ptr;

		void AddRef() { ++counter; }
		int Release() { return --counter; }

		size_t counter = 0;
	};

public:
	shared_ptr() {
		m_Object = new T();
		m_referenceCounter = new ReferenceCounter();
	}

	shared_ptr(T* ptr) : m_Object(ptr), m_referenceCounter(0) {
		m_referenceCounter = new ReferenceCounter();
		m_referenceCounter->AddRef();
	}

	~shared_ptr() {
		if (m_referenceCounter->Release() == 0) {
			delete m_Object;
			delete m_referenceCounter;
		}
	}

	shared_ptr(const shared_ptr<T>& obj) : m_Object(obj.m_Object), m_referenceCounter(obj.m_referenceCounter) {
		m_referenceCounter->AddRef();
	}

	T& operator*() {
		return *m_Object;
	}

	T* operator->() {
		return m_Object;
	}

	shared_ptr<T>& operator= (const shared_ptr<T>& obj) {
		if (*this == obj) {
			return *this;
		}

		// Decrement old reference. Delete if counter is 0
		if (m_referenceCounter.Release() == 0) {
			delete m_Object;
			delete m_referenceCounter;
		}

		// Copy new data and counter. Increment Counter
		m_Object = obj.m_Object;
		m_referenceCounter = obj.m_referenceCounter;
		m_referenceCounter->AddRef();

		return *this;
	}

private:
	ReferenceCounter* m_referenceCounter{ nullptr };
	T* m_Object{ nullptr };
};

class SmartPointers : public TestCase {
public:
	SmartPointers(std::string name);
	~SmartPointers();
	
	void exec();
};

}

