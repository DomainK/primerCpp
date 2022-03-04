#include <iostream>
#include "Sales_data.h"
#include "Screen.h"
using std::istream; using std::cin;
using std::ostream; using std::cout;
using std::endl; using std::cerr;

int main()
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n"; 

	return 0;
}