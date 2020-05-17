//Book.h
//Greatljc

#ifndef BOOK_H
#define BOOK_H
#include <string>
class Book {
public:
	friend std::istream& operator>>(std::istream&, Book &book);
	friend std::ostream& operator<<(std::ostream&, const Book &book);
	friend bool operator==(const Book &lhs, const Book &rhs);
	friend bool operator!=(const Book &lhs, const Book &rhs);
	Book(const std::string &name = " " , const std::string &isbn = " ") :name(name), isbn(isbn) { }
	std::string get_name() const { return name; }
	std::string get_isbn() const { return isbn; }

private:
	std::string name;
	std::string isbn;
};
std::istream& operator>>(std::istream&, Book &book);
std::ostream& operator<<(std::ostream&, const Book &book);
bool operator==(const Book &lhs, const Book &rhs);
bool operator!=(const Book &lhs, const Book &rhs);

std::istream& operator>>(std::istream &is, Book &book) {
	is >> book.name >> book.isbn;
	if(!is) 
		book = Book();
	return is;

}

std::ostream& operator<<(std::ostream &os, const Book &book) {
	os << book.name << " " << book.isbn << " ";
	return os;
}

bool operator==(const Book &lhs, const Book &rhs) {
	return lhs.isbn == rhs.isbn;
}

bool operator!=(const Book &lhs, const Book &rhs) {
	return !(lhs == rhs);
}

#endif