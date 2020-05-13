#ifndef FOLDER_H
#define FOLDER_H
#include <set>
class Message;
class Folder {
public:
	Folder() = default;
	void addMsg(Message *m);
	void remMsg(Message *m);
private:
	std::set<Message*> msgs;
};
void Folder::addMsg(Message *m) {
	msgs.insert(m);
}
void Folder::remMsg(Message *m) {
	msgs.erase(m);
}

#endif