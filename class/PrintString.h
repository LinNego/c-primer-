//Greatljc
//PrintString.h

#ifndef PRINT_STRING_H
#define PRINT_STRING_H
#include <string>
#include <iostream>
class PrintString {
public:
	std::string operator()(std::istream &is = cin) {
		is >> str;
		if(is) return std;
		return string("");
	}

	int operator()(std::istream &is = cin, int &i) {
		std::string temp;
		i = 0;
		while(is) {
			is >> temp;
			vs.push_back(temp);
			++i;
		}
		return i;
	}

private:
	std::string str;
	std::vector<std::string> vs;
}

#endif