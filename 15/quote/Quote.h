#pragma once

#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

class Quote {
public:
	Quote() = default;  // constructor is default;

	//copy-assignment operator
	Quote& operator=(const Quote&);

	//copy constructor
	Quote(const Quote& rhs) : bookNo(rhs.bookNo), price(rhs.price) { }

	Quote(const std::string& book, double sales_price) :
		bookNo(book), price(sales_price) { };

	std::string isbn() const { return bookNo; }

	virtual double net_price(std::size_t n) const
	{
		return price * n;
	}
	//move-assignment operator
	Quote& operator=(Quote&&) noexcept;
	 
	//move constructor
	Quote(Quote&& rhs) noexcept : bookNo(std::move(rhs.bookNo)),
		price(std::move(rhs.price)) { }


	virtual ~Quote() = default;   //dynamic bind destructor

	virtual void debug() { std::cout << bookNo + " " << price << " "; }

	virtual Quote* clone() const& { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(std::move(*this)); }

private:
	std::string bookNo;

protected:
	double price = 0.0;

};

inline Quote& Quote::operator=(const Quote& rhs) {
	bookNo = rhs.bookNo;
	price = rhs.price;
	return *this;
}

inline Quote& Quote::operator=(Quote&& rhs) noexcept {
	bookNo = std::move(rhs.bookNo);
	price = std::move(rhs.price);
	return *this;
}

#endif // !QUOTE_H

