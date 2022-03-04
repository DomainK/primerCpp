#pragma once

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data
{
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);
	friend std::ostream& print(std::ostream&, const Sales_data&);
	friend std::istream& operator>>(std::istream&, Sales_data&);
	friend std::ostream& operator<<(std::ostream&, Sales_data&);
	friend bool operator==(const Sales_data&, const Sales_data&);
public:
	Sales_data(const std::string& s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p* n) { }
	Sales_data() :Sales_data("", 0, 0) { }
	Sales_data(std::string s) :Sales_data(s, 0, 0) { }
	Sales_data(std::istream& is) :Sales_data() { read(is, *this); }
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	Sales_data& operator+=(const Sales_data& rhs) {
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}

private:
	inline double avg_price() const {
		return units_sold ? revenue / units_sold : 0;
	};
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

std::istream& operator>>(std::istream& is, Sales_data& it) {
	double price;
	is >> it.bookNo >> it.units_sold >> price;
	if (is)
		it.revenue = it.units_sold * price;
	else
		it = Sales_data();
	return is;
}

std::ostream& operator<<(std::ostream& os, Sales_data& it) {
	os << it.isbn() << " " << it.units_sold << " " << it.revenue << " "
		<< it.avg_price();
	return os;
}

bool operator==(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.isbn() == rhs.isbn() && lhs.units_sold == rhs.units_sold
		&& lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data& lhs, const Sales_data& rhs) {
	return !(lhs == rhs);
}

#endif // !SALES_DATA_H
