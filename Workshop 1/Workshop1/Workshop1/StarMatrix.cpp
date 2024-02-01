#include "StarMatrix.h"
#include <iostream>
#include <string>
int StarMain()
{
	int x = 4;
	int y = 0;
	std::cout << "Int x set to: " << x << std::endl;
	std::cout << "Input number of rows\n>>";
	char c ;
	std::cin >> c;
	y = atoi(&c);
	for (int i = 0; i < y; i++) {
		std::cout << std::string(x, '*') << std::endl;
	}
	std::cout << "Input height of triangle \n>>";
	std::cin >> c;
	y = atoi(&c);
	for (int i = 1; i <= 4; i++) {
		std::cout << std::string(i, '*') << std::endl;
	}
	//do rest in a bit - moving on ot someting more complicated
	return 0;
}
