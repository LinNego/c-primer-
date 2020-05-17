#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>


class StrBlobPtr;
//#include "StrBlobPtr.h"
class StrBlob {
public:
	friend class StrBlobPtr;
	typedef std::vector<std::string>::size_type size_type; 
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	StrBlob(const StrBlob&);
	StrBlob& operator=(const StrBlob&);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	//添加和删除元素
	void push_back(const std::string &t) { data->push_back(t); }
	//void push_back(const std::string &t) &;
	//void push_back(std::string &&t)&&;
	void push_back(std::string &&t) { data->push_back(t); }
	void pop_back();
	bool operator<(const StrBlob &rhs) const { return *data < *rhs.data; }
	bool operator==(const StrBlob &rhs) const { return *data == *rhs.data;}
	bool operator!=(const StrBlob &rhs) const { return *data != *rhs.data; }
	const std::string operator[](unsigned t)const {
		if(t >= data->size()) 
			throw std::runtime_error("t is so big");
		return (*data)[t];  //error : data->[t];
	}
	std::string operator[](unsigned t) {
		if(t >= data->size()) 
			throw std::runtime_error("t is so big");
		return (*data)[t];   //error: data->[t];
	}

	//访问元素
	std::string& front() const;
	std::string& back() const;
	//begin, end
	/*这里需要解决两个类相互引用的问题。
	 *很重要，这里不能直接定义这两个函数。
	 *因为StrBlobPtr不是完整的类型，编译器并不知道该类有什么成员
	 *需要定义完StrBlobPtr类在继续定义这两个函数。
	 */
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string> >(il)) {}




void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

std::string& StrBlob::front() const {
	check(0, "visit a empty StrBlob");
	return data->front();

}


std::string& StrBlob::back() const {
	check(0, "visit a empty StrBlob");
	return data->back();
}
void StrBlob::check(size_type i, const std::string &msg) const {
	if(i >= data->size()) {
		throw std::out_of_range(msg);
	}
}

#include "StrBlobPtr.h"

StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this); 
}

StrBlobPtr StrBlob::end() {
	return StrBlobPtr(*this, data->size());
}

#endif