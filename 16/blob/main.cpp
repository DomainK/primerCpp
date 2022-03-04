#include "Blob.h"
#include <iostream>

int main() {
	Blob<int> squares = { 0,1,2,3,4,5,6,7,8,9 };
	for (size_t i = 0; i != squares.size(); ++i) {
		squares[i] = i * i;
		std::cout << squares[i] << " ";
	}
}