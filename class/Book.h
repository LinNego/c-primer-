//Book.h
//Greatljc

#ifndef BOOK_H
#define BOOK_H
#include <string>
class Book {
public:
	Book(const std::string &name = " " , const std::string &isbn = " ") :name(name), isbn(isbn) { }
	std::string get_name() const { return name; }
	std::string get_isbn() const { return isbn; }
private:
	std::string name;
	std::string isbn;
};

#endif