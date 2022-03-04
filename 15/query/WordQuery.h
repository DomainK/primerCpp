#pragma once

#ifndef WORDQUERY_H
#define WORDQUERY_H

#include "Query.h"

class WordQuery :public Query_base {
	friend class Query;

	WordQuery(const std::string&s) : query_word(s) { }
	QueryResult eval(const TextQuery& t) const;
	std::string rep() const { return query_word; }
	std::string query_word;
};

Query::Query(const std::string& s) : q(new WordQuery(s)) { }

#endif // !WordQuery
