#pragma once

#ifndef FOLDER_H
#define FOLDER_H

#include <set>
#include "Message.h"

class Folder {
public:
	Folder();
	Folder(const std::set<Message*> m) :Msgs(m) { };
	Folder& operator=(const Folder&);
	~Folder() { };
	void addMsg(Message* msg) { Msgs.insert(msg); }
	void remMsg(Message* msg) { Msgs.erase(msg); }

private:
	std::set<Message*> Msgs;
};

Folder& Folder::operator=(const Folder& rhs) {
	this->Msgs = rhs.Msgs;
	return *this;
}


#endif // !FOLDSER_H

