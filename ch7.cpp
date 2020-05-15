//ch7.cpp
//Greatljc

#include "class/Sales_data.h"
#include "class/Person.h"
#include "class/Screen.h"
#include "class/X.h"
#include "class/Y.h"
#include "class/Nodefault.h"
#include "class/C.h"
#include <iostream>
using namespace std;
//7.1
void fun_7_1() {
	Sales_data total;
	if(read(cin, total)) {
		Sales_data temp;
		while(read(cin, temp)) {
			if(total.isbn() == temp.isbn()) {
				total.combine(temp);
			}
			else {
				print(cout, total) << endl;
				total = temp;
			}
		}
		print(cout , total);
	}
	else {
		cerr << " No data ?!" << endl;
	}
}

//7.2
//见Sales_data类

//7.3
//见7.1

//7.4
//见Person.h
//应该是const的

//7.5
//见7.4

//7.6
//见Sales_data.h

//7.7
//见7.1

//7.8
//因为print不需要修改Sales_data
//read需要修改Sales_data

//7.9
//见Person.h

//7.10
//判断流的状态

//7.11
void fun_7_11() {
	Sales_data a(cin), b("2424-23-23"), c;
	print(cout, a) << endl;
	print(cout, b) << endl;
	print(cout, c) << endl;
}

//7.12
//见类文件

//7.13
void fun_7_13() {
	Sales_data total(cin);
	//Sales_data temp(cin);	
	if(cin) {
		Sales_data temp;
		while(read(cin, temp)) {
			if(total.isbn() == temp.isbn()) {
				total.combine(temp);
			}
			else {
				print(cout, total) << endl;
				total = temp;
			}
		}
		print(cout , total);
	}
	else {
		cerr << " No data ?!" << endl;
	}
}

//7.14
//只是将初始化放到了构造函数题进行。

//7.15
//见Person.h

//7.16
//没有限定。
//函数接口应该在public
//数据成员和一些工具函数的实现在private

//7.17
//struct默认的访问说明符是public
//class默认的访问说明符是private
//除此之外没有任何区别

//7.18
//封装的目的不让用户代码破坏对象的状态

//7.19
//函数接口

//7.20
//在需要访问别的类的private的时候有用

//7.21
//见Sales_data.h

//7.22
//见Person.h

//7.23
//见Screen.h

//7.24
//见Screen.h

//7.25
//可以，数据成员中没有需要自己管理内存的成员

//7.26
//在avg_price函数的定义中加上inline

//7.27
//可以加上默认参数 char c = ' '

//7.28
void fun_7_28() {
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << '\n';
	myScreen.display(cout);
	cout << "\n";
}

//7.29
//两个输出的display不同

//7.30
//优点：增加可读性
//缺点：多余

//7.31
//见X.h Y.h

//7.32
//见Window_msg.h 和 Screen.h

//7.33
//pos是类内定义的，只有::才进入了类的作用域

//7.34
//未定义

//7.35
//initVal使用了typedef的Type
//setVal使用的是double
//类内的initVal使用的是double
//函数的实现中
//Type 是string
//Type parm是double

//7.36
//需要先声明base再声明rem

//7.37
//见Sales_data就可以知道

//7.38
//见Sales_data.h

//7.39
//不合法，编译器并不知道调用哪个构造函数

//7.40
//Book.h

//7.41
//略

//7.42
//略

//7.43
void fun_7_43() {
	C c;
}

//7.44
//不合法，因为NoDefault没有默认构造函数

//7.45
//错误

//7.46
//略

//7.47
//不应该

//7.48
//1.将"9-999-99999-9"转换成string
//2.将null_isbn转换成Sales_data;
//3.错误
//如果都是explicit的，将会发生错误

//7.49
//会调用Sales_data为参数的

//7.50
//见Person.h

//7.51
//略

//7.52
//正确

//7.53
//参考书本

//7.54
//不应该，需要赋值，如果constexpr只能够有返回语句了。

//7.55
//是

//7.56
//不与普通的数据成员相同，不属于某一个类，不在类内初始化。
//静态的生存期

//7.57
//参考书本

//7.58
//静态数据成员应该在类外定义。
int main() {
	fun_7_43();
	return 0;
}





















