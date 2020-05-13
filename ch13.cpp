//Greacljc
//ch13.cpp

#include <iostream>
#include <string>
#include <vector>
#include "class/StrBlob.h"
#include <algorithm>
using namespace std;

//13.1
//拷贝控制函数定义了同类型的另一个对象初始化本对象时做什么。

//13.2
//如果说声明是拷贝控制函数的，那么的确非法的。因为函数的参数不是引用类型

//13.3
//编译器为这些类定义了拷贝控制函数,合成的拷贝控制函数将所有非static的成员全部拷贝到正在创建的对象中。

//13.4
//1.foo_bar的参数非引用类型
//2.new Point这里
//3*heap = local
//4.Point pa[4] = ...
//5.return *heap

//13.5
class HasPtr {
public:
	friend void swap(HasPtr&m ,HasPtr&);
	HasPtr(const std::string &s = std::string()):
		ps(new std::string(s)){ }
	HasPtr(const HasPtr&);
	HasPtr(HasPtr&&);
	HasPtr& operator=(const HasPtr&);
	HasPtr& operator=(HasPtr&&);
	bool operator<(const HasPtr &rhs)const { return *ps < *rhs.ps && i < rhs.i; }
	~HasPtr() { delete ps; } //没加引用计数版析构函数
private:
	std::string *ps;
	int i;
};

HasPtr::HasPtr(const HasPtr &has): ps(new std::string(*has.ps)), i(has.i){  }
HasPtr& HasPtr::operator=(const HasPtr &has) {
	string *p = new string(*has.ps);  //为了正确处理自赋值的情况
	delete ps;
	ps = p;
	i = has.i;
	return *this;
}

HasPtr::HasPtr(HasPtr &&rhs): ps(rhs.ps), i(rhs.i) { rhs.ps = nullptr; }
HasPtr& HasPtr::operator=(HasPtr &&has) {
	if(this != &has) {
		delete ps;
		ps = has.ps;
		i = has.i;
		has.ps = nullptr;
	}
	return *this;
}

//13.6
//1.控制对象如何赋值
//2.=号？
//3.控制对象如何赋值
//4.未定义自己的拷贝空直运算符

//13.7
//1.用StrBlob赋值给另一个StrBlob，会导致成员赋值发生。
//像第十二章所说，shared_ptr会增加计数1次。
//2.如果是StrBlobPtr，用的是weak_ptr，赋值不会导致指针的计数器加1


//13.8
//见上面HasPtr类

//13.9
//对象被销毁时做什么，完成资源回收的工作，如果一个类未定义自己的成员。

//13.10
//StrBlob被销毁，会导致指针的计数器减1，StrBlobPtr被销毁，并不会导致指针的计数器减1(weak_ptr)


//13.11
//见类

//13.12
//3个，accum, item1, item2

//13.13

struct X {
	X() { cout << "X()" << endl;}
	X(const X&) { cout << "X(const)" << endl; }
	X& operator=(const X&) { cout << "operator=" << endl; return *this; }
	~X() { cout << "~X() " << endl; }
};

void testX(X arg) {
	X x = arg, y;  //这里使用的是拷贝控制函数
	y = x;  //用的是拷贝赋值运算符
	//这两个上面的区别就是一个是已经存在对象，一个是需要初始化的对象

}

//13.14
class numbered {
public:
	static int number;
	numbered(): mysn(++number) { };
	//14题需要把这两个个函数注释掉
	numbered(const numbered&) { mysn = ++number; }
	numbered& operator=(const numbered &nbr) { mysn = ++number; return *this; }	
	int mysn;
};
int numbered::number = 0;

void testnumbered (){
	numbered a, b = a, c = b;
	cout << a.mysn << " " << b.mysn << " " << c.mysn << endl;
}

//13.15
//见上面类和测试函数

//13.16
//如果是第十五题的情况下，不会改变输出结果。如果非引用，number就会++。

//13.17
//见上
	

//13.18
class Employee {
public:
	static int ID;
	Employee(): name(""), id(++ID) {}
	Employee(string s) : name(s), id(++ID) { }
	Employee(const Employee &Ep) : name(Ep.name), id(++ID) {}
	Employee& operator=(const Employee&) = delete;
private:
	string name;
	int id;
};

//13.19
//需要，不能使用合成的拷贝构造的函数，因为需要递增ID。
//同时拷贝赋值运算符应该定义为删除的。
//见类。


//13.20
/*TextQuery, 合成拷贝控制成员
 *拷贝。指向文档的指针指针将会的计数器加1。
 *而map拷贝过去。指针的计数器也加1。
 *赋值行为和拷贝差不多
 *销毁的话如果指针计数器变为0加将自动销毁智能指针指向的内存

 *QueryResult
 *拷贝，weak_ptr不会使得计数器加1
 *赋值。和拷贝类似
 *销毁weak_ptr并不会导致weak_ptr绑定的shared_ptr计数器减1.
 */

//13.21
//不需要，这两个类的成员都是智能指针，可以自动控制资源的释放。


//13.22
//见13.5

//13.23
//略

//13.24
//未定义析构函数，将导致内存泄漏
//未定义拷贝控制函数，会使得string*指针指向同一块内存

//13.25
StrBlob::StrBlob(const StrBlob &SB) : 
				data(new vector<string>(*(SB.data))) { }


StrBlob& StrBlob::operator=(const StrBlob &SB) {
	data.reset(new vector<string>(*(SB.data)));
//	data = make_shared<vector<string>>(*(SB.data));//允许
	//data = new vector<string>不允许
	//智能指针不用手动处理自赋值的情况
	return *this;
}

//13.26
//见上面


//13.27
/*
 *HasPtr::HasPtr(const HasPtr &rhs) :ps(rhs.ps), i(rhs.i), use(rhs.use)
 					{ ++*use; }
 *~HasPtr() {
	if(--*use == 0) {
		delete ps;
		delete use;
	}
 }
 *HasPtr& operator=(const HasPtr &rhs) {
 	++*rhs.use;
 	if(--*use == 0) {
		delete ps;
		delete use;
 	}
 	ps = rhs.ps;
 	i = rhs.i;
 	use = rhs.use;
 	return *this;
 }
*/
 //13.28
class TreeNode {
	string value;
	int count;
	TreeNode *left;
	TreeNode *right;
public:
	TreeNode(const string value, int count) :value(value), count(count), left(nullptr), right(nullptr)
						{ }	
	TreeNode(const TreeNode&) = delete;
	TreeNode& operator=(const TreeNode&) = delete;
	void deleteNode(TreeNode*);
	~TreeNode(); //感到奇怪的是delete是删除这个节点还是删除以这一课节点为根的树。
	                //更倾向于后者
};

void TreeNode::deleteNode(TreeNode *tp) {
	if(tp->left) deleteNode(tp->left);
	if(tp->right) deleteNode(tp->right);
	delete tp;
}

TreeNode::~TreeNode() {
	deleteNode(left);
	deleteNode(right);
}

class BinStrTree {
	TreeNode *root;
public:
	BinStrTree(TreeNode *tr): root(tr) {} 
	~BinStrTree() { delete root; }
};

//上面的代码存在bug,错误的

//13.29
//不会递归调用这个swap(HasPtr&, HasPtr&) 的原因在于
//1.首先使用了using std::swap
//2.对于函数里面调用的swap(string*, string*)，明显标准库的swap更加符合函数匹配。

//13.30

inline
void swap(HasPtr &lhs, HasPtr &rhs) {
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	cout << "start" << endl;
}

//13.31
void testless() {
	vector<HasPtr> v;
	v.push_back(HasPtr( "zzz"));
	v.push_back(HasPtr("no"));
	v.push_back(HasPtr("yes"));
	v.push_back(HasPtr("a"));
	sort(v.begin(), v.end());
	//好像并不会调用自定义的swap
}



//13.32
//不会，类指针的底层数据本身就是指针，调用标准库的swap已经足够

//13.33
//如果参数是Folder，save的是局部变量的Folder
//如果参数是const Folder&，那么不允许在常量上面添加Message

//13.34
//见类文件Message.h

//13.35
//使用合成拷贝，单纯的拷贝的set，可是在set中的每一个Folder并没有添加这个Message.

//13.36
//见类文件Folder.h

//13.37
//见类文件Message.h

//13.38
//避免拷贝花费的时间多

//13.39
//略

//13.40
//见StrVec.h

//13.41
//后置递增递增变量的值，返回变量递增之前的值。也就是要构造的位置。
//如果使用前置运算符，那么递增变量的值，将不会在我们期望的位置上构造内存。

//13.42
//略

//13.43

/*void StrVec::free() {
	for_each(elements, first_free, [](std::string &p) -> void { alloc.destroy(&p)})	
}
*/
//更倾向于这样实现

//13.44
//见类文件String.h

//13.45
/*左值恒久，右值短暂*/

//13.46
//r1 左值引用
//r2 左值引用
//r3 左值引用
//r4 右值引用

//13.47
//见String.h

//13.49
//见类文件

//13.50
//见类文件

//13.51
//返回的是一个右值，右值即将被销毁，使用的移动拷贝控制成员。

//13.52/
//如同书本而言，赋值运算符的参数是一个非引用参数
//对于第一行hp，用hp2来赋值，hp2是一个左值，rhs使用拷贝构造函数来构造。
//对于第二行hp，用hp2来赋值，hp2是一个用move函数绑定了，返回一个右值引用，rhs使用移动构造函数初始化。

//13.53
//需要进行匹配,见HasPtr

//13.54
//如果参数是右值引用，将会使用移动赋值运算符
//如果参数不是右值引用，将会使用拷贝并交换运算符

//13.55
//见StrBlob.h

//13.56
//ret.sorted() 调用导致无限递归调用。 ret是一个左值，调用ret.sorted()还是调用左值版本

//13.57 调用的将会是右值版本

//13.58
class Foo {
public:
	Foo sorted() &&;
	Foo sorted() const &;
private:
	vector<int> data;
};
Foo Foo::sorted() && {
	sort(data.begin(), data.end());
	cout << "&&" << endl;
	return *this;
}

Foo Foo::sorted() const & {
	Foo ret(*this);
	cout << "const & " << endl;
	return ret.sorted();
}
int main() {
	Foo().sorted();
	Foo f;
	f.sorted();
	return 0;
}