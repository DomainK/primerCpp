#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
using std::string;
#include "Sales_item.h"
#include <fstream>

int main()
{
	std::ifstream in("input.txt");
	std::streambuf* cinbackup;
	cinbackup = cin.rdbuf(in.rdbuf());

	Sales_item total;
	if (std::cin >> total) {
		Sales_item trans;
		while (std::cin >> trans) {
			if (total.isbn() == trans.isbn())
				total += trans;
			else {
				std::cout << total << std::endl;
				total = trans;
			}
		}
		std::cout << total << std::endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}

	return 0;
}