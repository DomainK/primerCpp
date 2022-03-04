#pragma once

#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H

#include "Quote.h"
#include "Disc_quote.h"

// offer discount for a limited number of purchase
class Limit_quote : public Disc_quote {
	Limit_quote() = default;
	Limit_quote(const std::string& book, double price,
		std::size_t qty, double disc, std::size_t qty_m) :
		Disc_quote(book, price, qty, disc), qty_max(qty_m){ }
	double net_price(std::size_t) const final;

private:
	std::size_t qty_max = 0;
};

inline double Limit_quote::net_price(std::size_t cnt) const {
	if (cnt <= qty_max)
		return cnt * (1 - discount) * price;
	else
		return qty_max * (1 - discount) * price + (cnt - qty_max) * price;
}


#endif // !LIMIT_QUOTE_H
