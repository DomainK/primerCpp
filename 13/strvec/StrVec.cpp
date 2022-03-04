#include "StrVec.h"
#include <algorithm>
#include <memory>

std::allocator<std::string> StrVec::alloc;

void StrVec::push_back(const std::string& s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::push_back(std::string&& s) {
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string* b, const std::string* e) {
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b,e,data) };
}

void StrVec::free() {
	if (elements) {
		std::for_each(elements, first_free, [](std::string* s) {alloc.destroy(s); });
		/*for (auto p = first_free; p != elements;)
			alloc.destroy(--p);*/
		alloc.deallocate(elements, cap - elements);
	}
}

//void StrVec::reallocate() {
//	auto newcapacity = size() ? 2 * size() : 1;
//	auto newdata = alloc.allocate(newcapacity);
//	auto dest = newdata;
//	auto elem = elements;
//	for (size_t i = 0; i != size(); ++i)
//		alloc.construct(dest++, std::move(*elem++));
//	free();
//	elements = newdata;
//	first_free = dest;
//	cap = elements + newcapacity;
//}

void StrVec::reallocate() {
	auto newcapacity = size() ? 2 * size() : 1;
	auto first = alloc.allocate(newcapacity);
	auto last = std::uninitialized_copy(make_move_iterator(begin()),
		make_move_iterator(end()), first);
	free();
	elements = first;
	first_free = last;
	cap = elements + newcapacity;
}