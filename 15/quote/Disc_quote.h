#pragma once

#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "Quote.h"
#include <string>

// abstract base class from Quote
// cannot create a object of Disc_quote
class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book, double price,
		std::size_t qty, double disc) :
		Quote(book, price), quantity(qty), discount(disc){ }
	double net_price(std::size_t) const = 0; // pure virtual function
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

#endif // !DISC_QUOTE_H

