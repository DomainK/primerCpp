#include <iostream>
#include <fstream>
#include "Query.h"

void runQueries(std::ifstream& infile);

int main() {
	std::ifstream fin("file.txt");
	/*runQueries(fin);*/
	TextQuery tq(fin);
	Query w1("you");
	Query w2("your");
	Query w3 = w1 & w2;
	print(std::cout, w1.eval(tq)) << std::endl;
	print(std::cout, w2.eval(tq)) << std::endl;
	print(std::cout, w3.eval(tq)) << std::endl;

	return 0;
}

//void runQueries(std::ifstream& infile) {
//	TextQuery tq(infile);
//	while (true) {
//		std::cout << "enter word to look for, or q to quit: ";
//		std::vector<std::string> word;
//		std::string s;
//		if (!(std::cin >> s) || s == "q") break;
//		Query w1(s);
//		print(std::cout, w1.eval(tq)) << std::endl;
//	}
//}