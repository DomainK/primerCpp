#pragma once

#ifndef DEBUG_H
#define DEBUG_H

class Debug
{
public:
	constexpr Debug(bool b = true) :hw(b), io(b), other(b) { }
	constexpr Debug(bool h, bool i, bool o) :
		hw(h), io(i), other(o) { }
	constexpr bool any() { return hw || io || other; }
	void set_io(const bool b) { io = b; }
	void set_hw(const bool b) { hw = b; }
	void set_other(const bool b) { other = b; }
private:
	bool hw;    //Ó²¼þ´íÎó
	bool io;	//IO´íÎó
	bool other;	//ÆäËû´íÎó
};

#endif // !DEBUG_H
