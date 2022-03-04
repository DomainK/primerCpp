#pragma once

#ifndef NOTQURY_H
#define NOTQURY_H

#include "Query.h"

class NotQuery : public Query_base {
	friend Query operator~(const Query&);

	NotQuery(const Query& q) :query(q) { }

	std::string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery&) const;

	Query query;
};

Query operator~(const Query& operand) {
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}


#endif // !NOTQUERY_H
