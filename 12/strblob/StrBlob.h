#pragma once

#ifndef STRBLOB_H
#define STRBLOB_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

class StrBlobPtr;

class StrBlob {
	friend class StrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> i1);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const std::string& t) { data->push_back(t); }
	void pop_back();
	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string& msg) const;
};

inline StrBlob::StrBlob() :data(std::make_shared<std::vector<std::string>>()) { }
inline StrBlob::StrBlob(std::initializer_list<std::string> i1) :
	data(std::make_shared<std::vector<std::string>>(i1)) { }

#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

class StrBlobPtr {
public:
	StrBlobPtr() :curr(0) { }
	StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) { }
	StrBlobPtr& operator++();
	StrBlobPtr operator++(int);
	StrBlobPtr& operator--();
	StrBlobPtr operator--(int);
	StrBlobPtr& operator+=(const size_t);
	StrBlobPtr& operator-=(const size_t);
	std::string& operator*() const {
		auto p = check(curr, "dereference past end");
		return(*p)[curr];
	}
	std::string* operator->() const {
		return&this->operator*();
	}
	std::string& deref() const;
	StrBlobPtr& incr();
	bool compare(StrBlobPtr& s1) const
		{ return ((*this).curr == s1.curr) ? 1 : 0; }
private:
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

inline StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
inline StrBlobPtr StrBlob::end() {
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

inline StrBlobPtr& StrBlobPtr::operator++() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

inline StrBlobPtr StrBlobPtr::operator++(int) {
	StrBlobPtr ret = *this;
	++* this;
	return ret;
}

inline StrBlobPtr& StrBlobPtr::operator--() {
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

inline StrBlobPtr StrBlobPtr::operator--(int) {
	StrBlobPtr ret = *this;
	--* this;
	return ret;
}

inline StrBlobPtr& StrBlobPtr::operator+=(const size_t n) {
	curr += n;
	check(curr, "increment past out end of StrBlobPtr");
	return *this;
}

StrBlobPtr operator+(StrBlobPtr& it,size_t n) {
	StrBlobPtr tmp = StrBlobPtr(it);
	tmp += n;
	return tmp;
}

inline StrBlobPtr& StrBlobPtr::operator-=(const size_t n) {
	curr -= n;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

StrBlobPtr operator-(StrBlobPtr& it, size_t n) {

}

#endif // !STRBLOBPTR_H
#endif // !STRBLOB_H

