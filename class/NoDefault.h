//Greatljc
//NoDefault.h

#ifndef NODEFAULT_H
#define NODEFAULT_H
class NoDefault {
public:
	NoDefault() = default;  //error: no matching function for call to 'NoDefault::NoDefault()
	NoDefault(int t): t(t) { }
	int t;
};


#endif