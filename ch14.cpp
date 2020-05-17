//Greatljc
//ch14

#include "class/Sales_data.h"
#include "class/Book.h"
#include "class/String.h"
#include "class/Strvec.h"
#include "class/StrBlob.h"
#include "class/StrBlobPtr.h"
#include "class/Ptr_StrBlobPtr.h"
#include "class/if_else.h"
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>
using namespace std;

//14.1
//略

//14.2
//Sales_data

//14.3
//略

//14.4
//判断依据：运算符的原始意义是不是需要改变原始对象的状态

//14.5
//Book.h
//需要重载输入输出运算符就好

//14.6
//见Sales_data

//14.7
//见String.h

//14.8
//见Book.h

//14.9
//见Sales_data.h

//14.10
//流错误

//14.11
//少了异常处理

//14.12
//见Book.h

//14.13
//略

//14.14
//因为代码里减少了

//14.15
//不应该

//14.16
//见各头文件

//14.17
//见Book.h

//14.18
//见String.h
void fun14_18() {
	StrVec s1, s2;
	s1.push_back(string("aafasfs"));
	s2.push_back(string("aafasf"));
	if(s1 < s2) cout << "yes" << '\n';
}

//14.19
//见Book.h

//14.20
//见Sales_data.h

//14.21
//见Sales.data.h

//14.22
//见Sales_data.h

//14.23
//见Strvec.h

//14.24
//略

//14.25
//略

//14.26
//见各头文件

//14.27, 14.28
//见头文件

//14.29
//需要改变对象的状态

//14.30
//见头文件

//14.31
//不用自己管理内存，所以不需要自己定义析构函数，根据三五法则，其他拷贝空直成员也不需要自己定义

//14.32
//见Ptr_StrBlobPtr.h

//14.33
//1个以上

//14.34
//if_else.h

//14.35
//PrintString.h

//14.36
//PrintString.h

//14.37
//略

//14.38
class Bigs {
public:
	Bigs(unsigned t): t(t) { }
	bool operator()(const string &s) const { return s.size() >= t; }
private:
	unsigned t;
};

//14.39
//略
//14.40
//和上面的Bigs差不多

//14.41
//增加抽象？

//14.42
void fun14_42() {
	//a() ?
	vector<int> a;
	auto n = count_if(a.begin(), a.end(), bind2nd(greater<int>(), 1024));
	vector<string> s1;
	auto i = find_if(s1.begin(), s1.end(), bind2nd(not_equal_to<string>(), "pooh"));	
	for_each(a.begin(), a.end(), bind2nd(multiplies<int>(),2));
}

//14.43
bool fun14_43(int dividend) {
	vector<int> a;
	return count_if(a.begin(), a.end(), bind2nd(modulus<int>(), 2)) == 0; 

}

int add(int i, int j) { return i + j; }

int (*fp)(int i, int j) = add;
auto mod = [](int i, int j) { return i % j; };

struct divide {
	int operator() (int denominator, int divisor) {
		return denominator / divisor;
	}
};

void fun14_44() {
	map<string, function<int(int, int)>> cal;
	cal.insert({"+", fp});
	cal.insert({"-", minus<int>()});
	cal.insert({"*", [](int i, int j) { return i * j; }});
	cal.insert({"/", divide()});
	cal.insert({"%", mod});
}

//14.45
//isbn()和revenue;

//14.46
//应该，应该

//14.47
//前者将返回const int
//后者将对象转换成const

//14.48
//不应该

//14.49
//见Book.h

//14.50
//1.二义性错误
//2.operator float();

//14.51
//调用cal(int)
//>???Long Double用户定义的的。

//14.52
//ld = si + ld si不能转换成LongDouble, ld也不能转换成SmallInt,所以没有函数匹配
//ld = ld + si 可以用operator+(const SmallInt&), 也可以用operator(1, 2)，存在二义性

//14.53
//改成d = s1 + SmallInt(3.14);

int main() {
	fun14_18();
	return 0;
}