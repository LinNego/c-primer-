#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H
#include <string>
#include <memory>
#include <iostream>
class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s,
				std::shared_ptr<std::set<int>> p,
				std::shared_ptr<std::vector<std::string>> f):
		word(s), lines(p), file(f){}
		std::set<int>::iterator begin()const;
		std::set<int>::iterator end()const;
		std::shared_ptr<std::vector<std::string>> get_file()const;
private:
	std::string word;
	std::shared_ptr<std::vector<std::string>> file;
	std::shared_ptr<std::set<int>> lines;
};

std::set<int>::iterator QueryResult::begin() const{
	return lines->begin();
}

std::set<int>::iterator QueryResult::end() const{
	return lines->end();
}

std::shared_ptr<std::vector<std::string>>
QueryResult::get_file() const {
	return file;
}

std::ostream& print(std::ostream &os, const QueryResult &qr) {
	os << qr.word << "occurs" << qr.lines->size() << "times" << std::endl;
	for(auto num: *qr.lines) {
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
	}
	return os;
}

#endif