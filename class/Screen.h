//Greatljc
//Screen.h
#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>
class Screen {
public:
	friend class Window_mgr;   //如果不是模板，声明有缘不需要有前置声明？
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c = ' '): 
		heigth(ht), width(wd), contents(ht * wd, c){ }
	char get() const
		{ return contents[cursor];}
	inline char get(pos r, pos c) const;
	Screen &move(pos r, pos c);
	inline Screen& set(char ch);
	inline Screen& set(pos r, pos c, char ch);
	const Screen& display(std::ostream &os) const { do_play(os); return *this; }
	Screen& display(std::ostream &os) { do_play(os); return *this; }
private:
	unsigned cursor = 0;
	unsigned heigth = 0, width = 0;
	std::string contents;
	void do_play(std::ostream &os) const { os << contents; }
};

inline
Screen& Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

char Screen::get(pos r, pos c) const {
	return contents[r * width + c];
}

Screen& Screen::set(char c) {
	contents[cursor] = c;	
	return *this;
}

Screen& Screen::set(pos r, pos c, char ch) {
	contents[r * width + c] = ch;
	return *this;
}

























#endif