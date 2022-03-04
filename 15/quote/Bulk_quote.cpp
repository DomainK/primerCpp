#include "Bulk_quote.h"

double Bulk_quote::net_price(std::size_t n) const
{
	if (n >= qty_min)
		return n * (1 - discount) * price;
	else
		return n * price;
}