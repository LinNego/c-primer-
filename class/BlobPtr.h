//BlobPtr
//Greatljc

#include <memory>
#include <vector>
#include "Blob.h"
#include <iostream>
template <typename T>
class BlobPtr {
public:
	BlobPtr(): curr(0) { }
	/*
	BlobPtr(Blob<T> &a, std::size_t sz = 0):
		wptr(a.data), curr(sz) { }
		*/
	
	BlobPtr(Blob<T> &a, std::size_t sz = 0):
		wptr(a.data), curr(sz) { }

	T& operator*() const;
	BlobPtr& operator++();
	BlobPtr& operator--();
	BlobPtr operator++(int);
	BlobPtr operator--(int);
private:
	std::shared_ptr<std::vector<T>>
		check(std::size_t, const std::string&) const;

	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};

template <typename T>
std::shared_ptr<std::vector<T>>
BlobPtr<T>::check(std::size_t i, const std::string &std) const {
	auto ret = wptr.lock();
	if(!ret) {
		throw std::runtime_error(std);
	}
	if(i >= ret->size()) {
		throw std::out_of_range(std);
	}
	return ret;
}

template <typename T>
T& BlobPtr<T>::operator*() const {
	auto p = check(curr, "visit curr");
	return (*p)[curr];
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
	auto p = check(curr + 1, "++ error");
	++curr;	
	return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
	auto p = check(curr - 1, "-- error");
	--curr;
	return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int i) {
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int i) {
	BlobPtr ret = *this;
	--*this;
	return ret;
}

















