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
	Sales_data() = default;
	Sales_data(const std::string &bookNo, unsigned units_sold = 0, double revenue = 0):
		bookNo(bookNo), units_sold(units_sold), revenue(revenue) { }
	Sales_data(std::istream &is) {   // = std::cin
		read(is, *this);
	}
	std::string isbn() const { return bookNo;}
	Sales_data& combine(const Sales_data &rhs) ;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

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