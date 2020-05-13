#ifndef STR_BLOB_PTR_H
#define STR_BLOB_PTR_H

#include "StrBlob.h"
#include <memory>
#include <iostream>
class StrBlobPtr {
public:
	StrBlobPtr(): curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0):
		wptr(a.data), curr(sz) { }
	std::string& deref() const;
	StrBlobPtr& incur();
	bool operator!=(const StrBlobPtr&) const;
	std::size_t get_curr() { return curr; }
private:
	std::shared_ptr<std::vector<std::string>> 
		check(std::size_t, const std::string&) const;

	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

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













