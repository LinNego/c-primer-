#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>

class QueryResult;
class TestQuery {
public:
	
	TestQuery(std::ifstream &);
	QueryResult query(const std::string &) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	//std::map<std::string, std::set<int> > wordline;
	std::map<std::string, std::shared_ptr<std::set<int>>> lines;
};

TestQuery::TestQuery(std::ifstream &in) :file(new std::vector<std::string>) {
	std::string text;
	while(std::getline(in, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream line(text);
		std::string word;
		while(line >> word) {
			auto &linenumber = lines[word];
			if(!linenumber) {
				//linenumber.reset(new std::set<int>);
				linenumber = std::make_shared<std::set<int> >();
			}
			linenumber->insert(n);
		}
	}
}

#include "QueryResult.h"
QueryResult TestQuery::query(const std::string &s) const {
	static std::shared_ptr<std::set<int>> nodata(new std::set<int>);
	auto loc = lines.find(s);
	if(loc == lines.end()) {
		return QueryResult(s, nodata, file);
	}
	else {
		return QueryResult(s, loc->second, file);
	}
}
#endif