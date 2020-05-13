//ch10.cpp
//Greatljc
#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <list>
#include <functional>
#include <iterator>
#include <deque>
#include <fstream>
using namespace std;
using namespace std::placeholders;
//10.1

int times(vector<int> &vi, int val) {
	return count(vi.begin(), vi.end(), val);
}

//10.1
int times(list<string> &ls, string val) {
	return count(ls.begin(), ls.end(), val);
}

//10.3
//maybe need return long long
int sum(vector<int> &vi) {  
	return accumulate(vi.begin(), vi.end(), 0);
}

//10.4
//因为vector的元素类型是double，调用accumulate函数的初始和值是0，是一个整型，所以会导致和会丢失精度。
//test

double sum(vector<double> &vd) {
	double ans = accumulate(vd.begin(), vd.end(), 0);
	return ans;
}
/*vector<double> vd = {1.2, 3.2};
 *cout << sum(vd);  输出4
 */

//10.5
//因为const char *没有重载+，会导致编译失败
/*
bool equals(const char *str1, const char *str2) {
	return equal(begin(str1), end(str1), begin(str2));
}
*/
//10.6
void set_zero(vector<int> &ve) {
	fill_n(ve.begin(), ve.size(), 0);
}

//10.7
//(a)
void copys() {
	vector<int> vec;
	list<int> lst;
	int i;
	while(cin >> i) lst.push_back(i);
	copy(lst.cbegin(), lst.cend(), back_inserter(vec));
}
//(b)reserve()函数只是扩充了内存，让容器至少可以容纳10个。仅仅是分配了内存，没有构造。
//应该调用的是resize()

//10.8
//个人理解：因为back_inserter绑定了一个容器的引用，调用了push_back，并不是算法改变的容器的大小，而是自身的操作改变的大小

//10.9
void elimDups(vector<string> &words) {
	string s;
	while(cin >> s) {
		words.push_back(s);
	}
	sort(words.begin(), words.end());
	vector<string>::iterator end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	for(int i = 0; i < words.size(); ++i) {
		cout << words[i] << endl;
	}
}

//10.10
//增加操作的兼容性


//10.11
bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}
void elimDups(vector<string> &words, int val) {
	string s;
	while(cin >> s) {
		words.push_back(s);
	}
	sort(words.begin(), words.end());
	vector<string>::iterator end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	stable_sort(words.begin(), words.end(), isShorter);
	for(int i = 0; i < words.size(); ++i) {
		cout << words[i] << endl;
	}
}
/*vector<string> words;
 *elimDups(words, 0);
 */

//10.12 简化版Sales_data
struct Sales_data {
	Sales_data() = default;
	string Isbn;
	string isbn() const { return Isbn; }
};
bool compareIsbn(const Sales_data &sa1, const Sales_data &sa2) {
	return sa1.isbn() < sa2.isbn();
}
void sortSales_date(vector<Sales_data> &vsa) {
	sort(vsa.begin(), vsa.end(), compareIsbn);
}
/*ector<Sales_data> vsa;
 *sortSales_date(vsa);
 */

//10.13
bool isBigger(const string &str1) {
	return str1.size() >= 5;
}
void sortString(vector<string> &vs) {
	string str;
	while(cin >> str) {
		vs.push_back(str);
	}
	vector<string>::iterator end_big = partition(vs.begin(), vs.end(), isBigger);
	for(auto i = vs.begin(); i != end_big; ++i) {
		cout << *i << endl;
	}
}

//10.14
/*
 [](int i, int j) -> long long {return i + j; }
 */

//10.15
int sum(int i) {
	auto ans = [i](int j) { return i + j;};
	return ans(2);
}

//10.16
//as same as biggies

//10.17
void sortSales_dates(vector<Sales_data> &vsa) {
	sort(vsa.begin(), vsa.end(), [](const Sales_data sa1, const Sales_data &sa2) { return sa1.isbn().size() < sa2.isbn().size();});
}

//10.18
void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), 
			     [sz] (const string &a, const string &b)
			  	   { return a.size() < b.size(); });
	auto wc = partition(words.begin(), words.end(),
							[sz](const string &a)
								{ return a.size() >= sz; });

	auto count = words.end() - wc;
	for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}

//10.19

void biggiess(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), 
			     [sz] (const string &a, const string &b)
			  	   { return a.size() < b.size(); });
	auto wc = stable_partition(words.begin(), words.end(),
							[sz](const string &a)
								{ return a.size() >= sz; });

	auto count = words.end() - wc;
	for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}


//10.20
int times(vector<string> &vs, int t) {
	return count_if(vs.begin(), vs.end(), [t](const string &s) { return s.size() > t; });
}

//10.21
bool fun(int t) {
	auto ans = [t]()mutable -> bool{
		if(t == 0) return false;
		while(--t != 0)
		return true;
	};
	return ans();

}

//10.22
bool lessnum(const string &s, int len) {
	return s.size() <= len;
}

int timess(vector<string> &vs, int t) {
	return count_if(vs.begin(), vs.end(), bind(lessnum, _1, t));
}

//10.23
//至少一个

//10.24
bool check_size(const string &s, string::size_type sz) {
	return s.size() >= sz;
}

void find_first_str(vector<string> &vi, const string &str) {
	auto ans = find_if(vi.begin(), vi.end(), bind(check_size, _1, str.size()));
}

//10.25
void biggiesss(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), 
			     [sz] (const string &a, const string &b)
			  	   { return a.size() < b.size(); });
	auto wc = partition(words.begin(), words.end(),
							bind(check_size, _1, sz));

	auto count = words.end() - wc;
	for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}

//10.26
//back_inserter使用的是push_back()
//front_inserter使用的是push_front()
//inserter使用的是inserter()

//10.27
void use_unique_copu(vector<int> &vi, list<int> &li) {
	sort(vi.begin(), vi.end());
	unique_copy(vi.begin(), vi.end(), back_inserter(li));
}

//10.28
void copy_other(vector<int> &vi) {
	vector<int> s;
	deque<int> di;
	list<int> li;
	copy(vi.begin(), vi.end(), back_inserter(s));
	copy(vi.begin(), vi.end(), front_inserter(di));
	copy(vi.begin(), vi.end(), inserter(li, li.begin()));
}

//10.29

void read_txt(const string &s, vector<string> &vs) {
	ifstream in(s);
	istream_iterator<string> str_in(in), eof;
	while(str_in != eof) {
		string temp = *str_in++;
		vs.push_back(temp);
	}
}

//10.30
void read_int_print(istream &in, ostream &out) {
	istream_iterator<int> ins(in), eof;
	ostream_iterator<int> outs(out);
	vector<int> vi;
	while(ins != eof) {
		int temp = *ins++;
		vi.push_back(temp);
	}
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), outs);
}

//10.31
void read_int_prints(istream &in, ostream &out) {
	istream_iterator<int> ins(in), eof;
	ostream_iterator<int> outs(out);
	vector<int> vi;
	while(ins != eof) {
		int temp = *ins++;
		vi.push_back(temp);
	}
	sort(vi.begin(), vi.end());
	unique_copy(vi.begin(), vi.end(), outs);
}

//10.32 略

//10.33
void read_print2(const string &input, const string &output1, const string &output2) {
	ifstream in(input);
	ofstream out1(output1), out2(output2);
	istream_iterator<int> ins(in), eof;
	ostream_iterator<int> outs1(out1, " "), outs2(out2, "\n");
	while(ins != eof) {
		int temp;
		temp = *ins++;
		if(temp % 2) {
			*outs1++ = temp;
		}
		else {
			*outs2++ = temp;
		}
	}
}

//10.34
void reverse_print(vector<int> &vi) {
	for(auto i = vi.cbegin(); i != vi.cend(); ++i) {
		cout << *i << " ";
	}
}

//10.35
void reverse_prints(vector<int> &vi) {
	auto l = vi.end();
	for(auto l = vi.end() - 1; l != vi.begin(); ++l) {
		cout << *l << " ";
	}
	cout << *vi.begin() << endl;
}

//10.36
void find_reverse(list<int> &li) {
	auto i = find(li.rbegin(), li.rend(), 0);
}

//10.37
void copy_reverse(vector<int> &ve, list<int> &li) {
	auto l = ve.rbegin() + 3;
	auto i = l + 5; 
	copy(l, i, li.begin());
}

//10.38
/*输入
 *输出
 *前向迭代器
 *双向迭代器
 *随机访问迭代器
 */

//10.39
//list：双向迭代器
//vector:随机访问迭代器

//10.40
//双向迭代器，双向迭代器，随机访问迭代器

//10.41
//1.在beg和end中，找到oldval, 用newval替换
//2.在beg和end中，使得pred成立的，都用new_val替换
//3.在beg和end的范围，拷贝到dest指向的容器，然后将那么==old_val的换成new_val
//4.和3的区别就是使得pred成立的换成new_val


void elimDups(list<string> &words) {
	string s;
	while(cin >> s) {
		words.push_back(s);
	}
	words.sort();
	words.unique();
}


int main() {
	
	return 0;
}