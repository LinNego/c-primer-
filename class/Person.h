//Person.h
//Greatljc

#ifndef PERSON_H
#define PERSON_H
#include <iostream>
class Person {
	friend std::istream& read(std::istream&, Person &);
	friend std::ostream& print(std::ostream&, const Person&);
public:
	std::string get_name() const { return name; }
	std::string get_address() const { return address; }
	Person(const std::string name = "", const std::string address = "") :
			name(name), address(address) { }

private:
	std::string name;
	std::string address;
};

std::istream& read(std::istream &is, Person &person) {
	is >> person.name >> person.address;
	return is;
}

std::ostream& print(std::ostream &os, const Person &person) {
	os << person.name << "address: " << person.address;
	return os;
}

#endif