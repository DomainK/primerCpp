#pragma once

#ifndef BASKET_H
#define BASKET_H

#include "Quote.h"
#include <memory>
#include <set>

class Basket {
public:

	void add_item(const Quote &sale)
	{
		items.insert(std::shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote&& sale)
	{
		items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
	}
	

	double total_receipt(std::ostream&) const;

private:

	static bool compare(const std::shared_ptr<Quote> &lhs,
		const std::shared_ptr<Quote> &rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}

	std::multiset<std::shared_ptr<Quote>, decltype(compare)* > items{ compare };
};

double print_total(std::ostream& os, const Quote& item, size_t n);

#endif // !Basket
