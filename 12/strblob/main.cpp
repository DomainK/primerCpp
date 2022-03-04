#include "StrBlob.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::string;
using std::cout;

int main()
{
	std::ifstream fin("file2.txt");
	StrBlob sb;
	string line;

	while (std::getline(fin, line))
	{
		if (!line.empty())
			sb.push_back(line);
		else
			std::cerr << "No data?!" << std::endl;
	}

	StrBlobPtr sb_begin(sb.begin());
	StrBlobPtr sb_end(sb.end());
	while (!sb_begin.compare(sb_end))
	{
		cout << sb_begin.deref()<< std::endl;
		sb_begin.incr();
	}

	return 0;
}