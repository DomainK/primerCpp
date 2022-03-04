#include <iostream>
#include "Person.h"

Person::Person(istream& is)
{
	read(*this, is);
}

istream& read(Person& person, istream& is) {
	is >> person.name >>  person.location;
	return is;
}

ostream& print(const Person& person, ostream& os) {
	os << person.name << " " << person.location;
	return os;
}