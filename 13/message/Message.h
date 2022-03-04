#pragma once

#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>
#include "Folder.h"

class Message {
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	explicit Message(const std::string& str = "") :
		contents(str) { }
	Message(const Message&);
	Message& operator=(const Message&);
	Message(Message&& m);
	Message& operator=(Message&& rhs);
	~Message();
	void save(Folder&);
	void remove(Folder&);
	void add_folders(Folder* f) { folders.insert(f); }
	void rem_folders(Folder* f) { folders.erase(f); }
	void move_Folders(Message* m);

private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};

inline Message::Message(const Message& m) :
	contents(m.contents), folders(m.folders) {
	add_to_Folders(m);
}

inline Message::~Message() {
	remove_from_Folders();
}

inline Message& Message::operator=(const Message& rhs) {
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

inline Message::Message(Message&& m) :contents(std::move(m.contents)) {
	move_Folders(&m);
}

inline Message& Message::operator=(Message&& rhs) {
	if (this != &rhs) {
		remove_from_Folders();
		contents = std::move(rhs.contents);
		move_Folders(&rhs);
	}
	return *this;
}

#endif // !MESSAGE_H
