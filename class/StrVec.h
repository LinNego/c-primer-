#ifndef STRVEC_H
#define STRVEC_H
#include <memory>
#include <string>
#include <utility>
#include <algorithm>
#include <initializer_list>
#include <iostream>


class StrVec {
public:
	StrVec():
		elements(nullptr), first_free(nullptr), cap(nullptr) { }
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	StrVec(std::initializer_list<std::string> li);
	~StrVec();
	StrVec(StrVec &&s) noexcept;
	StrVec& operator=(StrVec&&) noexcept;
	StrVec& operator=(std::initializer_list<std::string>);
	bool operator<(const StrVec &rhs) const;
	bool operator==(const StrVec &rhs) const;
	bool operator!=(const StrVec &rhs) const { return !(*this == rhs);}
	const std::string& operator[](unsigned t) const{
		if(t >= first_free - elements) {
			throw std::runtime_error("error: t is so big");
		}
		return elements[t];
	}
	std::string& operator[](unsigned t) {
		if(t >= first_free - elements) {
			throw std::runtime_error("error: t is so big");
		}
		return elements[t];
	}

	void push_back(const std::string&);
	unsigned size() const { return first_free - elements; }
	unsigned capacity() const { return cap - elements; } 
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }
private:
	static std::allocator<std::string> alloc;
	void chk_n_alloc();
	std::pair<std::string*, std::string*> alloc_n_copy
		(const std::string*, const std::string*);

	void free();
	void reallocate();
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};

std::allocator<std::string> StrVec::alloc;

StrVec& StrVec::operator=(std::initializer_list<std::string> il) {
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

bool StrVec::operator<(const StrVec &rhs) const {
	std::cout << ";;;" << '\n';
	std::string *b = elements, *c = rhs.elements;
	while(1) {
		if(c == rhs.first_free) return false;
		if(b == first_free || *b < *c) return true;
		++b;
		++c;
	}
}

bool StrVec::operator==(const StrVec &rhs) const {
	if(first_free - elements != rhs.first_free - rhs.elements) return false;
	std::string *b = elements, *c = rhs.elements;
	for(int i = 0; i < first_free - elements; ++i) {
		if(*b != *c) return false;
		++b;
		++c;
	}
	return true;
}


StrVec::StrVec(StrVec &&s) noexcept :
	elements(s.elements), first_free(s.first_free), cap(s.cap) {
		s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
	if(this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}
	

void StrVec::chk_n_alloc() {
	if(size() == capacity()) 
		reallocate();
}

void StrVec::push_back(const std::string &s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
	std::string *data = alloc.allocate(e - b);
	return std::pair<std::string*, std::string*>(data, uninitialized_copy(b, e, data));
}
/*
void StrVec::free() {
	if(elements) {
		for(auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}
*/
void StrVec::free() {
	for_each(elements, first_free, [](std::string &p) -> void { alloc.destroy(&p); });	
	alloc.deallocate(elements, cap - elements);
}

StrVec::StrVec(const StrVec &s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec &rhs) {
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate() {
	auto newcapcity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapcity);

	auto dest = newdata;
	auto elem = elements;
	for(unsigned i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));	
	}
	free();

	elements = newdata;
	first_free = dest;
	cap = elements + newcapcity;
}

StrVec::StrVec(std::initializer_list<std::string> il) {
	for(auto i: il) {
		push_back(i);
	}
}

StrVec::~StrVec() {
	free();
}

#endif