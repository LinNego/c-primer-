//Greatljc
//ch12.cpp

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include "class/StrBlob.h"    //注意，这两个文件哪个先include决定编译是否能成功
#include "class/StrBlobPtr.h" //因为实现和声明没有分隔开。
#include <cstring>
using namespace std;

//12.1
//4个


//12.2
//见StrBlob.h"

//12.3
//两个不需要，常量的的类

//12.4
/*因为size_type是一个无符号整数.
 *如果调用check函数时传入的是负数，导致会变成一个正数。
 */ 

//12.5
//优点：允许了隐式的类型转换
//缺点：不明确

//12.6

vector<int>* get_p() {
	return new vector<int>;
}
void get_input(vector<int> *vi) {
	int n;
	while(cin >> n) {
		vi->push_back(n);
	}
}

void print_input(vector<int> *vi) {
	for(int i = 0; i < vi->size(); ++i) {
		cout << (*vi)[i] << " ";
	}	
	cout << endl;
	delete vi;
}

//12.7
shared_ptr<vector<int> > get_sp(int n) {
	return make_shared<vector<int>>();
}

void get_input(shared_ptr<vector<int>> vi) {
	int n;
	while(cin >> n) {
		vi->push_back(n);
	}

}

void print_input(shared_ptr<vector<int>> vi) {
	for(int i = 0; i < vi->size(); ++i) {
		cout << (*vi)[i] << " ";
	}	
	cout << endl;
}

//12.8
//指针类型转变成bool类型将不可以被释放

//12.9
//r = q，将导致原本r指向的100的位置的内存泄露
//r2 = q2，减少r2的引用计数，如果r2的引用计数为0，自动释放原本r2指向的内存
//增加q2的引用计数。

//12.10
//调用是正确的。


//12.11
//process函数结束后，p指向的内存被释放，p成了一个空悬的智能指针。


//12.12
//a.合法，将sp作为实参传入到process
//b.不合法，不能将一个内置指针转换到智能指针
//c.不合法，原因通b
//d.合法，但是很有可能会出错，因为重新创建了一个临时对象，两个对象独立创建的。
  //在函数结束后，临时对象指向的内存被释放，也导致了p成为了空悬。


 //12.13
 //删除了sp指向的内存。


//12.14
//挺合理的

//12.15
/*
 *void f(destination &d) {
	connection c = connect(&d);
	shared_ptr<connection> p(&c, [](connection *p) -> void {disconnect(*p); });
 }
 */
//12.16
void trys() {
	unique_ptr<int> p(new int(5));
	//unique_ptr<int> s(p);不可以被赋值或者被拷贝。
	/*
	 *error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) 
	 *[with _Tp = int; _Dp = std::default_delete<int>; std::unique_ptr<_Tp, _Dp> = std::unique_ptr<int>]
	 */
}

//12.17
//a.错误，ix不是一个指针
//b.pi指向的不是动态申请的内存
//c.正确
//d.错误，不是动态申请的指针
//e.正确
//f.正确，但后续操作极其有可能出错误。因为p5和p2指向的同一个内存位置，所以p5指向的内存释放后，p2也变成了空悬指针。


//12.18
//因为shared_ptr不是唯一指向某一个内存位置的智能指针。

//12.19
//定义在类文件

//12.20

void read_StrBlob(ifstream &in) {
	string str;
	StrBlob Sb;
	
	while(in >> str) {
		Sb.push_back(str);
	}
	
	StrBlobPtr Sbp = Sb.begin();
	cout << Sbp.deref();
	
	while(Sbp != Sb.end()) {   //两个StrBlobPtr都是相同的StrBlob
		cout << Sbp.deref() << endl;;
		Sbp.incur();
	}	
	return ;
}

//12.21
//第一个版本，私以为更加清晰

//12.22
//StrBlobPtr的构造函数接受的StrBlob参数改为接受const StrBlob参数。
//ConstStrBlobPtr成员应该和StrBlobPtr成员相同，但是构造函数接受的应该是const版本的。

//12.23
void fun12_23_1(const char *str1, const char *str2) {
	char ans[100];
	int len1 = strlen(str1), len2 = strlen(str2);
	for(int i = 0; i < len1; ++i) {
		ans[i] = str1[i];
	}
	for(int j = 0; j < len2; ++j) {
		ans[len1 + j] = str2[j];
	}
}

void fun12_23_2(const string &s1, const string &s2) {
	char ans[100];
	for(int i = 0; i < s1.size(); ++i) {
		ans[i] = s1[i];
	}
	for(int i = 0; i < s2.size(); ++i) {
		ans[i + s1.size()] = s2[i];
	}
}

//12.24
void fun12_24() {
	char *p = new char[10];
	scanf("%s", p);
	printf("%s\n", p);
	//很奇怪，当输入超过10个，程序访问内存越界，但是输出是可以的。输出之后程序异常退出
}

//12.25
//delete []pa;

//12.26
void fun12_26(int n) {
	allocator<string> alloc;
	auto  p = alloc.allocate(n);
	auto  q = p;
	string s;
	while(cin >> s && q != p + n) {
		*q++ = s;
	}
	while(q != p) {
		alloc.destroy(--q);
	}
	alloc.deallocate(p, n);
}

//12.27
//书本详细

//12.28
void fun12_28(ifstream &in, const string &sought) {
	vector<string> vs;
	map<string, set<int>> mss;
	string words;
	while(getline(in, words)) {
		vs.push_back(vs);
		int n = vs.size() - 1;
		istringstream line(words);
		string word;
		while(line >> word) {
			set<int> &si = mss[line];
			si.insert(n);
		}
	}
	auto p = mss.find(sought);
	if(p == mss.end()) {
		cout << "nodata" << endl;
	}
	else {
		for(auto i: mss[p.second]) {
			cout << i << " " << vs[i];
		}
	}

}


//12.29
//差不多

//12.30
//看TextQuery.h和QueryResult.h

//12.31
//用vector需要重新排序

//12.32
//vector<string>换成StrBlob就行，提供的接口是一样的。



 

int main() {
	fun12_24();
	return 0;
}