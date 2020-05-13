//String.h
//Greatljc
#ifndef STRING_H
#define STRING_H
#include <memory>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
class String {
public:
	typedef std::string::size_type size_t;
	String():
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	String(String&&) noexcept;
	String& operator=(String&&) noexcept;
	size_t size() const { return first_free - elements;}
	size_t capacity() const { return cap - elements; }
	char* begin() const { return elements; }
	char* end() const { return first_free; }
private:
	static std::allocator<char> alloc;
	char *elements;  //指向分配的内存第一个元素
	char *first_free; //指向未构造内存的第一个的位置
	char *cap;       //指向已分配内存的之后一个位置
	void chk_n_alloc();
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();
	void reallocate();
};
std::allocator<char> String::alloc;

String& String::String(String &&rhs) :noexcept
		elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap) {
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

String& String::operator=(String &&rhs) noexcept {
	if(this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.first_free = rhs.elements = rhs.cap = nullptr;
	}
}

void String::free() {
	if(elements) {
		for(char *b = first_free; b != elements;) 
			alloc.destroy(--b);
		alloc.deallocate(elements, cap - elements);
	}
}
/*
std::pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e) {
	auto data = alloc.allocate(e - b);
	return {data, std::uninitialized_copy(b, e, data)};
}
*/

std::pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e) {
	auto data = alloc.allocate(e - b);
	return std::pair<char*, char*>(data, std::uninitialized_copy(b, e, data));
}

String::String(const String &Str) {
	auto ret = alloc_n_copy(Str.begin(), Str.end());
	elements = ret.first;
	first_free = cap = ret.second;	
}


void String::reallocate() {
	size_t newcapcity = size() ? 2 * size(): 100;
	char *newdata = alloc.allocate(newcapcity);
	char *dest = newdata;
	char *elem = elements;
	for(size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapcity;
}


void String::chk_n_alloc() {
	if(size() == capacity()) reallocate();
}


String::String(const char *str) {
	int len = strlen(str);
	char *newdata = alloc.allocate(2 * len);
	char *dest = newdata;
	for(int i = 0; i < len; ++i) {
		alloc.construct(dest++, str[i]);
	}
	elements = newdata;
	first_free = dest;
	cap = elements + 2 * len;
}

String& String::operator=(const String &Str) {
	auto data = alloc_n_copy(Str.begin(), Str.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}















#endif