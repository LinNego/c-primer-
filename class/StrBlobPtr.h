#ifndef STR_BLOB_PTR_H
#define STR_BLOB_PTR_H

#include "StrBlob.h"
#include <memory>
#include <iostream>
class StrBlobPtr {
public:
	friend StrBlobPtr operator+(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend StrBlobPtr operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	StrBlobPtr(): curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0):
		wptr(a.data), curr(sz) { }
	std::string& deref() const;
	StrBlobPtr& incur();
	bool operator!=(const StrBlobPtr&) const;
	std::size_t get_curr() { return curr; }
	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
	const std::string operator[](unsigned t)const {
		auto p = check(t, "t is so big");
		return (*p)[t];  //error : data->[t];
	}
	std::string operator[](unsigned t) {
		auto p = check(t, "t is so big");
		return (*p)[t];  //error: data->[t];
	}
private:
	std::shared_ptr<std::vector<std::string>> 
		check(std::size_t, const std::string&) const;

	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

StrBlobPtr& StrBlobPtr::operator++() {
	check(curr, "out of out_of_range");
	++curr;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator--() {
	--curr;
	check(curr, "out_of_range");
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int i) {
	StrBlobPtr ret = *this;
	++*this;
	return ret;
}

StrBlobPtr StrBlobPtr::operator--(int i) {
	StrBlobPtr ret = *this;
	--*this;
	return ret;
}
StrBlobPtr operator+(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
StrBlobPtr operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

StrBlobPtr operator+(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	auto r1 = lhs.check(lhs.curr, "out_of_range");
	auto r2 = rhs.check(rhs.curr, "out_of_range");
	int curr = 0;
	StrBlobPtr ret;
	ret.wptr = lhs.wptr;
	if(r1 == r2) curr = lhs.curr + rhs.curr;
	else throw std::runtime_error("different class");
	ret.curr = curr;
	return ret;
}

StrBlobPtr operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	auto r1 = lhs.check(lhs.curr, "out_of_range");
	auto r2 = rhs.check(rhs.curr, "out_of_range");
	int curr = 0;
	StrBlobPtr ret;
	ret.wptr = lhs.wptr;
	if(r1 == r2) curr = lhs.curr - rhs.curr;
	else throw std::runtime_error("different class");
	if(curr < 0) throw std::runtime_error("less zero");
	ret.curr = curr;
	return ret;
}


std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
	auto ret = wptr.lock();
	if(!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if(i >= ret->size()) {
		throw std::out_of_range(msg);
	}
	return ret;
}

bool StrBlobPtr::operator!=(const StrBlobPtr &SBP) const {
	return curr != SBP.curr;
}

std::string& StrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incur() {
	check(curr, "incurement past end of StrBlobPtr");
	++curr;
	return *this;
}


#endif













