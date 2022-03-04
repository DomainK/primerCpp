#pragma once

#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "Quote.h"
//#include "Disc_quote.h"

// offer discount for a large purchase
//class Bulk_quote : public Disc_quote {
//public:
//	Bulk_quote() = default;
//	Bulk_quote(const std::string& book, double price,
//		std::size_t qty, double disc) :
//		Disc_quote(book, price, qty, disc){ }
//
//	// override the function in Disc_quote to offer certain discount
//	double net_price(std::size_t) const override; 
//};
//
//inline double Bulk_quote::net_price(std::size_t cnt) const 
//{
//	if (cnt >= quantity)
//		return cnt * (1 - discount) * price;
//	else
//		return cnt * price;
//}

class Bulk_quote : public Quote {
public:

	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double price,
		std::size_t qty, double disc) : Quote(book, price),
		qty_min(qty), discount(disc) { }

	Bulk_quote* clone() const& { return new Bulk_quote(*this); }
	Bulk_quote* clone()&& { return new Bulk_quote(std::move(*this)); }

	double net_price(std::size_t n) const override;

private:

	std::size_t qty_min = 0;
	double discount = 0.0;
};

#endif // !BULK_QUOTE_H
