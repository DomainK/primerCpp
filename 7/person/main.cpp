#include <iostream>
#include "Person.h"

using std::string; using std::cerr;
using std::endl;

int main()
{
	Person student;
	if (read(student, cin))
		print(student, cout); 
	else
	{
		cerr << "No data?!" << endl;
	}
}