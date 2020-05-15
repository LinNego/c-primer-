//ch16
//Greatljc

#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
//16.1
//实例化模板就是用特定的类型来调用模板

//16.2
template <typename T>
int compare(const T &lhs, const T &rhs) {
	return lhs < rhs ? 1 : -1;
}

//16.3


//16.4
template <typename T, typename U>
T find(const T &b, const T &e, const U &val) {
	T i = b;
	while(i != e) {
		if(*i == val) return i;
		++i;
	}
	return e;
}

//16.5
template <unsigned N, typename T>
void print(const T (&arr)[N]) {
	for(int i = 0; i < N; ++i) {
		cout << arr[i] << " ";
	}
	/*
	for(auto i: arr) {
		cout << i << " ";
	}
	*/
}

//16.6
template <unsigned N, typename T>
T* begin(const T (&arr)[N]) {  //数组的引用可以的参数中加上维度大小也是可以的，传递指针存在问题。
	return arr;
}

template <unsigned N, typename T>
T* end(const T (&arr)[N]) {
	return arr + N;
}


//16.7
template <unsigned N, typename T> constexpr
T* end(const T (&arr)[N]) {
	return N;
}

//16.7
//不是所有容器都有重载了<运算符，但是!= 几乎所有容器都重载了。
int main() {
	//cout << compare(1, 2) << endl;
	int a[5] = {1, 2, 3, 4, 5};
	cout << *begin(a)  << " " <<  *end(a) << endl;
	return 0;
}