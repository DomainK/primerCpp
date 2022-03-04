#pragma once

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using std::istream; using std::cin;
using std::ostream; using std::cout;

struct Person
{
	Person() = default;
	Person(std::string& n, std::string L) :
		name(n), location(L) { }
	Person(istream&);

	std::string getName() const { return name; };
	std::string getLoca() const { return location; };

	std::string name;
	std::string location;
};

istream& read(Person&, istream&);
ostream& print(const Person&, ostream&);


#endif // !PERSON_H
