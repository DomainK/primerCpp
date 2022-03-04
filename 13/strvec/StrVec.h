#pragma once
#ifndef STRVEC_H
#define STRVEC_H

#include <memory>
#include <string>
#include <utility>
#include <initializer_list>

class StrVec {
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) { }
	StrVec(const std::initializer_list<std::string>);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	StrVec(StrVec&& s) noexcept;
	StrVec& operator=(StrVec&& rhs) noexcept;
	StrVec& operator=(std::initializer_list<std::string>);
	std::string& operator[](std::size_t n) { return elements[n]; }
	const std::string& operator[](std::size_t n) const { return elements[n]; }
	~StrVec() { free(); }
	void push_back(const std::string&);
	void push_back(std::string&&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string* begin() const { return elements; }
	std::string* end() const{ return first_free; }

private:
	static std::allocator<std::string> alloc;
	std::string* elements;
	std::string* first_free;
	std::string* cap;
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	std::pair<std::string*, std::string*> alloc_n_copy
	(const std::string*, const std::string*);
	void free();
	void reallocate();
};

inline StrVec::StrVec(const StrVec& s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

inline StrVec::StrVec(StrVec&& s) noexcept :
	elements(s.elements), first_free(s.first_free), cap(s.cap) {
	s.elements = s.first_free = s.cap = nullptr;
}

inline StrVec& StrVec::operator=(StrVec&& rhs) {
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

inline StrVec::StrVec(const std::initializer_list<std::string> list) {
	auto newdata = alloc_n_copy(list.begin(), list.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

inline StrVec& StrVec::operator=(const StrVec& rhs) {
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

inline StrVec& StrVec::operator=(std::initializer_list<std::string> i1) {
	auto data = alloc_n_copy(i1.begin(), i1.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

#endif // !STRVEC_H
