//Greatljc
//Ptr_StrBlobPtr.h

#ifndef PTR_STRBLOBPTR_H
#define PTR_STRBLOBPTR_H

#include "StrBlobPtr.h"
class Ptr_StrBlobPtr {
public:
	Ptr_StrBlobPtr(StrBlobPtr *p = nullptr): p(p) {} 
	StrBlobPtr& operator*() const {
		return *p;
	}
	StrBlobPtr* operator->() const {
		return & this->operator*();
	}
private:
	StrBlobPtr *p;
};


#endif