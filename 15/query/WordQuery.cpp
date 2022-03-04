#include "WordQuery.h"

QueryResult WordQuery::eval(const TextQuery& t) const
{
	return t.query(query_word);
}