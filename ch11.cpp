//Greatljc 
//ch11.cpp
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <cctype>
#include <list>
#include <utility>
#include <vector>
using namespace std;


//11.1
//map的关键字类型可以是其他数据类型，vector的关键字类型是整数。

//11.2

//11.3
int times(map<string, int> &msz) {
	string word;
	while(cin >> word) {
		++msz[word];
	}
	for(const auto &w : msz) {
		cout << w.first << "times" << w.second << endl;
	}
}

//11.4
int timesp(map<string, int> &msz) {
	string word;
	while(cin >> word) {
		if(word[word.size() - 1] == '.' || word[word.size() - 1] == ',') word = word.substr(0, word.size() - 1);
		word[0] = toupper(word[0]);
		++msz[word];
	}
	for(const auto &w: msz) {
		cout << w.first << "times" << w.second << endl;
	}
}

//11.5
//看情况
//11.6
//看情况

//11.7
void fun(map<string, vector<string> > &msvs) {
	string fname;
	while(cin >> fname) {
		string cname;
		while(cin >> cname) {
			msvs[fname].push_back(cname);
		}
	}
}

//11.8
void fun(vector<string> &vs, vector<int> &vi) {
	string word;
	while(cin >> word) {
		if(vs.empty()) {
			vs.push_back(word);
			vi.push_back(1);
		}
		else {
			int ok = 0;
			for(int i = 0; i < vs.size(); ++i) {
				if(vs[i] == word) {
					++vi[i];
					ok = 1;
					break;
				}
			}
			if(!ok) {
				vs.push_back(word);
				vi.push_back(1);
			}
		}
	}
}


//11.9
//map<string, list<int>> msli;

//11.10
//vector的可以，因为vector的迭代器定义了 < 。list的不行，没有定义小于。

//11.11
//multiset<Sales_data, bool (*)(const Sales &lhs, const Sales_data &rhs);

//11.12
void fun(vector<pair<string, int>> &vp) {
	string word;
	int n;
	while(cin >> word >> n) {
		vp.push_back(pair<string, int>(word, n));
	}
}

//11.13
//1.pair<string, int> p(word, n);
//2.pair<string, int> p = make_pair(word, n);
//3.pair<string, int> p{word, n};

//11.14
void fun(map<string, vector<string> > &msvs, vector<pair<string, int> > &vp) {
	string fname;
	while(cin >> fname) {
		string cname, data;
		while(cin >> cname >> data) {
			msvs[fname].push_back(cname);
			vp.push_back(pair<string, int>(cname, data));
		}
	}
}

//11.15
//mapped_type = pair<int, vector<int>>
//key_type = int
//value_type = int

//11.16
//map<string, int> p; 
//*p.begin = pair<string, int>("good", 2);

//11.17
//1.合法，每一次将元素插入到c容器的末尾
//2.不合法，multiset没有push_back()
//3.合法
//4.合法

//11.18

pair<string, int>::iterator map_it = word_count.cbegin();

//11.19
typedef bool (*compareIsbn)(const Sales_data&, const Sales_data&);
multiset<Sales_data, compareIsbn> bookstore(compareIsbn);
multiset<Sales_data, compareIsbn>::iterator b = multiset.begin();

//11.20
void funplus(map<string, int> &word_count) {
	string word;
	while(cin >> word) {
		auto ret = word_count.insert({word, 1});
		if(!ret.second) ++ret.first->second;
	}
}

//11.21
/*将word插入到word_count，如果word_count已经存在word的关键字，insert什么也不做。
 *如果不存在，first指向的一个pair的迭代器，然后解迭代器就是就得到次数。
 */

//11.22
//map<string, vector<int>> msv;
//pair<pair<string, vector<int>>, bool> = msv.insert({"hello", {1, 2, 3, 4}});

//11.23
void funm(multimap<string, vector<string> > &msvs) {
	string fname;
	while(cin >> fname) {
		string cname;
		vector<string> vs;
		while(cin >> cname) {
			vs.push_back(cname);
		}
		msvs.insert(pair<string, vector<string>> (fname, vs));
	}
}


//`11.24
/*完成一个可以动态伸缩数组的功能.
 *
 */

//11.25
/*错误， 内存还没初始化
 */

//11.26
//map<string, int> msi;
//string
//int

//11.27
//对于需要统计计数的count，不需要就find

//11.28
//map<string, vector<int> >msvi;
//pair<string, vector<int> >::iterator ret = msvi.find("");

//11.29
//upper_bound和lower_bound返回一个不影响排序的插入位置
//equal_range返回尾后迭代器

//11.30
//mutiset返回的迭代器是由pair和string类型的pair，所以是解迭代器。

//11.31
void funs() {
	multiset<string, string> msns;
	string aname >> name;
	cin >> aname >> name;
	for(auto pos = msns.equal_range(aname); pos.first != pos.second; ) {
		if(pos.first->second == name) {
			pos = msns.erase(pos);
		}
		else {
			++pos.first;
		}
	}

}

//11.32
void print(multiset<string, string> &msns) {
	auto b = msns.begin();
	while(b != msns.end()) {
		cout << b.first << " " << b.second << endl;
	}
}

//11.33
//看书

//11.34
//添加了不希望添加的内容

//11.35
//进行了检查

//11.36
//读取一个空格，跳过空格，并且生成一个空串

//11.37
//无序更快

//11.38
//貌似一样，可以替换。
int main() {
	return 0;
}