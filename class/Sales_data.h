//Greatljc
//Sales_data.h

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <stdexcept>
#include <iostream>

class Sales_data {
public:
	friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
	friend std::istream& read(std::istream &in, Sales_data &rhs);
	friend std::ostream& print(std::ostream &os, const Sales_data &rhs);
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	friend std::istream& operator>>(std::istream&, Sales_data&);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
	Sales_data() = default;
	Sales_data(const std::string &bookNo, unsigned units_sold = 0, double revenue = 0):
		bookNo(bookNo), units_sold(units_sold), revenue(revenue) { }
	Sales_data(std::istream &is) {   // = std::cin
		read(is, *this);
	}
	std::string isbn() const { return bookNo;}
	Sales_data& combine(const Sales_data &rhs) ;

	Sales_data& operator+=(const Sales_data &rhs) {
		if(bookNo != rhs.bookNo) 
			throw std::runtime_error("error: different isbn");
		units_sold += rhs.units_sold;
		revenue += rhs.units_sold;
		return *this;
	}

	Sales_data& operator=(const std::string &str) {
		bookNo = str;
		units_sold = 0;
		revenue = 0.0;
		return *this;
	}
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

std::ostream& operator<<(std::ostream &os, const Sales_data&);
std::istream& operator>>(std::istream &is, const Sales_data&);
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

std::ostream& operator<<(std::ostream &os, const Sales_data &rhs) {
	os << rhs.bookNo << " " << rhs.units_sold << " " << rhs.revenue << " ";
	return os;
}

std::istream& operator>>(std::istream &is, Sales_data &rhs) {
	double price;
	is >> rhs.bookNo >> rhs.units_sold >> price;
	if(is) {
		rhs.revenue = rhs.units_sold * price;
	}
	else 
		rhs = Sales_data();
	return is;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data ret = lhs;
	ret += rhs;
	return ret;
}


Sales_data& Sales_data::combine(const Sales_data &rhs) {
	if(this->bookNo != rhs.bookNo) 
		throw std::runtime_error("error different isbn");
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	if(lhs.bookNo != rhs.bookNo) {
		throw std::runtime_error("error different isbn");
	}
	Sales_data ret;
	ret.bookNo = rhs.bookNo;
	ret.units_sold += lhs.units_sold + rhs.units_sold;
	ret.revenue += lhs.revenue + rhs.revenue;
	return ret;
}

std::istream& read(std::istream &in, Sales_data &rhs) {
	double price;
	in >> rhs.bookNo >> rhs.units_sold >> price;
	rhs.revenue += price * rhs.units_sold;
	return in;
}

std::ostream& print(std::ostream &os, const Sales_data &rhs) {
	os << rhs.bookNo << " " << rhs.units_sold <<" " << rhs.revenue << " ";
	return os;
}

#endif