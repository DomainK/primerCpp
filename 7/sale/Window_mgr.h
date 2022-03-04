#pragma once

#ifndef WINDOW_MGR
#define WINDOW_MGR

#include <iostream>
#include <vector>
#include "Screen.h"

class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen&);
private:
	std::vector<Screen> screens{ Screen(24,80,' ') };
};

#endif // !WINDOW_MGR

