//ch9_ans.cpp
//Greatljc
/*
9.1
(a) 要求字典序插入容器，那么元素会频繁的移动，那么vector和deque不行。只能用list了。
(b) deque
(c)vector

9.2
#include <list>
using std::list;
list<deque<int> > l;

9.3
对于 begin() 和 end() ,指向同一个容器，并且可以通过反复加 begin()到达 end()

9.4
#include <vector>
using std::vector;

bool find(vector<int>::iterator begin, vector<int>::iterator end, int d) {
	for(auto b = begin; b != end; ++b) {
		if(*b == d) return true;
	}
	return false;
}

9.5
#include <vector>
using std::vector;

vector<int>::iterator find(vector<int>::iterator begin, vector<int>::iterator end, int d) {
	for(auto b = begin; b != end; ++b) {
		if(*b == d) return b;
	}
	return end;
}

9.6
error:list迭代器没有重载<运算符

9.7
vector<int>::iterator

9.8
list<string>::const_iterator
list<string>::reference

9.9
begin()获取iteartor
cbegin()获取const_iterator

9.10
v1是一个元素类型为int的vector
v2是一个元素类型为int的常量vector
it1是一个vector<int>迭代器，it2是一个vector<int> 常量迭代器
it3是一个vector<int>迭代器，it4是一个vector<int> 常量迭代器

9.11
#include <vector>
1.vector<int> v1; //空的vector容器
2.vector<int> v2(v1) //包含着v1的拷贝
3.vector<int> v3{1, 2, 3} //包含3个int元素的vector的容器
4.vector<int> v4(v3.begin(), v3.end()); //包含v3的元素
5.vector<int> v5(5);  //包含5个默认初始化的int的vector
6.vector<int> v6(5, 5);  //包含5个初始化为1的int的vector

9.12
拷贝的方法需要两个容器的类型和元素类型都匹配。
用迭代器进行初始化的容器的只需要容器的元素类型可以进行转换得到就行。

9.13
#include <vector>
#include <list>

list<int> l1;
vector<int> v;
vector<double> v1(l1.begin(), l1.end());
vector<double> v2(v.begin(), v.end());

9.14
#include <list>
#include <string>
#include <vector>

using std::list;
using std::string;
using std::vector;

list<char*> l1;
vector<string> v1;
v1.assign(l1.cbegin(), l1.cend());

9.15
#include <vector>
#include <cstdio>

std::vector<int> v1, v2;

bool judge() {
	return v1 == v2
}
*/
/*
//9.16
#include <list>
#include <vector>
#include <algorithm>
#include <cstdio>

std::list<int> l1 = {1, 3, 5};
std::vector<int> v1 = {1, 3, 5, 7};

bool judge_equal() {
	if(l1.size() != v1.size()) return false;
	for(auto i = l1.cbegin(), j = v1.cbegin(); i != l1.cend(); ++i, ++j) {
		if(*i != *j) return false;
	}
	return true;
}

bool judge_less() {
	std::list<int>::iterator i;
	std::vector<int>::iterator j;
	for(i = l1.begin(),j = v1.begin(); ; ++i, ++j) {
		if(i == l1.end() && j == v1.end()) return false;
		if(i == l1.end()) return true;
		if(j == v1.end()) return false;
		if(*i > *j) return false;

	}
}
int main() {
	if(judge_less()) {
		printf("sss");
	}
}

//9.17

c1和c2是同一种类型的容器，并且容器的类型也相同

//9.18

#include <string>
#include <deque>
#include <iostream>
using namespace std;

void fun() {
	string str;
	deque<string> de;
	while(cin >> str) {
		de.push_back(str);
	}
	for(deque<string>::iterator i = de.cbegin(); i != de.cend(); ++i) {
		cout << *i << endl;
	}
}

//9.19
#include <string>
#include <list>
#include <iostream>
using namespace std;

void fun() {
	string str;
	list<string> l;
	while(cin >> str) {
		l.push_back(str);
	}
	for(list<string>::iterator i = l.cbegin(); i != l.cend(); ++i) {
		cout << *i << endl;
}	

//9.20

#include <list>
#include <deque>
#include <iostream>

void fun() {
	std::deque<int> d0, d1;
	std::list<int> l1;
	int num;
	while(cin >> num) {
		li.push_back(num);
	}
	for(std::list<int>::iterator i = l.cbegin(); i != l.cend(); ++i) {
		if(*i % 2 == 0) d0.push_back(*i);
		else  d1.push_back(*i);
	}
}

//9.21

//9.22

while循环内部，iter = iv.insert(iter, 2 * some_val);

//9.23
val1 == val2 == val3 == val4

//9.24

//9.25
如果elem1 == elem2，什么也不干
如果elem2是尾后迭代器，那么删除除尾后迭代器的元素
如果都是尾后迭代器，那么程序行为未定义

//9.26

#include <vector>
#include <list>
using std::vector;
using std::list;

int ia[] = {0, 1, 1, 2, 3 ,5 ,8, 13, 21, 55, 89};
void fun() {
	vector<int> v;
	list<int> l;
	for(int i = 0; i < 11; ++i) {
		v.push_back(ia[i]);
		l.push_back(ia[i]);
	}
	auto i = v.begin();
	while(i != v.end()) {
		if(*i % 2) {
			i = v.erase(i);
		}
	}
	i = l.begin();
	while(i != l.end()) {
		if(*i % 2 == 0) {
			i = l.erase(i);
		}
	}
}



//9.27
#include <forward_list>
#include <iostream>
using namespace std;

void find(forward_list<int> &fl) {
	auto bb = fl.before_begin();
	auto b = fl.begin();
	while(b != fl.end()) {
		if(*b % 2) {
			b = fl.erase_after(*b);
		}
		else {
			bb = b;
			++b;
		}
	}
}

int main() {
	forward_list<int> fl = {1, 2, 3, 4, 5, 6, 7};
	find(fl);
	forward_list::iterator b = fl.begin();
	while(b != fl.end()) {
		cout << *b << " ";
	}
}


//9.28
#include <forward_list>
#include <string>
using namespace std;

void insertstr(string &s1, string &s2, forward_list<string> fl) {
	forward_list<string>::iterator cur = fl.begin(), pre = fl.before_begin();
	int ok = 0;
	while(cur != fl.end()) {
		pre = cur;
		if(*cur == s1) {
			cur = fl.insert_after(cur, s2);
			ok = 1;
			break;
		}
		++cur;

	}
	if(!ok) {
		fl.insert_after(pre, s2);
	}
}


//9.29
添加75个元素，并默认初始化这75个元素
删除90个元素

//9.30
元素类型可以执行默认初始化

//9.31

list可以，forward_list不可以
//forward_list
forward_list<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
auto pre = vi.before_begin();
auto cur = vi.begin();
while(cur != vi.end()) {
	if(*cur % 2) {
		pre = vi.insert_after(pre, *cur);
		cur += 2;
	}
	else {
		pre = vi.erase_after(pre, *cur);
		cur = pre + 1;
	}
}

//9.32
不合法，++比*优先级高，先算++，再算*，那么得到的将不会是所期望的

//9.33
begin()迭代器失效，进入了死循环.

//9.34
?也不知道是不是没有写大括号
如果这样写，那么程序陷入，无论找没找到奇数。
假设是漏写了大括号，那么进入循环，找到第一个奇数，在奇数前面复制这个奇数，++迭代器又重新回到这个奇数。

//9.35
capacity是该vector可以存多少个元素，size是该vector已经存了多少个元素

//9.36
不可能

//9.37
array是固定大小的，不能动态增加内存，也就没有必要capacity
list存储元素的内存不是连续的

//9.38
#include <vector>
#include <iostream>
using namespace std;
int main() {
	vector<int> v;
	v.reserve(4);
	for(int i = 0; i < 5; ++i) {
		cout << "v.size()" << v.size() << endl;		
		cout << "v:capacity()" << v.capacity() << endl;
	}
	return 0;
}

//9.39
首先先将vector的内存容量变成1024，然后从标准输入中读取string，一直读到文件末尾
resize()只改变size()，不改变capacity().
*/

//9.40
//依赖于标准库的实现

//9.41
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	vector<char> vc = {'a', 'b', 'c', 'd', 'e'};
	string s(vc.begin(), vc.end());
	cout << s << endl;
	return 0;
}


//9.42

//预留超过100个元素的string，使用reverse函数

//9.43

void find_replace(string &s, string &oldVal, string &newVal) {
	int oldLen = oldVal.size(), newLen = newVal.size();
	string::iterator sb = s.begin();
	while(sb != s.end() - oldLen) {
		if(string(sb, sb + oldLen) == oldVal) {
			sb = s.erase(sb, sb + oldLen);
			sb = s.insert(sb, newVal.begin(), newVal.end());
			advance(sb, newLen);
		}
		else {
			++sb;
		}
	}
}


//9.44

void find_replace1(string &s, string &oldVal, string &newVal) {
	int oldLen = oldVal.size(), newLen = newVal.size();
	for(int i = 0; i <= s.size() - oldLen; ++i) {
		if(s.substr(i, oldLen) == oldVal) {
			s.replace(i, oldLen, newVal);
			i += newLen;
		}
	}
}

//9.45

string& append_plus(string &s, const char *str1, const char *str2) {
	s.insert(s[0], str1);   //错误 s.insert(s.begin(), str1)
	s.append(str2);
	return s;
}

//9.46

void append_plus2(string &s, const char *str1, const char *str2) {
	s.insert(0, str1);
	s.insert(s.size(), str2);
}

//9.47

const char *number = "0123456789";
const char *alpha = "abcdefghijklmnopqrstuvwxyz";

void find1(string &s, int *index1, int *index2) {
	string::size_type i = 0;
	int index = 0;
	while(i != string::npos) {
		i = s.find_first_of(number, i);
		index1[index] = i;
	}
	i = 0, index = 0;
	while(i != string::npos) {
		i = s.find_first_of(alpha, i);
		index2[index] = i;
	}
}

void find2(string &s, int *index1, int *index2) {
	string::size_type pre_not = 0, cur_not;
	unsigned index = 0;
	while(cur_not != string::npos) {
		cur_not = s.find_first_not_of(number, pre_not + 1);
		for(int i = 0; i < cur_not - pre_not; ++i) {
			index1[index++] = pre_not + i;
		}
		pre_not = cur_not;
	}
	pre_not = cur_not = 0;
	index = 0;
	while(cur_not != string::npos) {
		cur_not = s.find_first_of(alpha, pre_not + 1);
		for(int i = 0; i < cur_not - pre_not; ++i) {
			index1[index++] = pre_not + i;
		}
		pre_not = cur_not;

	}
}

//9.48
//string::npos;

//9.49

const char* not_bound = "acenmorsuvwxz";

string not_include(ifstream &in) {
	string max(""), word;
	while(in >> word) {
		if(word.find(not_bound) == string::npos && max.size() < word.size()) {
			max = word;
		}
	}
	return max;
}

//9.50 c++11标准，谨慎使用，万一使用的编译器不支持c++11

long long cal(vector<string> &vs) {
	long long ans = 0;
	for(int i = 0; i < vs.size(); ++i) {
		ans += stoi(vs[i]);
	}
	return ans;
}

//9.51
struct Day {
	unsigned year, month, day;
	Day() = default;
	Day(string s);
	void show() { cout << year << "year" << month << "month" << day << "day" << endl;}
};
//通过搜索三种格式的不同，一个是有','， 一个是有'/'，一个是只有' '。


//9.52
//处理中缀表达式
long long fun(string s) {
	stack<char> sta1, sta2;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == '(') sta1.push(s[i]);
		if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*') sta1.push(s[i]);
		if(s[i] == ')') {
			while(sta1.top() != '(') {
				char ch = sta1.top();
				int n1, n2;
				n1 = sta2.top() - '0';
				sta2.pop();
				n2 = sta2.top() - '0';
				sta2.pop();
				if(ch == '+') {
					sta2.push(n1 + n2);
				}
				else if(ch == '-') {
					sta2.push(n1 * n2);
				}
				else if(ch == '/') {
					sta2.push(n1 / n2);
				}
				else {
					sta2.push(n1 * n2);
				}
				sta1.pop();
			}
			sta1.pop();
		}
		if(isdigit(s[i])) {
			sta2.push(s[i]);
		}
	}
	string temp;
	while(!sta2.empty()) {
		temp += sta2.top();
		sta2.pop();
	}
	return stol(temp);
}


