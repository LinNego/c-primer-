//Greatljc
//testclass.cpp

//#include "StrBlobPtr.h"
//#include "TextQuery.h"
//#include "QueryResult.h"
#include "String.h"
#include <cstring>
#include <iostream>
using namespace std;
int main() {
	char ch[10];
	memset(ch, 0, sizeof(ch));	
	ch[0] = '1';
	ch[1] = '2';
	ch[2] = '3';
	String s(ch);
	cout << ch[0] << endl;
	return 0;
}